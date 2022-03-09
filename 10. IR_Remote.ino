#include <IRremote.h>

#define IRPin 25

IRrecv irread(IRPin);
decode_results results;

void setup() {
    Serial.begin(9600);
    irread.enableIRIn();
}

void loop() {
    if (irread.decode(&results)) {
        unsigned int readData = results.value;
        Serial.println(readData, HEX);
        irread.resume();
    }
    delay(100);
}
