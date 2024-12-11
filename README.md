# ExtendedChars

An extension library for Adafruit GFX that supports more characters.

## Description

This library provides functions to handle extended characters like German umlauts for use with the Adafruit GFX library. It includes support for two fonts: Extended_ClassicFont7pt and Extended_FreeSans9pt7b.

## Supported Characters

Currently, the library supports the following German umlauts and special characters:
- Ä (U+00C4)
- Ö (U+00D6)
- Ü (U+00DC)
- ä (U+00E4)
- ö (U+00F6)
- ü (U+00FC)
- ß (U+00DF)

## Installation

### Arduino

1. Download the library as a ZIP file and extract it.
2. Move the extracted folder to your Arduino libraries directory (usually `Documents/Arduino/libraries`).
3. Restart the Arduino IDE.

### PlatformIO

1. Add the following to your `platformio.ini` file:
    ```ini
    lib_deps =
        https://github.com/dpoettler/ExtendedChars.git
    ```

## Usage

### Example

```cpp
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "ExtendedChars.h"
#include "Extended_ClassicFont7pt.h"
#include "Extended_FreeSans9pt7b.h"

Adafruit_SSD1306 display(128, 64, &Wire);

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    
    // Set font
    display.setFont(&Extended_ClassicFont7pt);
    
    // Print text with extended characters
    display.setCursor(0, 20);
    display.print(ExtendedChars::extendChars("Hällo Wörld"));
    
    display.display();
}

void loop() {
    // Nothing to do here
}
```

## Contributing
Update the already supported fonts or create your own with the [Adafruit GFX Font Customizer](https://tchapi.github.io/Adafruit-GFX-Font-Customiser/)

## License
This library is licensed under the GPL v3 License.
