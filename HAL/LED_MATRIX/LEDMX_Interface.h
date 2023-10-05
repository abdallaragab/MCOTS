/*
 * LEDMX_Interface.h
 *	SWC:
 *	Version:
 *  Created on: Jun 5, 2023
 *      Author: Abdallah ragab
 */

#ifndef LEDMX_INTERFACE_H_
#define LEDMX_INTERFACE_H_

void LEDMX_voidInit(void);

void LEDMX_voidDisplay(u8* Copy_u8Frame);

void LEDMX_voidDisplayLine(u8* Copy_u8Frame,u8 Copy_u8Length,u32 Copy_u32MoveDelay);


void LEDMX_voidClearDisplay(void);

#endif /* LEDMX_INTERFACE_H_ */
