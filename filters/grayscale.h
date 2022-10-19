#pragma once

#include "filter.h"

class Grayscale : public Filter {
public:
    Grayscale() = default;
    Grayscale(const std::vector<const std::string>& filter_params);
    static void CheckFilterParameters(const std::vector<const std::string>& filter_params);
    void FilterImage(Image& image) override;
};