/*
 * SYSTICK_Programe.c
 *	SWC:
 *	Version:
 *  Created on: Jun 5, 2023
 *      Author: Abdallah ragab
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"
#include "SYSTICK_INTERFACE.h"
#include "SYSTICK_PRIVATE.h"
#include "SYSTICK_CONFIG.h"

u8 STK_u8SingleIntFlag=0;

void(*STK_pToFunction)(void);

void STK_void_Init(){
	CLEAR_BIT(STK_CTRL,0);
	CLEAR_BIT(STK_CTRL,1);
	STK_LOAD=0;
	STK_VAL=0;

#if(STK_CLK==STK_AHB_CLK)
	SET_BIT(STK_CTRL,2);

#elif(STK_CLK==STK_AHB_CLK_DIV_BY_8)
	CLEAR_BIT(STK_CTRL,2);
#else
#error("ERROR SYSTICK CLK")



#endif
}

void STK_voidSetBusyWait(u32 Copyu32NoCounts){
	CLEAR_BIT(STK_CTRL,0);
	CLEAR_BIT(STK_CTRL,1);
	STK_LOAD=0;
	STK_VAL=0;

	STK_LOAD=Copyu32NoCounts;
	SET_BIT(STK_CTRL,0);
	while(GET_BIT(STK_CTRL,16)==BIT_RESET);
	CLEAR_BIT(STK_CTRL,1);



}

void STK_voidSetIntervalSingle(u32 Copyu32NoCounts,void (*Lpf)(void)){
	STK_pToFunction=Lpf;
	STK_LOAD=Copyu32NoCounts;
	SET_BIT(STK_CTRL,0);
	SET_BIT(STK_CTRL,1);
	STK_u8SingleIntFlag=1;


}
void STK_voidSetIntervalPeriodic(u32 Copyu32NoCounts,void (*Lpf)(void)){
	STK_pToFunction=Lpf;
	STK_LOAD=Copyu32NoCounts;
	SET_BIT(STK_CTRL,0);
	SET_BIT(STK_CTRL,1);
	STK_u8SingleIntFlag=0;

}


void SysTick_Handler(void){
	if(STK_u8SingleIntFlag==1){
		Private_voidDisableSTK();
		CLEAR_BIT(STK_CTRL,1);
	}
	if(STK_pToFunction!=NULL){
		STK_pToFunction();
	}
	u8 __attribute__((unused))Local_u8TempVariable=GET_BIT(STK_CTRL,16);
}

static void  Private_voidDisableSTK(){
	CLEAR_BIT(STK_CTRL,0);
	STK_LOAD=0;
	STK_VAL=0;

}
