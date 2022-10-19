#pragma once

#include "convolution.h"

class EdgeDetection : public Convolution {
public:
    EdgeDetection(double tthreshold);
    EdgeDetection(const std::vector<const std::string>& filter_params);
    static void CheckFilterParameters(const std::vector<const std::string>& filter_params);
    void FilterImage(Image& image) override;

    double threshold;
};