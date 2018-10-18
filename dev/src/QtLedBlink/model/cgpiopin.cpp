#include <iostream>
#include <cstdint>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include "cgpiopin.h"
#include "ciopin.h"
#ifdef CALL_PIGPIO_LIBRARY
#include "LibpigpioWrap.h"
#endif  /* CALL_PIGPIO_LIBRARY */
#ifdef USE_PIGPIO_LIBRARY
#include "pigpio.h"
#endif  /* USE_PIGPIO_LIBRARY */
using namespace std;

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

/**
 * @brief CGPIOPin::SetupPinMode    Setup gpio pin mode.
 * @param pin   Number of pin in GPIO.
 * @param mode  Mode of GPIO pin, input or output.
 */
void CGPIOPin::SetupPinMode(int pin, int mode)
{
    if (((pin < 0) || (53 < pin))
     || ((GPIO_PIN_MODE::GPIO_PIN_MODE_INPUT != mode)
      && (GPIO_PIN_MODE::GPIO_PIN_MODE_OUTPUT != mode)))
    {
        throw invalid_argument("Invalid pin number or mode has been set.");
    }

    this->mPin = pin;
    this->mMode = mode;

#ifdef CALL_PIGPIO_LIBRARY
    SetGPIOMode(pin, mode);
#endif  /* CALL_CALL_PIGPIO_LIBRARY */
#ifdef USE_PIGPIO_LIBRARY
    int Result = gpioSetMode(static_cast<unsigned int>(this->mPin),
                             static_cast<unsigned int>(this->mMode));
    if (PI_BAD_GPIO == Result) {
        throw runtime_error("gpioSetMode() failed because of GPIO pin.");
    } else if (PI_BAD_MODE == Result) {
        throw runtime_error("gpioSetMode() failed because of PIN mode.");
    }
#endif  /* USE_PIGPIO_LIBRARY */
}

/**
 * @brief CGPIOPin::SetPinValue Set pin level, HIGH or LOW.
 * @param value Value to set in pin.
 * @return  Returns 0 if the operation finished successfully, otherwise
 *          returns none zero value or throws exception.
 */
int CGPIOPin::SetPinValue(int value)
{
#ifdef CALL_PIGPIO_LIBRARY
    SetGPIO(this->mPin, value);
#endif  /* CALL_CALL_PIGPIO_LIBRARY */
#ifdef USE_PIGPIO_LIBRARY
    int Result = gpioWrite(static_cast<unsigned int>(this->mPin),
                           static_cast<unsigned int>(value));
    if (PI_BAD_GPIO == Result) {
        throw runtime_error("gpioSetMode() failed because of GPIO pin.");
    } else if (PI_BAD_MODE == Result) {
        throw runtime_error("gpioSetMode() failed because of PIN mode.");
    }
    return Result;  //It must be "0", meaning OK.
#endif  /* USE_PIGPIO_LIBRARY */
}

/**
 * @brief CGPIOPin::GetPinValue Get pin level, HIGH or LOW.
 * @return  Returns 0, the pin has LOW level, or 1, the pin has HIGH level.
 *          Otherwise returns none 0 or 1, or throw exception if any error
 *          has occurs while running.
 */
int CGPIOPin::GetPinValue()
{
#ifdef CALL_PIGPIO_LIBRARY
    return GetGPIO(this->mPin);
#else
    int Result = gpioRead(static_cast<unsigned int>(this->mPin));
    if (PI_BAD_GPIO == Result) {
        throw runtime_error("gpioSetMode() failed because of GPIO pin.");
    } else if (PI_BAD_MODE == Result) {
        throw runtime_error("gpioSetMode() failed because of PIN mode.");
    }
    return Result;
#endif
#ifdef USE_PIGPIO_LIBRARY
#endif  /* USE_PIGPIO_LIBRARY */
}
