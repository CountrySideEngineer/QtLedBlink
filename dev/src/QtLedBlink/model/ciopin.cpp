#include <cstdint>
#include "ciopin.h"
#ifdef USE_PIGPIO_LIBRARY
#include "pigpio.h"
#endif  /* USE_PIGPIO_LIBRARY*/

//Initialize static member parameter
CIOPin* CIOPin::mInstance = nullptr;
bool CIOPin::IsInit = false;
/**
 * @brief CIOPin::CIOPing constructor
 */
CIOPin::CIOPin() {
#ifdef CALL_PIGPIO_LIBRARY
    LibInitialize();
#endif  /* CALL_PIGPIO_LIBRARY */
#ifdef USE_PIGPIO_LIBRARY
    if (true == CIOPin::IsInit) {
        /*
         * If the pigpio library has been already initialized,
         * nothing to do in the constructor.
         */
    } else {
        int InitResult = gpioInitialise();
        if (InitResult < 0) {
            CIOPin::IsInit = false;
        } else {
            CIOPin::IsInit = true;
        }
    }
#endif  /* USE_PIGPIO_LIBRARY */
}

/**
 * @brief CIOPing::~CIOPing destructor
 */
CIOPin::~CIOPin() {
#ifdef CALL_PIGPIO_LIBRARY
    LibFinalize();
#endif  /* CALL_PIGPIO_LIBRARY */
#ifdef USE_PIGPIO_LIBRARY
    if (true == CIOPin::IsInit) {
        /*
         * If the pigpio library has been initialized, successfully,
         * it must be finalized, otherwise it must be done nothing.
         */
        gpioTerminate();
        CIOPin::IsInit = false;
    }
#endif  /* USE_PIGPIO_LIBRARY */
}
