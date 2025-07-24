#pragma once
#include "bmp.hpp"
#include "rectangle.hpp"

class BMPDrawer {
public:
    BMPDrawer(BMP& bmp);

    void draw_X(Rectangle rect);
    void draw_line(Point a, Point b);

private:
    BMP& bmp_;
};
