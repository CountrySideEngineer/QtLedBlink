/*
 * LibpigpioWrap.h
 *
 *  Created on: 2018/09/18
 *      Author: CountrySideEngineer
 */
#ifndef LIBPIGPIOWRAP_H_
#define LIBPIGPIOWRAP_H_

#ifdef __cplusplus
extern "C" {
#endif  //__cplusplus

//GPIO level macro
#define GPIO_LV_OFF     (0)
#define GPIO_LV_ON      (1)

//GPIO in/out direction macro.
#define GPIO_INPUT      (0)
#define GPIO_OUTPUT     (1)

//Result
#define GPIO_RESULT_ERR_SUCCESS                 (0)
#define GPIO_RESULT_ERR_NOT_INITIALIZED         (1)
#define GPIO_RESULT_ERR_INVALID_PIN_INDEX       (2)
#define GPIO_RESULT_ERR_INVALID_ACC_DIRECTION   (3)
#define GPIO_RESULT_ERR_OUTPUT_VALUE_INVALID    (4)
#define GPIO_RESULT_ERR_REASON_UNKNOWN          (255)   //0xFF

//Declaration of functions in the library.
extern uint8_t LibInitialize();
extern uint8_t LibFinalize();
extern uint8_t SetGPIOMode(int pin, int mode);
extern uint8_t SetGPIO(int pin, int value);

#ifdef __cplusplus
}
#endif  //__cplusplus
#endif /* LIBPIGPIOWRAP_H_ */
