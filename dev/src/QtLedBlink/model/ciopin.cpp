#include "stdint.h"
#include "ciopin.h"
#include "LibpigpioWrap.h"

//Initialize static member parameter
CIOPin* CIOPin::mInstance = nullptr;

/**
 * @brief CIOPin::CIOPing constructor
 */
CIOPin::CIOPin() {
#ifdef CALL_PIGPIO_LIBRARY
    LibInitialize();
#endif  /* CALL_PIGPIO_LIBRARY */
}

/**
 * @brief CIOPing::~CIOPing destructor
 */
CIOPin::~CIOPin() {
#ifdef CALL_PIGPIO_LIBRARY
    LibFinalize();
#endif  /* CALL_PIGPIO_LIBRARY */
}
