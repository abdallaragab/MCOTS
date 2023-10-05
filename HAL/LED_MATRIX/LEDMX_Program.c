/*
 * LEDMX_Program.c
 *	SWC:
 *	Version:
 *  Created on: Jun 5, 2023
 *      Author: Abdallah ragab
 */


#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "GPIO.Interface.h"
#include "SYSTICK_INTERFACE.h"

#include "LEDMX_Private.h"
#include "LEDMX_Interface.h"
#include "LEDMX_Config.h"

static u32 LEDMX_FrameNum=0;

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
static void LEDMX_voidSetColValue(u8 Copy_u8ColValue){
	GPIO_u8ChangePinOutMode(LEDMX_Column1,!GET_BIT(Copy_u8ColValue,0));
	GPIO_u8ChangePinOutMode(LEDMX_Column2,!GET_BIT(Copy_u8ColValue,1));
	GPIO_u8ChangePinOutMode(LEDMX_Column3,!GET_BIT(Copy_u8ColValue,2));
	GPIO_u8ChangePinOutMode(LEDMX_Column4,!GET_BIT(Copy_u8ColValue,3));
	GPIO_u8ChangePinOutMode(LEDMX_Column5,!GET_BIT(Copy_u8ColValue,4));
	GPIO_u8ChangePinOutMode(LEDMX_Column6,!GET_BIT(Copy_u8ColValue,5));
	GPIO_u8ChangePinOutMode(LEDMX_Column7,!GET_BIT(Copy_u8ColValue,6));
	GPIO_u8ChangePinOutMode(LEDMX_Column8,!GET_BIT(Copy_u8ColValue,7));
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

void LEDMX_voidDisplayLine(u8* Copy_u8Frame,u8 Copy_u8Length,u32 Copy_u32MoveDelay){
	u8 strs[8];
	u32 temp_lcdFrame=0;
	while(temp_lcdFrame<Copy_u8Length){
	for(u8 temp_counter3=0;temp_counter3<8;temp_counter3++){
					strs[temp_counter3]=Copy_u8Frame[(temp_lcdFrame+temp_counter3)%Copy_u8Length];
				}

				//LEDMX_voidDisplay(ab+8);
				for(u8 temp_counter=0;temp_counter<Copy_u32MoveDelay;temp_counter++)
				{

					//LEDMX_voidDisplay(&strm[0]+(temp_lcdFrame%8));
					LEDMX_voidDisplay(&strs[0]);

				}
				temp_lcdFrame++;

	}
}


void LEDMX_voidDisplay(u8* Copy_u8Frame){

	//LEDMX_voidClearDisplay();

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[0]);
	GPIO_u8ChangePinOutMode(LEDMX_Column1,GPIO_u8_OP_MODE_RESET);
	STK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[1]);
	GPIO_u8ChangePinOutMode(LEDMX_Column2,GPIO_u8_OP_MODE_RESET);
	STK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[2]);
	GPIO_u8ChangePinOutMode(LEDMX_Column3,GPIO_u8_OP_MODE_RESET);
	STK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[3]);
	GPIO_u8ChangePinOutMode(LEDMX_Column4,GPIO_u8_OP_MODE_RESET);
	STK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[4]);
	GPIO_u8ChangePinOutMode(LEDMX_Column5,GPIO_u8_OP_MODE_RESET);
	STK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[5]);
	GPIO_u8ChangePinOutMode(LEDMX_Column6,GPIO_u8_OP_MODE_RESET);
	STK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[6]);
	GPIO_u8ChangePinOutMode(LEDMX_Column7,GPIO_u8_OP_MODE_RESET);
	STK_voidSetBusyWait(2500);

	LEDMX_voidClearColumns();
	LEDMX_voidSetRowValue(Copy_u8Frame[7]);
	GPIO_u8ChangePinOutMode(LEDMX_Column8,GPIO_u8_OP_MODE_RESET);
	STK_voidSetBusyWait(2500);




}


void LEDMX_voidInit(){
	GPIO_u8SetPinMode(LEDMX_ROW1   ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW2   ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW3   ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW4   ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW5   ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW6   ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW7   ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_ROW8   ,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column1,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column2,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column3,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column4,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column5,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column6,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column7,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinMode(LEDMX_Column8,GPIO_u8_PinModeOutput);

	GPIO_u8SetPinOutputType(LEDMX_ROW1   ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW2   ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW3   ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW4   ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW5   ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW6   ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW7   ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_ROW8   ,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column1,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column2,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column3,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column4,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column5,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column6,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column7,GPIO_u8_OP_PP);
	GPIO_u8SetPinOutputType(LEDMX_Column8,GPIO_u8_OP_PP);


	GPIO_u8SetPinOutputSpeed(LEDMX_ROW1   ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW2   ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW3   ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW4   ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW5   ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW6   ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW7   ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_ROW8   ,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column1,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column2,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column3,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column4,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column5,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column6,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column7,GPIO_u8_MODE_MS);
	GPIO_u8SetPinOutputSpeed(LEDMX_Column8,GPIO_u8_MODE_MS);

	LEDMX_voidClearDisplay();


}







void LEDMX_voidClearDisplay(void){
	LEDMX_voidClearColumns();
	LEDMX_voidClearRows();

}





