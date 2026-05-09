
#include"../Include/LIB/BIT_MATH.h"
#include"../Include/LIB/STD_TYPES.h"

#include"../Include/MCAL/DIO/DIO_Interface.h"

#include"../Include/MCAL/USART/USART_Interface.h"
#include"../Include/MCAL/USART/USART_Private.h"
#include"../Include/MCAL/USART/USART_Cfg.h"

#define F_CPU 8000000UL
#define NULL 0
void (*CALLBACKFUNC[3])(void)={NULL,NULL,NULL};

void MUSART_VoisInit()
{
	//Equation Of Buadrate
	u16 Local_u16BuadRtaeValue = BUADRATE_EQUATION;
	//GET The Value Of Char Size
	u8 Local_u8Pit2=(GET_BIT(Character_Size , 2));
	u8 Local_u8Pit1=(GET_BIT(Character_Size , 1));
	u8 Local_u8Pit0=(GET_BIT(Character_Size , 0));

	if(SPEED_MODE == NORMAL_SPEED)
	{
		CLR_BIT(UCSRA , 1);
	}
	else if(SPEED_MODE == DOUBLE_SPEED)
	{

		SET_BIT(UCSRA , 1);
		Local_u16BuadRtaeValue *= 2 ;

	}

	UBRRL =(u8)Local_u16BuadRtaeValue;
	UBRRH =(u8)(Local_u16BuadRtaeValue >> 8);

	UCSRB &= 0b00000011;
	UCSRB |=((RX_INTTERUPT_ENABLE << 7 ) | (TX_INTTERUPT_ENABLE << 6) | (DATA_INTTERUPT_ENABLE << 5) |(1 << 4) | (1 <<3) | (Local_u8Pit2 <<2) ) ;

	u8 Local_u8UCSRCValue =
	UCSRC &= 0b00000001;
	UCSRC |= ( (1 << 7) | (USART_Mode_Select << 6) | (Parity_Mode <<4 ) | (Stop_Bit_Select <<3) | (Local_u8Pit1 << 2) | (Local_u8Pit0 <<1) );

}

void MUSART_VoidSndByteSynchBlocking(u8 A_u8DataByate)
{
	//Check If Register Empty
	while(GET_BIT(UCSRA , 5) == 0);
	//Set The Valu
	UDR =A_u8DataByate;
	//Check If Register Empty After Transmation
	while(GET_BIT(UCSRA , 5) == 0);
	//Clear Flag
	SET_BIT(UCSRA ,6);
}

void MUSART_VoidSndByteSynchNonBlocking(u8 A_u8DataByate)
{
	u32 Local_u16TimeOut =0 ;
	//Check If Register Empty
	while(GET_BIT(UCSRA , 5) == 0)
	{
		Local_u16TimeOut++ ;
		if(Local_u16TimeOut == TIME_OUT)
		{
			break;
		}
	}
	if(Local_u16TimeOut != TIME_OUT)
	{
		Local_u16TimeOut = 0 ;
		//Set The Valu
		UDR =A_u8DataByate;
		while(GET_BIT(UCSRA , 5) == 0)
		{
			Local_u16TimeOut++ ;
			if(Local_u16TimeOut == TIME_OUT)
			{
				break;
			}
		}
	}
	//Check If Register Empty After Transmation

	//Clear Flag
	SET_BIT(UCSRA ,6);
}

void MUSART_VoidSenString(u8 *A_u8String)
{
	while(*A_u8String > 0)
	{
		MUSART_VoidSndByteSynchNonBlocking(*A_u8String++);
	}
}

void MUSART_VoidSendByteAsynchorouns(u8 A_u8Data)
{
	if(GET_BIT(UCSRA , 5) == 1)
	{
		UDR= A_u8Data;
	}
}

u8 MUSART_VoidRecevByteBlocking()
{
	while(GET_BIT(UCSRA , 7) == 0);
	return UDR;
}

u8 MUSART_VoidRecevByteNonBlocking()
{
	u32 Local_u16TimeOut = 0 ;
	u8 Local_u8RetuenValue =RETURN_UNRECEVED_DATA;
	while(GET_BIT(UCSRA , 7) == 0)
	{
		Local_u16TimeOut++;
		if(Local_u16TimeOut == TIME_OUT)
		{
			break;
		}
	}
	if(Local_u16TimeOut != TIME_OUT)
	{
		Local_u16TimeOut =0;
		Local_u8RetuenValue=UDR;
	}
	return Local_u8RetuenValue;
}

u8 MUSART_VoidRecevByteAsynchg()
{
	return UDR;
}

void MUSART_VoidSetCallBck(INTERRUPT_Complate_CONFIG A_INTERRUPT_Complate_CONFIG , void (*PtrToFunc)(void))
{
	if(PtrToFunc != NULL)
	{
		CALLBACKFUNC[A_INTERRUPT_Complate_CONFIG] = PtrToFunc;
	}
}


void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if(CALLBACKFUNC[RX_COMPLATE_INTERRUPT] != NULL)
	{
		CALLBACKFUNC[RX_COMPLATE_INTERRUPT]();
	}
}

void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	if(CALLBACKFUNC[DATA_EMPTY_COMPLATE] != NULL)
	{
		CALLBACKFUNC[DATA_EMPTY_COMPLATE]();
	}
}

void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	if(CALLBACKFUNC[TX_COMPLATE_INTERRUPT] != NULL)
	{
		CALLBACKFUNC[TX_COMPLATE_INTERRUPT]();
	}
}











