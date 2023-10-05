/*
 * NVIC_Interface.h
 *	SWC:
 *	Version:
 *  Created on: Jun 6, 2023
 *      Author: Abdallah ragab
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptNum);
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptNum);
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptNum);
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptNum);

u8 NVIC_u8GetInterruptState(u8 Copy_u8InterruptNum);

/*FUNCTION Name=NVIC_voidSetInterruptPriority
 * Description:Changes the priority of the given Interrupt peripheral
 * I/P Parameters:
 * Copy_u8InterruptNum : the number of the required peripheral
 * Copy_u8GroupId    :the desired Group Id of interrupt note:if PriorityConfig= NVIC_GROUB0BITS_SUB4BITS then enter 0
 * Copy_u8SubGroupId :the desired SubGroup Id of interrupt note:if PriorityConfig= NVIC_GROUB4BITS_SUB0BITS then enter 0
 *
 */
void NVIC_voidSetInterruptPriority(u8 Copy_u8InterruptNum,u8 Copy_u8GroupId, u8 Copy_u8SubGroupId);


/*
 *FUNCTION Name= NVIC_SetPriorityConfig
I/P Parameters:
 * Copy_u8Priority:
 *
 * NVIC_GROUB4BITS_SUB0BITS
 *	NVIC_GROUB3BITS_SUB1BITS
 *	NVIC_GROUB2BITS_SUB2BITS
 *	NVIC_GROUB1BITS_SUB3BITS
 *	NVIC_GROUB0BITS_SUB4BITS
 */
void NVIC_SetPriorityConfig(u8 Copy_u8Priority);

#define 		NVIC_GROUB4BITS_SUB0BITS		0b011
#define 		NVIC_GROUB3BITS_SUB1BITS		0b100
#define 		NVIC_GROUB2BITS_SUB2BITS		0b101
#define 		NVIC_GROUB1BITS_SUB3BITS		0b110
#define 		NVIC_GROUB0BITS_SUB4BITS		0b111









#endif /* NVIC_INTERFACE_H_ */
