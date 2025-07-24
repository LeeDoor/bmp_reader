#include "bmp_drawer.hpp"
#include "bmp_printer.hpp"
#include "bmp_writer.hpp"
#include "bmp_reader.hpp"
#include "cli_input.hpp"
#include <cassert>
#include <iostream>

BMP try_read_bmp() {
    while (true) {
        try {
            std::cout << ">> Enter input BMP file name: ";
            std::string filename = CLIInput::read_string();
            BMPReader reader(filename);
            BMP bmp = reader.read_from_file();
            return bmp;
        } catch (const std::exception& ex) {
            std::cout 
                << "Failed while reading BMP from file: " << ex.what() 
                << "\nPlease try again\n";    
        }
    }
}

void try_write_bmp(const BMP& bmp) {
    while (true) {
        try {
            std::cout << ">> Enter output BMP file name: ";
            std::string filename = CLIInput::read_string();
            BMPWriter writer(filename);
            writer.write_to_file(bmp);
            return;
        } catch (const std::exception& ex) {
            std::cout 
                << "Failed while writing BMP to file: " << ex.what() 
                << "\nPlease select other file name\n";    
        }
    }
}

void try_draw_X(BMP& bmp) {
    Rectangle rect;
    std::cout << "Entering rectangle to draw the X in it.\n";
    rect = CLIInput::read_rectangle_in_area(
        {0, 0}, {bmp.width() - 1, bmp.height() - 1});
    BMPDrawer drawer(bmp);
    drawer.draw_X(rect);
}

int main() {
    try {
        BMP bmp = try_read_bmp();
        BMPPrinter printer(std::cout);
        printer.print_bmp(bmp);
        try_draw_X(bmp);
        printer.print_bmp(bmp);
        try_write_bmp(bmp);
    } catch (const std::exception& ex) {
        std::cout << "Application failed: " << ex.what();
        return 1;
    }
    return 0;
}
