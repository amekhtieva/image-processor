#pragma once

#include <string>
#include <memory>

#include "../matrix.h"

class Filter {
public:
    virtual ~Filter(){};
    virtual void FilterImage(Image& image) = 0;
    static std::unique_ptr<Filter> CreateFilter(const std::vector<const std::string>& filter_params);
};
