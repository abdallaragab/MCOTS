/**************************************** Includes ****************************************/

#include "BIT_MATHS.h"
#include "STD_TYPES.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"


typedef void(*fptr)(void);


static fptr Global_pfArray[23]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};


u8 EXTI_u8SetInterruptStatus(u8 Copy_u8EXTINumber, u8 Copy_u8EXTIStatus)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;

	switch(Copy_u8EXTIStatus)
	{
		case EXTI_INTERRUPT_NOT_MASKED:

			Local_u8ErrorState = STD_TYPES_OK;
			SET_BIT(EXTI -> IMR, Copy_u8EXTINumber);
			break;

		case EXTI_INTERRUPT_MASKED:

			Local_u8ErrorState = STD_TYPES_OK;
			CLEAR_BIT(EXTI -> IMR, Copy_u8EXTINumber);
			break;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8SetInterruptEdge(u8 Copy_u8EXTINumber, u8 Copy_u8EXTIEdge)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;

	switch(Copy_u8EXTIEdge)
	{
		case EXTI_RISING_EDGE:

			Local_u8ErrorState = STD_TYPES_OK;
			SET_BIT(EXTI->RSTR, Copy_u8EXTINumber);
			CLEAR_BIT(EXTI -> FTSR, Copy_u8EXTINumber);

			break;

		case EXTI_FALLING_EDGE:

			Local_u8ErrorState = STD_TYPES_OK;
			CLEAR_BIT(EXTI->RSTR, Copy_u8EXTINumber);
			SET_BIT(EXTI -> FTSR, Copy_u8EXTINumber);
			break;

		case EXTI_RISING_FALLING_EDGE:

			Local_u8ErrorState = STD_TYPES_OK;

			SET_BIT(EXTI->RSTR, Copy_u8EXTINumber);
			SET_BIT(EXTI -> FTSR, Copy_u8EXTINumber);
			break;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8ClearInterruptPending(u8 Copy_u8EXTINumber)
{

	u8 Local_u8ErrorState = STD_TYPES_OK;

	SET_BIT(EXTI -> PR, Copy_u8EXTINumber);

	return Local_u8ErrorState;
}

u8 EXTI_u8IsInterruptActive(u8 Copy_u8EXTINumber, u8* Copy_pu8EXTIStatus)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	*Copy_pu8EXTIStatus = GET_BIT(EXTI -> PR, Copy_u8EXTINumber);

	return Local_u8ErrorState;
}





u8 EXTI_u8SetInterruptCallback(u8 Copy_u8EXTINumber, void (*Copy_pfCallback)(void)){

	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8EXTINumber<23){
		Global_pfArray[Copy_u8EXTINumber]=Copy_pfCallback;

	}
	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;

}


/*Note:This Function shouldn't be in this Driver*/
/***********************************************/
/***********************************************/
/***********************************************/
/***********************************************/
/***********************************************/
/***********************************************/

void EXTI_voidChangeEXTISource(u8 Copy_u8IntPort,u8 Copy_u8IntNum){
	if(Copy_u8IntNum<4){
		MODIFY_REG(SYSCFG_EXTICR1,(Copy_u8IntPort%4<<Copy_u8IntNum),(0b1111<<Copy_u8IntNum%4));

	}
	else if(Copy_u8IntNum>=4&&Copy_u8IntNum<8){
		MODIFY_REG(SYSCFG_EXTICR2,(Copy_u8IntPort%4<<Copy_u8IntNum),(0b1111<<Copy_u8IntNum%4));

	}
	else if(Copy_u8IntNum>=8&&Copy_u8IntNum<12){
		MODIFY_REG(SYSCFG_EXTICR3,(Copy_u8IntPort%4<<Copy_u8IntNum),(0b1111<<Copy_u8IntNum%4));

	}
	else if(Copy_u8IntNum>=12&&Copy_u8IntNum<16){
		MODIFY_REG(SYSCFG_EXTICR4,(Copy_u8IntPort%4<<Copy_u8IntNum),(0b1111<<Copy_u8IntNum%4));

		}

}




/*
u8 EXTI_u8SetInterruptCallback(u8 Copy_u8EXTINumber, void (*Copy_pfCallback)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_u8EXTINumber > 4 && Copy_u8EXTINumber < 10)
	{
		Copy_u8EXTINumber = 5;
	}
	else if(Copy_u8EXTINumber >= 10 && Copy_u8EXTINumber <= 15)
	{
		Copy_u8EXTINumber = 6;
	}
	else
	{
	}

	Global_pfArray[Copy_u8EXTINumber] = Copy_pfCallback;

	return Local_u8ErrorState;
}
*/

/**************************************** EXTI ISRs ****************************************/



void EXTI0_IRQHandler(void){

	SET_BIT(EXTI->PR,0);

	if(Global_pfArray[0]!=NULL){
		Global_pfArray[0]();
	}
	else{

	}

}

void EXTI1_IRQHandler(void){
	SET_BIT(EXTI->PR,1);
	if(Global_pfArray[1]!=NULL){
		Global_pfArray[1]();
	}
	else{

	}
}











void EXTI2_IRQHandler(void)
{
	SET_BIT(EXTI -> PR, 2);

	if(Global_pfArray[EXTI_LINE2] != NULL)
	{
		Global_pfArray[EXTI_LINE2]();
	}
	else
	{
		/*Do nothing*/
	}
}

void EXTI3_IRQHandler(void)
{
	SET_BIT(EXTI -> PR, 3);

	if(Global_pfArray[3] != NULL)
	{
		Global_pfArray[3]();
	}
	else
	{
		/*Do nothing*/
	}
}

void EXTI4_IRQHandler(void)
{
	SET_BIT(EXTI -> PR, 4);

	if(Global_pfArray[4] != NULL)
	{
		Global_pfArray[4]();
	}
	else
	{
		/*Do nothing*/
	}
}

void EXTI9_5_IRQHandler(void)
{

	if(GET_BIT(EXTI -> PR, 5)==1){
		SET_BIT(EXTI -> PR, 5);
		Global_pfArray[5]();
	}
	 if(GET_BIT(EXTI -> PR, 6)==1){
		SET_BIT(EXTI -> PR, 6);
		Global_pfArray[6]();
	}
	 if(GET_BIT(EXTI -> PR, 7)==1){
		SET_BIT(EXTI -> PR, 7);

		Global_pfArray[7]();
	}
	 if(GET_BIT(EXTI -> PR, 8)==1){
		SET_BIT(EXTI -> PR, 8);
		Global_pfArray[8]();
	}
	 if(GET_BIT(EXTI -> PR, 9)==1){
		SET_BIT(EXTI -> PR, 9);
		Global_pfArray[9]();
	}

}

void EXTI15_10_IRQHandler(void)
{
	if(GET_BIT(EXTI -> PR, 10)==1){
		SET_BIT(EXTI -> PR, 10);
		Global_pfArray[10]();
	}
	 if(GET_BIT(EXTI -> PR, 11)==1){
		SET_BIT(EXTI -> PR,11);
		Global_pfArray[11]();
	}
	 if(GET_BIT(EXTI -> PR, 12)==1){
		SET_BIT(EXTI -> PR, 12);

		Global_pfArray[12]();
	}
	 if(GET_BIT(EXTI -> PR, 13)==1){
		SET_BIT(EXTI -> PR, 13);
		Global_pfArray[13]();
	}
	 if(GET_BIT(EXTI -> PR, 14)==1){
		SET_BIT(EXTI -> PR, 14);
		Global_pfArray[14]();
	}
	 if(GET_BIT(EXTI -> PR, 15)==1){
		SET_BIT(EXTI -> PR, 15);
		Global_pfArray[14]();
	}

}
