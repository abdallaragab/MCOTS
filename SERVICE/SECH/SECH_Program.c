/*
 * SECH_Program.c
 *	SWC:
 *	Version:
 *  Created on: Jun 11, 2023
 *      Author: Abdallah ragab
 */
#include "../LIB/BIT_MATHS.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/RCC/RCC_Interface.h"
#include "../MCAL/SYSTICK/SYSTICK_INTERFACE.h"


#include "SECH_Config.h"
#include "SECH_Interface.h"
#include "SECH_Private.h"
void SECH_StartOs(void)
{

    STK_void_Init();
    STK_voidSetIntervalPeriodic(1000,Private_Sechduler);

}
void SECH_voidCreatTask(u8 Copy_u8TaskPriority, u32 Copy_u8Periodicity, void (*pf)(void), u32 Copy_u32_FirstDelay)
{
    if (Copy_u8TaskPriority > NO_OF_TASKS)
    {
        /* code */
    }
    else
    {
        Task_Arr[Copy_u8TaskPriority].Periodiciy = Copy_u8Periodicity;
        Task_Arr[Copy_u8TaskPriority].FirstDelay = Copy_u32_FirstDelay;
        Task_Arr[Copy_u8TaskPriority].pf = pf;
    }
}



static void Private_Sechduler(){

    for (u8 i = 0; i < NO_OF_TASKS; i++)
    {
        /* code */
        if ((Task_Arr[i].FirstDelay==0)&&(Task_Arr[i].pf!=NULL))
        {
            Task_Arr[i].pf();
            Task_Arr[i].FirstDelay=Task_Arr[i].Periodiciy-1;
        }
        else
        {
        Task_Arr[i].FirstDelay--;
                
                }
        
        
    }
    
}













