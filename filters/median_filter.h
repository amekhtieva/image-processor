#pragma once

#include "filter.h"

class MedianFilter : public Filter {
public:
    MedianFilter() = default;
    MedianFilter(int64_t radius);
    MedianFilter(const std::vector<const std::string>& filter_params);
    static void CheckFilterParameters(const std::vector<const std::string>& filter_params);
    void FilterImage(Image& image) override;

    int64_t window_radius = 1;
};