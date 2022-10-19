#pragma once

#include <fstream>
#include <string_view>

#include "../matrix.h"

template <typename Type>
void WriteByBites(std::ofstream& output, Type number) {
    unsigned char buffer[sizeof(Type)];
    for (size_t i = 0; i < sizeof(Type); ++i) {
        buffer[i] = number % 256;
        number = number >> 8;
    }
    output.write(reinterpret_cast<char*>(buffer), sizeof(buffer));
}

void WriteToBmp(Image& image, std::string_view output_file);
