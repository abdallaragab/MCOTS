/*
  * File:  SPI_Interface.h 
 *	SWC:    SPI
 *	Version: 1.0 
 *  Created on: 19-06-2023 
 *  Author: Abdallah Ragab 
 */
#ifndef SPI_INTERFACE
#define SPI_INTERFACE



void SPI_voidInit(u8 Copy_u8MODE);




void SPI_voidTrancieve(u8 Datau8TransData,u8 * Datau8ReceData);

void SPI_Send(u8 Datau8TransData);

void SPI_voidReceive(u8 * Datau8ReceData);


#define SPI_MODE_MASTER			0
#define SPI_MODE_SLAVE			1
#endif // SPI_INTERFACE
