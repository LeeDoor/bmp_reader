#include "bmp_writer.hpp"

BMPWriter::BMPWriter(const std::string& filename) {
    ofs_.open(filename, std::ios::binary);
    if(!ofs_.is_open())
        throw std::runtime_error("unable to open file " + filename);
}
void BMPWriter::write_to_file(const BMP& bmp) {
    const auto& metadata = bmp.metadata();
    const auto& matrix = bmp.value();
    ofs_.write(reinterpret_cast<const char*>(&metadata), sizeof(BMPMetadata));
    for(const auto& row : matrix) {
        ofs_.write(reinterpret_cast<const char*>(&row), sizeof(Color) * bmp.width());
    }
}
