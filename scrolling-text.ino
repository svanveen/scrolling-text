#include <avr/pgmspace.h>

#include "utils.h"
#include "LedMatrix.h"

LedMatrix<12, 10, 11> led;

constexpr char inputString[] = "HELLO WORLD!";
constexpr auto bytes = ledByteRepresentation<inputString>();

void setup() {
    init();
    led.shutdown(false);
    led.setIntensity(1);
}

size_t index = 0;

void loop() {

    for (byte row = 0; row < 8; ++row) {
        led.setRow(row, bytes[(index + row) % bytes.size()]);
    }

    if (++index >= bytes.size()) {
        index = 0;
    }

    delay(200);
}



