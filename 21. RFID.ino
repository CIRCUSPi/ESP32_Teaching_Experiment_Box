#include <Wire.h>
#include "MFRC522_I2C.h"

MFRC522 mfrc522(0x28);

String readRFID() {
  String mfrc522ReadCode = "";
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {}
  else {
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      mfrc522ReadCode += String(mfrc522.uid.uidByte[i], HEX);
    }
  }
  return mfrc522ReadCode;
}

String readCode = "";

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mfrc522.PCD_Init();
}


void loop() {
  readCode = readRFID();
  if (readCode != "") {
    Serial.println(readCode);
  }
}
