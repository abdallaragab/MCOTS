/*
 * RCC_Program.c

 *
 *  Created on: May 31, 2023
 *      Author: a-m-m
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"
#include  "RCC_Interface.h"
#include  "RCC_Private.h"
#include  "RCC_Config.h"





u8 RCC_u8InitSysClk(void) {

	u8 Local_error_state = STD_TYPES_OK
	;
#if(RCC_u32_CLOCK_SRC==RCC_u32_HSI)
	SET_BIT(RCC->RCC_CR, 0);
	while (GET_BIT((RCC->RCC_CR),1) == BIT_RESET);
#elif(RCC_u32_CLOCK_SRC== RCC_u32_HSE)
	#if(RCC_u32_HSE_MODE== RCC_u32_HSE_BYBASS)
		SET_BIT((RCC->RCC_CR),18);
	#elif(RCC_u32_HSE_MODE== RCC_u32_HSE_CRYSTAL)
		CLEAR_BIT((RCC->RCC_CR),18);
	#else
		#error "wrong HSE Mode"
		Local_error_state=STD_TYPES_NOK;
	#endif
	SET_BIT((RCC->RCC_CR),16);
	while(GET_BIT((RCC->RCC_CR),17)==BIT_RESET);
	MODIFY_REG((RCC->RCC_CFGR),RCC_u32_CLOCK_SRC,RCC_CFGR_SW);
		//in case of choosing PLL as clock source ,the PLL Clock input and multiplication factor must be configured
#elif(RCC_u32_CLOCK_SRC==RCC_u32_PLL)
	#if(RCC_u32_PLL_SRC==RCC_u32_PLL_SRC_HSI)
		SET_BIT(RCC->RCC_CR, 0);
		while (GET_BIT((RCC->RCC_CR),1) == BIT_RESET);
	#elif(RCC_u32_PLL_SRC==RCC_u32_PLL_SRC_HSE)

			#if(RCC_u32_HSE_MODE== RCC_u32_HSE_BYBASS)
					SET_BIT((RCC->RCC_CR),18);
			#elif(RCC_u32_HSE_MODE== RCC_u32_HSE_CRYSTAL)
					CLEAR_BIT((RCC->RCC_CR),18);
			#else
				#error "wrong HSE Mode"
				Local_error_state=STD_TYPES_NOK;

				#endif

			//Enable HSE clock and wait until stabilize
			SET_BIT((RCC->RCC_CR),16);
			while(GET_BIT((RCC->RCC_CR),17)==BIT_RESET);
			//prepare PLL configs ans wait pll stabilize
			MODIFY_REG(RCC->RCC_PLLCFGR,RCC_u32_PLL_SRC|RCC_u32_PLLP|RCC_u32_PLLN|RCC_u32_PLLM,RCC_PLLCFGR_PLLSRC|RCC_PLLCFGR_PLLP|RCC_PLLCFGR_PLLM|RCC_PLLCFGR_PLLN);
			SET_BIT((RCC->RCC_CR),24);
			while(GET_BIT((RCC->RCC_CR),25)==BIT_RESET);
			//switch to PLL as main clock source
			MODIFY_REG((RCC->RCC_CFGR),RCC_u32_CLOCK_SRC,RCC_CFGR_SW);

			#endif


#else
	#error "wrong Clock source Mode"
	Local_error_state=STD_TYPES_NOK;
#endif
	MODIFY_REG((RCC->RCC_CFGR),RCC_u32_CLOCK_SRC,RCC_CFGR_SW);
	return Local_error_state;
}


u8 RCC_u8EnableHSE(u32 HSE_mode) {
	u8 Local_error_state = STD_TYPES_OK;
	if (HSE_mode == RCC_u32_HSE_CRYSTAL)
		CLEAR_BIT((RCC->RCC_CR), 18);
	else if (HSE_mode == RCC_u32_HSE_BYBASS)
		SET_BIT((RCC->RCC_CR), 18);
	SET_BIT((RCC->RCC_CR), 16);
	while (GET_BIT((RCC->RCC_CR),17) == BIT_RESET)
		;
	return Local_error_state;
}


u8 RCC_u8DisableHSE(void){
	u8 Local_error_state = STD_TYPES_OK;
	CLEAR_BIT(RCC->RCC_CR,16);

	return Local_error_state;

}


u8 RCC_u8DisablePeripheralClk(u8 copy_u8BusId, u8 copy_u8Peripheral) {
	u8 Local_error_state = STD_TYPES_OK
	;
	if (copy_u8Peripheral <= 31) {
		switch (copy_u8BusId) {
		case RCC_u8_AHB1_BUS:
			CLEAR_BIT((RCC->RCC_AHB1ENR), copy_u8Peripheral);
			break;
		case RCC_u8_AHB2_BUS:
					CLEAR_BIT((RCC->RCC_AHB1ENR), copy_u8Peripheral);
					break;
		case RCC_u8_APB1_BUS:
			CLEAR_BIT((RCC->RCC_APB1ENR), copy_u8Peripheral);

			break;
		case RCC_u8_APB2_BUS:
			CLEAR_BIT((RCC->RCC_APB2ENR), copy_u8Peripheral);

			break;
		default:
			Local_error_state = STD_TYPES_NOK
			;
			break;
		}

	}
	else{
				Local_error_state = STD_TYPES_NOK;
			}

	return Local_error_state;
}

u8 RCC_u8EnablePeripheralClk(u8 copy_u8BusId,u8 copy_u8Peripheral){
	u8 Local_error_state = STD_TYPES_OK
		;
		if (copy_u8Peripheral <= 31) {
			switch (copy_u8BusId) {
			case RCC_u8_AHB1_BUS:
				SET_BIT((RCC->RCC_AHB1ENR), copy_u8Peripheral);
				break;
			case RCC_u8_AHB2_BUS:
				SET_BIT((RCC->RCC_AHB1ENR), copy_u8Peripheral);
						break;
			case RCC_u8_APB1_BUS:
				SET_BIT((RCC->RCC_APB1ENR), copy_u8Peripheral);
				break;
			case RCC_u8_APB2_BUS:
				SET_BIT((RCC->RCC_APB2ENR), copy_u8Peripheral);

				break;
			default:
				Local_error_state = STD_TYPES_NOK;
				break;
			}

		}
		else{
			Local_error_state = STD_TYPES_NOK;
		}

		return Local_error_state;
	}


u8 RCC_u8EnableHSI(void){
	u8 Local_error_state = STD_TYPES_OK;
	SET_BIT(RCC->RCC_CR, 0);
	while (GET_BIT((RCC->RCC_CR),1) == BIT_RESET);
	return Local_error_state;

}


u8 RCC_u8DisableHSI(void){
	u8 Local_error_state = STD_TYPES_OK;
	CLEAR_BIT(RCC->RCC_CR, 0);

		return Local_error_state;

}
