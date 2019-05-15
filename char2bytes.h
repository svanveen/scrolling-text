#ifndef SCROLLING_TEXT_CHAR2BYTES_H
#define SCROLLING_TEXT_CHAR2BYTES_H

#include "array.h"

// @formatter:off
constexpr array<byte, 5> resolveLedBytes(const char c) {
    return (c == 'A')  ? array<byte, 5>{{254,  17,  17, 254,   0}}
         : (c == 'B')  ? array<byte, 5>{{255, 137, 137, 118,   0}}
         : (c == 'C')  ? array<byte, 5>{{126, 129, 129,  66,   0}}
         : (c == 'D')  ? array<byte, 5>{{255, 129, 129, 126,   0}}
         : (c == 'E')  ? array<byte, 5>{{255, 137, 137, 129,   0}}
         : (c == 'F')  ? array<byte, 5>{{255,   9,   9,   1,   0}}
         : (c == 'G')  ? array<byte, 5>{{126, 129, 137, 137, 121}}
         : (c == 'H')  ? array<byte, 5>{{255,  16,  16, 255,   0}}
         : (c == 'I')  ? array<byte, 5>{{  0, 129, 255, 129,   0}}
         : (c == 'J')  ? array<byte, 5>{{ 96, 128, 128, 127,   0}}
         : (c == 'K')  ? array<byte, 5>{{255,  24,  36, 195,   0}}
         : (c == 'L')  ? array<byte, 5>{{255, 128, 128, 128,   0}}
         : (c == 'M')  ? array<byte, 5>{{255,   4,  16,   4, 255}}
         : (c == 'N')  ? array<byte, 5>{{255,   4,  16,  64, 255}}
         : (c == 'O')  ? array<byte, 5>{{126, 129, 129, 126,   0}}
         : (c == 'P')  ? array<byte, 5>{{255,  17,  17,  14,   0}}
         : (c == 'Q')  ? array<byte, 5>{{126, 129, 161, 193, 254}}
         : (c == 'R')  ? array<byte, 5>{{255,  49,  81, 142,   0}}
         : (c == 'S')  ? array<byte, 5>{{142, 145, 145,  97,   0}}
         : (c == 'T')  ? array<byte, 5>{{  1,   1, 255,   1,   1}}
         : (c == 'U')  ? array<byte, 5>{{127, 128, 128, 127,   0}}
         : (c == 'V')  ? array<byte, 5>{{ 63,  64, 128,  64,  63}}
         : (c == 'W')  ? array<byte, 5>{{255,  32,  16,  32, 255}}
         : (c == 'X')  ? array<byte, 5>{{227,  20,   8,  20, 227}}
         : (c == 'Y')  ? array<byte, 5>{{  7,   4, 248,   4,   7}}
         : (c == 'Z')  ? array<byte, 5>{{225, 209, 201, 197, 195}}
         : (c == '0')  ? array<byte, 5>{{126, 133, 145, 193, 126}}
         : (c == '1')  ? array<byte, 5>{{  0,   4,   2, 255,   0}}
         : (c == '2')  ? array<byte, 5>{{194, 161, 145, 142,   0}}
         : (c == '3')  ? array<byte, 5>{{ 66, 137, 153, 102,   0}}
         : (c == '4')  ? array<byte, 5>{{ 56,  36,  34, 255,  32}}
         : (c == '5')  ? array<byte, 5>{{135, 137, 137, 113,   0}}
         : (c == '6')  ? array<byte, 5>{{126, 145, 145, 11,   04}}
         : (c == '7')  ? array<byte, 5>{{  1, 121,   5,   3,   0}}
         : (c == '8')  ? array<byte, 5>{{118, 137, 137, 118,   0}}
         : (c == '9')  ? array<byte, 5>{{ 70, 137, 137, 126,   0}}
         : (c == ' ')  ? array<byte, 5>{{  0,   0,   0,   0,   0}}
         : (c == '.')  ? array<byte, 5>{{  0,   0, 128,   0,   0}}
         : (c == '!')  ? array<byte, 5>{{  0,   0, 191,   0,   0}}
         : (c == '-')  ? array<byte, 5>{{  0,  16,  16,  16,   0}}
         : (c == '\0') ? array<byte, 5>{{  0,   0,   0,   0,   0}}
         : 				 array<byte, 5>{{  0, 255, 129, 255,   0}};
}
// @formatter:on

#endif // SCROLLING_TEXT_CHAR2BYTES_H
