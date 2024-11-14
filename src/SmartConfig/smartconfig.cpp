#include "smartconfig.h"
#include <Ticker.h>
#include <WiFi.h>

Ticker ticker;

static bool smartConfigFlag = false; // flag trạng thái smart config

void smartConfig_Setup(void)
{
    pinMode(PIN_LED,OUTPUT);
    pinMode(PIN_BUTTON,INPUT);
}

void smartConfig_Proc(void)
{
    if (longPress())
    { // kiểm tra nhấn nút bật Smart Config
        enter_smartconfig();
        Serial.println("Waiting for SmartConfig.");
    }
    // Thoát chế độ Smart Config sau khi kết nối tới Wifi
    if (WiFi.status() == WL_CONNECTED && smartConfigFlag && WiFi.smartConfigDone())
    {
        exit_smart();
        WiFi.hostname("esp32");
        WiFi.setAutoReconnect(true);
        // Serial.printf("Connection status: %d\n", WiFi.status());
        Serial.println("WiFi Connected.");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
        // Blynk.begin(auth,ssid,pass);        // Khởi tạo kết nối tới Blynk bằng token xác thực và thông tin Wifi
    }
    else if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("WiFi Connected.");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    }

}

bool longPress(void)     //kiểm tra nhấn nút 3s
{
  static int lastPress = 0;
  if (millis() - lastPress > 3000 && digitalRead(PIN_BUTTON) == 0) {
    return true;
  } else if (digitalRead(PIN_BUTTON) == 1) {
    lastPress = millis();
  }
  return false;
}

void tick(void) // Hàm chuyển trạng thái LED
{
    // toggle state
    int state = digitalRead(PIN_LED); // get the current state of GPIO1 pin
    digitalWrite(PIN_LED, !state);    // set pin to the opposite state
}

void enter_smartconfig(void) // bật chế độ smart config
{
    if (smartConfigFlag == false)
    {
        smartConfigFlag = true;
        ticker.attach(0.2, tick); // LED chớp nhanh
        WiFi.beginSmartConfig();
    }
}

void exit_smart(void) // thoát chế độ smart config
{
    ticker.detach();
    LED_OFF();
    smartConfigFlag = false;
}


