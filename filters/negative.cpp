#include "negative.h"

#include <stdexcept>

Negative::Negative(const std::vector<const std::string>& filter_params) {
    CheckFilterParameters(filter_params);
}

void Negative::CheckFilterParameters(const std::vector<const std::string>& filter_params) {
    if (filter_params.size() != 1) {
        throw std::runtime_error("Negative filter has no parameters");
    }
}

void Negative::FilterImage(Image& image) {
    for (int64_t y = 0; y < image.Height(); ++y) {
        for (int64_t x = 0; x < image.Width(); ++x) {
            image(y, x) = RGB{.red = 1.0, .green = 1.0, .blue = 1.0} - image(y, x);
        }
    }
}
