/*
 * GPIO_Program.c
 *	SWC:GPIO
 *	Version:v1
 *  Created on: Jun 2, 2023
 *      Author: Abdallah ragab
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"
#include "GPIO.Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Conf.h"


/*Func name:GPIO_u8SetPinMode
 * Description:  configure the I/O direction mode
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinMode:GPIO_u8_PinModeInput:GPIO_u8_PinModeInput
 *													GPIO_u8_PinModeOutput
 *													GPIO_u8_PinModeAF
 *													GPIO_u8_PinModeAnalog
 *				return:Local_Error_state
 *
 *
 */

u8 GPIO_u8SetPinMode(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinMode) {
	u8 Local_Error_state = STD_TYPES_OK;
	if (copy_u8PortId <= GPIO_u8PortC && copy_u8PinId <= GPIO_Pin15&&copy_u8PinMode<=GPIO_u8_PinModeAnalog) {
		if ((copy_u8PortId == GPIO_u8PortC) && (copy_u8PinId < GPIO_Pin13)) {
			Local_Error_state = STD_TYPES_NOK;
		} else {
			switch (copy_u8PortId) {
			case GPIO_u8PortA:
				//USE modify register to modify the value of corresponding GPIOXModer bits
				MODIFY_REG(GPIOA->GPIO_MODER, (copy_u8PinMode << copy_u8PinId*2),(GPIOX_MODER_MODER0<<copy_u8PinId*2));
				break;
			case GPIO_u8PortB:
				MODIFY_REG(GPIOB->GPIO_MODER, (copy_u8PinMode << copy_u8PinId*2),(GPIOX_MODER_MODER0<<copy_u8PinId*2));
				break;
			case GPIO_u8PortC:
				MODIFY_REG(GPIOC->GPIO_MODER, (copy_u8PinMode << copy_u8PinId*2),(GPIOX_MODER_MODER0<<copy_u8PinId*2));
				break;
			default:
				Local_Error_state = STD_TYPES_NOK
				break;
			}
		}
	}
	else{
		Local_Error_state = STD_TYPES_NOK;
	}
	return Local_Error_state;
}


/*Func GPIO_u8SetPinOutputType
 * Description: change Port Pin output Type
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinType: GPIO_u8_OP_PP
 * 								GPIO_u8_OP_OP
 *
 *
 *
 *				return:Local_Error_state
 *
 *
 */

u8	 GPIO_u8SetPinOutputType(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinType){
	u8 Local_Error_state = STD_TYPES_OK;
	if (copy_u8PortId <= GPIO_u8PortC && copy_u8PinId <= GPIO_Pin15 && copy_u8PinType<=GPIO_u8_OP_OP ) {
			if ((copy_u8PortId == GPIO_u8PortC) && (copy_u8PinId < GPIO_Pin13)) {
				Local_Error_state = STD_TYPES_NOK;
			} else {
				switch (copy_u8PortId) {
				case GPIO_u8PortA:
					//USE modify register to modify the value of corresponding GPIOXModer bits
					MODIFY_REG(GPIOA->GPIO_OTYPER, (copy_u8PinType << copy_u8PinId),(GPIOX_OTYPER_OT0<<copy_u8PinId));
					break;
				case GPIO_u8PortB:
					MODIFY_REG(GPIOB->GPIO_OTYPER, (copy_u8PinType << copy_u8PinId),(GPIOX_OTYPER_OT0<<copy_u8PinId));
					break;
				case GPIO_u8PortC:
					MODIFY_REG(GPIOC->GPIO_OTYPER, (copy_u8PinType << copy_u8PinId),(GPIOX_OTYPER_OT0<<copy_u8PinId));
					break;
				default:
					Local_Error_state = STD_TYPES_NOK
					break;
				}
			}
		}
		else{
			Local_Error_state = STD_TYPES_NOK;
		}
	return Local_Error_state;
}


/*Func name:GPIO_u8SetPinOutputSpeed
 * Description:configure the I/O output speed
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinSpeed:
 *							 	 GPIO_u8_MODE_LS		    //GPIO PIN Low speed Mode
 *							 	 GPIO_u8_MODE_MS			//GPIO PIN Medium speed Mode
 *							 	 GPIO_u8_MODE_HS			//GPIO PIN high speed Mode
 *							 	 GPIO_u8_MODE_VHS			//GPIO PIN Very high speed Mode
 *
 *				return:Local_Error_state
 *
 *
 */
u8 GPIO_u8SetPinOutputSpeed(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinSpeed){
	u8 Local_Error_state = STD_TYPES_OK;
	if (copy_u8PortId <= GPIO_u8PortC && copy_u8PinId <= GPIO_Pin15&&copy_u8PinSpeed<=GPIO_u8_MODE_VHS) {
		if ((copy_u8PortId == GPIO_u8PortC) && (copy_u8PinId < GPIO_Pin13)) {
			Local_Error_state = STD_TYPES_NOK;
		} else {
			switch (copy_u8PortId) {
			case GPIO_u8PortA:
				//USE modify register to modify the value of corresponding GPIOXModer bits
				MODIFY_REG(GPIOA->GPIO_OSPEEDR, (copy_u8PinSpeed << copy_u8PinId*2),(GPIOX_OSPEEDR_OSPEEDR0<<copy_u8PinId*2));
				break;
			case GPIO_u8PortB:
				MODIFY_REG(GPIOB->GPIO_OSPEEDR, (copy_u8PinSpeed << copy_u8PinId*2),(GPIOX_OSPEEDR_OSPEEDR0<<copy_u8PinId*2));
				break;
			case GPIO_u8PortC:
				MODIFY_REG(GPIOC->GPIO_OSPEEDR, (copy_u8PinSpeed << copy_u8PinId*2),(GPIOX_OSPEEDR_OSPEEDR0<<copy_u8PinId*2));
				break;
			default:
				Local_Error_state = STD_TYPES_NOK
				break;
			}
		}
	}
	else{
		Local_Error_state = STD_TYPES_NOK;
	}
	return Local_Error_state;
}



/*Func name: GPIO_u8SetPinPullMode
 * Description:configure the I/O pull-up or pull-down
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinPullMode:
 *								 	GPIO_u8_NO_PP_PD			// No pull-up, pull-down
 *								 	GPIO_u8_PP					//Pull-up
 *							 		GPIO_u8_PD					//Pull-down
 *
 *
 *				return:Local_Error_state
 */
u8 GPIO_u8SetPinPullMode(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinPullMode){

		u8 Local_Error_state = STD_TYPES_OK;
		if (copy_u8PortId <= GPIO_u8PortC && copy_u8PinId <= GPIO_Pin15&&copy_u8PinPullMode<=GPIO_u8_PD) {
			if ((copy_u8PortId == GPIO_u8PortC) && (copy_u8PinId < GPIO_Pin13)) {
				Local_Error_state = STD_TYPES_NOK;
			} else {
				switch (copy_u8PortId) {
				case GPIO_u8PortA:
					//USE modify register to modify the value of corresponding GPIOXModer bits
					MODIFY_REG(GPIOA->GPIO_PUPDR, (copy_u8PinPullMode << copy_u8PinId*2),(GPIOX_PUPDR_PUPDR0<<copy_u8PinId*2));
					break;
				case GPIO_u8PortB:
					MODIFY_REG(GPIOB->GPIO_PUPDR, (copy_u8PinPullMode << copy_u8PinId*2),(GPIOX_PUPDR_PUPDR0<<copy_u8PinId*2));
					break;
				case GPIO_u8PortC:
					MODIFY_REG(GPIOC->GPIO_PUPDR, (copy_u8PinPullMode << copy_u8PinId*2),(GPIOX_PUPDR_PUPDR0<<copy_u8PinId*2));
					break;
				default:
					Local_Error_state = STD_TYPES_NOK
					break;
				}
			}
		}
		else{
			Local_Error_state = STD_TYPES_NOK;
		}
		return Local_Error_state;
	}




/*Func name: GPIO_u8GetPinValue
 * Description: Get Port input data
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 *
 *				return:PinValue
 */
u8 	 GPIO_u8GetPinValue(u8 copy_u8PortId,u8 copy_u8PinId){
	u8 Local_PinValue=0;
	u8 Local_Error_state = STD_TYPES_OK;
	if (copy_u8PortId <= GPIO_u8PortC && copy_u8PinId <= GPIO_Pin15) {
		if ((copy_u8PortId == GPIO_u8PortC) && (copy_u8PinId < GPIO_Pin13)) {
			Local_Error_state = STD_TYPES_NOK;
		} else {
			switch (copy_u8PortId) {
			case GPIO_u8PortA:
				Local_PinValue=GET_BIT(GPIOA->GPIO_IDR,copy_u8PinId);
				break;
			case GPIO_u8PortB:
				Local_PinValue=GET_BIT(GPIOB->GPIO_IDR,copy_u8PinId);
				break;
			case GPIO_u8PortC:
				Local_PinValue=GET_BIT(GPIOC->GPIO_IDR,copy_u8PinId);
				break;
			default:
				Local_Error_state = STD_TYPES_NOK
				break;
			}
		}
	}
	else{
		Local_Error_state = STD_TYPES_NOK;
	}
	return Local_PinValue;
}




/*Func name: GPIO_u8ChangePinOutMode
 * Description: change Port Output data
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinPullMode:
 *								 	PIO_u8_OP_MODE_RESET		//GPIO PIN Output Reset
 *								 	PIO_u8_OP_MODE_SET			//GPIO PIN Output Set
 *
 *
 *
 *				return:Local_Error_state
 */
u8 GPIO_u8ChangePinOutMode(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinOutVal){
	u8 Local_Error_state = STD_TYPES_OK;
	if (copy_u8PortId <= GPIO_u8PortC && copy_u8PinId <= GPIO_Pin15&&copy_u8PinOutVal<=GPIO_u8_OP_MODE_SET) {
		if ((copy_u8PortId >= GPIO_u8PortC) && (copy_u8PinId < GPIO_Pin13)) {
			Local_Error_state = STD_TYPES_NOK;
		} else {
			switch (copy_u8PortId) {
			case GPIO_u8PortA:
				MODIFY_REG(GPIOA->GPIO_ODR, (copy_u8PinOutVal << copy_u8PinId),(GPIOX_ODR_ODR0<<copy_u8PinId));
				break;
			case GPIO_u8PortB:
				MODIFY_REG(GPIOB->GPIO_ODR, (copy_u8PinOutVal << copy_u8PinId),(GPIOX_ODR_ODR0<<copy_u8PinId));
				break;
			case GPIO_u8PortC:
				MODIFY_REG(GPIOC->GPIO_ODR, (copy_u8PinOutVal << copy_u8PinId),(GPIOX_ODR_ODR0<<copy_u8PinId));
				break;
			default:
				Local_Error_state = STD_TYPES_NOK
				break;
			}
		}
	}
	else{
		Local_Error_state = STD_TYPES_NOK;
	}
	return Local_Error_state;
}

u8 GPIO_u8ChangePortOutValue(u8 copy_u8PortId,u16 copy_u16PortOutVal){
	u8 Local_Error_state = STD_TYPES_OK;
		if (copy_u8PortId <= GPIO_u8PortC ) {
			 {
				switch (copy_u8PortId) {
				case GPIO_u8PortA:
					GPIOA->GPIO_ODR=copy_u16PortOutVal;
					break;
				case GPIO_u8PortB:
					GPIOB->GPIO_ODR=copy_u16PortOutVal;
					break;
				case GPIO_u8PortC:
					GPIOC->GPIO_ODR=copy_u16PortOutVal;
					break;
				default:
					Local_Error_state = STD_TYPES_NOK
					break;
				}
			}
		}
		else{
			Local_Error_state = STD_TYPES_NOK;
		}
		return Local_Error_state;
}



/*Func name: GPIO_u8DirectSetPinOutMode
 * Description:Direct atomic change of OP Mode
 * I/P arguments:
 * 				copy_u8PortId:specifies the required port:  GPIO_u8PortA			GPIO_u8PortB				GPIO_u8PortC
 * 				copy_u8PinId:specifies the required Pin:	GPIO_Pin0->GPIO_Pin15 	GPIO_Pin0->GPIO_Pin15		GPIO_Pin13->GPIO_Pin15
 * 				copy_u8PinPullMode:
 *								 	PIO_u8_OP_MODE_RESET		//GPIO PIN Output Reset
 *								 	PIO_u8_OP_MODE_SET			//GPIO PIN Output Set
 *
 *
 *
 *				return:Local_Error_state
 */
u8 GPIO_u8DirectSetPinOutMode(u8 copy_u8PortId, u8 copy_u8PinId,u8 copy_u8PinOutVal) {
	u8 Local_Error_state = STD_TYPES_OK
	;
	if (copy_u8PortId <= GPIO_u8PortC && copy_u8PinId <= GPIO_Pin15) {
		if ((copy_u8PortId == GPIO_u8PortC) && (copy_u8PinId < GPIO_Pin13)) {
			Local_Error_state = STD_TYPES_NOK
			;
		} else {
			if (copy_u8PinOutVal == 1) {
				switch (copy_u8PortId) {
				case GPIO_u8PortA:
					SET_BIT(GPIOA->GPIO_BSRR,copy_u8PinId);
					break;
				case GPIO_u8PortB:
					SET_BIT(GPIOB->GPIO_BSRR,copy_u8PinId);

					break;
				case GPIO_u8PortC:
					SET_BIT(GPIOC->GPIO_BSRR,copy_u8PinId);
					break;
				default:
					Local_Error_state = STD_TYPES_NOK
					break;
				}
			} else if (copy_u8PinOutVal == 0) {
				switch (copy_u8PortId) {
				case GPIO_u8PortA:
					SET_BIT(GPIOA->GPIO_BSRR,copy_u8PinId+16);
					break;
				case GPIO_u8PortB:
					SET_BIT(GPIOB->GPIO_BSRR,copy_u8PinId+16);

					break;
				case GPIO_u8PortC:
					SET_BIT(GPIOC->GPIO_BSRR,copy_u8PinId+16);
					break;
				default:
					Local_Error_state = STD_TYPES_NOK
					break;
				}
			}
		}
	} else {
		Local_Error_state = STD_TYPES_NOK
		;
	}
	return Local_Error_state;
}

u8 GPIO_u8SetAlterFunc(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8AlterFunNum) {
	u8 Local_Error_state = STD_TYPES_OK;
	if (Copy_u8PortID > GPIO_u8PortC || Copy_u8PinID > GPIO_Pin15|| Copy_u8AlterFunNum > 15) {
		Local_Error_state = STD_TYPES_NOK
	} else {
		if (Copy_u8PinID <= GPIO_Pin7) {
			switch (Copy_u8PortID) {
			case GPIO_u8PortA:
				MODIFY_REG(GPIOA->GPIO_AFRL, (Copy_u8AlterFunNum<<Copy_u8PinID  * 4), (15<<Copy_u8PinID * 4));
				break;
			case GPIO_u8PortB:
				MODIFY_REG(GPIOB->GPIO_AFRL,(Copy_u8AlterFunNum<<Copy_u8PinID  *4), (15<<Copy_u8PinID*4));

				break;
			case GPIO_u8PortC:
				MODIFY_REG(GPIOC->GPIO_AFRL, (Copy_u8AlterFunNum<<Copy_u8PinID  *4), (15<<Copy_u8PinID*4));

				break;
			default:
				break;
			}

		} else {
			switch (Copy_u8PortID) {
			case GPIO_u8PortA:
				MODIFY_REG(GPIOA->GPIO_AFRH, (Copy_u8AlterFunNum<<Copy_u8PinID%8*4), (15<<Copy_u8PinID%8*4));
				break;
			case GPIO_u8PortB:
				MODIFY_REG(GPIOB->GPIO_AFRH, (Copy_u8AlterFunNum<<Copy_u8PinID%8*4), (15<<Copy_u8PinID%8*4));
				break;
			case GPIO_u8PortC:
				MODIFY_REG(GPIOC->GPIO_AFRH, (Copy_u8AlterFunNum<<Copy_u8PinID%8*4), (15<<Copy_u8PinID%8*4));

				break;
			default:
				break;
			}

		}

	}
	return Local_Error_state;
}



