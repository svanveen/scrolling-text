#ifndef SCROLLING_TEXT_ARRAY_H
#define SCROLLING_TEXT_ARRAY_H

#include <stdlib.h>

typedef unsigned char byte;

template<typename T, size_t N>
struct array {
    T data[N];

    constexpr const T &operator[](size_t index) const {
        return data[index];
    }

    constexpr size_t size() const {
        return N;
    }
};

#endif // SCROLLING_TEXT_ARRAY_H
