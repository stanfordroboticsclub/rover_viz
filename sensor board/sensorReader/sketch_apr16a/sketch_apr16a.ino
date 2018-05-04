#include <Wire.h>
#define SLAVE_ADDRESS   0x69

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
}

void loop() {
  delay(100);
}

void requestEvent() {

}

void receiveEvent(int bytesReceived) {
  
}

