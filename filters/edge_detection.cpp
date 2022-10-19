#include "edge_detection.h"
#include "grayscale.h"

#include <stdexcept>

EdgeDetection::EdgeDetection(double tthreshold) : threshold(tthreshold) {
    matrix = Matrix<double>({{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}});
}

EdgeDetection::EdgeDetection(const std::vector<const std::string>& filter_params) {
    CheckFilterParameters(filter_params);
    threshold = std::stod(filter_params.at(1));
    matrix = Matrix<double>({{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}});
}

void EdgeDetection::CheckFilterParameters(const std::vector<const std::string>& filter_params) {
    if (filter_params.size() != 2) {
        throw std::runtime_error("Edge detection filter has one parameter");
    }
    if (std::stod(filter_params[1]) > 1 || std::stod(filter_params[1]) < 0) {
        throw std::runtime_error("Parameter of edge detection filter must be a number from 0 to 1");
    }
}

void EdgeDetection::FilterImage(Image& image) {
    Grayscale grayscale;
    grayscale.FilterImage(image);

    Process(image);

    for (int64_t y = 0; y < image.Height(); ++y) {
        for (int64_t x = 0; x < image.Width(); ++x) {
            if (image(y, x).red > threshold) {
                image(y, x) = {.red = 1.0, .green = 1.0, .blue = 1.0};
            } else {
                image(y, x) = {.red = 0.0, .green = 0.0, .blue = 0.0};
            }
        }
    }
}
