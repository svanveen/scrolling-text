#ifndef SCROLLING_TEXT_ARRAY_H
#define SCROLLING_TEXT_ARRAY_H

#include <stdlib.h>

template<typename T, size_t N>
struct Array {
    constexpr const T &operator[](size_t index) const {
        return data[index];
    }

    constexpr size_t size() const {
        return N;
    }

    T data[N];
};

#endif // SCROLLING_TEXT_ARRAY_H
