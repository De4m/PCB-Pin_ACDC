#include <Keyboard.h>
#include <Arduino.h>

Keyboard::Keyboard(int Pin)
{
  this->_Pin = Pin;
}

void Keyboard::Setup()
{
    pinMode(this->_Pin, INPUT_PULLUP);  
}

void Keyboard::Update()
{
    if ((digitalRead(this->_Pin)==0)&&((millis()-this->_tick)>=200))
    {

    }
    this->_tick = millis();

    this->ButtonPressed = !digitalRead(this->_Pin);
    this->ButtonWasPressed = (this->_PreviousButtonPressed == true && this->ButtonPressed == false);
    this->_PreviousButtonPressed = this->ButtonPressed ;

}