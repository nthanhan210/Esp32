#include "main.h"
#include <Arduino.h>


void setup() {
  Serial.begin(115200);
  // bluetooth_Setup();
  smartConfig_Setup();
}

void loop() {
  smartConfig_Proc();
}

// put function definitions here:
