#include "filter.h"
#include "crop.h"
#include "grayscale.h"
#include "negative.h"
#include "sharpening.h"
#include "edge_detection.h"
#include "gaussian_blur.h"
#include "bloom_effect.h"
#include "median_filter.h"

#include <stdexcept>

std::unique_ptr<Filter> Filter::CreateFilter(const std::vector<const std::string>& filter_params) {
    std::unique_ptr<Filter> ptr;
    if (filter_params.at(0) == "-crop") {
        ptr = std::make_unique<Crop>(filter_params);
    } else if (filter_params.at(0) == "-gs") {
        ptr = std::make_unique<Grayscale>(filter_params);
    } else if (filter_params.at(0) == "-neg") {
        ptr = std::make_unique<Negative>(filter_params);
    } else if (filter_params.at(0) == "-sharp") {
        ptr = std::make_unique<Sharpening>(filter_params);
    } else if (filter_params.at(0) == "-edge") {
        ptr = std::make_unique<EdgeDetection>(filter_params);
    } else if (filter_params.at(0) == "-blur") {
        ptr = std::make_unique<GaussianBlur>(filter_params);
    } else if (filter_params.at(0) == "-bloom") {
        ptr = std::make_unique<BloomEffect>(filter_params);
    } else if (filter_params.at(0) == "-med") {
        ptr = std::make_unique<MedianFilter>(filter_params);
    } else {
        throw std::runtime_error("Invalid filter");
    }
    return ptr;
}
