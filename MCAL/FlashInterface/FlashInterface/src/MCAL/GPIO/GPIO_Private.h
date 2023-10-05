/*
 * GPIO_Private.h
 *	SWC:GPIO
 *  Created on: Jun 2, 2023
 *      Author: abdallah ragab
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIOA_Base_Address		0x40020000
#define GPIOB_Base_Address		0x40020400
#define GPIOC_Base_Address		0x40020800

//Register GPIOx_MODER BITS  mask
#define GPIOX_MODER_MODER0		0x00000003

//Register GPIOX_OTYPER BITS  mask
#define GPIOX_OTYPER_OT0		0x00000001


//Register GPIOX_OSPEEDR BITS  mask
#define GPIOX_OSPEEDR_OSPEEDR0	0x00000003


//Register GPIOX_PUPDR BITS  mask
#define GPIOX_PUPDR_PUPDR0		0x00000003


//Register GPIOX_IDR BITS  mask
#define GPIOX_IDR_IDR0			0x00000001

//Register GPIOX_ODR BITS  mask
#define GPIOX_ODR_ODR0			0x00000001


//Register GPIOX_BSRR BITS  mask
#define GPIOX_BSRR_BS0			0x00000001
#define GPIOX_BSRR_BY0			0x00010000



typedef struct {
	volatile u32 GPIO_MODER ;
	volatile u32 GPIO_OTYPER;
	volatile u32 GPIO_OSPEEDR;
	volatile u32 GPIO_PUPDR;
	volatile u32 GPIO_IDR;
	volatile u32 GPIO_ODR;
	volatile u32 GPIO_BSRR;
	volatile u32 GPIO_LCKR;
	volatile u32 GPIO_AFRL;
	volatile u32 GPIO_AFRH;
}GPIO_Def_t;

#define GPIOA						((GPIO_Def_t*)(GPIOA_Base_Address))
#define GPIOB						((GPIO_Def_t*)(GPIOB_Base_Address))
#define GPIOC						((GPIO_Def_t*)(GPIOC_Base_Address))



#endif /* GPIO_PRIVATE_H_ */
