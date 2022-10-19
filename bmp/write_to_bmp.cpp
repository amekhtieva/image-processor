#include "write_to_bmp.h"
#include "bmp_header.h"

#include <vector>

void WriteToBmp(Image& image, std::string_view output_file) {
    BitMapFileHeader bmfh(image);
    BitMapInfoHeader bmih(image);
    std::ofstream output{static_cast<std::string>(output_file), std::ios::binary};

    WriteByBites(output, bmfh.type);
    WriteByBites(output, bmfh.size);
    WriteByBites(output, bmfh.reserved1);
    WriteByBites(output, bmfh.reserved2);
    WriteByBites(output, bmfh.offsetBits);

    WriteByBites(output, bmih.size);
    WriteByBites(output, bmih.width);
    WriteByBites(output, bmih.height);
    WriteByBites(output, bmih.planes);
    WriteByBites(output, bmih.bitCount);
    WriteByBites(output, bmih.compression);
    WriteByBites(output, bmih.sizeImage);
    WriteByBites(output, bmih.xPelsPerMeter);
    WriteByBites(output, bmih.yPelsPerMeter);
    WriteByBites(output, bmih.colorsUsed);
    WriteByBites(output, bmih.colorsImportant);

    for (std::vector<RGB>& line : image.GetData()) {
        for (RGB& pixel : line) {
            unsigned char blue = std::max(std::min(pixel.blue * 255, 255.0), 0.0);
            unsigned char green = std::max(std::min(pixel.green * 255, 255.0), 0.0);
            unsigned char red = std::max(std::min(pixel.red * 255, 255.0), 0.0);
            output.write(reinterpret_cast<char*>(&blue), sizeof(blue));
            output.write(reinterpret_cast<char*>(&green), sizeof(green));
            output.write(reinterpret_cast<char*>(&red), sizeof(red));
        }
        char dummy[3] = {0, 0, 0};
        output.write(dummy, bmih.width % 4);
    }
}
