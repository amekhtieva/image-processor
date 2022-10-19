#include "grayscale.h"

#include <stdexcept>

Grayscale::Grayscale(const std::vector<const std::string>& filter_params) {
    CheckFilterParameters(filter_params);
}

void Grayscale::CheckFilterParameters(const std::vector<const std::string>& filter_params) {
    if (filter_params.size() != 1) {
        throw std::runtime_error("Grayscale filter has no parameters");
    }
}

void Grayscale::FilterImage(Image& image) {
    for (int64_t y = 0; y < image.Height(); ++y) {
        for (int64_t x = 0; x < image.Width(); ++x) {
            image(y, x).red = image(y, x).green = image(y, x).blue =
                0.299 * image(y, x).red + 0.587 * image(y, x).green + 0.114 * image(y, x).blue;
        }
    }
}
