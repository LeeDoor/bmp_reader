#include "bmp_drawer.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>

BMPDrawer::BMPDrawer(BMP& bmp) 
    : bmp_{bmp} 
{}
void BMPDrawer::draw_X(Rectangle rect) {
    auto to_flip = select_line(rect.a, rect.b);
    to_flip.merge(select_line({ rect.b.x, rect.a.y }, { rect.a.x, rect.b.y }));
    std::for_each(to_flip.begin(), to_flip.end(), [this](Point point) {
        bmp_.flip_pixel(point);
    });
}

std::set<Point> BMPDrawer::select_line(Point a, Point b) {
    int dx = abs(static_cast<int>(b.x) - static_cast<int>(a.x));
    int dy = abs(static_cast<int>(b.y) - static_cast<int>(a.y));
    int sx = (a.x < b.x) ? 1 : -1;
    int sy = (a.y < b.y) ? 1 : -1;
    int err = dx - dy;
    std::set<Point> result;
    while (true) {
        result.insert({a.x, a.y});
        if (a.x == b.x && a.y == b.y) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            a.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            a.y += sy;
        }
    }
    return result;
}
