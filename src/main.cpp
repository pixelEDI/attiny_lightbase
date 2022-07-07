#include <Arduino.h>

const byte LEDgreen = 1;
const byte LEDblue = 0;
const byte soundModule = 2;

unsigned int clap = 0;
unsigned long detection_range_start = 0;
unsigned long detection_range = 0;

void ledOn(byte LED)
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite(LED, i);
    delay(5);
  }
}

void turnOnLEDs()
{
  ledOn(LEDgreen);
  ledOn(LEDblue);
}

void ledOff(byte LED)
{
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(LED, i);
    delay(5);
  }
}

void turnOffLEDs()
{
  ledOff(LEDgreen);
  ledOff(LEDblue);
}

void detectTwoClapsInTimeWindow(unsigned int timeWindow2ndClap)
{
  int status_sensor = digitalRead(soundModule);
  if (status_sensor == HIGH)
  {
    if (clap == 0)
    {
      clap++;
      detection_range = detection_range_start = millis();
    }
    else if (clap >= 0 && millis() - detection_range >= timeWindow2ndClap)
    {
      clap++;
      detection_range = millis();
    }
  }
}

void setup()
{
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDblue, OUTPUT);
}

void loop()
{
  detectTwoClapsInTimeWindow(300);

  if (millis() - detection_range_start >= 1000)
  {
    if (clap == 2)
    {
      // turn on the leds
      static byte cnt = 0;

      switch (cnt)
      {
      case 0:
        ledOn(LEDgreen);
        cnt++;
        break;
      case 1:
        ledOff(LEDgreen);
        ledOn(LEDblue);
        cnt++;
        break;
      case 2:
        ledOff(LEDblue);
        turnOnLEDs();
        cnt++;
        break;

      default:
        cnt = 0;
      }
    }

    // reset
    clap = 0;
  }
}