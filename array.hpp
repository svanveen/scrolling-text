#ifndef ARRAY_HPP
#define ARRAY_HPP

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

#endif // ARRAY_HPP
