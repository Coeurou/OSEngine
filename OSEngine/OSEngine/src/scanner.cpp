#include <kabuto.h>
#include <logger.h>

#include <cctype>
#include <charconv>
#include <nameof.hpp>
#include <sstream>

namespace ose {

scanner::scanner(string_view source) : my_source(source) {}

result<u32> scanner::scan(string_view source) {
    my_source = std::move(source);

    error_type err = error_type::no_error;

    auto it = std::begin(my_source);
    const auto get_chars_until = [&](char c) {
        const auto str_begin = std::begin(my_source);
        const auto str_end = std::end(my_source);

        const size_t offset = std::distance(str_begin, it);
        size_t pos = my_source.find(c, offset);
        bool found = (pos != string_view::npos);

        if (found) {
            // we don't want to process the char just found so we move next to it
            const auto next_char_it = str_begin + pos;
            it = (next_char_it != str_end) ? next_char_it : std::prev(str_end);
        }
        else {
            pos = my_source.size();
            it = std::prev(str_end);
        }
        return std::make_tuple(offset, pos - offset, found);
    };

    for (; it != std::end(my_source); it++) {
        char c = *it;
        switch (c) {
            case ';': {
                my_tokens.emplace_back(token(token::type::sequence));
                break;
            }
            case '<': {
                my_tokens.emplace_back(token(token::type::redirect_input));
                break;
            }
            case '>': {
                if (auto next = std::next(it); next != std::end(my_source) && *next == *it) {
                    my_tokens.emplace_back(token(token::type::append_output));
                    it = next;
                }
                else {
                    my_tokens.emplace_back(token(token::type::redirect_output));
                }
                break;
            }
            case '|': {
                if (auto next = std::next(it); next != std::end(my_source) && *next == *it) {
                    my_tokens.emplace_back(token(token::type::or_op));
                    it = next;
                }
                else {
                    my_tokens.emplace_back(token(token::type::pipe));
                }
                break;
            }
            case '&': {
                if (auto next = std::next(it); next != std::end(my_source) && *next == *it) {
                    my_tokens.emplace_back(token(token::type::and_op));
                    it = next;
                }
                else {
                    my_tokens.emplace_back(token(token::type::background));
                }
                break;
            }
            case '-': {
                const auto [offset, count, found] = get_chars_until(' ');
                my_tokens.emplace_back(token(token::type::expr, string(my_source.substr(offset, count))));
                break;
            }
            case '{': {
                const auto revert = it;
                auto [offset, count, found] = get_chars_until('}');
                if (found) {
                    // we want to capture closing brace
                    count++;
                    my_tokens.emplace_back(token(token::type::expr, string(my_source.substr(offset, count))));
                }
                else {
                    it = revert;
                    err = error_type::invalid_parameter;
                    log_error(log_category::system, "[scanner::scan] invalid token : couldn't found closing brace");
                }
                break;
            }
            case '\"': {
                const auto revert = it;
                auto [offset, count, found] = get_chars_until('\"');
                if (found) {
                    // we don't want to capture opening quote
                    offset++;
                    my_tokens.emplace_back(token(token::type::expr, string(my_source.substr(offset, count))));
                }
                else {
                    it = revert;
                    err = error_type::invalid_parameter;
                    log_error(log_category::system, "[scanner::scan] invalid token : couldn't found ending quote");
                }
                break;
            }
            case ' ': {
                break;
            }
            default: {
                const auto offset = std::distance(std::begin(my_source), it);
                if (std::isalnum(c)) {
                    const auto [_, count, found] = get_chars_until(' ');
                    const auto litteral = my_source.substr(offset, count);
                    const char* expr_begin = litteral.data();
                    const char* expr_end = litteral.data() + litteral.size();
                    
                    token::object lexeme = string(litteral);
                    if (std::isdigit(litteral[0])) {
                        if (litteral.find('.') != string_view::npos) {
                            double d = 0.0;
                            if (auto [p, errc] = std::from_chars(expr_begin, expr_end, d); errc == std::errc()) {
                                lexeme = d;
                            }
                            else {
                                float f = 0.f;
                                if (auto [pf, errf] = std::from_chars(expr_begin, expr_end, d); errf == std::errc()) {
                                    lexeme = static_cast<double>(f);
                                }
                                else {
                                    err = error_type::invalid_parameter;
                                    log_error(log_category::system, "[scanner::scan] invalid token : floating number incorrect, pos {}", offset);
                                }
                            }
                        }
                        else {
                            u32 i = 0;
                            if (auto [pu, errc] = std::from_chars(expr_begin, expr_end, i); errc == std::errc()) {
                                lexeme = i;
                            }
                            else {
                                err = error_type::invalid_parameter;
                                log_error(log_category::system, "[scanner::scan] invalid token : integral number incorrect, pos {}", offset);
                            }
                        }
                    }
                    
                    my_tokens.emplace_back(token(token::type::expr, lexeme));
                }
                else {
                    err = error_type::invalid_parameter;
                    log_error(log_category::system, "[scanner::scan] invalid character found {}, pos {}", c, offset);
                }
                break;
            }
        }
    }

    my_tokens.emplace_back(token(token::type::eof));

    log_debug(log_category::system, "tokens scanned: {}\n", to_string(*this));
    return (err == error_type::no_error) ? result<u32>(EXIT_SUCCESS) : result<u32>(err);
}

result<u32> scanner::scan() {
    return scan(my_source);
}

const array<token>& scanner::tokens() const {
    return my_tokens;
}

string to_string(const scanner& s) {
    std::ostringstream stream;
    stream << '[';
    for (const auto& t : s.tokens()) {
        stream << to_string(t) << ", ";
    }
    stream.seekp(-2, stream.cur);
    stream << ']';

    return stream.str();
}

}  // namespace ose