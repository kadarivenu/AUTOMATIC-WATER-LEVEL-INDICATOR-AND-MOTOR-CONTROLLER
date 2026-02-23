#include <Wire.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>

/* ---------------- LCD Configuration ---------------- */
LiquidCrystal_I2C lcd(0x27, 16, 2);

/* ---------------- Pin Definitions ---------------- */
#define TRIG_PIN 8
#define ECHO_PIN 9
#define SET_BUTTON 10
#define MODE_BUTTON 11
#define RELAY_PIN 12

/* ---------------- Variables ---------------- */
long duration;
long inches;
int set_val;          // Tank height reference
int percentage;
bool state = 0;
bool pump = 0;

/* ---------------- Setup ---------------- */
void setup()
{
    lcd.init();
    lcd.backlight();

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(SET_BUTTON, INPUT_PULLUP);
    pinMode(MODE_BUTTON, INPUT_PULLUP);
    pinMode(RELAY_PIN, OUTPUT);

    digitalWrite(RELAY_PIN, HIGH);   // Pump OFF (Active LOW Relay)

    lcd.setCursor(0, 0);
    lcd.print("WATER LEVEL:");
    lcd.setCursor(0, 1);
    lcd.print("PUMP:OFF MANUAL");

    /* Read stored tank height from EEPROM */
    set_val = EEPROM.read(0);

    if (set_val > 150 || set_val <= 0)
        set_val = 100;   // Default tank depth

    delay(2000);
}

/* ---------------- Main Loop ---------------- */
void loop()
{
    /* Trigger Ultrasonic Pulse */
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    /* Read Echo */
    duration = pulseIn(ECHO_PIN, HIGH);

    /* Convert to inches */
    inches = microsecondsToInches(duration);

    /* Calculate Water Percentage */
    percentage = (set_val - inches) * 100 / set_val;

    if (percentage < 0) percentage = 0;
    if (percentage > 100) percentage = 100;

    /* Display Percentage */
    lcd.setCursor(12, 0);
    lcd.print("    ");
    lcd.setCursor(12, 0);
    lcd.print(percentage);
    lcd.print("%");

    /* ----------- AUTO MODE ----------- */
    if (digitalRead(MODE_BUTTON))
    {
        lcd.setCursor(9, 1);
        lcd.print("AUTO   ");

        if (percentage < 30)
            pump = 1;

        if (percentage > 99)
            pump = 0;
    }

    /* ----------- MANUAL MODE ----------- */
    else
    {
        lcd.setCursor(9, 1);
        lcd.print("MANUAL");

        if (!digitalRead(SET_BUTTON) && !state)
        {
            state = 1;
            pump = !pump;
        }

        if (digitalRead(SET_BUTTON))
            state = 0;
    }

    /* ----------- Set Tank Height ----------- */
    if (!digitalRead(SET_BUTTON) && digitalRead(MODE_BUTTON))
    {
        set_val = inches;
        EEPROM.update(0, set_val);
        delay(500);
    }

    /* ----------- Relay Control ----------- */
    digitalWrite(RELAY_PIN, pump ? LOW : HIGH);

    lcd.setCursor(5, 1);
    if (pump)
        lcd.print("ON ");
    else
        lcd.print("OFF");

    delay(500);
}

/* ---------------- Distance Conversion ---------------- */
long microsecondsToInches(long microseconds)
{
    return microseconds / 74 / 2;
}
