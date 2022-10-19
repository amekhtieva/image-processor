#pragma once

#include "filter.h"

class BloomEffect : public Filter {
public:
    BloomEffect(double tthreshold);
    BloomEffect(const std::vector<const std::string>& filter_params);
    static void CheckFilterParameters(const std::vector<const std::string>& filter_params);
    void FilterImage(Image& image) override;

    double threshold;
};