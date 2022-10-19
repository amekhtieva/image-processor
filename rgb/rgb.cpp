#include "rgb.h"

#include <algorithm>

RGB RGB::operator+(const RGB& other) const {
    return {.red = red + other.red, .green = green + other.green, .blue = blue + other.blue};
}

RGB RGB::operator-(const RGB& other) const {
    return {.red = red - other.red, .green = green - other.green, .blue = blue - other.blue};
}

RGB RGB::operator*(double coefficient) const {
    return {.red = coefficient * red, .green = coefficient * green, .blue = coefficient * blue};
}

RGB operator*(double coefficient, const RGB& rgb) {
    return rgb * coefficient;
}

bool RGB::operator<(const RGB& other) const {
    return red + green + blue < other.red + other.green + other.blue;
}

RGB& RGB::Normalize() {
    red = std::clamp(red, 0.0, 1.0);
    green = std::clamp(green, 0.0, 1.0);
    blue = std::clamp(blue, 0.0, 1.0);
    return *this;
}
