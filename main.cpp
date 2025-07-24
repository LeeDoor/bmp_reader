#include "bmp_printer.hpp"
#include "bmp_reader.hpp"
#include <cassert>
#include <iostream>

BMP try_read_bmp() {
    while (true) {
        try {
            std::string filename;
            std::cout << ">> Enter input BMP file name: ";
            std::cin >> filename;
            BMPReader reader(filename);
            BMP bmp = reader.read_from_file();
            return bmp;
        } catch (const std::exception& ex) {
            std::cout 
                << "Something went wrong: " << ex.what() 
                << "\nPlease try again\n";    
        }
    }
}

int main() {
    try {
        BMP bmp = try_read_bmp();
        BMPPrinter printer(std::cout);
        printer.print_bmp(bmp);
    } catch (const std::exception& ex) {
        std::cout << "Application failed: " << ex.what();
        return 1;
    }
    return 0;
}
