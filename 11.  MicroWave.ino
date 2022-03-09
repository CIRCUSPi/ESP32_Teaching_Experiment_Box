#define MWPin 5

void setup() {
    Serial.begin(9600);
    pinMode(MWPin, INPUT);
}

void loop() {
    int MWRead = digitalRead(MWPin);
    if (MWRead) {
        Serial.println("Watchout!");
    }
    else {
      Serial.println("Safety");
    }
}
