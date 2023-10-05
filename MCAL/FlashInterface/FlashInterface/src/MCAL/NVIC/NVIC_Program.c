/*
 * NVIC_Program.c
 *	SWC:
 *	Version:
 *  Created on: Jun 6, 2023
 *      Author: Abdallah ragab
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"
static u32 StaticGlobal_u8PriorityConfig;


void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptNum){

	SET_BIT( NVIC->NVIC_ISER[Copy_u8InterruptNum/32],(Copy_u8InterruptNum%32));

}
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptNum){
	SET_BIT( NVIC->NVIC_ICER[Copy_u8InterruptNum/32],(Copy_u8InterruptNum%32));

}

void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptNum){
	SET_BIT( NVIC->NVIC_ISPR[Copy_u8InterruptNum/32],(Copy_u8InterruptNum%32));

}

void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptNum){
	SET_BIT( NVIC->NVIC_ICPR[Copy_u8InterruptNum/32],(Copy_u8InterruptNum%32));


}

u8 NVIC_u8GetInterruptState(u8 Copy_u8InterruptNum){
	u8 Local_u8IntState=GET_BIT( NVIC->NVIC_IABR[Copy_u8InterruptNum/32],(Copy_u8InterruptNum%32));

	return Local_u8IntState;
}

void NVIC_voidSetInterruptPriority(u8 Copy_u8InterruptNum, u8 Copy_u8GroupId, u8 Copy_u8SubGroupId){
	u8 local_u8PriorityConfig=(u8)((StaticGlobal_u8PriorityConfig>>8)&0b111);
	u8 Local_u8Priority1=((Copy_u8GroupId)<<(local_u8PriorityConfig-3))|Copy_u8SubGroupId;

	//u8 Local_u8Priority = Copy_u8SubGroupId | (Copy_u8GroupId << ((StaticGlobal_u8PriorityConfig - 0x05FA0300)/256)); //0x05FA0400
	    NVIC ->NVIC_IPR[Copy_u8InterruptNum] = (Local_u8Priority1 << 4);
}

void NVIC_SetPriorityConfig(u8 Copy_u8Priority){
	u16 VECTKEY=0x5FA;
	StaticGlobal_u8PriorityConfig=((VECTKEY<<16)|(Copy_u8Priority<<8));
	SCB->SCB_AIRCR=StaticGlobal_u8PriorityConfig;

}








