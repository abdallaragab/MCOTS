/*
  * File:  TFT_Program.c 
 *	SWC:    TFT
 *	Version: 1.0 
 *  Created on: 27-06-2023 
 *  Author: Abdallah Ragab 
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"
#include "../../MCAL/RCC/RCC_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_INTERFACE.h"
#include "../../MCAL/GPIO/GPIO.Interface.h"
#include "../../MCAL/SPI/SPI_Interface.h"
#include "TFT_Interface.h"
#include "TFT_Private.h"
#include "TFT_Config.h"



void TFT_voidSendCommand(u8 copyu8Command){
	u8 temp[9]={0};
	GPIO_u8DirectSetPinOutMode(TFT_WRX,GPIO_u8_OP_MODE_RESET);
	SPI_voidTrancieve(copyu8Command,temp);
	STK_voidSetBusyWait(20);

}
void TFT_voidSendData( u8 copyu8Data){
	u8 temp[9]={0};
	GPIO_u8DirectSetPinOutMode(TFT_WRX,GPIO_u8_OP_MODE_SET);
	SPI_voidTrancieve(copyu8Data,temp);
	STK_voidSetBusyWait(20);

}
void TFT_voidInit(void) {
	/*Clock phase 1 , Clock polarity is 1*/
	SPI_voidInit(SPI_MODE_MASTER);
	TFT_voidSendReset();

	/*Command mode*/
	GPIO_u8DirectSetPinOutMode(TFT_CSX, GPIO_u8_OP_MODE_RESET);

	/*sleep put command*/
	TFT_voidSendCommand(0x11);

	STK_voidSetBusyWait(400000);
	//color mode command
	TFT_voidSendCommand(0x3A);

	/* 565RGB */
	TFT_voidSendData(0x05);


	TFT_voidSendCommand(0x29);
	STK_voidSetBusyWait(40);
}
static void TFT_voidSendReset2(void){

	GPIO_u8DirectSetPinOutMode(TFT_RES,GPIO_u8_OP_MODE_SET);
	STK_voidSetBusyWait(1000);
	GPIO_u8DirectSetPinOutMode(TFT_RES,GPIO_u8_OP_MODE_RESET);
	STK_voidSetBusyWait(10);
	GPIO_u8DirectSetPinOutMode(TFT_RES,GPIO_u8_OP_MODE_SET);
	STK_voidSetBusyWait(1000);

	GPIO_u8DirectSetPinOutMode(TFT_RES,GPIO_u8_OP_MODE_RESET);
	STK_voidSetBusyWait(100000);
	GPIO_u8DirectSetPinOutMode(TFT_RES,GPIO_u8_OP_MODE_SET);
	STK_voidSetBusyWait(0xfffff);



}

static void TFT_voidSendReset(void){

	GPIO_u8DirectSetPinOutMode(TFT_RES,GPIO_u8_OP_MODE_SET);
	STK_voidSetBusyWait(1000);
//	GPIO_u8DirectSetPinOutMode(TFT_RES,GPIO_u8_OP_MODE_RESET);
//	STK_voidSetBusyWait(10);
//	GPIO_u8DirectSetPinOutMode(TFT_RES,GPIO_u8_OP_MODE_SET);
//	STK_voidSetBusyWait(1000);

	GPIO_u8DirectSetPinOutMode(TFT_RES,GPIO_u8_OP_MODE_RESET);
	STK_voidSetBusyWait(100);
	GPIO_u8DirectSetPinOutMode(TFT_RES,GPIO_u8_OP_MODE_SET);

	/*wait for 120 ms*/
	STK_voidSetBusyWait(300000);



}
void TFT_DisplayImage(u8 * image_data,u32 length){

	//send CASET command (address set)
	TFT_voidSendCommand(0x2a);
	//1st psrameter  XS[15:8]
	TFT_voidSendData(0x0);
	TFT_voidSendData(0x0);
	TFT_voidSendData(0x0);
	TFT_voidSendData(127);

	TFT_voidSendCommand(0x2b);
	//1st psrameter  XS[15:8]
	TFT_voidSendData(0x0);
	TFT_voidSendData(0x0);
	TFT_voidSendData(0x0);
	TFT_voidSendData(159);

	//MADCTL command (memory access control )
	TFT_voidSendCommand(0x36);
	TFT_voidSendData(0x0);

	//send command for writing to ram
	TFT_voidSendCommand(0x2c);

	for (u32 var = 0; var < length; var++) {
		TFT_voidSendData(image_data[var]);
	}
	TFT_voidSendCommand(0);

}
