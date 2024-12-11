#include "ExtendedChars.h"

// Define the static members
const UnicodeChar ExtendedChars::ADDITIONAL_CHARS[] = {
    {0x00C4, "Ä"},  // Upper Ä umlaut
    {0x00D6, "Ö"},  // Upper Ö umlaut
    {0x00DC, "Ü"},  // Upper Ü umlaut
    {0x00E4, "ä"},  // Lower ä umlaut
    {0x00F6, "ö"},  // Lower ö umlaut
    {0x00FC, "ü"},  // Lower ü umlaut
    {0x00DF, "ß"},  // Sharp ß
};

const uint8_t ExtendedChars::ADDITIONAL_CHARS_COUNT = sizeof(ADDITIONAL_CHARS) / sizeof(ADDITIONAL_CHARS[0]);

namespace {
    bool isInSupportedChars(uint16_t unicode) {
        for (uint8_t i = 0; i < ExtendedChars::ADDITIONAL_CHARS_COUNT; i++) {
            if (unicode == ExtendedChars::ADDITIONAL_CHARS[i].code) {
                return true;
            }
        }
        return false;
    }

    uint16_t extractUnicode(char firstByte, char secondByte) {
        return ((firstByte & 0x1F) << 6) | (secondByte & 0x3F);
    }
}

String ExtendedChars::extendChars(const String &str) {
    String result;
    result.reserve(str.length());

    for (size_t i = 0; i < str.length(); i++) {
        if ((str[i] & 0x80) == 0) {
            result += str[i];
        }
        else if ((str[i] & 0xE0) == 0xC0) {
            uint16_t unicode = extractUnicode(str[i], str[i + 1]);
            if (isInSupportedChars(unicode)) {
                result += (char)unicode;
            }
            i++;
        }
        else if ((str[i] & 0xF0) == 0xE0) {
            result += str.substring(i, i + 3);
            i += 2;
        }
    }
    return result;
}