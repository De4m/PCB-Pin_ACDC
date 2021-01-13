/*
 * Pin_ACDC - Firmware for pin ACDC.
 * Version 0.1 Jan,21
 * Copyright 2021 De4m@yandex.ru
 * 
 */

#include <Arduino.h>

int LED_1 = 3;
int LED_2 = 4;
int LED_3 = 5;
int BUTTON = 0;


void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);  
  pinMode(LED_3, OUTPUT); 
  pinMode(BUTTON, INPUT);   
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW); 
  digitalWrite(LED_3, HIGH);  
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, HIGH); 
  digitalWrite(LED_3, LOW);   
   // wait for a second
  delay(1000);
}
