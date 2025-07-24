#pragma once
#include "bmp.hpp"
#include "bmp_file_headers.hpp"
#include <string>
#include <fstream>

class BMPReader {
public:
    BMPReader(const std::string& filename);
    ~BMPReader();

    BMP read_from_file();

private:
    BMPFileHeader read_file_header();
    BMPInfoHeader read_info_header();
    BMP read_bit_map(BMPInfoHeader info_header);

    std::ifstream ifs_;
};
