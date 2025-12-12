#include <DHT.h>

#define DHTPIN 4        // GPIO pin connected to DATA
#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("DHT22 Sensor Reading...");
}

void loop() {
  float humidity = dht.readHumidity();     
  float temperature = dht.readTemperature(); 

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %  \t");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(2000);  
}
