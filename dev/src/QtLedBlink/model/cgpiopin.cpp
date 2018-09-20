#include "cgpiopin.h"
#include "ciopin.h"

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
