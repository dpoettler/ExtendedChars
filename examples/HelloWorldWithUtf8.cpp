#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ExtendedChars.h>
#include <Fonts/Extended_ClassicFont7pt.h>
#include <Fonts/Extended_FreeSans9pt7b.h>

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