/*
 * File:  LEDMX_Program.c
 *	SWC:    LEDMX
 *	Version: 1.0 
 *  Created on: 31-08-2023 
 *  Author: Abdallah Ragab 
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"
#include "../../MCAL/GPIO/GPIO.Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_INTERFACE.h"


#include "LEDMX_Interface.h"
#include "LEDMX_Config.h"
#include "LEDMX_Private.h"

#define LEDMX_ROW_DELAY		8000

void LEDMX_voidInit(void) {

	GPIO_u8SetPinMode(LEDMX_Column1, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column2, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column3, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column4, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column5, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column6, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column7, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column8, GPIO_u8_PinModeOutput);

	GPIO_u8SetPinMode(LEDMX_ROW1, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW2, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW3, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW4, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW5, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW6, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW7, GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW8, GPIO_u8_PinModeOutput);

	GPIO_u8SetPinOutputType(LEDMX_ROW1, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW2, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW3, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW4, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW5, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW6, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW7, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW8, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column1, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column2, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column3, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column4, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column5, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column6, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column7, GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column8, GPIO_u8_OP_PP);

	GPIO_u8SetPinOutputSpeed(LEDMX_ROW1, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW2, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW3, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW4, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW5, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW6, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW7, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW8, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column1, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column2, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column3, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column4, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column5, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column6, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column7, GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column8, GPIO_u8_MODE_MS);

}

void LEDMX_voidClearDisplay(void){
	LEDMX_voidClearColumns();
	LEDMX_voidClearRows();
}

static void LEDMX_voidClearColumns(){
		GPIO_u8ChangePinOutMode(LEDMX_Column1,GPIO_u8_OP_MODE_SET);
		GPIO_u8ChangePinOutMode(LEDMX_Column2,GPIO_u8_OP_MODE_SET);
		GPIO_u8ChangePinOutMode(LEDMX_Column3,GPIO_u8_OP_MODE_SET);
		GPIO_u8ChangePinOutMode(LEDMX_Column4,GPIO_u8_OP_MODE_SET);
		GPIO_u8ChangePinOutMode(LEDMX_Column5,GPIO_u8_OP_MODE_SET);
		GPIO_u8ChangePinOutMode(LEDMX_Column6,GPIO_u8_OP_MODE_SET);
		GPIO_u8ChangePinOutMode(LEDMX_Column7,GPIO_u8_OP_MODE_SET);
		GPIO_u8ChangePinOutMode(LEDMX_Column8,GPIO_u8_OP_MODE_SET);
}

static void LEDMX_voidClearRows(){
	GPIO_u8ChangePinOutMode(LEDMX_ROW1,GPIO_u8_OP_MODE_RESET);
	GPIO_u8ChangePinOutMode(LEDMX_ROW2,GPIO_u8_OP_MODE_RESET);
	GPIO_u8ChangePinOutMode(LEDMX_ROW3,GPIO_u8_OP_MODE_RESET);
	GPIO_u8ChangePinOutMode(LEDMX_ROW4,GPIO_u8_OP_MODE_RESET);
	GPIO_u8ChangePinOutMode(LEDMX_ROW5,GPIO_u8_OP_MODE_RESET);
    GPIO_u8ChangePinOutMode(LEDMX_ROW6,GPIO_u8_OP_MODE_RESET);
  	GPIO_u8ChangePinOutMode(LEDMX_ROW7,GPIO_u8_OP_MODE_RESET);
    GPIO_u8ChangePinOutMode(LEDMX_ROW8,GPIO_u8_OP_MODE_RESET);


}


void LEDMX_voidDisplay(u8* Copy_u8Frame){
	LEDMX_voidClearDisplay();
	//LEDMX_voidClearColumns();
	GPIO_u8ChangePinOutMode(LEDMX_Column1,GPIO_u8_OP_MODE_RESET);
	LEDMX_voidSetRowValue(Copy_u8Frame[0]);
	STK_voidSetBusyWait(LEDMX_ROW_DELAY);

	LEDMX_voidClearColumns();
	GPIO_u8ChangePinOutMode(LEDMX_Column2,GPIO_u8_OP_MODE_RESET);
	LEDMX_voidSetRowValue(Copy_u8Frame[1]);
	STK_voidSetBusyWait(LEDMX_ROW_DELAY);


	LEDMX_voidClearColumns();
	GPIO_u8ChangePinOutMode(LEDMX_Column3,GPIO_u8_OP_MODE_RESET);
	LEDMX_voidSetRowValue(Copy_u8Frame[2]);
	STK_voidSetBusyWait(LEDMX_ROW_DELAY);



	LEDMX_voidClearColumns();
	GPIO_u8ChangePinOutMode(LEDMX_Column4,GPIO_u8_OP_MODE_RESET);
	LEDMX_voidSetRowValue(Copy_u8Frame[3]);
	STK_voidSetBusyWait(LEDMX_ROW_DELAY);

	LEDMX_voidClearColumns();
	GPIO_u8ChangePinOutMode(LEDMX_Column5,GPIO_u8_OP_MODE_RESET);
	LEDMX_voidSetRowValue(Copy_u8Frame[4]);
	STK_voidSetBusyWait(LEDMX_ROW_DELAY);

	LEDMX_voidClearColumns();
	GPIO_u8ChangePinOutMode(LEDMX_Column6,GPIO_u8_OP_MODE_RESET);
	LEDMX_voidSetRowValue(Copy_u8Frame[5]);
	STK_voidSetBusyWait(LEDMX_ROW_DELAY);

	LEDMX_voidClearColumns();
	GPIO_u8ChangePinOutMode(LEDMX_Column7,GPIO_u8_OP_MODE_RESET);
	LEDMX_voidSetRowValue(Copy_u8Frame[6]);
	STK_voidSetBusyWait(LEDMX_ROW_DELAY);

	LEDMX_voidClearColumns();
	GPIO_u8ChangePinOutMode(LEDMX_Column8,GPIO_u8_OP_MODE_RESET);
	LEDMX_voidSetRowValue(Copy_u8Frame[7]);
	STK_voidSetBusyWait(LEDMX_ROW_DELAY);


}
static void LEDMX_voidSetRowValue(u8 Copy_u8RowValue){
	GPIO_u8ChangePinOutMode(LEDMX_ROW1,GET_BIT(Copy_u8RowValue,0));
	GPIO_u8ChangePinOutMode(LEDMX_ROW2,GET_BIT(Copy_u8RowValue,1));
	GPIO_u8ChangePinOutMode(LEDMX_ROW3,GET_BIT(Copy_u8RowValue,2));
	GPIO_u8ChangePinOutMode(LEDMX_ROW4,GET_BIT(Copy_u8RowValue,3));
	GPIO_u8ChangePinOutMode(LEDMX_ROW5,GET_BIT(Copy_u8RowValue,4));
	GPIO_u8ChangePinOutMode(LEDMX_ROW6,GET_BIT(Copy_u8RowValue,5));
	GPIO_u8ChangePinOutMode(LEDMX_ROW7,GET_BIT(Copy_u8RowValue,6));
	GPIO_u8ChangePinOutMode(LEDMX_ROW8,GET_BIT(Copy_u8RowValue,7));
}

