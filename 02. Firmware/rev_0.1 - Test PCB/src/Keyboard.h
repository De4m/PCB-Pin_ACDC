class Keyboard
{
    private:
        int _Pin = 0;
        unsigned long _tick = 0;
        bool _PreviousButtonPressed;

    public:
        Keyboard(int Pin);
        void Setup();
        void Update();
        bool ButtonPressed;
        bool ButtonWasPressed;

};