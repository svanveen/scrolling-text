#ifndef SCROLLING_TEXT_LEDMATRIX_H
#define SCROLLING_TEXT_LEDMATRIX_H

#include "Arduino.h"

template <byte MOSI_PIN, byte CLK_PIN, byte CS_PIN>
struct LedMatrix {

    LedMatrix()
    {
        pinMode(MOSI, OUTPUT);
        pinMode(CLK, OUTPUT);
        pinMode(CS, OUTPUT);

        write(OP_DISPLAYTEST, 0x00);
        write(OP_SCANLIMIT, 0x07);
        //decode is done in source
        write(OP_DECODEMODE, 0x00);
        clearDisplay();
        //we go into shutdown-mode on startup
        shutdown(true);
    }

    void write(byte opcode, byte data)
    {
        digitalWrite(CS, LOW);
        shiftOut(MOSI, CLK, MSBFIRST, opcode);
        shiftOut(MOSI, CLK, MSBFIRST, data);
        digitalWrite(CS, HIGH);
    }

    void setRow(byte row, byte data)
    {
        write(row + 1, data);
    }

    void clearDisplay()
    {
        for (byte i = 0; i < 8; ++i)
        {
            write(i + 1, 0x00);
        }
    }

    void shutdown(bool doShutdown)
    {
        write(OP_SHUTDOWN, !doShutdown);
    }

    void setIntensity(byte intensity)
    {
        if (intensity >= 0 && intensity < 16)
        {
            write(OP_INTENSITY, intensity);
        }
    }

private:
    static constexpr byte MOSI = MOSI_PIN;
    static constexpr byte CLK = CLK_PIN;
    static constexpr byte CS = CS_PIN;

    static constexpr byte OP_DECODEMODE = 9;
    static constexpr byte OP_INTENSITY = 10;
    static constexpr byte OP_SCANLIMIT = 11;
    static constexpr byte OP_SHUTDOWN = 12;
    static constexpr byte OP_DISPLAYTEST = 15;
};

#endif // SCROLLING_TEXT_LEDMATRIX_H
