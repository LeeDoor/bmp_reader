#pragma once
#include <vector>
#include "bmp_metadata.hpp"
#include "color.hpp"
#include "point.hpp"

class BMP {
public:
    using RowType = std::vector<Color>;
    using MatrixType = std::vector<RowType>;

    BMP(BMPMetadata metadata, size_t width, size_t height, Color fill = WHITE);

    size_t height() const;
    size_t width() const;

    const MatrixType& value() const &;
    const BMPMetadata& metadata() const &;

    void redraw_pixel(Point position, Color new_color);
    void flip_pixel(Point position);

private:
    BMPMetadata metadata_;
    MatrixType matrix_;   
};
