#include "median_filter.h"

#include <stdexcept>

MedianFilter::MedianFilter(int64_t radius) : window_radius(radius) {
}

MedianFilter::MedianFilter(const std::vector<const std::string>& filter_params) {
    CheckFilterParameters(filter_params);
    if (filter_params.size() > 1) {
        window_radius = std::stoi(filter_params.at(1));
    }
}

void MedianFilter::CheckFilterParameters(const std::vector<const std::string>& filter_params) {
    if (filter_params.size() > 2) {
        throw std::runtime_error("Median filter has at most one parameter");
    }
}

void MedianFilter::FilterImage(Image& image) {
    Image new_image(image.Height(), image.Width());
    for (int64_t y = 0; y < image.Height(); ++y) {
        for (int64_t x = 0; x < image.Width(); ++x) {
            std::vector<RGB> pixels;
            for (int64_t i = y - window_radius; i <= y + window_radius; ++i) {
                for (int64_t j = x - window_radius; j <= x + window_radius; ++j) {
                    pixels.push_back(image(i, j));
                }
            }
            std::sort(pixels.begin(), pixels.end());
            new_image(y, x) = pixels[pixels.size() / 2];
        }
    }
    image = new_image;
}
