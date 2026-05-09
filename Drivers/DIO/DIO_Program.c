/*
 * DIO_Program.c
 *
 *  Created on: Apr 15, 2023
 *      Author: abdelrahmanhossam
 */


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/DIO/DIO_Private.h"
#include "../include/MCAL/DIO/DIO_Cfg.h"



void MDIO_voidInit(void)
{
	DDRA_REG = CONC_BIT(PORTA_PIN7_DIRECTION,PORTA_PIN6_DIRECTION,PORTA_PIN5_DIRECTION,
						PORTA_PIN4_DIRECTION,PORTA_PIN3_DIRECTION,PORTA_PIN2_DIRECTION,
						PORTA_PIN1_DIRECTION,PORTA_PIN0_DIRECTION);

	DDRB_REG = CONC_BIT(PORTB_PIN7_DIRECTION,PORTB_PIN6_DIRECTION,PORTB_PIN5_DIRECTION,
						PORTB_PIN4_DIRECTION,PORTB_PIN3_DIRECTION,PORTB_PIN2_DIRECTION,
						PORTB_PIN1_DIRECTION,PORTB_PIN0_DIRECTION);

	DDRC_REG = CONC_BIT(PORTC_PIN7_DIRECTION,PORTC_PIN6_DIRECTION,PORTC_PIN5_DIRECTION,
						PORTC_PIN4_DIRECTION,PORTC_PIN3_DIRECTION,PORTC_PIN2_DIRECTION,
						PORTC_PIN1_DIRECTION,PORTC_PIN0_DIRECTION);

	DDRD_REG = CONC_BIT(PORTD_PIN7_DIRECTION,PORTD_PIN6_DIRECTION,PORTD_PIN5_DIRECTION,
						PORTD_PIN4_DIRECTION,PORTD_PIN3_DIRECTION,PORTD_PIN2_DIRECTION,
						PORTD_PIN1_DIRECTION,PORTD_PIN0_DIRECTION);

	PORTA_REG = CONC_BIT(PORTA_PIN7_VALUE,PORTA_PIN6_VALUE,PORTA_PIN5_VALUE,
					  	 PORTA_PIN4_VALUE,PORTA_PIN3_VALUE,PORTA_PIN2_VALUE,
						 PORTA_PIN1_VALUE,PORTA_PIN0_VALUE);

	PORTB_REG = CONC_BIT(PORTB_PIN7_VALUE,PORTB_PIN6_VALUE,PORTB_PIN5_VALUE,
						 PORTB_PIN4_VALUE,PORTB_PIN3_VALUE,PORTB_PIN2_VALUE,
						 PORTB_PIN1_VALUE,PORTB_PIN0_VALUE);

	PORTC_REG = CONC_BIT(PORTC_PIN7_VALUE,PORTC_PIN6_VALUE,PORTC_PIN5_VALUE,
						 PORTC_PIN4_VALUE,PORTC_PIN3_VALUE,PORTC_PIN2_VALUE,
						 PORTC_PIN1_VALUE,PORTC_PIN0_VALUE);

	PORTD_REG = CONC_BIT(PORTD_PIN7_VALUE,PORTD_PIN6_VALUE,PORTD_PIN5_VALUE,
						 PORTD_PIN4_VALUE,PORTD_PIN3_VALUE,PORTD_PIN2_VALUE,
						 PORTD_PIN1_VALUE,PORTD_PIN0_VALUE);
}


void MDIO_voidSetPinDirection (DIO_PORTS A_DIOPort,DIO_PINS A_DIOPinNo, PIN_DIRECTION A_PinDirection )
{
	// Input validation
	if ((A_DIOPort<=PORTD) && (A_DIOPinNo <=PIN7) && (A_PinDirection<=DIO_OUTPUT))
	{
		switch (A_DIOPort)
		{
		case PORTA:
					switch (A_PinDirection)
					{
					case DIO_OUTPUT: SET_BIT(DDRA_REG,A_DIOPinNo); break;
					case DIO_INUPT : CLR_BIT(DDRA_REG,A_DIOPinNo); break;
					}
					break;
		case PORTB:
					switch (A_PinDirection)
					{
					case DIO_OUTPUT: SET_BIT(DDRB_REG,A_DIOPinNo); break;
					case DIO_INUPT : CLR_BIT(DDRB_REG,A_DIOPinNo); break;
					}
					break;
		case PORTC:
					switch (A_PinDirection)
					{
					case DIO_OUTPUT: SET_BIT(DDRC_REG,A_DIOPinNo); break;
					case DIO_INUPT : CLR_BIT(DDRC_REG,A_DIOPinNo); break;
					}
					break;
		case PORTD:
					switch (A_PinDirection)
					{
					case DIO_OUTPUT: SET_BIT(DDRD_REG,A_DIOPinNo); break;
					case DIO_INUPT : CLR_BIT(DDRD_REG,A_DIOPinNo); break;
					}
					break;
		}
	}
}

void MDIO_voidSetPinValue (DIO_PORTS A_DIOPort,DIO_PINS A_DIOPinNo, DIO_VALUE A_PinValue )
{
	// Input validation
	if ((A_DIOPort<=PORTD) && (A_DIOPinNo <=PIN7) && (A_PinValue<=DIO_SET))
	{
		switch (A_DIOPort)
		{
		case PORTA:
					switch (A_PinValue)
					{
					case DIO_SET:    SET_BIT(PORTA_REG,A_DIOPinNo); break;
					case DIO_RESET : CLR_BIT(PORTA_REG,A_DIOPinNo); break;
					}
					break;
		case PORTB:
					switch (A_PinValue)
					{
					case DIO_SET:    SET_BIT(PORTB_REG,A_DIOPinNo); break;
					case DIO_RESET : CLR_BIT(PORTB_REG,A_DIOPinNo); break;
					}
					break;
		case PORTC:
					switch (A_PinValue)
					{
					case DIO_SET:    SET_BIT(PORTC_REG,A_DIOPinNo); break;
					case DIO_RESET : CLR_BIT(PORTC_REG,A_DIOPinNo); break;
					}
					break;
		case PORTD:
					switch (A_PinValue)
					{
					case DIO_SET:    SET_BIT(PORTD_REG,A_DIOPinNo); break;
					case DIO_RESET : CLR_BIT(PORTD_REG,A_DIOPinNo); break;
					}
					break;
		}
	}
}

void MDIO_voidTogglePinValue (DIO_PORTS A_DIOPort,DIO_PINS A_DIOPinNo)
{
	// Input validation
	if ((A_DIOPort<=PORTD) && (A_DIOPinNo <=PIN7))
	{
		switch (A_DIOPort)
		{
		case PORTA:
					TOGGLE_BIT(PORTA_REG,A_DIOPinNo);
					break;
		case PORTB:
					TOGGLE_BIT(PORTB_REG,A_DIOPinNo);
					break;
		case PORTC:
					TOGGLE_BIT(PORTC_REG,A_DIOPinNo);
					break;
		case PORTD:
					TOGGLE_BIT(PORTD_REG,A_DIOPinNo);
					break;
		}
	}
}


DIO_VALUE MDIO_DIO_VALUEGetPinValue (DIO_PORTS A_DIOPort,DIO_PINS A_DIOPinNo)
{
	DIO_VALUE PinRead= 255;
	// Input validation
	if ((A_DIOPort<=PORTD) && (A_DIOPinNo <=PIN7))
	{
		switch (A_DIOPort)
		{
		case PORTA:
					PinRead= GET_BIT(PINA_REG,A_DIOPinNo);
					break;
		case PORTB:
					PinRead= GET_BIT(PINB_REG,A_DIOPinNo);
					break;
		case PORTC:
					PinRead= GET_BIT(PINC_REG,A_DIOPinNo);
					break;
		case PORTD:
					PinRead= GET_BIT(PIND_REG,A_DIOPinNo);
					break;
		}
	}
	return PinRead;
}

// PORTA,0b01011100
void MDIO_voidSetPortDirection (DIO_PORTS A_DIOPort, u8 A_PortDirection)
{
	if ((A_DIOPort<=PORTD) )
	{
		switch (A_DIOPort)
		{
		case PORTA:
					DDRA_REG = A_PortDirection;
					break;
		case PORTB:
					DDRB_REG = A_PortDirection;
					break;
		case PORTC:
					DDRC_REG = A_PortDirection;
					break;
		case PORTD:
					DDRD_REG = A_PortDirection;
					break;
		}
	}
}

void MDIO_voidSetPortValue (DIO_PORTS A_DIOPort, u8 A_PortValue)
{
	if ((A_DIOPort<=PORTD) )
	{
		switch (A_DIOPort)
		{
		case PORTA:
					PORTA_REG = A_PortValue;
					break;
		case PORTB:
					PORTB_REG = A_PortValue;
					break;
		case PORTC:
					PORTC_REG = A_PortValue;
					break;
		case PORTD:
					PORTD_REG = A_PortValue;
					break;
		}
	}
}
