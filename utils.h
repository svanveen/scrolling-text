#ifndef SCROLLING_TEXT_UTILS_H
#define SCROLLING_TEXT_UTILS_H

#include <stdlib.h>
#include "Array.h"
#include "Byte.h"
#include "char2bytes.h"
#include "IndexSequence.h"

/// Static concatination of arrays
template<typename T, size_t N1, size_t... I1, size_t N2, size_t... I2>
constexpr Array<T, N1 + N2> concatInternal(const Array<T, N1>& arr1,
                                           const Array<T, N2>& arr2,
                                           const IndexSequence<I1...>&,
                                           const IndexSequence<I2...>&)
{
    return {arr1[I1]..., arr2[I2]...};
}

template<typename T, size_t N>
constexpr Array<T, N> concat(const Array<T, N>& arr)
{
    return arr;
}

template<typename T, size_t N1, size_t N2>
constexpr Array<T, N1 + N2> concat(const Array<T, N1>& arr1, const Array<T, N2>& arr2)
{
    return concatInternal(arr1, arr2, MakeIndexSequence<N1>{}, MakeIndexSequence<N2>{});
}

template<typename T, size_t N1, size_t N2, typename ...Args>
constexpr Array<T, N1 + N2 * (1 + sizeof...(Args))> concat(const Array<T, N1>& arr1,
                                                           const Array<T, N2>& arr2,
                                                           const Args &...args) {
    return concat(concat(arr1, arr2), args...);;
}


/// Resolve led representation for characters
constexpr int length(const char *str) {
    return *str ? 1 + length(str + 1) : 1;
}

template<size_t N, size_t... I>
constexpr Array<byte, 5 * N> ledByteRepresentationInternal(const char* c, IndexSequence<I...>)
{
    return concat(resolveLedBytes(c[I])...);
}

template<const char *str>
constexpr Array<byte, 5 * length(str)> ledByteRepresentation()
{
    return ledByteRepresentationInternal<length(str)>(str, MakeIndexSequence<length(str)>{});
}

#endif // SCROLLING_TEXT_UTILS_H
