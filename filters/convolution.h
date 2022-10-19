#pragma once

#include "filter.h"

class Convolution : public Filter {
public:
    void Process(Image& image);
    Matrix<double> matrix = Matrix<double>(0, 0);
};
