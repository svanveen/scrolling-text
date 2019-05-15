#ifndef SCROLLING_TEXT_UTILS_H
#define SCROLLING_TEXT_UTILS_H

#include <stdlib.h>
#include "Array.h"
#include "Byte.h"
#include "char2bytes.h"
#include "IndexSequence.h"

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
