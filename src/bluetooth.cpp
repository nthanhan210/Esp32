#include "BluetoothSerial.h"
#include "main.h"
// #include "NimBLEDevice.h"
BluetoothSerial BT;
bool blueToothFlag = false;
void bluetooth_Setup(void)
{
    blueToothFlag = true;
    BT.begin();
    Serial.println("Bluetooh started! Ready to pair....");
    ticker.attach(0.5, tick);
    // NimBLEDevice :: init("ESP32");
    // NimBLEServer *server = NimBLEDevice::createService();
    // NimBLEService *service = server->createService("ABCD");
    // NimBLECharacteristic *ch = service->createCharacteristic("1234");
    // service->start();
    // ch->setValue("Hello BLE");

    // NimBLEAdvertising *ads = NimBLEDevice::getAdvertising();
    // ads->addServiceUUID("ABCD");
    // ads->start();
}
char buffer[64];
void bluetooth_Proc(void)
{
    if (longPress()==1 && !smartConfigFlag)
    {
        blueToothFlag = false;
        smartConfig_Setup();
        BT.end();
    }
    static uint index = 0;
    if (Serial.available())
    {
        BT.write(Serial.read());
    }
    if (BT.available())
    {
        buffer[index] = BT.read();
        if (buffer[index] == 'z')
        {
            int i;
            for (i = 0; i < index; i++)
            {
                Serial.println(buffer);
            }

            index = 0;
        }
    }
}