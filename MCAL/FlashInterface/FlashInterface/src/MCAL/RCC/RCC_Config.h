/*
 * RCC_Config.h
 *
 *  Created on: May 31, 2023
 *      Author: a-m-m
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/*System clock SOURCE
*option=
*			1- RCC_u32_HSI
*			2- RCC_u32_HSE
*			3- RCC_u32_PLL
*/
#define RCC_u32_CLOCK_SRC		RCC_u32_HSI

/*in case of using RCC_u32_HSE as system clock source you need to configure the next parameters
 *options:
 *			RCC_u32_HSE_CRYSTAL
 *			RCC_u32_HSE_BYBASS
 */
#define RCC_u32_HSE_MODE		RCC_u32_HSE_CRYSTAL


/*PLL Clock Source
 * Options: 1- RCC_u32_PLL_SRC_HSI_DIV2
 * 			2- RCC_u32_PLL_SRC_HSE
 */
#define RCC_u32_PLL_SRC		RCC_u32_PLL_SRC_HSI

/*
//PLL output clock frequency = VCO frequency / PLLP
 * PLLP options:
 * 				 RCC_PLLP2
 * 				 RCC_PLLP4
 * 				 RCC_PLLP6
 * 				 RCC_PLLP8
 *
 */
#define RCC_u32_PLLP		RCC_u32_PLLP4


//VCO output frequency = VCO input frequency × PLLN with range 192MHZ <=VCO  <=432MHZ
#define RCC_u32_PLLN			192


//VCO input frequency = PLL input clock frequency / PLLM with 2 <=PLLM <=
#define RCC_u32_PLLM			3




#endif /* RCC_CONFIG_H_ */
