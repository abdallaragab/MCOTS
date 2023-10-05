/*
 * EXTI_private.h
 *
 *  Created on: Jul 26, 2021
 *      Author: Alahram
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_



typedef struct{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RSTR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_t;



#define EXTI ((volatile EXTI_t *) 0x40013C00 )

#define SYSCFG_BASE_ADDRESS		0x40013800

#define SYSCFG_EXTICR1			*((volatile u32 *)SYSCFG_BASE_ADDRESS+0x8)
#define SYSCFG_EXTICR2			*((volatile u32 *)SYSCFG_BASE_ADDRESS+0xc)
#define SYSCFG_EXTICR3			*((volatile u32 *)SYSCFG_BASE_ADDRESS+0x10)
#define SYSCFG_EXTICR4			*((volatile u32 *)SYSCFG_BASE_ADDRESS+0x14)

#endif /* EXTI_PRIVATE_H_ */


