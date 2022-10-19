#include "bmp_header.h"

BitMapFileHeader::BitMapFileHeader(std::ifstream& input) {
    type = ReadByBites<uint16_t>(input);
    size = ReadByBites<uint32_t>(input);
    reserved1 = ReadByBites<uint16_t>(input);
    reserved2 = ReadByBites<uint16_t>(input);
    offsetBits = ReadByBites<uint32_t>(input);
}

BitMapFileHeader::BitMapFileHeader(Image& image) {
    size = 54 + (image.Width() * 3 + image.Width() % 4) * image.Height();
}

BitMapInfoHeader::BitMapInfoHeader(std::ifstream& input) {
    size = ReadByBites<uint32_t>(input);
    width = ReadByBites<uint32_t>(input);
    height = ReadByBites<uint32_t>(input);
    planes = ReadByBites<uint16_t>(input);
    bitCount = ReadByBites<uint16_t>(input);
    compression = ReadByBites<uint32_t>(input);
    sizeImage = ReadByBites<uint32_t>(input);
    xPelsPerMeter = ReadByBites<uint32_t>(input);
    yPelsPerMeter = ReadByBites<uint32_t>(input);
    colorsUsed = ReadByBites<uint32_t>(input);
    colorsImportant = ReadByBites<uint32_t>(input);
}

BitMapInfoHeader::BitMapInfoHeader(Image& image) {
    width = image.Width();
    height = image.Height();
    sizeImage = (image.Width() * 3 + image.Width() % 4) * image.Height();
}
