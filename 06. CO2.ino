/*
 * 需額外連接ESP32腳位上的5V電源
 */
byte cmd[9] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
byte recv[9];

int j = 0, ppm;

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  j = 0;
}

void loop() {
  for (int i=0; i<9; i++) {
    Serial2.write(cmd[i]);
  }
  while(Serial2.available() == 0);
  while(Serial2.available() > 0) {
    recv[j] = Serial2.read();
    j++;
  }
  if (j!=0 && CRC() == true) {
    ppm = 256*recv[2] + recv[3];
    j = 0;
    Serial.print("CO2: ");
    Serial.print(ppm);
    Serial.println("ppm");
  }
  delay(10000);
}

bool CRC() {
  byte checksum = 0;
  for (int i=1; i<8; i++) {
    checksum += recv[i];
  }
  if (checksum == 0) {
    return false;
  }
  else if ((0xFF-checksum+1) == recv[8]) {
    return true;
  }
  else {
    return false;
  }
}
