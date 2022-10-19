#include "read_from_bmp.h"
#include "bmp_header.h"

#include <stdexcept>

Image ReadFromBmp(std::string_view input_file) {
    std::ifstream input{static_cast<std::string>(input_file), std::ios::binary};
    input.seekg(0, input.end);
    int file_size = input.tellg();
    input.seekg(0, input.beg);

    BitMapFileHeader bmfh(input);
    BitMapInfoHeader bmih(input);

    if (bmfh.type != 0x4D42 || bmfh.size != file_size || bmfh.offsetBits != 54 || bmih.size != 40 ||
        bmih.bitCount != 24 || bmih.compression != 0) {
        throw std::runtime_error("Invalid input file type");
    }

    Image image(bmih.height, bmih.width);
    for (size_t y = 0; y < image.Height(); ++y) {
        for (size_t x = 0; x < image.Width(); ++x) {
            unsigned char blue;
            unsigned char green;
            unsigned char red;
            input.read(reinterpret_cast<char*>(&blue), sizeof(blue));
            input.read(reinterpret_cast<char*>(&green), sizeof(green));
            input.read(reinterpret_cast<char*>(&red), sizeof(red));
            image(y, x) = {.red = static_cast<double>(red) / 255,
                           .green = static_cast<double>(green) / 255,
                           .blue = static_cast<double>(blue) / 255};
        }
        input.ignore(image.Width() % 4);
    }

    return image;
}
