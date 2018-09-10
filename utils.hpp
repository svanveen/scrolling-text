#ifndef UTILS_HPP
#define UTILS_HPP

#include <stdlib.h>
#include "array.hpp"
#include "char2bytes.hpp"

typedef unsigned char byte;


/// Index sequence deduction
template<size_t ...args>
struct Index {
};

template<size_t M, size_t ...N>
struct T : T<M - 1, M, N...> {
};
template<size_t ...N>
struct T<0, N...> : Index<0, N...> {
};

template<size_t N>
struct S : T<N - 1> {
};

template<>
struct S<0> : Index<> {
};


/// Static concatination of arrays
template<typename T, size_t N1, size_t... I1, size_t N2, size_t... I2>
constexpr array<T, N1 + N2> concatInternal(const array<T, N1> &arr1,
                                           const array<T, N2> &arr2,
                                           const Index<I1...> &,
                                           const Index<I2...> &) {
    return {arr1[I1]..., arr2[I2]...};
}

template<typename T, size_t N1, size_t N2>
constexpr array<T, N1 + N2> concat(const array<T, N1> &arr1, const array<T, N2> &arr2) {
    return concatInternal(arr1, arr2, S<N1>{}, S<N2>{});
}

template<typename T, size_t N1, size_t N2, typename ...Args>
constexpr array<T, N1 + N2 * (1 + sizeof...(Args))> concat(const array<T, N1> &arr1,
                                                           const array<T, N2> &arr2,
                                                           const Args &...args) {
    return concat(concat(arr1, arr2), args...);;
}

template<typename T, size_t M, size_t N, size_t... I>
constexpr array<T, M * N> concatInternal(const array<array<T, N>, M> &arrArr, Index<I...>) {
    return concat(arrArr[I]...);
}

template<typename T, size_t M, size_t N>
constexpr array<T, M * N> concat(const array<array<T, N>, M> &arrArr) {
    return concatInternal(arrArr, S<M>{});
}


/// Resolve led representation for characters
constexpr int length(const char *str) {
    return *str ? 1 + length(str + 1) : 1;
}

template<size_t N, size_t... I>
constexpr array<byte, 5 * N> ledByteRepresentationInternal(const char *c, Index<I...>) {
    return concat(array<array<byte, 5>, N>{resolveLedBytes(c[I])...});
}

template<const char *str>
constexpr array<byte, 5 * length(str)> ledByteRepresentation() {
    return ledByteRepresentationInternal<length(str)>(str, S<length(str)>{});
}

#endif // UTILS_HPP
