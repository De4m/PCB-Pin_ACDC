#include <Arduino.h>
#include <Effects.h>

void AllOn()
{
  digitalWrite(LED_1,HIGH);
  digitalWrite(LED_2,HIGH); 
  digitalWrite(LED_3,HIGH); 
}

void AllOff()
{ 
  digitalWrite(LED_1,LOW);
  digitalWrite(LED_2,LOW); 
  digitalWrite(LED_3,LOW); 
}

void NextEffect()
{
  AllOff();
  delay(5000);
}

void RunAllEffects()
{
    Effect0();
    Effect1();
    Effect2();
    Effect3();
    Effect4();
    Effect5();
    Effect6();
    Effect7();
    Effect8();
}

void RunRandomEffects()
{

}



void Effect0()
{
  // Effect 0 - "ON -OFF"
  for (int i=0;i<5;i++)
  {
    AllOn();
    delay(500);
    AllOff();
    delay(500);  
  }
  NextEffect();
}

void Effect1()
{

  // Effect 1 - "ON 5sec"
  AllOn();
  delay(5000);
  NextEffect();
}

void Effect2()
{
   // Effect 2 - "Flash"
  for (int j=0;j<5;j++)
  {
    for (int i=0;i<5;i++)
    {   
      AllOff();
      delay(100);
      AllOn();
      delay(50);
    }
    delay(1500);
  }
  NextEffect();
}

void Effect3()
{

  // Effect 3 - "Dynamic flash"
  for (int i=0;i<500;i=i+25)
      {   
        AllOn();
        delay(i);
        AllOff();
        delay(501-i);
      }
  AllOn();
  delay(5000);
  NextEffect();
}

void Effect4()
{
  // Effect 4 - "Flash fast"
  for (int i=0;i<500;i=i+15)
      {   
        AllOn();
        delay(50);
        AllOff();
        delay(50);
      }
  NextEffect();
}

void Effect5()
{
  // Effect 5 - "Flash ___
  for (int i=0;i<5;i++)
      {   
        digitalWrite(LED_1,HIGH);
        delay(150);
        digitalWrite(LED_2,HIGH);
        delay(150);
        digitalWrite(LED_3,HIGH);
        delay(1500);
        digitalWrite(LED_1,LOW);
        delay(150);
        digitalWrite(LED_2,LOW);
        delay(150);
        digitalWrite(LED_3,LOW);
        delay(150);
      }
  NextEffect();
}

void Effect6()
{
  // Effect 6 - "Flash medium"
  for (int i=0;i<500;i=i+15)
      {   
        AllOn();
        delay(150);
        AllOff();
        delay(50);
      }
  NextEffect();
}

void Effect7()
{
  // Effect 7 - "Flash concrete
  for (int i=0;i<500;i=i+15)
      {   
        AllOn();
        delay(50);
        AllOff();
        delay(150);
      }
  NextEffect();
}

void Effect8()
{
  // Effect 8 - "Flash ___
  for (int i=0;i<5;i++)
      {   
        digitalWrite(LED_1,HIGH);
        delay(150);
        digitalWrite(LED_2,HIGH);
        delay(150);
        digitalWrite(LED_3,HIGH);
        delay(1500);
        digitalWrite(LED_1,LOW);
        delay(150);
        digitalWrite(LED_2,LOW);
        delay(150);
        digitalWrite(LED_3,LOW);
        delay(150);
      }
  NextEffect();
}

