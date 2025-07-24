#include "bmp_reader.hpp"
#include <filesystem>

BMPReader::BMPReader(const std::string& filename) {
    if(std::filesystem::path(filename).extension() != ".bmp")
        throw std::runtime_error("provided file must be .bmp");
    if(!std::filesystem::exists(filename) || std::filesystem::is_directory(filename))
        throw std::runtime_error("no such file");
    ifs_.open(filename, std::ios::binary);
    if(!ifs_.is_open())
        throw std::runtime_error("unable to open file " + filename);
}
BMPReader::~BMPReader() {
    ifs_.close();
}

BMP BMPReader::read_from_file() {
    BMPFileHeader file_header = read_file_header();
    BMPInfoHeader info_header = read_info_header();
    ifs_.seekg(file_header.offset);
    BMP bmp{{file_header, info_header}, info_header.width, info_header.height};
    fill_bit_map(bmp);
    return bmp;
}

BMPFileHeader BMPReader::read_file_header() {
    BMPFileHeader file_header;
    ifs_.read(reinterpret_cast<char*>(&file_header), 14);
    if(file_header.type != 0x4D42)
        throw std::runtime_error("given file is corrupted");
    return file_header;
}
BMPInfoHeader BMPReader::read_info_header() {
    BMPInfoHeader info_header;
    ifs_.read(reinterpret_cast<char*>(&info_header), sizeof(info_header));
    return info_header;
}
void BMPReader::fill_bit_map(BMP& bmp) {
    const auto& info_header = bmp.metadata().info_header;
    const size_t pixel_size = info_header.bit_count / 8;
    const size_t line_size = pixel_size * info_header.width;
    const size_t line_size_offset = line_size + (4 - (line_size % 4)) % 4;

    char *line = new char[line_size_offset];
    for(size_t i = 0; i < info_header.height; ++i) {
        ifs_.read(line, line_size_offset);
        for(size_t j = 0; j < info_header.width; ++j) {
            Color color = WHITE;
            color.blue = line[j * pixel_size];
            color.green = line[j * pixel_size + 1];
            color.red = line[j * pixel_size + 2];
            bmp.redraw_pixel({j, info_header.height - i - 1}, color);
        }
    }
    delete[] line;
}
