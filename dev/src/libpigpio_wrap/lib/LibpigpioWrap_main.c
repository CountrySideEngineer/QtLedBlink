/*
 * LibpigpioWrap_main.c
 *
 *  Created on: 2018/09/18
 *      Author: CountrySideEngineer
 */
#include <stdio.h>
#include "pigpio.h"
#include "LibpigpioWrap.h"

#define LIB_VERSION_MAJOR       (0xFF)
#define LIB_VERSION_MINOR       (0x01)


static int IsInit = 0;

/**
 * @brief   Initialize pigpio library.
 * @return  If initialize finished successfully, returns 0, otherwise
 *          none-zero value. The mean of "none-zero" values is below:
 *          0x01    :   The library has already been initialized.
 *          0xFF    :   The cause of failure is unknown.
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
 * @brief   Finalize pigpio library.
 * @return  If finalize finished succesfully, returns 0, otherwise returns
 *          none-zero value. The mean of "none-zero" value is below:
 *          0x01    :   The library has not been initialized.
 *          0xFF    :   Unknown error. This value must not been returned.
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

/**
 * @brief   Get version of library.
 * @return  Return library version. This returns 2byte data, upper byte
 *          contains major version, lower byte contains minor one.
 */
uint16_t LibVersion(void) {
    uint16_t version = 0;

    version = (((uint16_t)LIB_VERSION_MAJOR) << 8) ||
            ((uint16_t)LIB_VERSION_MINOR);

    return version;
}

/**
 * @brief   Configure GPIO pin direction, input or output.
 * @param[in]   pin     GPIO pin index on RaspberryPi.
 * @param[in]   mode    Pin access direction, input or output.
 *                      To configure pin directoin as input, use GPIO_INPUT,
 *                      as output, use GPIO_OUTPUT.
 * @return  If pin configuration finished successfully, returns 0, otherwise
 *          returns none-zero value. The mean of each "none-zero" value is
 *          below:
 *          0x01    :   The library has not been initialized.
 *          0x02    :   The pin index is invalid.
 *          0x03    :   The mode is invalid.
 *          0xFF    :   Unknown error. This value must not been returned.
 */
uint8_t SetGPIOMode(int pin, int mode) {
    int result = GPIO_RESULT_ERR_REASON_UNKNOWN;

    //Check arguments and parameter.
    if (0 == IsInit) {
        result = GPIO_RESULT_ERR_NOT_INITIALIZED;
    } else if ((pin < 0) || (53 < pin)) {
        result = GPIO_RESULT_ERR_INVALID_PIN_INDEX;
    } else if ((GPIO_OUTPUT != mode) && (GPIO_INPUT != mode)) {
        result = GPIO_RESULT_ERR_INVALID_ACC_DIRECTION;
    } else {
        int ret = gpioSetMode((unsigned int)pin, (unsigned int)mode);
        if (PI_BAD_GPIO == ret) {
            result = GPIO_RESULT_ERR_INVALID_PIN_INDEX;
        } else if (PI_BAD_MODE == ret) {
            result = GPIO_RESULT_ERR_INVALID_ACC_DIRECTION;
        } else {
            result = GPIO_RESULT_ERR_SUCCESS;
        }
    }
    return result;
}

/**
 *  @brief  Set PIN value, high and low.
 *  @param[in]  pin     GPIO pin index on RaspberryPi.
 *  @param[in]  value   Value to set to value, only GPIO_LV_OFF and GPIO_LV_ON
 *                      are allowed.
 * @return  If pin configuration finished successfully, returns 0, otherwise
 *          returns none-zero value. The mean of each "none-zero" value is
 *          below:
 *          0x01    :   The library has not been initialized.
 *          0x02    :   The pin index is invalid.
 *          0x04    :   The value to set to pin are invalid.
 *          0xFF    :   Unknown error. This value must not been returned.
 */
uint8_t SetGPIO(int pin, int value) {
    int result = GPIO_RESULT_ERR_REASON_UNKNOWN;

    //Check arguments and parameter.
    if (0 == IsInit) {
        result = GPIO_RESULT_ERR_NOT_INITIALIZED;
    } else if ((pin < 0) || (53 < pin)) {
        result = GPIO_RESULT_ERR_INVALID_PIN_INDEX;
    } else if ((GPIO_LV_OFF != value) && (GPIO_LV_ON != value)) {
        result = GPIO_RESULT_ERR_OUTPUT_VALUE_INVALID;
    } else {
        int ret = gpioWrite((unsigned int)pin, (unsigned int)value);
        if (PI_BAD_GPIO == ret) {
            result = GPIO_RESULT_ERR_INVALID_PIN_INDEX;
        } else if (PI_BAD_LEVEL == ret) {
            result = GPIO_RESULT_ERR_OUTPUT_VALUE_INVALID;
        } else {
            result = GPIO_RESULT_ERR_SUCCESS;
        }
    }

    return result;
}
