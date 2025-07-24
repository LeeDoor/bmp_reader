#pragma once
#include "bmp.hpp"
#include <iostream>

template<typename OS>
class BMPPrinter {
public:
    BMPPrinter(OS& os) : os_(os) {}
        
    void print_bmp(const BMP& bmp) {
        auto matrix = bmp.value();
        for(const auto& row : matrix) {
            print_row(row);
        }
    }

private:
    void print_row(const BMP::RowType& row) {
        for(size_t i = 0; i < row.size(); ++i) {
            print_pixel(row[i]);
            os_ << ' ';
        }
        os_ << std::endl;
    }
    void print_pixel(Color color) {
        if(color == WHITE) {
            os_ << '-';
        } else if (color == BLACK) {
            os_ << '@';
        } else {
            throw std::runtime_error("Can't print pixel that is neither black nor white");
        }
    }

    OS& os_;
};
