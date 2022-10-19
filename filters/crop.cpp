#include "crop.h"

#include <algorithm>
#include <stdexcept>

Crop::Crop(size_t width, size_t height) : new_width(width), new_height(height) {
}

Crop::Crop(const std::vector<const std::string>& filter_params) {
    CheckFilterParameters(filter_params);
    new_width = std::stoi(filter_params.at(1));
    new_height = std::stoi(filter_params.at(2));
}

void Crop::CheckFilterParameters(const std::vector<const std::string>& filter_params) {
    if (filter_params.size() != 3) {
        throw std::runtime_error("Crop filter has two parameters");
    }
    if (std::stoi(filter_params.at(1)) == 0 || std::stoi(filter_params.at(2)) == 0) {
        throw std::runtime_error("Parameters of crop filter must be positive numbers");
    }
}

void Crop::FilterImage(Image& image) {
    Image new_image(std::min(image.Height(), new_height), std::min(image.Width(), new_width));
    for (int64_t y = 0; y < new_image.Height(); ++y) {
        for (int64_t x = 0; x < new_image.Width(); ++x) {
            new_image(y, x) = image(image.Height() - new_image.Height() + y, x);
        }
    }
    image = new_image;
}
