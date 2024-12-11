#pragma once
#include <Arduino.h>

// Structure for individual Unicode characters
struct UnicodeChar {
    uint16_t code;
    const char* description;
};

class ExtendedChars {
public:
    static String extendChars(const String &str);

    // Supported character sets
    static const UnicodeChar ADDITIONAL_CHARS[];
    static const uint8_t ADDITIONAL_CHARS_COUNT;

private:
    ExtendedChars() = delete;
};