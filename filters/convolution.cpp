#include "convolution.h"

void Convolution::Process(Image& image) {
    Image new_image(image.Height(), image.Width());
    for (int64_t y0 = 0; y0 < image.Height(); ++y0) {
        for (int64_t x0 = 0; x0 < image.Width(); ++x0) {
            RGB new_pixel{.red = 0.0, .green = 0.0, .blue = 0.0};
            for (int64_t y = 0; y < matrix.Height(); ++y) {
                for (int64_t x = 0; x < matrix.Width(); ++x) {
                    new_pixel =
                        new_pixel + matrix(y, x) * image(y0 - matrix.Height() / 2 + y, x0 - matrix.Width() / 2 + x);
                }
            }
            new_pixel.Normalize();
            new_image(y0, x0) = new_pixel;
        }
    }
    image = new_image;
}
