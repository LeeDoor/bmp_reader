#pragma once

#include <cstdint>
using ColorType = uint8_t;
struct Color {
    ColorType red;
    ColorType green;
    ColorType blue;
    bool operator== (const Color& other) const = default;
};

constexpr Color WHITE = {0xFF, 0xFF, 0xFF};
constexpr Color BLACK = {0x00, 0x00, 0x00};
