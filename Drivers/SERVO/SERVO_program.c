/*
 * SERVO_program.c
 *
 *  Created on: Aug 14, 2023
 *      Author: ahmed ayman
 */
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"

#include "../include/HAL/SERVO/SERVO_Interface.h"
#include "../include/MCAL/TIMERS/TIMERS_Interface.h"


void HSERVO_voidOpenTheDoor (void)
{

	MTIMER1_voidSetOCR1AValue(2000);
}

void HSERVO_voidCloseTheDoor (void)
{
	MTIMER1_voidSetOCR1AValue(1000);
}

