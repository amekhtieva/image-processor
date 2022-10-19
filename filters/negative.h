#pragma once

#include "filter.h"

class Negative : public Filter {
public:
    Negative() = default;
    Negative(const std::vector<const std::string>& filter_params);
    static void CheckFilterParameters(const std::vector<const std::string>& filter_params);
    void FilterImage(Image& image) override;
};
