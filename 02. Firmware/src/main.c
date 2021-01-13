/*
 * Pin_ACDC - Firmware for pin ACDC.
 * Version 0.1 Jan,21
 * Copyright 2021 De4m@yandex.ru
 * 
 */

//#include <Arduino.h>
#include <avr/io.h>


//int LED_0 = PB0;
//int LED_1 = PB1;
//int LED_2 = PB2;
//int LED_3 = PB3;
//int LED_4 = PB4;
//int LED_5 = PB5;



void setup()
{
  // initialize LED digital pin as an output.
  //pinMode(LED_0, OUTPUT);
  //pinMode(LED_1, OUTPUT);
  //pinMode(LED_2, OUTPUT);
  //pinMode(LED_3, OUTPUT);
  //pinMode(LED_4, OUTPUT);
  //pinMode(LED_5, OUTPUT);
  DDRB |= (1 << PB3); 	// pinMode(PB4, OUTPUT); 
  DDRB |= (1 << PB4); 	// pinMode(PB4, OUTPUT); 
  DDRB |= (1 << PB5); 	// pinMode(PB4, OUTPUT); 
  
//pinMode(BUTTON, INPUT);   
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  //digitalWrite(LED_0, HIGH);
  //digitalWrite(LED_1, HIGH);
  //digitalWrite(LED_2, HIGH);
  //digitalWrite(LED_3, HIGH);
  //digitalWrite(LED_4, HIGH);
  //digitalWrite(LED_5, HIGH);
  PORTB |= (1 << PB3); 	// digitalWrite(PB4, HIGH);
  PORTB |= (1 << PB4); 	// digitalWrite(PB4, HIGH);
  PORTB |= (1 << PB5); 	// digitalWrite(PB4, HIGH);


  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  //digitalWrite(LED_0, LOW);
  //digitalWrite(LED_1, LOW);
  //digitalWrite(LED_2, LOW);
  //digitalWrite(LED_3, LOW);
  //digitalWrite(LED_4, LOW);
  //digitalWrite(LED_5, LOW);
  PORTB &= ~(1 << PB3);
  PORTB &= ~(1 << PB4);
  PORTB &= ~(1 << PB5);
 	  
 // wait for a second
  delay(1000);
}
