/*
 * DAC_Program.c
 *
 *  Created on: Aug 20, 2023
 *      Author: a-m-m
 */


#include "song2.h"
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "DAC_Interface.h"
#include "DAC_Private.h"
#include "DAC_Config.h"
#include "GPIO.Interface.h"
#include "SYSTICK_INTERFACE.h"

static u32 MDACKu32track_counter=0;
void MDAC_voidInit(void){

	/*Init the GPIO PINS*/
		GPIO_u8SetPinMode		(MDAC_PIN0,GPIO_u8_PinModeOutput);
		GPIO_u8SetPinOutputType	(MDAC_PIN0,GPIO_u8_OP_PP);
		GPIO_u8ChangePinOutMode	(MDAC_PIN0,GPIO_u8_OP_MODE_RESET);
		 GPIO_u8SetPinOutputSpeed(MDAC_PIN0,GPIO_u8_MODE_HS);

		GPIO_u8SetPinMode		(MDAC_PIN1,GPIO_u8_PinModeOutput);
		GPIO_u8SetPinOutputType	(MDAC_PIN1,GPIO_u8_OP_PP);
		GPIO_u8ChangePinOutMode	(MDAC_PIN1,GPIO_u8_OP_MODE_RESET);
		 GPIO_u8SetPinOutputSpeed(MDAC_PIN1,GPIO_u8_MODE_HS);


		GPIO_u8SetPinMode		(MDAC_PIN2,GPIO_u8_PinModeOutput);
		GPIO_u8SetPinOutputType	(MDAC_PIN2,GPIO_u8_OP_PP);
		GPIO_u8ChangePinOutMode	(MDAC_PIN2,GPIO_u8_OP_MODE_RESET);
		 GPIO_u8SetPinOutputSpeed(MDAC_PIN2,GPIO_u8_MODE_HS);


		GPIO_u8SetPinMode		(MDAC_PIN3,GPIO_u8_PinModeOutput);
		GPIO_u8SetPinOutputType	(MDAC_PIN3,GPIO_u8_OP_PP);
		GPIO_u8ChangePinOutMode	(MDAC_PIN3,GPIO_u8_OP_MODE_RESET);
		 GPIO_u8SetPinOutputSpeed(MDAC_PIN3,GPIO_u8_MODE_HS);


		GPIO_u8SetPinMode		(MDAC_PIN4,GPIO_u8_PinModeOutput);
		GPIO_u8SetPinOutputType	(MDAC_PIN4,GPIO_u8_OP_PP);
		GPIO_u8ChangePinOutMode	(MDAC_PIN4,GPIO_u8_OP_MODE_RESET);
		 GPIO_u8SetPinOutputSpeed(MDAC_PIN4,GPIO_u8_MODE_HS);


		GPIO_u8SetPinMode		(MDAC_PIN5,GPIO_u8_PinModeOutput);
		GPIO_u8SetPinOutputType	(MDAC_PIN5,GPIO_u8_OP_PP);
		GPIO_u8ChangePinOutMode	(MDAC_PIN5,GPIO_u8_OP_MODE_RESET);
		 GPIO_u8SetPinOutputSpeed(MDAC_PIN5,GPIO_u8_MODE_HS);


		GPIO_u8SetPinMode		(MDAC_PIN6,GPIO_u8_PinModeOutput);
		GPIO_u8SetPinOutputType	(MDAC_PIN6,GPIO_u8_OP_PP);
		GPIO_u8ChangePinOutMode	(MDAC_PIN6,GPIO_u8_OP_MODE_RESET);
		 GPIO_u8SetPinOutputSpeed(MDAC_PIN6,GPIO_u8_MODE_HS);


		GPIO_u8SetPinMode		(MDAC_PIN7,GPIO_u8_PinModeOutput);
		GPIO_u8SetPinOutputType	(MDAC_PIN7,GPIO_u8_OP_PP);
		GPIO_u8ChangePinOutMode	(MDAC_PIN7,GPIO_u8_OP_MODE_RESET);
		 GPIO_u8SetPinOutputSpeed(MDAC_PIN7,GPIO_u8_MODE_HS);


		/*init the systick timer*/
		STK_void_Init();
}

void MDAC_voidRun(void){
	STK_voidSetIntervalPeriodic(250,MDAC_voidCallback);

}

static void MDAC_voidCallback(void){

	GPIO_u8ChangePinOutMode	(MDAC_PIN0,GET_BIT(song_raw[MDACKu32track_counter],0));
	GPIO_u8ChangePinOutMode	(MDAC_PIN1,GET_BIT(song_raw[MDACKu32track_counter],1));
	GPIO_u8ChangePinOutMode	(MDAC_PIN2,GET_BIT(song_raw[MDACKu32track_counter],2));
	GPIO_u8ChangePinOutMode	(MDAC_PIN3,GET_BIT(song_raw[MDACKu32track_counter],3));
	GPIO_u8ChangePinOutMode	(MDAC_PIN4,GET_BIT(song_raw[MDACKu32track_counter],4));
	GPIO_u8ChangePinOutMode	(MDAC_PIN5,GET_BIT(song_raw[MDACKu32track_counter],5));
	GPIO_u8ChangePinOutMode	(MDAC_PIN6,GET_BIT(song_raw[MDACKu32track_counter],6));
	GPIO_u8ChangePinOutMode	(MDAC_PIN7,GET_BIT(song_raw[MDACKu32track_counter],7));
	MDACKu32track_counter++;
	if(MDACKu32track_counter>=SONG_LEN){
		MDACKu32track_counter=0;
	}

}


