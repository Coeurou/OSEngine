#pragma once

#include <fmt/color.h>
#include <fmt/core.h>
#include <types.h>

namespace ose {

enum class log_severity {
  panic,
  alert,
  error,
  warn,
  info,
  debug,
  success,
  failure
};

enum class log_category {
  system,
  render,
  physics,
  anim,
  ai,
  gameplay,
};

enum class text_color : u32 {
  alice_blue = static_cast<u32>(fmt::color::alice_blue),
  antique_white = static_cast<u32>(fmt::color::antique_white),
  aqua = static_cast<u32>(fmt::color::aqua),
  aquamarine = static_cast<u32>(fmt::color::aquamarine),
  azure = static_cast<u32>(fmt::color::azure),
  beige = static_cast<u32>(fmt::color::beige),
  bisque = static_cast<u32>(fmt::color::bisque),
  black = static_cast<u32>(fmt::color::black),
  blanched_almond = static_cast<u32>(fmt::color::blanched_almond),
  blue = static_cast<u32>(fmt::color::blue),
  blue_violet = static_cast<u32>(fmt::color::blue_violet),
  brown = static_cast<u32>(fmt::color::brown),
  burly_wood = static_cast<u32>(fmt::color::burly_wood),
  cadet_blue = static_cast<u32>(fmt::color::cadet_blue),
  chartreuse = static_cast<u32>(fmt::color::chartreuse),
  chocolate = static_cast<u32>(fmt::color::chocolate),
  coral = static_cast<u32>(fmt::color::coral),
  cornflower_blue = static_cast<u32>(fmt::color::cornflower_blue),
  cornsilk = static_cast<u32>(fmt::color::cornsilk),
  crimson = static_cast<u32>(fmt::color::crimson),
  cyan = static_cast<u32>(fmt::color::cyan),
  dark_blue = static_cast<u32>(fmt::color::dark_blue),
  dark_cyan = static_cast<u32>(fmt::color::dark_cyan),
  dark_golden_rod = static_cast<u32>(fmt::color::dark_golden_rod),
  dark_gray = static_cast<u32>(fmt::color::dark_gray),
  dark_green = static_cast<u32>(fmt::color::dark_green),
  dark_khaki = static_cast<u32>(fmt::color::dark_khaki),
  dark_magenta = static_cast<u32>(fmt::color::dark_magenta),
  dark_olive_green = static_cast<u32>(fmt::color::dark_olive_green),
  dark_orange = static_cast<u32>(fmt::color::dark_orange),
  dark_orchid = static_cast<u32>(fmt::color::dark_orchid),
  dark_red = static_cast<u32>(fmt::color::dark_red),
  dark_salmon = static_cast<u32>(fmt::color::dark_salmon),
  dark_sea_green = static_cast<u32>(fmt::color::dark_sea_green),
  dark_slate_blue = static_cast<u32>(fmt::color::dark_slate_blue),
  dark_slate_gray = static_cast<u32>(fmt::color::dark_slate_gray),
  dark_turquoise = static_cast<u32>(fmt::color::dark_turquoise),
  dark_violet = static_cast<u32>(fmt::color::dark_violet),
  deep_pink = static_cast<u32>(fmt::color::deep_pink),
  deep_sky_blue = static_cast<u32>(fmt::color::deep_sky_blue),
  dim_gray = static_cast<u32>(fmt::color::dim_gray),
  dodger_blue = static_cast<u32>(fmt::color::dodger_blue),
  fire_brick = static_cast<u32>(fmt::color::fire_brick),
  floral_white = static_cast<u32>(fmt::color::floral_white),
  forest_green = static_cast<u32>(fmt::color::forest_green),
  fuchsia = static_cast<u32>(fmt::color::fuchsia),
  gainsboro = static_cast<u32>(fmt::color::gainsboro),
  ghost_white = static_cast<u32>(fmt::color::ghost_white),
  gold = static_cast<u32>(fmt::color::gold),
  golden_rod = static_cast<u32>(fmt::color::golden_rod),
  gray = static_cast<u32>(fmt::color::gray),
  green = static_cast<u32>(fmt::color::green),
  green_yellow = static_cast<u32>(fmt::color::green_yellow),
  honey_dew = static_cast<u32>(fmt::color::honey_dew),
  hot_pink = static_cast<u32>(fmt::color::hot_pink),
  indian_red = static_cast<u32>(fmt::color::indian_red),
  indigo = static_cast<u32>(fmt::color::indigo),
  ivory = static_cast<u32>(fmt::color::ivory),
  khaki = static_cast<u32>(fmt::color::khaki),
  lavender = static_cast<u32>(fmt::color::lavender),
  lavender_blush = static_cast<u32>(fmt::color::lavender_blush),
  lawn_green = static_cast<u32>(fmt::color::lawn_green),
  lemon_chiffon = static_cast<u32>(fmt::color::lemon_chiffon),
  light_blue = static_cast<u32>(fmt::color::light_blue),
  light_coral = static_cast<u32>(fmt::color::light_coral),
  light_cyan = static_cast<u32>(fmt::color::light_cyan),
  light_golden_rod_yellow =
      static_cast<u32>(fmt::color::light_golden_rod_yellow),
  light_gray = static_cast<u32>(fmt::color::light_gray),
  light_green = static_cast<u32>(fmt::color::light_green),
  light_pink = static_cast<u32>(fmt::color::light_pink),
  light_salmon = static_cast<u32>(fmt::color::light_salmon),
  light_sea_green = static_cast<u32>(fmt::color::light_sea_green),
  light_sky_blue = static_cast<u32>(fmt::color::light_sky_blue),
  light_slate_gray = static_cast<u32>(fmt::color::light_slate_gray),
  light_steel_blue = static_cast<u32>(fmt::color::light_steel_blue),
  light_yellow = static_cast<u32>(fmt::color::light_yellow),
  lime = static_cast<u32>(fmt::color::lime),
  lime_green = static_cast<u32>(fmt::color::lime_green),
  linen = static_cast<u32>(fmt::color::linen),
  magenta = static_cast<u32>(fmt::color::magenta),
  maroon = static_cast<u32>(fmt::color::maroon),
  medium_aquamarine = static_cast<u32>(fmt::color::medium_aquamarine),
  medium_blue = static_cast<u32>(fmt::color::medium_blue),
  medium_orchid = static_cast<u32>(fmt::color::medium_orchid),
  medium_purple = static_cast<u32>(fmt::color::medium_purple),
  medium_sea_green = static_cast<u32>(fmt::color::medium_sea_green),
  medium_slate_blue = static_cast<u32>(fmt::color::medium_slate_blue),
  medium_spring_green = static_cast<u32>(fmt::color::medium_spring_green),
  medium_turquoise = static_cast<u32>(fmt::color::medium_turquoise),
  medium_violet_red = static_cast<u32>(fmt::color::medium_violet_red),
  midnight_blue = static_cast<u32>(fmt::color::midnight_blue),
  mint_cream = static_cast<u32>(fmt::color::mint_cream),
  misty_rose = static_cast<u32>(fmt::color::misty_rose),
  moccasin = static_cast<u32>(fmt::color::moccasin),
  navajo_white = static_cast<u32>(fmt::color::navajo_white),
  navy = static_cast<u32>(fmt::color::navy),
  old_lace = static_cast<u32>(fmt::color::old_lace),
  olive = static_cast<u32>(fmt::color::olive),
  olive_drab = static_cast<u32>(fmt::color::olive_drab),
  orange = static_cast<u32>(fmt::color::orange),
  orange_red = static_cast<u32>(fmt::color::orange_red),
  orchid = static_cast<u32>(fmt::color::orchid),
  pale_golden_rod = static_cast<u32>(fmt::color::pale_golden_rod),
  pale_green = static_cast<u32>(fmt::color::pale_green),
  pale_turquoise = static_cast<u32>(fmt::color::pale_turquoise),
  pale_violet_red = static_cast<u32>(fmt::color::pale_violet_red),
  papaya_whip = static_cast<u32>(fmt::color::papaya_whip),
  peach_puff = static_cast<u32>(fmt::color::peach_puff),
  peru = static_cast<u32>(fmt::color::peru),
  pink = static_cast<u32>(fmt::color::pink),
  plum = static_cast<u32>(fmt::color::plum),
  powder_blue = static_cast<u32>(fmt::color::powder_blue),
  purple = static_cast<u32>(fmt::color::purple),
  rebecca_purple = static_cast<u32>(fmt::color::rebecca_purple),
  red = static_cast<u32>(fmt::color::red),
  rosy_brown = static_cast<u32>(fmt::color::rosy_brown),
  royal_blue = static_cast<u32>(fmt::color::royal_blue),
  saddle_brown = static_cast<u32>(fmt::color::saddle_brown),
  salmon = static_cast<u32>(fmt::color::salmon),
  sandy_brown = static_cast<u32>(fmt::color::sandy_brown),
  sea_green = static_cast<u32>(fmt::color::sea_green),
  sea_shell = static_cast<u32>(fmt::color::sea_shell),
  sienna = static_cast<u32>(fmt::color::sienna),
  silver = static_cast<u32>(fmt::color::silver),
  sky_blue = static_cast<u32>(fmt::color::sky_blue),
  slate_blue = static_cast<u32>(fmt::color::slate_blue),
  slate_gray = static_cast<u32>(fmt::color::slate_gray),
  snow = static_cast<u32>(fmt::color::snow),
  spring_green = static_cast<u32>(fmt::color::spring_green),
  steel_blue = static_cast<u32>(fmt::color::steel_blue),
  tan = static_cast<u32>(fmt::color::tan),
  teal = static_cast<u32>(fmt::color::teal),
  thistle = static_cast<u32>(fmt::color::thistle),
  tomato = static_cast<u32>(fmt::color::tomato),
  turquoise = static_cast<u32>(fmt::color::turquoise),
  violet = static_cast<u32>(fmt::color::violet),
  wheat = static_cast<u32>(fmt::color::wheat),
  white = static_cast<u32>(fmt::color::white),
  white_smoke = static_cast<u32>(fmt::color::white_smoke),
  yellow = static_cast<u32>(fmt::color::yellow),
  yellow_green = static_cast<u32>(fmt::color::yellow_green)
};  // enum class color

struct syslog {
  string my_date = "";
  log_severity my_severity = log_severity::debug;
  log_category my_category = log_category::system;
  string_view my_msg = "";
};

string to_string(const syslog& log);
string get_formatted_date();

template <typename S, typename... Args>
inline auto format(const S& format_str, Args&&... args) {
  return fmt::format(format_str, std::forward<Args>(args)...);
}

template <typename... Args>
inline void log(FILE* f, log_category category, log_severity severity,
                string_view format_str, Args&&... args) {
  text_color color = text_color::white;
  switch (severity) {
    case log_severity::panic: {
      color = text_color::crimson;
      break;
    }
    case log_severity::alert: {
      color = text_color::indian_red;
      break;
    }
    case log_severity::failure:
    case log_severity::error: {
      color = text_color::red;
      break;
    }
    case log_severity::warn: {
      color = text_color::gold;
      break;
    }
    case log_severity::info: {
      color = text_color::ivory;
      break;
    }
    case log_severity::debug: {
      color = text_color::light_cyan;
      break;
    }
    case log_severity::success: {
      color = text_color::chartreuse;
      break;
    }
    default: {
      break;
    }
  }

  const syslog log{get_formatted_date(), severity, category, format_str};
  fmt::print(f, fmt::fg(static_cast<fmt::color>(color)), to_string(log), std::forward<Args>(args)...);
}

template <typename... Args>
inline void log_panic(log_category category, string_view format_str,
                      Args&&... args) {
  log(stderr, category, log_severity::panic, format_str,
      std::forward<Args>(args)...);
  std::exit(EXIT_FAILURE);
}

template <typename... Args>
inline void log_alert(log_category category, string_view format_str,
                      Args&&... args) {
  log(stderr, category, log_severity::alert, format_str,
      std::forward<Args>(args)...);
  std::exit(EXIT_FAILURE);
}

template <typename... Args>
inline void log_error(log_category category, string_view format_str,
                      Args&&... args) {
  log(stderr, category, log_severity::error, format_str,
      std::forward<Args>(args)...);
}

template <typename... Args>
inline void log_warning(log_category category, string_view format_str,
                        Args&&... args) {
  log(stdout, category, log_severity::warn, format_str,
      std::forward<Args>(args)...);
}

template <typename... Args>
inline void log_info(log_category category, string_view format_str,
                     Args&&... args) {
  log(stdout, category, log_severity::info, format_str,
      std::forward<Args>(args)...);
}

template <typename... Args>
inline void log_debug(log_category category, string_view format_str,
                      Args&&... args) {
  log(stdout, category, log_severity::debug, format_str,
      std::forward<Args>(args)...);
}

template<class Number> string to_string(Number n) {
    static_assert(std::is_arithmetic_v<Number>, "[to_string] template version compatible only with number types");
    return std::to_string(n);
}

}  // namespace ose