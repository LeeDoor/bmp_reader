#pragma once
#include "rectangle.hpp"
#include "point.hpp"
#include <climits>
#include <iostream>

class CLIInput {
public:
    static std::string read_string() {
        std::string string;
        std::cin >> string;
        return string;
    }
    static int read_int(int from, int to) {
        int input;
        while (true) {
            std::cin >> input;
            if(std::cin.good() && from <= input && input <= to)
                return input;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "please try again: ";
        }
        return input;
    }
    static Point read_point_in_area(Point topleft, Point bottomright) {
        if(topleft.x > bottomright.x || topleft.y > bottomright.y)
            throw std::logic_error("illegal area input in read_point_in_area");
        Point point;
        std::cout << "Enter x in [" << topleft.x << "; " << bottomright.x << "]: ";
        point.x = read_int(topleft.x, bottomright.x);
        std::cout << "Enter y in [" << topleft.y << "; " << bottomright.y << "]: ";
        point.y = read_int(topleft.y, bottomright.y);
        return point;
    }
    static Rectangle read_rectangle_in_area(Point topleft, Point bottomright) {
        if(topleft.x > bottomright.x || topleft.y > bottomright.y)
            throw std::logic_error("illegal area input in read_rectangle_in_area");
        Rectangle rectangle;
        std::cout << "Entering top-left corner of area.\n";
        rectangle.a = read_point_in_area(topleft, bottomright);
        std::cout << "Entering bottom-right corner of area.\n";
        rectangle.b = read_point_in_area(topleft, bottomright);
        return rectangle;
    }
};
