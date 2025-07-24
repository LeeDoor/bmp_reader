#pragma once
#include <compare>
#include <cstddef>

using Dimention = size_t;
struct Point {
    Dimention x;
    Dimention y;
    auto operator<=> (const Point& other) const = default;
};
