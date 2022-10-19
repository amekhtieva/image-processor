#pragma once

#include "convolution.h"

class Sharpening : public Convolution {
public:
    Sharpening();
    Sharpening(const std::vector<const std::string>& filter_params);
    static void CheckFilterParameters(const std::vector<const std::string>& filter_params);
    void FilterImage(Image& image) override;
};