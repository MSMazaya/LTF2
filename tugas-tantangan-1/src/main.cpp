#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Led.hpp"
#include "TrafficLight.hpp"

#define BAUD 9600
#define DO0 13
#define DO1 12
#define DO2 14
#define BT0 4
#define BT1 16
#define BT2 17

Led green(DO0);
Led yellow(DO1);
Led red(DO2);

TrafficLight traffic_light(&green, &yellow, &red);

void setup()
{
  Serial.begin(BAUD);
  Serial.println("\nBasic DIO");

  pinMode(DO0, OUTPUT);
  pinMode(DO1, OUTPUT);
  pinMode(DO2, OUTPUT);
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);

  Serial.println("bt0 bt1 bt2 d0 d1 d2");
}

void loop()
{
  int digital_input_bt1 = digitalRead(BT1);
  int digital_input_bt2 = digitalRead(BT2);
  Serial.println("BT1");
  Serial.println(digital_input_bt1);
  Serial.println("BT2");
  Serial.println(digital_input_bt2);

  bool button_clicked = (digital_input_bt2 == HIGH) || (digital_input_bt1 == HIGH);
  if (button_clicked)
  {
    traffic_light.change();
  }

  Serial.println(button_clicked);

  traffic_light.actionBasedOnState();
}