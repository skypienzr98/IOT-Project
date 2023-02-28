#include <DHT.h>

DHT dht(26, DHT11);  // DHT Sensor (Pin, Type)

void setup() {
  dht.begin();
  delay(2000);
  Serial.begin(115200);
  
}

void loop() {
  // Read temperature as Celsius
  float temp = dht.readTemperature();
  // Reading humidity
  float humidity = dht.readHumidity();

  //Display Measurements on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C ");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("% ");
  delay(2000);
}