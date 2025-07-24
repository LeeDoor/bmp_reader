#pragma once
#include "bmp.hpp"
#include "rectangle.hpp"
#include <set>

class BMPDrawer {
public:
    BMPDrawer(BMP& bmp);
    void draw_X(Rectangle rect);

private:
    std::set<Point> select_line(Point a, Point b);

    BMP& bmp_;
};
