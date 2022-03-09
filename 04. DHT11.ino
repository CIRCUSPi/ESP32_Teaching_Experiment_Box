#include "DHTesp.h"

DHTesp dht;
const byte DHTPin = 17;

void setup() {
  Serial.begin(9600);
  dht.setup(DHTPin, DHTesp::DHT11);
}

void loop() {
  TempAndHumidity getValues = dht.getTempAndHumidity();
  Serial.print("Temperature: ");
  Serial.print(getValues.temperature, 1);
  Serial.print("°C, Humidity: ");
  Serial.print(getValues.humidity, 1);
  Serial.println("%RH");
  delay(2000);
}
