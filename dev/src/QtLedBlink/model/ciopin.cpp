#include "stdint.h"
#include "ciopin.h"
//#include "LibpigpioWrap.h"

//Initialize static member parameter
CIOPin* CIOPin::mInstance = nullptr;

/**
 * @brief CIOPin::CIOPing constructor
 */
CIOPin::CIOPin() {
    //Call library function to initialize pigpio library.
}

/**
 * @brief CIOPing::~CIOPing destructor
 */
CIOPin::~CIOPin() {
    //Call library functoin to terminate pigpio library.
}
