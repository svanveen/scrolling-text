#ifndef SCROLLING_TEXT_UTILS_H
#define SCROLLING_TEXT_UTILS_H

#include "Array.h"
#include "Byte.h"
#include "IndexSequence.h"

constexpr size_t SYMBOL_WIDTH = 5;

// @formatter:off
constexpr Array<byte, SYMBOL_WIDTH> resolveLedBytes(const char c) {
    return (c == 'A')  ? Array<byte, SYMBOL_WIDTH>{{254,  17,  17, 254,   0}}
         : (c == 'B')  ? Array<byte, SYMBOL_WIDTH>{{255, 137, 137, 118,   0}}
         : (c == 'C')  ? Array<byte, SYMBOL_WIDTH>{{126, 129, 129,  66,   0}}
         : (c == 'D')  ? Array<byte, SYMBOL_WIDTH>{{255, 129, 129, 126,   0}}
         : (c == 'E')  ? Array<byte, SYMBOL_WIDTH>{{255, 137, 137, 129,   0}}
         : (c == 'F')  ? Array<byte, SYMBOL_WIDTH>{{255,   9,   9,   1,   0}}
         : (c == 'G')  ? Array<byte, SYMBOL_WIDTH>{{126, 129, 137, 137, 121}}
         : (c == 'H')  ? Array<byte, SYMBOL_WIDTH>{{255,  16,  16, 255,   0}}
         : (c == 'I')  ? Array<byte, SYMBOL_WIDTH>{{  0, 129, 255, 129,   0}}
         : (c == 'J')  ? Array<byte, SYMBOL_WIDTH>{{ 96, 128, 128, 127,   0}}
         : (c == 'K')  ? Array<byte, SYMBOL_WIDTH>{{255,  24,  36, 195,   0}}
         : (c == 'L')  ? Array<byte, SYMBOL_WIDTH>{{255, 128, 128, 128,   0}}
         : (c == 'M')  ? Array<byte, SYMBOL_WIDTH>{{255,   4,  16,   4, 255}}
         : (c == 'N')  ? Array<byte, SYMBOL_WIDTH>{{255,   4,  16,  64, 255}}
         : (c == 'O')  ? Array<byte, SYMBOL_WIDTH>{{126, 129, 129, 126,   0}}
         : (c == 'P')  ? Array<byte, SYMBOL_WIDTH>{{255,  17,  17,  14,   0}}
         : (c == 'Q')  ? Array<byte, SYMBOL_WIDTH>{{126, 129, 161, 193, 254}}
         : (c == 'R')  ? Array<byte, SYMBOL_WIDTH>{{255,  49,  81, 142,   0}}
         : (c == 'S')  ? Array<byte, SYMBOL_WIDTH>{{142, 145, 145,  97,   0}}
         : (c == 'T')  ? Array<byte, SYMBOL_WIDTH>{{  1,   1, 255,   1,   1}}
         : (c == 'U')  ? Array<byte, SYMBOL_WIDTH>{{127, 128, 128, 127,   0}}
         : (c == 'V')  ? Array<byte, SYMBOL_WIDTH>{{ 63,  64, 128,  64,  63}}
         : (c == 'W')  ? Array<byte, SYMBOL_WIDTH>{{255,  32,  16,  32, 255}}
         : (c == 'X')  ? Array<byte, SYMBOL_WIDTH>{{227,  20,   8,  20, 227}}
         : (c == 'Y')  ? Array<byte, SYMBOL_WIDTH>{{  7,   4, 248,   4,   7}}
         : (c == 'Z')  ? Array<byte, SYMBOL_WIDTH>{{225, 209, 201, 197, 195}}
         : (c == '0')  ? Array<byte, SYMBOL_WIDTH>{{126, 133, 145, 193, 126}}
         : (c == '1')  ? Array<byte, SYMBOL_WIDTH>{{  0,   4,   2, 255,   0}}
         : (c == '2')  ? Array<byte, SYMBOL_WIDTH>{{194, 161, 145, 142,   0}}
         : (c == '3')  ? Array<byte, SYMBOL_WIDTH>{{ 66, 137, 153, 102,   0}}
         : (c == '4')  ? Array<byte, SYMBOL_WIDTH>{{ 56,  36,  34, 255,  32}}
         : (c == '5')  ? Array<byte, SYMBOL_WIDTH>{{135, 137, 137, 113,   0}}
         : (c == '6')  ? Array<byte, SYMBOL_WIDTH>{{126, 145, 145, 11,   04}}
         : (c == '7')  ? Array<byte, SYMBOL_WIDTH>{{  1, 121,   5,   3,   0}}
         : (c == '8')  ? Array<byte, SYMBOL_WIDTH>{{118, 137, 137, 118,   0}}
         : (c == '9')  ? Array<byte, SYMBOL_WIDTH>{{ 70, 137, 137, 126,   0}}
         : (c == ' ')  ? Array<byte, SYMBOL_WIDTH>{{  0,   0,   0,   0,   0}}
         : (c == '.')  ? Array<byte, SYMBOL_WIDTH>{{  0,   0, 128,   0,   0}}
         : (c == '!')  ? Array<byte, SYMBOL_WIDTH>{{  0,   0, 191,   0,   0}}
         : (c == '-')  ? Array<byte, SYMBOL_WIDTH>{{  0,  16,  16,  16,   0}}
         : (c == '\0') ? Array<byte, SYMBOL_WIDTH>{{  0,   0,   0,   0,   0}}
         : 				 Array<byte, SYMBOL_WIDTH>{{  0, 255, 129, 255,   0}};
}
// @formatter:on

constexpr int length(const char* str)
{
    return *str ? 1 + length(str + 1) : 1;
}

template <size_t N, size_t... I>
constexpr Array<byte, SYMBOL_WIDTH * N> ledByteRepresentationImpl(const char* c, IndexSequence<I...>)
{
    return concat(resolveLedBytes(c[I])...);
}

template <const char* str>
constexpr Array<byte, SYMBOL_WIDTH * length(str)> ledByteRepresentation()
{
    return ledByteRepresentationImpl<length(str)>(str, MakeIndexSequence<length(str)>{});
}

#endif // SCROLLING_TEXT_UTILS_H
