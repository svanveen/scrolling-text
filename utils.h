#ifndef SCROLLING_TEXT_UTILS_H
#define SCROLLING_TEXT_UTILS_H

#include <stdlib.h>
#include "array.h"
#include "char2bytes.h"
#include "IndexSequence.h"

typedef unsigned char byte;

/// Static concatination of arrays
template<typename T, size_t N1, size_t... I1, size_t N2, size_t... I2>
constexpr array<T, N1 + N2> concatInternal(const array<T, N1> &arr1,
                                           const array<T, N2> &arr2,
                                           const IndexSequence<I1...>&,
                                           const IndexSequence<I2...>&)
{
    return {arr1[I1]..., arr2[I2]...};
}

template<typename T, size_t N>
constexpr array<T, N> concat(const array<T, N> &arr) {
    return arr;
}

template<typename T, size_t N1, size_t N2>
constexpr array<T, N1 + N2> concat(const array<T, N1> &arr1, const array<T, N2> &arr2) {
    return concatInternal(arr1, arr2, MakeIndexSequence<N1>{}, MakeIndexSequence<N2>{});
}

template<typename T, size_t N1, size_t N2, typename ...Args>
constexpr array<T, N1 + N2 * (1 + sizeof...(Args))> concat(const array<T, N1> &arr1,
                                                           const array<T, N2> &arr2,
                                                           const Args &...args) {
    return concat(concat(arr1, arr2), args...);;
}


/// Resolve led representation for characters
constexpr int length(const char *str) {
    return *str ? 1 + length(str + 1) : 1;
}

template<size_t N, size_t... I>
constexpr array<byte, 5 * N> ledByteRepresentationInternal(const char* c, IndexSequence<I...>)
{
    return concat(resolveLedBytes(c[I])...);
}

template<const char *str>
constexpr array<byte, 5 * length(str)> ledByteRepresentation() {
    return ledByteRepresentationInternal<length(str)>(str, MakeIndexSequence<length(str)>{});
}

#endif // SCROLLING_TEXT_UTILS_H
