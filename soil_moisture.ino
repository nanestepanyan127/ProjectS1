int soil_pin = A0;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  // Read the analog value from the sensor
  int sensorValue = analogRead(soil_pin);
  
  // Print the raw value to the serial monitor
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  delay(1000); 
}