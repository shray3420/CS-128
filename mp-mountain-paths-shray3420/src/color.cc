#include "color.hpp"

#include <iostream>

Color::Color(int r, int g, int b): red_(r), green_(g), blue_(b) {
  if (r > kMaxColorValue || r < 0 || g > kMaxColorValue || g < 0 ||
      b > kMaxColorValue || b < 0) {
    throw std::invalid_argument("");
  }
}

// do not modify
bool operator==(const Color& rhs, const Color& lhs) {
  return (rhs.Red() == lhs.Red() && rhs.Green() == lhs.Green() &&
          rhs.Blue() == lhs.Blue());
}