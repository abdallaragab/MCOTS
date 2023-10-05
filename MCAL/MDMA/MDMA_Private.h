/*
  * File:  MDMA_Private.h 
 *	SWC:    MDMA
 *	Version: 1.0 
 *  Created on: 27-08-2023 
 *  Author: Abdallah Ragab 
 */
#ifndef MDMA_PRIVATE
#define MDMA_PRIVATE


typedef struct{
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;

}DMACHANNEL_t;

typedef struct{
	volatile u32 DMA_LISR   ;
	volatile u32 DMA_HISR   ;
	volatile u32 DMA_LIFCR  ;
	volatile u32 DMA_HIFCR  ;
	volatile DMACHANNEL_t DMACHANNEL[8];

}DMA_T;


#define DMA_BASE_ADDRESS	0x40026000

#define DMA1				((volatile DMA_T*)DMA_BASE_ADDRESS)
#define DMA2				((volatile DMA_T*)0x40026400)

#endif // MDMA_PRIVATE
