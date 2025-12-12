#include <Wire.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

// Optional: define I2C pins for D1 mini
#define I2C_SDA D4  // GPIO4
#define I2C_SCL D3  // GPIO5

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println(F("AHTxx + ESP8266 D1 mini test"));

  // Initialize I2C on custom pins for ESP8266
  Wire.begin(I2C_SDA, I2C_SCL);

  // Initialize the AHT sensor
  if (!aht.begin()) {
    Serial.println(F("Could not find AHT sensor, check wiring!"));
    while (1) {
      delay(1000);
    }
  }

  Serial.println(F("AHT sensor found and initialized."));
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);  // get new sensor events

  Serial.print(F("Temperature: "));
  Serial.print(temp.temperature);
  Serial.println(F(" °C"));

  Serial.print(F("Humidity:    "));
  Serial.print(humidity.relative_humidity);
  Serial.println(F(" %"));

  Serial.println(F("-----------------------------"));
  delay(2000);  // read every 2 seconds
}