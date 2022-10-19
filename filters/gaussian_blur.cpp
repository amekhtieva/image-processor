#include "gaussian_blur.h"

#include <cmath>
#include <stdexcept>

GaussianBlur::GaussianBlur(double ssigma) : sigma(ssigma) {
}

GaussianBlur::GaussianBlur(const std::vector<const std::string>& filter_params) {
    CheckFilterParameters(filter_params);
    sigma = std::stod(filter_params.at(1));
}

void GaussianBlur::CheckFilterParameters(const std::vector<const std::string>& filter_params) {
    if (filter_params.size() != 2) {
        throw std::runtime_error("Gaussian Blur filter has one parameter");
    }
}

void GaussianBlur::FilterImage(Image& image) {
    std::vector<double> coefficients;
    double summ_coefs = 0;
    for (int64_t r = -3 * sigma; r <= 3 * sigma; ++r) {
        double coef = std::exp(-r * r / (2 * sigma * sigma));
        coefficients.push_back(coef);
        summ_coefs += coef;
    }
    for (double& coef : coefficients) {
        coef /= summ_coefs;
    }
    matrix = Matrix<double>({coefficients});
    Process(image);

    matrix = Matrix<double>(coefficients.size(), 1);
    for (size_t i = 0; i < coefficients.size(); ++i) {
        matrix(i, 0) = coefficients[i];
    }
    Process(image);
}