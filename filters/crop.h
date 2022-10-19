#pragma once

#include "filter.h"

class Crop : public Filter {
public:
    Crop(size_t width, size_t height);
    Crop(const std::vector<const std::string>& filter_params);
    static void CheckFilterParameters(const std::vector<const std::string>& filter_params);
    void FilterImage(Image& image) override;

    size_t new_width;
    size_t new_height;
};