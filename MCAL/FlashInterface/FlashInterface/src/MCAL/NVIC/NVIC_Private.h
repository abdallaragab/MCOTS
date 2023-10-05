/*
 * NVIC_Private.h
 *	SWC:
 *	Version:
 *  Created on: Jun 6, 2023
 *      Author: Abdallah ragab
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS		0xE000E100

typedef struct{
	volatile u32 NVIC_ISER[8+24];
	volatile u32 NVIC_ICER[8+24];
	volatile u32 NVIC_ISPR[8+24];
	volatile u32 NVIC_ICPR[8+24];
	volatile u32 NVIC_IABR[8+56];
	volatile u8  NVIC_IPR[60*4];

}NVIC_t;

#define NVIC		((NVIC_t*)NVIC_BASE_ADDRESS)

typedef struct{
	volatile u32 SCB_ACTLR[415];
	volatile u32 SCB_CPUID;
	volatile u32 SCB_ICSR;
	volatile u32 SCB_VTOR;
	volatile u32 SCB_AIRCR;
	volatile u32 SCB_SCR;
	volatile u32 SCB_CCR;
	volatile u32 SCB_SHPR1;
	volatile u32 SCB_SHPR2;
	volatile u32 SCB_SHPR3;
	volatile u32 SCB_SHCSR;
	volatile u32 SCB_CFSR;
	volatile u32 SCB_HFSR[2];
	volatile u32 SCB_MMAR;
	volatile u32 SCB_BFAR;
	volatile u32 SCB_AFSR;
}SCB_t;

#define 		SCB_BASE_ADDRESS	0xE000E008
#define 		SCB					((SCB_t *)SCB_BASE_ADDRESS)



#endif /* NVIC_PRIVATE_H_ */
