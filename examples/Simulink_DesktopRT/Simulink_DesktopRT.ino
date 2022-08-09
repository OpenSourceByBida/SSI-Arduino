// Copyright (c) 2022 Pavlo Bida

#include "Arduino.h"
#include "SSIA.h"

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //  reading data from Simulink Desktop RT
  float value = FromSimulinkRT();

  //  writing data to Simulink Desktop RT
  ToSimulinkRT(value / 2);
  
  // turn the LED on if received value is approximately 10
  if(value > 9 && value < 11)
    digitalWrite(LED_BUILTIN, HIGH);
  else
    digitalWrite(LED_BUILTIN, LOW);
}
