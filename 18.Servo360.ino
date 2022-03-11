#include <ESP32Servo.h>

Servo myservo;

#define servoPin 33

void setup() {
  pinMode(servoPin, OUTPUT);
	myservo.setPeriodHertz(50); // standard 50 hz servo
	myservo.attach(servoPin, 500, 2500); // using default min/max of 500us and 2400us
}

void loop() {
	for (int pos = 0; pos <= 180; pos += 1) {
		myservo.write(pos);
		delay(15);
	}
	for (int pos = 180; pos >= 0; pos -= 1) {
		myservo.write(pos);
		delay(15);
	}
}
