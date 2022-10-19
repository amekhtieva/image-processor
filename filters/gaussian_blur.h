#pragma once

#include "convolution.h"

class GaussianBlur : public Convolution {
public:
    GaussianBlur(double ssigma);
    GaussianBlur(const std::vector<const std::string>& filter_params);
    static void CheckFilterParameters(const std::vector<const std::string>& filter_params);
    void FilterImage(Image& image) override;

    double sigma;
};
