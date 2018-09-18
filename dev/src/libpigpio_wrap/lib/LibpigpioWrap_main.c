/*
 * LibpigpioWrap_main.c
 *
 *  Created on: 2018/09/18
 *      Author: CountrySideEngineer
 */
#include <stdio.h>
#include "pigpio.h"

static int IsInit = 0;

/**
 * @brief	Initialize pigpio library.
 * @return	If initialize finished successfully, returns 0, otherwise
 * 			none-zero value. The mean of "none-zero" values is below:
 * 			0x01	:	The library has already been initialized.
 * 			0xFF	:	The cause of failure is unknown.
 */
uint8_t LibInitialize() {

	uint8_t InitResult = 0;

	/*
	 * Avoid initialize library twice, check whether the library has already
	 * been initialized.
	 */
	if (0 != IsInit) {
		InitResult = 0x01;
	} else {
		int InitRes = gpioInitialise();

		if (PI_INIT_FAILED == InitRes) {
			InitResult = 0xFF;

			IsInit = 0;
		} else {
			InitResult = 0x00;

			IsInit = 1;
		}
	}

	return InitResult;
}

/**
 * @brief	Finalize pigpio library.
 * @return	If finalize finished succesfully, returns 0, otherwise returns
 * 			none-zero value. The mean of "none-zero" value is below:
 * 			0x01	:	The library has not been initialized.
 * 			0xFF	:	Unknown error. This value must not been returned.
 */
uint8_t LibFinalize() {
	uint8_t FinalResult = 0;

	if (0 == IsInit) {
		FinalResult = 0x01;
	} else {
		gpioTerminate();

		FinalResult = 0x00;
		IsInit = 0;
	}

	return FinalResult;
}


