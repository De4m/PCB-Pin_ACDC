/*
 * TYPE: Firmware
 * NAME: Pin_ACDC
 * DESCRIPTION: Firmware for test Pin_ACDC. After is ON power or wakeup pin when press button 
 *              LED is light in next mode:
 *                  1. Sequential ON every LED. Delay 0.5sec before change mode
 *                  2. Flash all LED 3 times with delay 0.25 sec. Delay 0.5sec before change mode
 *                  3. Sequential smooth ON every LED in 0.25sec. Delay 0.5sec before change mode
 *                  4. .....
 *              After 30 min the Pin_ACDC goes into SleepMode. With minimal consumption power.
 *              BUTTON logic:
 *                  - if Pin_ACDC is in SleepMode, then WakeUp and start work.
 *                  - if Pin_ACDC is in WorkMode, then change LED mode.          
 * REVISION_PCB: rev:0.1
 * VERSION 0.1 (Jan, 2021)
 * Copyright 2021 De4m@yandex.ru
 */


#include <Arduino.h>
#include <avr/io.h>


#define LED_1 PB4
#define LED_2 PB3
#define LED_3 PB5

#define BUTTON_1 PB0
#define MAX_LEDMODE 2 

volatile int LedMode = 0;
volatile int buttonState = LOW;   


void setup()
{
  // init LED digital pin as an output.
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  
  // init Button
  pinMode(BUTTON_1, INPUT_PULLUP);   
  
}

void Change_LedMode()
{
  LedMode++;
  if (LedMode > MAX_LEDMODE){LedMode=0;}
}

void loop()
{
  switch (LedMode)
  {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break; 
    default:
      Change_LedMode();
      break;

  }
  Change_LedMode();
}


