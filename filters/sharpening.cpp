#include "sharpening.h"

#include <stdexcept>

Sharpening::Sharpening() {
    matrix = Matrix<double>({{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}});
}

Sharpening::Sharpening(const std::vector<const std::string>& filter_params) {
    CheckFilterParameters(filter_params);
    matrix = Matrix<double>({{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}});
}

void Sharpening::CheckFilterParameters(const std::vector<const std::string>& filter_params) {
    if (filter_params.size() != 1) {
        throw std::runtime_error("Sharpening filter has no parameters");
    }
}

void Sharpening::FilterImage(Image& image) {
    Process(image);
}
