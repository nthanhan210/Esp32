#define PIN_LED 2
#define PIN_BUTTON 0
#define LED_ON() digitalWrite(PIN_LED, LOW)
#define LED_OFF() digitalWrite(PIN_LED, HIGH)

extern void smartConfig_Setup(void);
extern void smartConfig_Proc(void);
extern bool longPress(void);
extern void tick(void);
extern void enter_smartconfig(void);
extern void exit_smart(void);