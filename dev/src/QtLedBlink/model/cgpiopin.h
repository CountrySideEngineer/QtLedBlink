#ifndef CGPIOPIN_H
#define CGPIOPIN_H


class CGPIOPin
{
public:
    CGPIOPin();
    virtual ~CGPIOPin();

    virtual void SetupPinMode(int pin, int mode);
    virtual void SetPinValue(int value);
    //virtual int GetPinValue();

protected:
    int mPin;
    int mMode;

};

#endif // CGPIOPIN_H
