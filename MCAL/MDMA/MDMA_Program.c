/*
  * File:  MDMA_Program.c 
 *	SWC:    MDMA
 *	Version: 1.0 
 *  Created on: 27-08-2023 
 *  Author: Abdallah Ragab 
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"
#include "MDMA_Interface.h"
#include "MDMA_Private.h"
#include "MDMA_Config.h"

void(*DMA_pToFunction)(void);

void MDMA_voidInit(u8 Copy_StreamID){

	/*the first step is to Disable DMA before Configuration*/
	//CLEAR_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,0);
	CLEAR_BIT( (DMA2->DMACHANNEL[Copy_StreamID].CR)  ,0);

	/*Second Step is to select the channel*/

	/*select S.W priority  LOW - Medium - High - Very HIgh*/

	SET_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,16);
	SET_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,17);

	/*Set Direction MTM , P2M , M2P*/
	SET_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,7);
	CLEAR_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,6);

	/*select cirural Mode*/
	SET_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,8);

	/*SRC aAnd DIS Increament for both*/
	SET_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,9);
	SET_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,10);


	/*set source Size and destnation size*/
	CLEAR_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,13);
	SET_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,14);

	CLEAR_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,11);
	SET_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,12);

	/*Disable Direct Mode*/
	SET_BIT(DMA2->DMACHANNEL[Copy_StreamID].FCR,2);

	/*use full buffer in circular*/
	SET_BIT(DMA2->DMACHANNEL[Copy_StreamID].FCR,0);
	SET_BIT(DMA2->DMACHANNEL[Copy_StreamID].FCR,1);


	/*Enable Interrupt*/
	DMA2->DMACHANNEL[Copy_StreamID].CR|=(1<<4);



}

void MDMA_voidClearFlagChannel0(void){

	DMA2->DMA_LIFCR|=((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5));

}

void MDMA_void_CallBack(void(*FPTR)(void)){
	DMA_pToFunction=FPTR;
}


void MDMA_voidStreamEnable(u8 Copy_StreamID){
	//MDMA_voidClearFlagChannel0();
	SET_BIT(DMA2->DMACHANNEL[Copy_StreamID].CR,0);
}


void MDMA_voidSetAddress(u32* PTRu32SrcAddress,u32* PTRu32DestAddress,u32 Copyu32Length,u8 Copyu8StreamID){
	DMA2->DMACHANNEL[Copyu8StreamID].PAR=(u32) PTRu32SrcAddress;
	DMA2->DMACHANNEL[Copyu8StreamID].M0AR=(u32)PTRu32DestAddress;
	DMA2->DMACHANNEL[Copyu8StreamID].NDTR=(u32)Copyu32Length;


}


void DMA2_Stream0_IRQHandler(void){
	MDMA_voidClearFlagChannel0();
	if(DMA_pToFunction!=NULL){
	DMA_pToFunction();
	}

}


