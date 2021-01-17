#include <Led.h>
#include <Arduino.h>

Led::Led(int Pin)
{
  this->_Pin = Pin;
  this->_ready = true;
}

void Led::On()
{
   digitalWrite(this->_Pin, HIGH);
}

void Led::Off()
{
   digitalWrite(this->_Pin, LOW);
}

bool Led::Ready()
{
    return this->_ready;
}

void Led::ConfOnOff (unsigned long  OnDelay, unsigned long OffDelay)
{
    this->_OnDelay = OnDelay;
    this->_OffDelay = OffDelay;
}

void Led::Run()
{
    this->_ready = false;
    this->_StartTime = millis();
}

void Led::Update()
{
    if (_ready == false)
    {
        this->_TimeNow = millis();
        this->_Delta =  this->_TimeNow - this->_StartTime;
        if (this->_Delta  < this->_OnDelay )
        {
            this->On();
        }
        else if (this->_Delta  < (this->_OnDelay + this->_OffDelay) ) 
        {
            this->Off();
        }  
        else
        {
            this->Off();
            this->_ready = true;
        } 
    }
}


void Led::Setup()
{
   pinMode(_Pin, OUTPUT);
   this->_ready=true;
}

void Led::Stop()
{
    this->Off();
    _ready = true;
}

