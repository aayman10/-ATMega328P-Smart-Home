#include <util/delay.h>
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"


#include "../include/MCAL/DIO/DIO_Interface.h"

#include"../include/MCAL/UART/UART_Interface.h"
#include "../include/HAL/LED/LED_Interface.h"
#include"../include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../include/HAL/SERVO/SERVO_Interface.h"

#define F_CPU 8000000UL


u8 CheckUserAndPass()
{
	MUART_voidInit();

	u8  counter = 0 ,Local_u8Flag = 0  ;

	u8 Local_u8Username1  [7] = "8001090" ;
	u8 Local_u8Username2  [7] = "8002080" ;
	u8 Local_u8Username3  [7] = "8003070" ;
	u8 Local_u8Username4  [7] = "8004060" ;
	u8 Local_u8Username5  [7] = "8005050" ;
	u8 Local_u8Username6  [7] = "8006040" ;
	u8 Local_u8Username7  [7] = "8007030" ;
	u8 Local_u8Username8  [7] = "8008020" ;
	u8 Local_u8Username9  [7] = "8009010" ;
	u8 Local_u8Username10 [7] = "8001000" ;

	u8 Local_u8Password1  [7] = "1234512" ;
	u8 Local_u8Password2  [7] = "1259876" ;
	u8 Local_u8Password3  [7] = "0397563" ;
	u8 Local_u8Password4  [7] = "1497852" ;
	u8 Local_u8Password5  [7] = "0397584" ;
	u8 Local_u8Password6  [7] = "3145987" ;
	u8 Local_u8Password7  [7] = "1020304" ;
	u8 Local_u8Password8  [7] = "7080908" ;
	u8 Local_u8Password9  [7] = "9050804" ;
	u8 Local_u8Password10 [7] = "3456785" ;

	u8 Local_u8GetPass = 0 ;
	u8 Local_u8GetUser = 0 ;

	u8 Local_u8SaveUser[7]  ;
	u8 Local_u8SavePass[7]  ;
	for( int i = 0 ; i < 7 ; i++)
	{
		Local_u8GetUser =MUART_u8ReadByteSyncBlocking();
		Local_u8SaveUser[i]=Local_u8GetUser;
	}

	for( int i = 0 ; i < 7 ; i++)
	{
		Local_u8GetPass =MUART_u8ReadByteSyncBlocking();
		Local_u8SavePass[i]=Local_u8GetPass;
	}
	for(int j = 0 ; j< 7 ;j++)
	{
		if( ((Local_u8SaveUser[j] ==Local_u8Username1[j]) && (Local_u8SavePass[j] == Local_u8Password1[j])) ||
			((Local_u8SaveUser[j] ==Local_u8Username2[j]) && (Local_u8SavePass[j] == Local_u8Password2[j])) ||
			((Local_u8SaveUser[j] ==Local_u8Username3[j]) && (Local_u8SavePass[j] == Local_u8Password3[j])) ||
			((Local_u8SaveUser[j] ==Local_u8Username4[j]) && (Local_u8SavePass[j] == Local_u8Password4[j])) ||
			((Local_u8SaveUser[j] ==Local_u8Username5[j]) && (Local_u8SavePass[j] == Local_u8Password5[j])) ||
			((Local_u8SaveUser[j] ==Local_u8Username6[j]) && (Local_u8SavePass[j] == Local_u8Password6[j])) ||
			((Local_u8SaveUser[j] ==Local_u8Username7[j]) && (Local_u8SavePass[j] == Local_u8Password7[j])) ||
			((Local_u8SaveUser[j] ==Local_u8Username8[j]) && (Local_u8SavePass[j] == Local_u8Password8[j])) ||
			((Local_u8SaveUser[j] ==Local_u8Username9[j]) && (Local_u8SavePass[j] == Local_u8Password9[j])) ||
			((Local_u8SaveUser[j] ==Local_u8Username10[j]) && (Local_u8SavePass[j] == Local_u8Password10[j])) )
		{
			counter++ ;
		}
	}

	if(counter == 7)
	{

		Local_u8Flag = 1 ;
	}

	return Local_u8Flag ;

}

void HOME_LEDCONROL()
{
	MTIMER1_voidInit();
	while(1)
		{
		u8 Loca_u8GetValue = 0 ;
		Loca_u8GetValue =MUART_u8ReadByteSyncBlocking();
		if(Loca_u8GetValue == '1')
		{

			MDIO_voidSetPinStatus(PORTA , PIN0 , DIO_SET);
			MDIO_voidSetPinStatus(PORTA , PIN1 , DIO_SET);
		}
		else if(Loca_u8GetValue == '0')
		{
			MDIO_voidSetPinStatus(PORTA , PIN0 , DIO_RESET);
			MDIO_voidSetPinStatus(PORTA , PIN1 , DIO_RESET);
		}
		else if(Loca_u8GetValue == 'm')
		{
			HSERVO_voidOpenTheDoor();
		}
		else if(Loca_u8GetValue == 'q')
		{
			HSERVO_voidCloseTheDoor();
		}

		}


}



int main()
{
	u8 Check_Data = 0;

	Check_Data =CheckUserAndPass();

	MDIO_voidInit();
	MUART_voidInit();

	if(Check_Data == 1)
		{
			MUART_voidSendStringSyncNonBlocking("d");
			HOME_LEDCONROL();
		}
	else{

		MUART_voidSendStringSyncNonBlocking("n");
		//Open Buzz
		MDIO_voidSetPinStatus(PORTB,PIN0,DIO_SET);
		_delay_ms(500);
		MDIO_voidSetPinStatus(PORTB,PIN0,DIO_RESET);
		for(int i = 0 ; i < 2 ;i++)
		{
			Check_Data =CheckUserAndPass();
			if(Check_Data == 1)
			{
				MUART_voidSendStringSyncNonBlocking("d");
				HOME_LEDCONROL();
			}
			else{
				//Open Buzz
				MDIO_voidSetPinStatus(PORTB,PIN0,DIO_SET);
				_delay_ms(500);
				MDIO_voidSetPinStatus(PORTB,PIN0,DIO_RESET);
				if(i<1)
				{
					MUART_voidSendStringSyncNonBlocking("n");
				}
			}
		}
		//Open Buzz
		MDIO_voidSetPinStatus(PORTB,PIN0,DIO_SET);
		_delay_ms(1000);
		MDIO_voidSetPinStatus(PORTB,PIN0,DIO_RESET);
		//Send Close Screen Bit
		MUART_voidSendStringSyncNonBlocking("o");

	}

}



