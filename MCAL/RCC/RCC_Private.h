/*
 * RCC_Private.h
 *
 *  Created on: May 31, 2023
 *      Author: a-m-m
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define RCC_u32_BASE_ADDRESS	0x40023800

#define RCC_CFGR_SW			0x00000003UL
#define RCC_CFGR_SWS		0x0000000CUL

#define RCC_CFGR_SWS_HSI			0x00000000CUL
#define RCC_CFGR_SWS_HSE			0x00000004CUL
#define RCC_CFGR_SWS_PLL			0x00000008CUL


#define RCC_PLLCFGR_PLLM	0x0000003FUL
#define RCC_PLLCFGR_PLLN	0x00007FC0UL
#define RCC_PLLCFGR_PLLP	0x00030000UL
#define RCC_PLLCFGR_PLLQ	0x0F000000UL
#define RCC_PLLCFGR_PLLSRC	0x00400000UL






#define RCC_u32_HSI		0x00000000
#define RCC_u32_HSE		0x00000001
#define RCC_u32_PLL		0x00000002


#define RCC_u32_HSE_BYBASS 		0x00040000
#define RCC_u32_HSE_CRYSTAL 	0x00000000

///MAIN PLL CLOCK INPUT
#define RCC_u32_PLL_SRC_HSI				0x00000000
#define RCC_u32_PLL_SRC_HSE				0x00400000

#define RCC_u32_PLLP2					0x00000000
#define RCC_u32_PLLP4					0x00010000
#define RCC_u32_PLLP6					0x00020000
#define RCC_u32_PLLP8					0x00030000


//Main PLL division factor
#define RCC_u32_PLL_DIV_FACTOR_NONE			0x00000000
#define RCC_u32_PLL_DIV_FACTOR_2			0x00020000	//VALUE of RCC_CFGR_PLLXTPRE



typedef struct{
	volatile u32 RCC_CR;
	volatile u32 RCC_PLLCFGR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_AHB1RST;
	volatile u32 RCC_AHB2RST;
	volatile u32 Reserved1;
	volatile u32 Reserved2;
	volatile u32 RCC_APB1RST;
	volatile u32 RCC_APB2RST;
	volatile u32 Reserved3;
	volatile u32 Reserved4;
	volatile u32 RCC_AHB1ENR;
	volatile u32 RCC_AHB2ENR;
	volatile u32 Reserved5;
	volatile u32 Reserved6;
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 Reserved7;
	volatile u32 Reserved8;
	volatile u32 RCC_AHB1LPENR;
	volatile u32 RCC_AHB2LPENR;
	volatile u32 Reserved9;
	volatile u32 Reserved10;
	volatile u32 RCC_APB1LPENR;
	volatile u32 RCC_APB2LPENR;
	volatile u32 Reserved11;
	volatile u32 Reserved12;
	volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
	volatile u32 Reserved13;
	volatile u32 Reserved14;
	volatile u32 RCC_SSCGR;
	volatile u32 RCC_PLLI2SCFGR;
	volatile u32 Reserved15;
	volatile u32 RCC_DCKCFGR;
}RCC_DEF;

#define RCC  ((RCC_DEF *)RCC_u32_BASE_ADDRESS)


#endif /* RCC_PRIVATE_H_ */
