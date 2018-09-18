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
#endif	//__cplusplus

//GPIO level macro
#define GPIO_LV_OFF	(0)
#define GPIO_LV_ON		(1)

//GPIO in/out direction macro.
#define GPIO_INPUT		(0)
#define GPIO_OUTPUT	(1)


//Declaration of functions in the library.
extern uint8_t LibInitialize();
extern uint8_t LibFinalize();

#ifdef __cplusplus
}
#endif	//__cplusplus
#endif /* LIBPIGPIOWRAP_H_ */
