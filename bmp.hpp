#pragma once
#include <vector>
#include "color.hpp"
#include "point.hpp"

class BMP {
public:
    using RowType = std::vector<Color>;
    using MatrixType = std::vector<RowType>;

    BMP(size_t width, size_t height, Color fill = WHITE);

    size_t height() const;
    size_t width() const;

    const MatrixType value() const;
    void redraw_pixel(Point position, Color new_color);
    void flip_pixel(Point position);

private:
    MatrixType matrix_;   
};
