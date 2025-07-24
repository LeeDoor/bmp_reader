#include "bmp_printer.hpp"
#include "bmp_reader.hpp"
#include <cassert>
#include <iostream>

int main() {
    BMPReader reader("/home/leedoor/Desktop/plus.bmp");
    auto a = reader.read_from_file();
    BMPPrinter printer(std::cout);
    printer.print_bmp(a);
}
