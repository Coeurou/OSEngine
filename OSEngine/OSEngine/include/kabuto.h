#pragma once

#include <result.h>
#include <types.h>

#include <optional>

namespace ose {

class token {
   public:
    enum class type {
        expr,
        pipe,
        redirect_input,
        redirect_output,
        append_output,
        and_op,
        or_op,
        background,
        sequence,
        eof
    };

    using object = std::variant<std::monostate, u32, f64, string>;

    token() = default;
    token(type t, object litteral = {});

    token::type token_type() const;
    const token::object& value() const;

   private:
    type my_type = type::eof;
    object my_litteral;
};

string to_string(const token::object& obj);
string to_string(const token& t);

class scanner {
   public:
    scanner() = default;
    scanner(string_view source);
    result<u32> scan();
    result<u32> scan(string_view source);

    const array<token>& tokens() const;

   private:
    string_view my_source;
    u32 my_current_idx = 0;
    array<token> my_tokens;
};

string to_string(const scanner& s);

}  // namespace ose