/*
  * File:  SPI_Private.h 
 *	SWC:    SPI
 *	Version: 1.0 
 *  Created on: 19-06-2023 
 *  Author: Abdallah Ragab 
 */
#ifndef SPI_PRIVATE
#define SPI_PRIVATE

typedef  struct{
	volatile u32 SPI_CR1     ;
	volatile u32 SPI_CR2     ;
	volatile u32 SPI_SR      ;
	volatile u32 SPI_DR      ;
	volatile u32 SPI_CRCPR   ;
	volatile u32 SPI_RXCRCR  ;
	volatile u32 SPI_TXCRCR  ;
	volatile u32 SPI_I2SCFGR ;
	volatile u32 SPI_I2SPR	;
}SPI_t;

#define SPI	     ((volatile SPI_t*) (0x40013000))

#endif // SPI_PRIVATE
