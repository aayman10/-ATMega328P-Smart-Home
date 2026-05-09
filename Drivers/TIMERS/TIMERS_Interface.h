/*
 * TIMERS_Interface.h
 *
 *  Created on: Apr 30, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_TIMERS_TIMERS_INTERFACE_H_
#define INCLUDE_MCAL_TIMERS_TIMERS_INTERFACE_H_

#define NORMAL_MODE        0
#define PHASE_CORRECT_MODE 1
#define CTC_MODE    	   2
#define FAST_PWM_MODE      3



#define NORMAL_DIO_PIN    0
#define TOGGLE_CTC	      1
#define CLEAR_CTC	      2
#define SET_CTC	          3
#define INVERTING_PWM     3
#define NONINVERTING_PWM  2

void MTIMER0_voidInit (void);
void MTIMER0_voidSetPreloadValue (u8 A_u8NoOfTicks);
void MTIMER0_voidSetOVFCallback (void (*A_PtrToFunc)(void));
void MTIMER0_voidSetCTCCallback (void (*A_PtrToFunc)(void));
void MTIMER0_voidSetOCR0Value (u8 A_u8OCR0Value);
void MTIMER0_voidStopTimer (void);
void SetServoValue (u16 A_u16Angle);
#endif /* INCLUDE_MCAL_TIMERS_TIMERS_INTERFACE_H_ */
