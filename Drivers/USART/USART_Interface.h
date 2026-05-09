/*
 * USART_Interface.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Tatget
 */

#ifndef INCLUDE_MCAL_USART_USART_INTERFACE_H_
#define INCLUDE_MCAL_USART_USART_INTERFACE_H_


typedef enum{
	DATA_EMPTY_COMPLATE =0 ,
	RX_COMPLATE_INTERRUPT,
	TX_COMPLATE_INTERRUPT
}INTERRUPT_Complate_CONFIG;

typedef enum{
	INTERRUPT_DISABLE = 0 ,
	INTERRUPT_ENABLE
}INTERRUPT_CONFIG;

typedef enum{
	DISABLE = 0,
	ENABLE
}TX_RX_ENABLE;

typedef enum{
	FIVE_BITS = 0 ,
	SIX_BITS,
	SEEVEN_BITS,
	EIGHT_BITS,
	NINE_BITS=7
}Character_Size;

typedef enum{
	Asynchronous_Operation = 0 ,
	synchronous_Operation
}USART_Mode_Select;

typedef enum{
	ONE_BIT = 0 ,
	TWO_BIT
}Stop_Bit_Select;

typedef enum{
	NORMAL_SPEED = 0 ,
	DOUBLE_SPEED
}SPEED_MODE;


typedef enum{
	DISALED = 0 ,
	Reserved,
	Enabled_Even_Parity,
	Enabled_ODD_Parity
}Parity_Mode;

void MUSART_VoisInit();
void MUSART_VoidSndByteSynchBlocking(u8 A_u8DataByate);
void MUSART_VoidSndByteSynchNonBlocking(u8 A_u8DataByate);
void MUSART_VoidSenString(u8 *A_u8String);
void MUSART_VoidSendByteAsynchorouns(u8 A_u8Data);
u8 MUSART_VoidRecevByteBlocking();
u8 MUSART_VoidRecevByteNonBlocking();
u8 MUSART_VoidRecevByteAsynchg();
void MUSART_VoidSetCallBck(INTERRUPT_Complate_CONFIG A_INTERRUPT_Complate_CONFIG , void (*PtrToFunc)(void));




#endif /* INCLUDE_MCAL_USART_USART_INTERFACE_H_ */
