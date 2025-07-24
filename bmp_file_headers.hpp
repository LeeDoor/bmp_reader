#pragma once    
#include <cstdint>
#pragma pack(push, 1)
struct BMPFileHeader {
    uint16_t type;
    uint32_t filesize;
    uint16_t reserved[2];
    uint32_t offset;
};
struct BMPInfoHeader {
    uint32_t struct_size;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t size_image;
    uint32_t x_pels_per_meter;
    uint32_t y_pels_per_meter;
    uint32_t clr_used;
    uint32_t clr_important;
};
#pragma pack(pop)
