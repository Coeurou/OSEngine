#include <algorithm.h>
#include <kabuto.h>
#include <logger.h>

#include <nameof.hpp>

namespace ose {

token::token(token::type t, token::object litteral) : my_type(t), my_litteral(std::move(litteral)) {}

token::type token::token_type() const {
    return my_type;
}

const token::object& token::value() const {
    return my_litteral;
}

string to_string(const token::object& obj) {
    return std::visit(overloaded{
                          [](auto arg) { return to_string(arg); },
                          [](std::monostate /*arg*/) { return string("EMPTY"); },
                          [](const string& arg) { return arg; },
                      },
                      obj);
}

string to_string(const token& t) {
    return format("{{ type: {}, litteral: {} }}", NAMEOF_ENUM(t.token_type()), to_string(t.value()));
}

}  // namespace ose