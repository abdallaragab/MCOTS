/*
  * File:  SPI_Program.c 
 *	SWC:    SPI
 *	Version: 1.0 
 *  Created on: 19-06-2023 
 *  Author: Abdallah Ragab 
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"
#include "SPI_Config.h"
void SPI_voidInit(u8 Copy_u8MODE){


	if (Copy_u8MODE==SPI_MODE_MASTER) {
		/*
		SET_BIT((SPI->SPI_CR1),2);
		SET_BIT((SPI->SPI_CR1),9);
		SET_BIT((SPI->SPI_CR1),0);


		SET_BIT((SPI->SPI_CR1),6);
		*/
		/* CHPA =1
		 * CHPOL = 1
		 * MSTR
		 * SPI Enable
		 * MSB First
		 * Slave Select By Sw
		 * B74
		 * */
		SPI->SPI_CR1=0x0347;


	} else {
		SET_BIT((SPI->SPI_CR1),0);
		SET_BIT((SPI->SPI_CR1),1);

		/*Slave MOde*/
		CLEAR_BIT((SPI->SPI_CR1),2);

		/*PreScaler 4 */
		SET_BIT((SPI->SPI_CR1),3);
		CLEAR_BIT((SPI->SPI_CR1),4);
		CLEAR_BIT((SPI->SPI_CR1),5);

		/*MSB First*/
		CLEAR_BIT((SPI->SPI_CR1),7);

		/*Recievie and send Mode*/
		CLEAR_BIT((SPI->SPI_CR1),10);

		/*Data Format 8 Bit*/
		CLEAR_BIT((SPI->SPI_CR1),11);

		/*DIsable CRC*/
		CLEAR_BIT((SPI->SPI_CR1),13);

		/*Disable BID MOde*/
		CLEAR_BIT((SPI->SPI_CR1),15);

		SET_BIT((SPI->SPI_CR1),6);

	}
}

void SPI_voidTrancieve(u8 Datau8TransData,u8 * Datau8ReceData){

	while(GET_BIT(SPI->SPI_SR,1)==0);
	SPI->SPI_DR=Datau8TransData;

	while(GET_BIT(SPI->SPI_SR,0)==0);
	*Datau8ReceData=(u8)(SPI->SPI_DR);

}

void SPI_voidReceive(u8 * Datau8ReceData){


	while(GET_BIT(SPI->SPI_SR,0)==0);
	*Datau8ReceData=(u8)(SPI->SPI_DR);

}

void SPI_Send(u8 Datau8TransData){
	while(GET_BIT(SPI->SPI_SR,1)==0);
	SPI->SPI_DR=Datau8TransData;


}

