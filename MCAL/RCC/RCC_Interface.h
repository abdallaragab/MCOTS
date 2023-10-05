/*
 * RCC_Interface.h
 *
 *  Created on: May 31, 2023
 *      Author: a-m-m
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

//#include "STD_TYPES.h"

#define  RCC_u8_AHB1_BUS			0
#define  RCC_u8_AHB2_BUS			1
#define  RCC_u8_APB1_BUS			2
#define  RCC_u8_APB2_BUS			3


//Peripherals IDS
//AHB1 Peripherals Clock enable
#define RCC_u8_AHB1ENR_GPIOA	0
#define RCC_u8_AHB1ENR_GPIOB	1
#define RCC_u8_AHB1ENR_GPIOC	2
#define RCC_u8_AHB1ENR_GPIOD	3
#define RCC_u8_AHB1ENR_GPIOE	4
#define RCC_u8_AHB1ENR_GPIOH	7
#define RCC_u8_AHB1ENR_CRC		12
#define RCC_u8_AHB1ENR_DMA1		21
#define RCC_u8_AHB1ENR_DMA2		22


//AHB2 PREPHERALS CLOCK ENABLE
#define RCC_u8_AHB2ENR_OTGFSEN	22


//APB2 Peripherals Clock enable
#define RCC_u8_APB1ENR_TIM2EN		0
#define RCC_u8_APB1ENR_TIM3EN		1
#define RCC_u8_APB1ENR_TIM4EN		2
#define RCC_u8_APB1ENR_TIM5EN		3
#define RCC_u8_APB1ENR_WWDGEN		11
#define RCC_u8_APB1ENR_SPI2EN		14
#define RCC_u8_APB1ENR_SPI3EN		15
#define RCC_u8_APB1ENR_USART2EN		17
#define RCC_u8_APB1ENR_I2C1EN		21
#define RCC_u8_APB1ENR_I2C2EN		22
#define RCC_u8_APB1ENR_I2C3EN		23
#define RCC_u8_APB1ENR_PWREN		28



//APB1 Peripherals Clock enable
#define RCC_u8_APB2ENR_TIM1EN		0
#define RCC_u8_APB2ENR_USART1EN		4
#define RCC_u8_APB2ENR_USART6EN		5
#define RCC_u8_APB2ENR_ADC1EN		8
#define RCC_u8_APB2ENR_SDIOEN		11
#define RCC_u8_APB2ENR_SPI1EN		12
#define RCC_u8_APB2ENR_SPI4EN		13
#define RCC_u8_APB2ENR_SYSCFGEN		14
#define RCC_u8_APB2ENR_TIM9EN		16
#define RCC_u8_APB2ENR_TIM10EN		17
#define RCC_u8_APB2ENR_TIM11EN		18




u8 RCC_u8InitSysClk(void);

u8 RCC_u8EnableHSE(u32 HSE_mode);

u8 RCC_u8DisableHSE(void);


u8 RCC_u8EnableHSI(void);



u8 RCC_u8EnablePeripheralClk(u8 copy_u8BusId,u8 copy_u8Peripheral);

u8 RCC_u8DisablePeripheralClk(u8 copy_u8BusId,u8 copy_u8Peripherals);




#endif /* RCC_INTERFACE_H_ */
