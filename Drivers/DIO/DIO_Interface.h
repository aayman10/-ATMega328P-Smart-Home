/*
 * DIO_Interface.h
 *
 *  Created on: Apr 15, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

typedef enum{
	DIO_INUPT=0,
	DIO_OUTPUT
}PIN_DIRECTION;

typedef enum{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_PINS;

typedef enum{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD
}DIO_PORTS;


typedef enum{
	DIO_RESET=0,
	DIO_SET,
	DIO_FLOATING=0,
	DIO_PULLUP
}DIO_VALUE;


void MDIO_voidInit(void);
void MDIO_voidSetPinDirection (DIO_PORTS A_DIOPort,DIO_PINS A_DIOPinNo, PIN_DIRECTION A_PinDirection );
void MDIO_voidSetPinValue (DIO_PORTS A_DIOPort,DIO_PINS A_DIOPinNo, DIO_VALUE A_PinValue );
void MDIO_voidTogglePinValue (DIO_PORTS A_DIOPort,DIO_PINS A_DIOPinNo);
DIO_VALUE MDIO_DIO_VALUEGetPinValue (DIO_PORTS A_DIOPort,DIO_PINS A_DIOPinNo);
void MDIO_voidSetPortValue (DIO_PORTS A_DIOPort, u8 A_PortValue);
void MDIO_voidSetPortDirection (DIO_PORTS A_DIOPort, u8 A_PortDirection);

#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
