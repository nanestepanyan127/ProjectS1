int lightSensor = D8;   // Digital output from light sensor
int buzzer = D7;        // Buzzer control pin

void setup() {
  pinMode(lightSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);   // buzzer off
  Serial.begin(115200);
}

void loop() {
  int sensorValue = digitalRead(lightSensor);

  Serial.println(sensorValue); // 0 = dark, 1 = light

  if (sensorValue == HIGH) {  
    // Light detected
    digitalWrite(buzzer, HIGH);
  } else {
    // No light
    digitalWrite(buzzer, LOW);
  }

  delay(1000);
}