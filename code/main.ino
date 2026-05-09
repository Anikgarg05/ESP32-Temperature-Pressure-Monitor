#include <Wire.h>
#include <Adafruit_BMP280.h>     // Use Adafruit_BME280.h if using BME280
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_BMP280 bmp;   // I2C

void setup() {
  Serial.begin(115200);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Initialize BMP280
  if (!bmp.begin(0x76)) {   // try 0x77 if not working
    Serial.println("BMP280 not found");
    display.println("Sensor Error!");
    display.display();
    while (1);
  }

  display.println("System Initializing...");
  display.display();
  delay(2000);
}

void loop() {
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0F; // hPa

  // Serial Output
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.println("----------------------");

  // OLED Output
  display.clearDisplay();

  display.setCursor(0, 10);
  display.setTextSize(1);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");

  display.setCursor(0, 30);
  display.print("Pressure:");
  display.setCursor(0, 45);
  display.print(pressure);
  display.println(" hPa");

  display.display();

  delay(2000);
}
