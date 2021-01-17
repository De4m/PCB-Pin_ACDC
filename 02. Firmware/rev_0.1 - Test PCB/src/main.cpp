/*
 * TYPE: Firmware
 * NAME: Test PCB (for Pin_ACDC) - 
 * DESCRIPTION: Firmware for test PCB. Check LED diode and BUTTON.
 *              Unit tesе contains: 
 *                  1. Sequential ON and OFF every LED 5 times 
 *                  2. 
 *                  3. Change ON and OFF for LED_1 if button is pressed.               
 * 
 * REVISION_PCB: rev:0.1
 * VERSION 0.1 (Jan, 2021)
 * Copyright 2021 De4m@yandex.ru
 * 
 * 
 *  
 */

#include <Arduino.h>
#include <avr/io.h>

#include <Keyboard.h>
//#include <Led.h>

#define LED_1 PB4
#define LED_2 PB3
#define LED_3 PB5

Keyboard KB (PB0);

int mode = 0;

void setup()
{
  //  Set 8Mhz speed
  CLKPR = (1<<CLKPCE);
  CLKPR = (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);

  //  Prepare LED
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

  KB.Setup();

}

void loop()
{
  // Check LED_1
  for (int i=0; i<=5; i++)
  {
    digitalWrite(LED_1, HIGH);
    delay(200);
    digitalWrite(LED_1, LOW);
    delay(200); 
  }
  digitalWrite(LED_1, HIGH);
  
  // Check LED_2
  for (int i=0; i<=5; i++)
  {
    digitalWrite(LED_2, HIGH);
    delay(200);
    digitalWrite(LED_2, LOW);
    delay(200); 
  }
  digitalWrite(LED_2, HIGH);  
  
  // Check LED_3
  for (int i=0; i<=5; i++)
  {
    digitalWrite(LED_3, HIGH);
    delay(200);
    digitalWrite(LED_3, LOW);
    delay(200); 
  }
  digitalWrite(LED_3, HIGH);    
  
  // Check Button  
  while(true)
  {
    KB.Update();
    if (KB.ButtonPressed)
      {
        mode++;    
      }
    if (mode > 1) 
      { mode = 0;}

    if (mode==0)
    {
        digitalWrite(LED_1, HIGH);
    }
    else
    {
        digitalWrite(LED_1, LOW);
    }
    
  }
 
}


