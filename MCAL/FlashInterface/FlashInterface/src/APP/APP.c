/*
 * APP.c
 *	SWC:
 *	Version:
 *  Created on: Jun 5, 2023
 *      Author: Abdallah ragab
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATHS.h"
#include "../MCAL/GPIO/GPIO.Interface.h"
#include "../MCAL/RCC/RCC_Interface.h"
#include "../MCAL/SYSTICK/SYSTICK_INTERFACE.h"
#include "../MCAL/MFLASH/MFLASH_Interface.h"
#include "../HAL/LEDMX/LEDMX_Interface.h"

int main() {
	RCC_u8InitSysClk();
	RCC_u8EnablePeripheralClk(RCC_u8_AHB1_BUS,RCC_u8_AHB1ENR_GPIOA);
	RCC_u8EnablePeripheralClk(RCC_u8_AHB1_BUS,RCC_u8_AHB1ENR_GPIOB);

	STK_void_Init();
	u32 NameArr[]={1,2,3,4,5,6,7,8,9};
	MFlash_u8EraseSector(MFLASH_Sector_5);
	MFlash_u8Write(MFLASH_Sector_5_START,NameArr,9);


	GPIO_u8SetPinMode(GPIO_u8PortB,0,GPIO_u8_PinModeOutput);
	GPIO_u8SetPinOutputType(GPIO_u8PortB,0,GPIO_u8_OP_PP);
	GPIO_u8ChangePinOutMode(GPIO_u8PortB,0,GPIO_u8_OP_MODE_SET);
	while (1) {

	}

	return 0;
}

