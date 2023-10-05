/*
  * File:  MFLASH_Program.c 
 *	SWC:    MFLASH
 *	Version: 1.0 
 *  Created on: 03-09-2023 
 *  Author: Abdallah Ragab 
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"
#include "MFLASH_Interface.h"
#include "MFLASH_Private.h"
#include "MFLASH_Config.h"
#define FLASH_BASE		0x08000000

static u8 MFlash_u8Unlock(void) {
	u8 status=STD_TYPES_OK;
	if(GET_BIT(MFLASH->CR, 31) != 0)
	  {
	    /* Authorize the FLASH Registers access */
	    MFLASH->KEYR= FLASH_KEY1;
	    MFLASH->KEYR= FLASH_KEY2;

	    /* Verify Flash is unlocked */
	    if(GET_BIT(MFLASH->CR, 31) != 0)
	    {
	      status = STD_TYPES_NOK;
	    }
	  }

	  return status;
}
static void MFlash_voidLock(void) {
	MFLASH->CR |=(1<<31);
}


u8 MFlash_u8EraseSector(u8 Copy_u32Sector) {
	u8 status=STD_TYPES_OK;
	if(Copy_u32Sector<=MFLASH_Sector_5){

		/*Unlock flash to start process*/
		MFlash_u8Unlock();

		/*Disable all interrupts to avoid errors*/
		__asm volatile ("cpsid i" : : : "memory");

		/*Wait if there is a current process using Flash*/
		while(GET_BIT(MFLASH->SR,16)==1);

		/*Set word size to be 32 bit*/
		CLEAR_BIT(MFLASH->CR,8);
		SET_BIT(MFLASH->CR,9);

		/**Choose sector Number*/
		MODIFY_REG(MFLASH->CR,Copy_u32Sector<<3,FLASH_CR_SNB);

		/*choose sector erase*/
		/*choose sector erase*/
		CLEAR_BIT(MFLASH->CR,2);
		SET_BIT(MFLASH->CR,1);
		CLEAR_BIT(MFLASH->CR,0);

		/*erase Flags*/
		MFLASH->SR|=(0b11111<<4);

		/*Start erase opreation*/
		SET_BIT(MFLASH->CR,16);

		/*Wait if there is a current process using Flash*/
		while(GET_BIT(MFLASH->SR,16)==1);

		/*Enable Interrupts again*/
		__asm volatile ("cpsie i" : : : "memory");

		/*Lock Flash again*/
		MFlash_voidLock();

	}
	else{
		status=STD_TYPES_NOK;

	}
	return status;
}

u8 MFlash_u8Write(u32 Copy_u32Address,u32* Ptr_u32Data,u32 Copy_u32Size  ) {
	u8 status=STD_TYPES_OK;

	if(Copy_u32Address<=MFLASH_Sector_5_END){

		/*Unlock flash to start process*/
		MFlash_u8Unlock();

		/*Disable all interrupts to avoid errors*/
		__asm volatile ("cpsid i" : : : "memory");

		/*Wait if there is a current process using Flash*/
		while(GET_BIT(MFLASH->SR,16)==1);

		/*Set word size to be 32 bit*/
		CLEAR_BIT(MFLASH->CR,8);
		SET_BIT(MFLASH->CR,9);




		/*erase Flags*/
		MFLASH->SR|=(0b11111<<4);

		/*Wait if there is a current process using Flash*/
		while(GET_BIT(MFLASH->SR,16)==1);


		/*start program mode*/
		SET_BIT(MFLASH->CR,0);

		/*Write Data*/
		for (u32 var = 0; var < Copy_u32Size; ++var) {
			*(u32 *)(Copy_u32Address+var*4)=Ptr_u32Data[var];
			while(GET_BIT(MFLASH->SR,16)==1);
		}

		/*Stop program mode*/
		CLEAR_BIT(MFLASH->CR,0);

		/*Enable Interrupts again*/
		__asm volatile ("cpsie i" : : : "memory");

		/*Lock Flash again*/
		MFlash_voidLock();

	}
	else{
		status=STD_TYPES_NOK;

	}

	return status;

}



