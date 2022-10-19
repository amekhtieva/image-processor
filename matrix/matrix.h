#pragma once

#include <vector>
#include <algorithm>

#include "rgb/rgb.h"

template <typename Type>
class Matrix {
public:
    Matrix(std::vector<std::vector<Type>> vec) : height_(vec.size()), matrix_(vec) {
        if (vec.empty()) {
            width_ = 0;
        } else {
            width_ = vec[0].size();
        }
    }

    Matrix(size_t height, size_t width) : width_(width), height_(height) {
        matrix_ = std::vector<std::vector<Type>>(height, std::vector<Type>(width));
    }

    size_t Width() {
        return width_;
    }

    size_t Height() {
        return height_;
    }

    std::vector<std::vector<Type>> GetData() {
        return matrix_;
    }

    Type& operator()(int64_t y, int64_t x) {
        x = std::clamp<int64_t>(x, 0, width_ - 1);
        y = std::clamp<int64_t>(y, 0, height_ - 1);
        return matrix_[y][x];
    }

    Type operator()(int64_t y, int64_t x) const {
        x = std::clamp<int64_t>(x, 0, width_ - 1);
        y = std::clamp<int64_t>(y, 0, height_ - 1);
        return matrix_[y][x];
    }

private:
    size_t width_;
    size_t height_;
    std::vector<std::vector<Type>> matrix_;
};

using Image = Matrix<RGB>;