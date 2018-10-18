#ifndef CGPIOPIN_H
#define CGPIOPIN_H


class CGPIOPin
{
#ifdef USE_PIGPIO_LIBRARY
public:
    enum GPIO_PIN_MODE {
        GPIO_PIN_MODE_INPUT = 0,
        GPIO_PIN_MODE_OUTPUT,
        GPIO_PIN_MODE_MAX
    };
#endif  /* USE_PIGPIO_LIBRARY */

public:
    CGPIOPin();
    virtual ~CGPIOPin();

    virtual void SetupPinMode(int pin, int mode);
    virtual int SetPinValue(int value);
    virtual int GetPinValue();

    int GetPin() { return this->mPin; }

protected:
    int mPin;
    int mMode;

};

#endif // CGPIOPIN_H
