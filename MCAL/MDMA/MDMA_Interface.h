/*
  * File:  MDMA_Interface.h 
 *	SWC:    MDMA
 *	Version: 1.0 
 *  Created on: 27-08-2023 
 *  Author: Abdallah Ragab 
 */
#ifndef MDMA_INTERFACE
#define MDMA_INTERFACE


void MDMA_voidInit(u8 Copy_StreamID);


void MDMA_voidSetAddress(u32* PTRu32SrcAddress,u32* PTRu32DestAddress,u32 Copyu32Length,u8 Copyu8StreamID);


void MDMA_voidClearFlagChannel0(void);
void MDMA_void_CallBack(void(*FPTR)(void));


void MDMA_voidStreamEnable(u8 Copy_StreamID);

#define MDMA_PRIORTY_LOW		0b00
#define MDMA_PRIORTY_MEDIUM		0b01
#define MDMA_PRIORTY_HIGH		0b10
#define MDMA_PRIORTY_VERY_HIGH	0b11










#endif // MDMA_INTERFACE
