/*
 * USART_Cfg.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Tatget
 */

#ifndef INCLUDE_MCAL_USART_USART_CFG_H_
#define INCLUDE_MCAL_USART_USART_CFG_H_

#define BUADRATE 9600

#define RX_INTTERUPT_ENABLE INTERRUPT_ENABLE

#define TX_INTTERUPT_ENABLE INTERRUPT_ENABLE

#define DATA_INTTERUPT_ENABLE INTERRUPT_ENABLE

#define USART_Mode_Select Asynchronous_Operation

#define Parity_Mode DISALED

#define Stop_Bit_Select ONE_BIT

#define Character_Size EIGHT_BITS

#define Clock_Polarity 0

#define SPEED_MODE DOUBLE_SPEED

#define RETURN_UNRECEVED_DATA 255

#endif /* INCLUDE_MCAL_USART_USART_CFG_H_ */
