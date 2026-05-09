/*
 * LED_Interface.h
 *
 *  Created on: Apr 9, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_LED_LED_INTERFACE_H_
#define INCLUDE_HAL_LED_LED_INTERFACE_H_

typedef enum
{
	OFF=0,
	ON
}LED_STATUS;

void HLED_voidSetLedStatus(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin,LED_STATUS A_LedStatus);
void HLED_voidToggleLedStatus(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin);


#endif /* INCLUDE_HAL_LED_LED_INTERFACE_H_ */
