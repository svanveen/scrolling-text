# Scrolling Text

**Scrolling Text** is a small Arduino application to show a scrolling text on an *8x8 LED matrix* module.
The real blowoff in this is that the byte sequence representing each character is computed at compile time. 
Hence there is no runtime overhead to compute the led configuration at each step.