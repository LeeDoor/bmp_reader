#include "bmp_writer.hpp"

BMPWriter::BMPWriter(const std::string& filename) {
    ofs_.open(filename, std::ios::binary);
    if(!ofs_.is_open())
        throw std::runtime_error("unable to open file " + filename);
}
void BMPWriter::write_to_file(const BMP& bmp) {
    BMPMetadata metadata = bmp.metadata();
    const auto& matrix = bmp.value();
    const size_t alignment = 4 - (bmp.width() * 3 % 4);
    metadata.file_header.offset = sizeof(metadata);
    ofs_.write(reinterpret_cast<const char*>(&metadata), sizeof(BMPMetadata));
    for(const auto& row : matrix) {
        ofs_.write(reinterpret_cast<const char*>(row.data()), sizeof(Color) * bmp.width());
        ofs_.write("\0\0\0", alignment);
    }
}
