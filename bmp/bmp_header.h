#pragma once
#include "../matrix.h"

#include <fstream>

struct BitMapFileHeader {
    BitMapFileHeader(std::ifstream& input);
    BitMapFileHeader(Image& image);

    uint16_t type = 0x4D42;
    uint32_t size;
    uint16_t reserved1 = 0;
    uint16_t reserved2 = 0;
    uint32_t offsetBits = 54;
};

struct BitMapInfoHeader {
    BitMapInfoHeader(std::ifstream& input);
    BitMapInfoHeader(Image& image);

    uint32_t size = 40;
    uint32_t width;
    uint32_t height;
    uint16_t planes = 1;
    uint16_t bitCount = 24;
    uint32_t compression = 0;
    uint32_t sizeImage;
    uint32_t xPelsPerMeter = 11811;
    uint32_t yPelsPerMeter = 11811;
    uint32_t colorsUsed = 0;
    uint32_t colorsImportant = 0;
};

template <typename Type>
Type ReadByBites(std::ifstream& input) {
    unsigned char buffer[sizeof(Type)];
    input.read(reinterpret_cast<char*>(buffer), sizeof(buffer));
    Type result = 0;
    for (size_t i = 0; i < sizeof(Type); ++i) {
        result += static_cast<Type>(buffer[i]) << 8 * i;
    }
    return result;
}