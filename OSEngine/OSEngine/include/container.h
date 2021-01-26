#pragma once

template<class T> constexpr size_t count(const T& container) noexcept {
    return container.size();
}

template<class T> const typename T::reference last(const T& container) {
    return *std::prev(container.end());
}

template<class T> typename T::reference last(T& container) {
    return *std::prev(container.end());
}

template<class T> const typename T::reference first(const T& container) {
    return *container.begin();
}

template<class T> typename T::reference first(T& container) {
    return *container.begin();
}

template<class T> bool is_empty(const T& container) noexcept {
    return container.empty();
}

template<class T> void clear(T& container) noexcept {
    return container.clear();
}