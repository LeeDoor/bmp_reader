#include "bmp_writer.hpp"

BMPWriter::BMPWriter(const std::string& filename) {
    ofs_.open(filename, std::ios::binary);
    if(!ofs_.is_open())
        throw std::runtime_error("unable to open file " + filename);
}
void BMPWriter::write_to_file(const BMP& bmp) {
    BMPMetadata metadata = bmp.metadata();
    const auto& matrix = bmp.value();
    size_t alignment = 4 - (bmp.width() * 3 % 4);
    alignment = alignment == 4 ? 0 : alignment;
    metadata.file_header.offset = sizeof(metadata);
    metadata.info_header.bit_count = 24;
    ofs_.write(reinterpret_cast<const char*>(&metadata), sizeof(BMPMetadata));
    for(auto it = matrix.rbegin(); it != matrix.rend(); ++it) {
        const auto& row = *it;
        ofs_.write(reinterpret_cast<const char*>(row.data()), sizeof(Color) * bmp.width());
        ofs_.write("\0\0\0", alignment);
    }
}
