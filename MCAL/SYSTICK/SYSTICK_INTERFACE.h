/*
 * SYSTICK_INTERFACE.h
 *	SWC:
 *	Version:
 *  Created on: Jun 5, 2023
 *      Author: Abdallah ragab
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

void STK_void_Init();

void STK_voidSetBusyWait(u32 Copyu32NoCounts);

void STK_voidSetIntervalSingle(u32 Copyu32NoCounts,void (*Lpf)(void));
void STK_voidSetIntervalPeriodic(u32 Copyu32NoCounts,void (*Lpf)(void));
void STK_voidGetRemainingTime(u32* Remaining_u32Time);
void STK_voidGetElapsedTime(u32* Elapsed_u32Time);



#endif /* SYSTICK_INTERFACE_H_ */
