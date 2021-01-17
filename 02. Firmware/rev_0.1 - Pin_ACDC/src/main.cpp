/*
 * TYPE: Firmware
 * NAME: Pin_ACDC
 * DESCRIPTION: Firmware for Pin_ACDC. After power is ON or wakeup when button is pressed 
 *              LED is light in next mode: 
 *                  1. Sequential repeat 15 times (aprox. 35 min) all light effects.
 *                  2. Start shut down mode
 *              After aprox. 35 min the Pin_ACDC goes into SleepMode. With minimal consumption power.
 *              BUTTON logic:
 *                  - if Pin_ACDC is in SleepMode, then WakeUp and start work.
 *                  - (in future) if Pin_ACDC is in WorkMode, then change LED mode.          
 * REVISION_PCB: rev:0.1
 * VERSION 0.1 (Jan, 2021)
 * MICROCONTROLLER: Attiny13A   FUSES: H:FD, L:6A  E:FF  
 * Copyright 2021 De4m@yandex.ru
 */


//#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>
//#include <avr/wdt.h>

#include <Arduino.h>
#include <avr/io.h>
#include <Effects.h>


#define LED_1 PB4
#define LED_2 PB3
#define LED_3 PB5

#define BUTTON_1 PB0
#define BUTTON_2 PB1

#define MAX_EFFECT 

// Wake up by button is pressed
ISR(PCINT0_vect )
{
  cli();  
}


// Change to minimal power consumption
void power_off()
{
    cli();                               // Disable Interrupts before next commands
    delay(100);
    wdt_disable();                       // Disable watch dog timer to save power
    set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Set sleep mode power down
    sleep_enable();
    sleep_bod_disable(); // Disable Brown out detector
    sei();               // Enable interrupts
    sleep_cpu();  
    sleep_disable();
    power_all_enable();
}

void setup()
{
  //  Set 8Mhz speed
  CLKPR = (1<<CLKPCE);
  CLKPR = (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);

  // Setup external interrupt (press button on PB0)
  GIMSK |= (1<<INT0)|(1<<PCIE);
  PCMSK |= (1<<PCINT0);

  // init LED digital pin as an output.
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

  pinMode(BUTTON_1, INPUT_PULLUP);  
  pinMode(BUTTON_2, INPUT_PULLUP);    
  
}


void loop()
{
  for (int i=0;i<15;i++)
  {
    RunAllEffects();
  }

  Effect2();
  power_off();
}

