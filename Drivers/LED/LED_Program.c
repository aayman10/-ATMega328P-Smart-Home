/*
 * LED_Program.c
 *
 *  Created on: Apr 9, 2023
 *      Author: abdelrahmanhossam
 */

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

/****************************************************/
/* DIO Directives		     					    */
/****************************************************/
#include "../include/MCAL/DIO/DIO_Interface.h"


/****************************************************/
/* DIO Directives		     					    */
/****************************************************/
#include "../include/HAL/LED/LED_Interface.h"
#include "../include/HAL/LED/LED_Private.h"
#include "../include/HAL/LED/LED_Cfg.h"


void HLED_voidSetLedStatus(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin,LED_STATUS A_LedStatus)
{
	MDIO_voidSetPinStatus(A_DIOPort, A_DIOPin, A_LedStatus);
}
void HLED_voidToggleLedStatus(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin)
{
	MDIO_voidTogglePinValue(A_DIOPort, A_DIOPin);
}
