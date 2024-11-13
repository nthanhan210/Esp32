#include <Arduino.h>
#include "BluetoothSerial.h"
// #include "NimBLEDevice.h"
BluetoothSerial BT;
// put function declarations here:
12345
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  BT.begin();

  // NimBLEDevice :: init("ESP32");
  // NimBLEServer *server = NimBLEDevice::createService();
  // NimBLEService *service = server->createService("ABCD");
  // NimBLECharacteristic *ch = service->createCharacteristic("1234");
  // service->start();
  // ch->setValue("Hello BLE");

  // NimBLEAdvertising *ads = NimBLEDevice::getAdvertising();
  // ads->addServiceUUID("ABCD");
  // ads->start();

  Serial.println("Bluetooh started! Ready to pair....");
}

void loop() {
  delay(20);
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    BT.write(Serial.read());
  }
  if (BT.available())
  {
    Serial.write(BT.read()+"\n");
  }
}

// put function definitions here:
