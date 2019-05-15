#ifndef SCROLLING_TEXT_ARRAY_H
#define SCROLLING_TEXT_ARRAY_H

#include <stdlib.h>
#include "IndexSequence.h"

template <typename T, size_t N>
struct Array {
    constexpr const T& operator[](size_t index) const
    {
        return data[index];
    }

    constexpr size_t size() const
    {
        return N;
    }

    T data[N];
};


/// Static concatination of arrays
template <typename T, size_t N1, size_t... I1, size_t N2, size_t... I2>
constexpr Array<T, N1 + N2> concatImpl(const Array<T, N1>& arr1,
                                       const Array<T, N2>& arr2,
                                       const IndexSequence<I1...>&,
                                       const IndexSequence<I2...>&)
{
    return {arr1[I1]..., arr2[I2]...};
}

template <typename T, size_t N>
constexpr Array<T, N> concat(const Array<T, N>& arr)
{
    return arr;
}

template <typename T, size_t N1, size_t N2>
constexpr Array<T, N1 + N2> concat(const Array<T, N1>& arr1, const Array<T, N2>& arr2)
{
    return concatImpl(arr1, arr2, MakeIndexSequence < N1 > {}, MakeIndexSequence < N2 > {});
}

template <typename T, size_t N1, size_t N2, typename ...Args>
constexpr Array<T, N1 + N2 * (1 + sizeof...(Args))> concat(const Array<T, N1>& arr1,
                                                           const Array<T, N2>& arr2,
                                                           const Args& ...args)
{
    return concat(concat(arr1, arr2), args...);;
}

#endif // SCROLLING_TEXT_ARRAY_H
