#pragma once
#include "bmp.hpp"
#include <string>
#include <fstream>

class BMPWriter {
public:
    BMPWriter(const std::string& filename);
    void write_to_file(const BMP& bmp);

private:
    std::ofstream ofs_;
};
