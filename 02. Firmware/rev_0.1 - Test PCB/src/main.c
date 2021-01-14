/*
 * TYPE: Firmware
 * NAME: Test PCB (for Pin_ACDC) - 
 * DESCRIPTION: Firmware for test PCB. Check LED diode and BUTTON.
 *              Unit tesе contains: 
 *                  1. Sequential ON and OFF every LED 3 times with delay 0.5sec 
 *                  2. Endless change state all LED with delay 0.5sec 
 *                  3. Change delay 0.5 <-> 1 sec. if BUTTOM is pressed.               
 * 
 * REVISION_PCB: rev:0.1
 * VERSION 0.1 (Jan, 2021)
 * Copyright 2021 De4m@yandex.ru
 * 
 */

#include <Arduino.h>
#include <avr/io.h>


#define LED_1 PB4
#define LED_2 PB3
#define LED_3 PB5

#define BUTTON_1 PB0

volatile int buttonState = LOW;   
volatile unsigned long millis_prev;

volatile bool work_flag = true;
volatile int delay_tm = 100;
/*
ISR(PCINT0_vect)
{
  delay(50); 
  if ( (PINB & (1<<BUTTON_1)) == 0 ) 
  {
    if (work_flag)
    {
      work_flag = false;
      delay_tm = 125;
      }
    else
    {
      work_flag = true;
      delay_tm = 500;
    }
    
    while ( (PINB & (1<<BUTTON_1)) == 0 ) {} // ждём отпускания кнопки
  }
}
*/
void pin_ISR() 
{
  
  asm("cli"); 
  if ( work_flag == true)
  {
    work_flag = false;
  }
  else
  {
    work_flag = true;
  }

  for (int i=0;i<=70;i++)
  {
    asm("nop"); 
  }  
  
  
  
  if ( digitalRead(BUTTON_1) == LOW )
  {
    delay_tm = 10;
  }
  else
  {
    delay_tm = 100;
  }
  asm("sei"); 
}


void setup()
{
  // init LED digital pin as an output.
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  
  // init Button
  pinMode(BUTTON_1, INPUT_PULLUP);   
  
  attachInterrupt(0, pin_ISR, RISING);
}


void loop()
{
  
  if ( work_flag == true)
  {
    digitalWrite(LED_1, HIGH);
  }
  else
  {
    digitalWrite(LED_1, LOW);
  }
  

    
  
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, HIGH);
    
  // wait for a half second
  delay(delay_tm);

  // turn the LED off by making the voltage LOW
  //digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
    
 // wait for a second
  delay(delay_tm);
 

}


