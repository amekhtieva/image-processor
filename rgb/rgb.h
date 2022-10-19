#pragma once

struct RGB {
    RGB operator+(const RGB& other) const;
    RGB operator-(const RGB& other) const;
    RGB operator*(double coefficient) const;
    bool operator<(const RGB& other) const;
    RGB& Normalize();

    double red;
    double green;
    double blue;
};

RGB operator*(double coefficient, const RGB& rgb);