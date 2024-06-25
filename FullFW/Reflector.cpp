#include "Reflector.h"

// This mayhaps needs to be changed.
const unsigned char Reflector::getRefChar(const unsigned char ch) const {
    return 0;
};

Reflector::Reflector() {
    numbers = {
        45, 58, 66, 47, 16, 25, 15, 88, 74, 62, 51, 77, 90, 61, 71, 6,
        4, 80, 19, 18, 94, 75, 53, 86, 28, 5, 76, 89, 24, 55, 92, 34,
        81, 82, 31, 63, 84, 93, 67, 50, 91, 72, 57, 68, 54, 3, 78, 52,
        39, 10, 49, 22, 44, 69, 42, 64, 46, 60, 13, 9, 35, 87, 23, 94,
        85, 7, 50, 79, 41, 73, 2, 40, 32, 33, 83, 36, 64, 87, 13, 61,
        35, 9, 33, 13, 40, 79, 22, 69, 56, 43, 37, 20
    };
}

const unsigned char Reflector::reflect(const unsigned char c) const {

    if (c == 10) return 31;
    if (c == 31) return 10;
    if (c < OFFSET || c > LAST) {
        std::cout << "Bad value: " << c << " TERMINATING" << std::endl;
        std::exit(1);
    }

    return static_cast<unsigned char> (numbers[c - 32] + 32);
}



