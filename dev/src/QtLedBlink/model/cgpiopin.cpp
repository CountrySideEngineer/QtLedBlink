#include <stdint.h>
#include "cgpiopin.h"
#include "ciopin.h"
#include "LibpigpioWrap.h"

/**
 * @brief CGPIOPin::CGPIOPin constructor. Create instance of IO pin.
 * The method is called every time when the CGPIOPin is create, but it is
 * no problem because the CIOPin is singleton.
 */
CGPIOPin::CGPIOPin() { CIOPin::create(); }

/**
 * @brief CGPIOPin::~CGPIOPin destructor. Delete instance of IO pin.
 */
CGPIOPin::~CGPIOPin() { CIOPin::destroy(); }

void CGPIOPin::SetupPinMode(int pin, int mode)
{
    this->mPin = pin;
    this->mMode = mode;

#ifdef CALL_PIGPIO_LIBRARY
    SetGPIOMode(pin, mode);
#endif  /* CALL_CALL_PIGPIO_LIBRARY */
}

void CGPIOPin::SetPinValue(int value)
{
#ifdef CALL_PIGPIO_LIBRARY
    SetGPIO(this->mPin, value);
#else
    value = 0;  //To take measures for variable unused warning.
#endif  /* CALL_CALL_PIGPIO_LIBRARY */
}

int CGPIOPin::GetPinValue()
{
#ifdef CALL_PIGPIO_LIBRARY
    return GetGPIO(this->mPin);
#else
    return 0;
#endif
}
