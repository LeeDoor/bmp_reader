#include "bmp.hpp"
#include <stdexcept>

BMP::BMP(size_t width, size_t height, Color fill) {
    if(width == 0 || height == 0) 
        throw std::runtime_error("bitmap can't be with zero width or height");
    matrix_ = {height, RowType{width, fill}};
}

size_t BMP::height() const { return matrix_.size(); }
size_t BMP::width() const { return matrix_[0].size(); }

const BMP::MatrixType BMP::value() const {
    return matrix_;
}
void BMP::redraw_pixel(Point position, Color new_color) {
    if (height() <= position.x || width() <= position.y)
        throw std::runtime_error("attempt to redraw outbound pixel");
    matrix_[position.x][position.y] = new_color;
}

void BMP::flip_pixel(Point position) {
    if (height() <= position.x || width() <= position.y)
        throw std::runtime_error("attempt to redraw outbound pixel");
    if(matrix_[position.x][position.y] == WHITE) redraw_pixel(position, BLACK);
    else redraw_pixel(position, WHITE);
}
