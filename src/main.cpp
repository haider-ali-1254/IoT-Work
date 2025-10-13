#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

// ---- OLED setup ----
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Wire.begin(21, 22); // ESP32 default I2C pins (SDA=21, SCL=22)

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    for (;;); // Loop forever if OLED not found
  }

  display.clearDisplay();
}

void loop() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 26);
  display.println("Haider (1254)");
  display.drawRect(15, 22, 98, 24, SSD1306_WHITE);

  display.display();
  delay(2000);
}
