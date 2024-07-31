#include "NDP.h"


void sendit(char* label) {
  if (strcmp(label, "NN0:illuminate") == 0) {
    Serial.println(label);
    NDP.noInterrupts();
    nicla::leds.begin();
    nicla::leds.setColor(blue);
    digitalWrite(5,HIGH);
    delay(200);
    nicla::leds.end();
    NDP.interrupts();
  }
  if (strcmp(label, "NN0:extinguish") == 0) {
    Serial.println(label);
    NDP.noInterrupts();
    nicla::leds.begin();
    nicla::leds.setColor(red);
    digitalWrite(5,LOW);
    delay(200);
    nicla::leds.end();
    NDP.interrupts();
  }
}

/**
  Blinking green LED when called. 
*/
void ledGreenOn() {
  nicla::leds.begin();
  nicla::leds.setColor(green);
  delay(200);
  nicla::leds.setColor(off);
  nicla::leds.end();
}

/**
  Infinite blinking red LED when a system error occurred. 
*/
void ledRedBlink() {
  while (1) {
    nicla::leds.begin();
    nicla::leds.setColor(red);
    delay(200);
    nicla::leds.setColor(off);
    delay(200);
    nicla::leds.end();
  }
}

/**
  Blinking blue LED when called (for BLE connection). 
*/
void ledBlueBlink() {
  for (int i = 0; i <= 2; i++) {
    nicla::leds.begin();
    nicla::leds.setColor(blue);
    delay(200);
    nicla::leds.setColor(off);
    delay(200);
    nicla::leds.end();
  }
}

/**
  Main section setup
*/
void setup() {
  Serial.begin(115200);
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  delay(200);
  digitalWrite(5, LOW);

  // Nicla System setup
  nicla::begin();
  nicla::disableLDO();
  //nicla::enableCharge(100);  // enabling the battery charger
  nicla::leds.begin();

  // Neural Decision Processor callbacks setup
  NDP.onError(ledRedBlink);
  NDP.onMatch(sendit);
  NDP.onEvent(ledGreenOn);

  Serial.println("Loading synpackages");

  // Neural Decision Processor firmware and ML model files loading
  NDP.begin("mcu_fw_120_v91.synpkg");
  NDP.load("dsp_firmware_v91.synpkg");
  NDP.load("ei_model.synpkg");
  Serial.println("packages loaded");
  NDP.getInfo();
  Serial.println("Configure mic");
  NDP.turnOnMicrophone();

  nicla::leds.end();

  NDP.interrupts();
}

void loop() {

}