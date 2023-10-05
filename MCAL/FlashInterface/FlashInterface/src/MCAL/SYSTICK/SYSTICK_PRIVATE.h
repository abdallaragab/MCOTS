/*
 * SYSTICK_PRIVATE.h
 *	SWC:
 *	Version:
 *  Created on: Jun 5, 2023
 *      Author: Abdallah ragab
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_



		 #define STK_CTRL		*((volatile u32*)0xE000E010)
		 #define STK_LOAD		*((volatile u32*)0xE000E014)
		 #define STK_VAL		*((volatile u32*)0xE000E018)
		 #define STK_CALIB 		*((volatile u32*)0xE000E01C)

static void  Private_voidDisableSTK();

#endif /* SYSTICK_PRIVATE_H_ */
