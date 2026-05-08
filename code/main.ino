#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

void setup() {
  Serial.begin(115200);
  bmp.begin();
}

void loop() {
  Serial.print("Temp: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" °C");

  Serial.print("Pressure: ");
  Serial.print(bmp.readPressure() / 100.0F);
  Serial.println(" hPa");

  delay(2000);
}
