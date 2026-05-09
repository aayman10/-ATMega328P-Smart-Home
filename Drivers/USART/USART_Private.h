/*
 * USART_Private.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Tatget
 */

#ifndef INCLUDE_MCAL_USART_USART_PRIVATE_H_
#define INCLUDE_MCAL_USART_USART_PRIVATE_H_

#define UDR   (*(volatile u8*) 0x2C)
#define UCSRA (*(volatile u8*) 0x2B)
#define UCSRB (*(volatile u8*) 0x2A)
#define UCSRC (*(volatile u8*) 0x40)
#define UBRRL (*(volatile u8*) 0x29)
#define UBRRH (*(volatile u8*) 0x40)


#define BUADRATE_EQUATION (F_CPU /16/BUADRATE-1)

#define TIME_OUT 10000


#endif /* INCLUDE_MCAL_USART_USART_PRIVATE_H_ */
