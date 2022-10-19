#include "bloom_effect.h"
#include "gaussian_blur.h"
#include "grayscale.h"

#include <stdexcept>

BloomEffect::BloomEffect(double tthreshold) : threshold(tthreshold) {
}

BloomEffect::BloomEffect(const std::vector<const std::string>& filter_params) {
    CheckFilterParameters(filter_params);
    threshold = std::stod(filter_params.at(1));
}

void BloomEffect::CheckFilterParameters(const std::vector<const std::string>& filter_params) {
    if (filter_params.size() != 2) {
        throw std::runtime_error("Bloom effect filter has one parameter");
    }
    if (std::stod(filter_params[1]) > 1 || std::stod(filter_params[1]) < 0) {
        throw std::runtime_error("Parameter of bloom effect filter must be a number from 0 to 1");
    }
}

void BloomEffect::FilterImage(Image& image) {
    Image grayscale_image = image;
    Grayscale grayscale;
    grayscale.FilterImage(grayscale_image);
    Image new_image(image.Height(), image.Width());
    for (int64_t y = 0; y < image.Height(); ++y) {
        for (int64_t x = 0; x < image.Width(); ++x) {
            if (threshold < grayscale_image(y, x).red) {
                new_image(y, x) = image(y, x);
            }
        }
    }

    GaussianBlur blur(7);
    blur.FilterImage(new_image);

    for (int64_t y = 0; y < image.Height(); ++y) {
        for (int64_t x = 0; x < image.Width(); ++x) {
            image(y, x) = image(y, x) + new_image(y, x);
            image(y, x).Normalize();
        }
    }
}
