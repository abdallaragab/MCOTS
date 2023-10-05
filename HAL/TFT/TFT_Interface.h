/*
  * File:  TFT_Interface.h 
 *	SWC:    TFT
 *	Version: 1.0 
 *  Created on: 27-06-2023 
 *  Author: Abdallah Ragab 
 */
#ifndef TFT_INTERFACE
#define TFT_INTERFACE

void TFT_voidSendCommand(u8 copyu8Command);

void TFT_voidInit(void);
void TFT_DisplayImage(u8 * image_data,u32 length);


void TFT_voidSendData( u8 copyu8Data);
#endif // TFT_INTERFACE
