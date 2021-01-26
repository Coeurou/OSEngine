#pragma once

#include <algorithm>

template<class T, class V> auto find(const T& container, const V& value) {
    return std::find(std::cbegin(container), std::cend(container), value);
}

template<class T, class V> auto find(T& container, const V& value) {
    return std::find(std::begin(container), std::end(container), value);
}

template<class T, class UnaryPredicate> auto find_if(const T& container, UnaryPredicate p) {
    return std::find_if(std::cbegin(container), std::cend(container), p);
}

template<class T, class UnaryPredicate> auto find_if(T& container, UnaryPredicate p) {
    return std::find_if(std::begin(container), std::end(container), p);
}

template<class T, class V> auto remove(T& container, const V& value) {
    return std::remove(std::begin(container), std::end(container), value);
}

template<class T, class UnaryPredicate> auto remove_if(T& container, UnaryPredicate p) {
    return std::remove_if(std::begin(container), std::end(container), p);
}

template<class It, class T> bool is_valid(It it, const T& container) {
    return (it != std::end(container));
}