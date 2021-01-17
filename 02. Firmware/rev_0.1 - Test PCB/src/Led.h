class Led 
{
    private:
        int _Pin = 0;
        unsigned long _OnDelay = 0;
        unsigned long _OffDelay = 0;
        unsigned long _StartTime;
        unsigned long _TimeNow;
        unsigned long _Delta; 
        bool _ready = true;
    public:
         Led(int Pin);
         void Run();
         void Update();
         void On();
         void Off();
         bool Ready();
         void ConfOnOff (unsigned long OnDelay, unsigned long OffDelay);
         void Setup();
         void Stop();
         

    protected:



};
