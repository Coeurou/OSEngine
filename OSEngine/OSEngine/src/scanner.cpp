#include <kabuto.h>
#include <logger.h>

#include <cctype>
#include <charconv>
#include <nameof.hpp>
#include <sstream>

namespace ose {

scanner::scanner(string_view source) : my_source(source) {}

result<u32> scanner::scan(string_view source) {
    for (auto it = source.begin(); it != source.end(); it++) {
        char c = *it;
        switch (c) {
            case '<': {
                my_tokens.emplace_back(token(token::type::redirect_input));
                break;
            }
            case '>': {
                if (const auto next = std::next(it); next != source.end() && *next == c) {
                    it = next;
                    my_tokens.emplace_back(token(token::type::append_output));
                }
                else {
                    my_tokens.emplace_back(token(token::type::redirect_output));
                }
                break;
            }
            case '&': {
                if (const auto next = std::next(it); next != source.end() && *next == c) {
                    it = next;
                    my_tokens.emplace_back(token(token::type::and_op));
                }
                else {
                    my_tokens.emplace_back(token(token::type::background));
                }
                break;
            }
            case '|': {
                if (const auto next = std::next(it); next != source.end() && *next == c) {
                    it = next;
                    my_tokens.emplace_back(token(token::type::or_op));
                }
                else {
                    my_tokens.emplace_back(token(token::type::pipe));
                }
                break;
            }
            case '\"': {
                const auto first_quote = static_cast<size_t>(std::distance(source.begin(), it));
                if (auto next_quote = source.find('\"', first_quote); next_quote != string_view::npos) {
                    ++next_quote;
                    it = std::begin(source) + next_quote;

                    my_tokens.emplace_back(
                        token(token::type::expr, string(source.substr(first_quote, next_quote - first_quote))));
                }
                else {
                    log_error(log_category::system,
                              "unexpected end of line, cannot close opened quote expression token.");
                    return error_type::invalid_parameter;
                }
                break;
            }
            case '{': {
                const auto first_brace = static_cast<size_t>(std::distance(source.begin(), it));
                if (auto next_brace = source.find('}', first_brace); next_brace != string_view::npos) {
                    ++next_brace;
                    it = std::begin(source) + next_brace;

                    my_tokens.emplace_back(
                        token(token::type::expr, string(source.substr(first_brace, next_brace - first_brace))));
                }
                else {
                    log_error(log_category::system,
                              "unexpected end of line, cannot close opened brace expression token.");
                    return error_type::invalid_parameter;
                }
                break;
            }
            case '-': {
                const auto current = static_cast<size_t>(std::distance(source.begin(), it));
                if (size_t end_expr = source.find(' ', current);  end_expr != string_view::npos) {
                    it = std::begin(source) + end_expr;
                    my_tokens.emplace_back(
                        token(token::type::expr, string(source.substr(current, end_expr - current))));
                }
                else {
                    my_tokens.emplace_back(
                        token(token::type::expr, string(source.substr(current))));
                    it = std::prev(source.end());
                }
                break;
            }
            default: {
                if (std::isalnum(c)) {
                    const auto end_str = std::find_if(std::next(it), source.end(), [](char ch) {
                        return std::isalnum(ch) == 0 && ch != '-' && ch != '.' && ch != '_';
                    });

                    // deduce litteral type (string, u32, float or double)
                    token::object litteral =
                        string(source.substr(std::distance(std::begin(source), it), std::distance(it, end_str)));
                    const string& expr = std::get<string>(litteral);
                    const char* expr_begin = expr.data();
                    const char* expr_end = expr.data() + expr.size();

                    if (expr.find('.') != string::npos) {
                        double litteral_as_double = 0;
                        if (auto [pf, errf] = std::from_chars(expr_begin, expr_end, litteral_as_double);
                            errf == std::errc()) {
                            litteral = litteral_as_double;
                        }
                    }
                    else {
                        u32 litteral_as_int = 0;
                        if (auto [p, err] = std::from_chars(expr_begin, expr_end, litteral_as_int);
                            err == std::errc()) {
                            litteral = litteral_as_int;
                        }
                    }

                    my_tokens.emplace_back(token(token::type::expr, litteral));
                    it = (end_str != source.end()) ? end_str : std::prev(source.end());
                }
                break;
            }
        }
    }

    my_tokens.emplace_back(token(token::type::eof));

    // log result
    {
        std::stringstream tokens_to_string;
        tokens_to_string << "[";
        for (const auto& t : my_tokens) {
            tokens_to_string << to_string(t) << ", ";
        }
        tokens_to_string << "]";
        log_debug(log_category::system, "tokens scanned: {}\n", tokens_to_string.str());
    }
    return result<u32>(EXIT_SUCCESS);
}

result<u32> scanner::scan() {
    return scan(my_source);
}

}  // namespace ose