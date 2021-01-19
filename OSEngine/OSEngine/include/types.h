#pragma once

#include <array>
#include <cstdint>
#include <limits>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace ose {

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using f32 = float;
using f64 = double;
using time_span = f32;

using string = std::string;
using string_view = std::string_view;

template <class T>
template<class T> using array = std::vector<T>;
template<class T, size_t N> using static_array = std::array<T, N>;
template <class T, class U>
using dictionary = std::unordered_map<T, U>;

template <class T>
[[nodiscard]] constexpr T max() noexcept {
  return std::numeric_limits<T>::max();
}

template <class T>
[[nodiscard]] constexpr T min() noexcept {
  return std::numeric_limits<T>::min();
}

}  // namespace ose