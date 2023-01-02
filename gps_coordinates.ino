#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define BAUD 9600
#define ARDUINO_GPS_TX 3  // GPS TX, Arduino RX pin
#define ARDUINO_GPS_RX 2  // GPS RX, Arduino TX pin

TinyGPSPlus gps;

SoftwareSerial SoftSerial(ARDUINO_GPS_RX, ARDUINO_GPS_TX);

void setup() {
  Serial.begin(BAUD);
  SoftSerial.begin(BAUD);
  delay(3000);
  Serial.println("GPS is ready");
}

void loop() {
  if (SoftSerial.available()) {
    while (SoftSerial.available()) {
      Serial.print(gps.location.lat(), 10);
      Serial.print(", ");
      Serial.println(gps.location.lng(), 10);
    }
  }
  if (Serial.available()) {
    SoftSerial.write(Serial.read());
  }
}
