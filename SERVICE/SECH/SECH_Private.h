/*
 * SECH_Interface.h
 *	SWC:
 *	Version:
 *  Created on: Jun 11, 2023
 *      Author: Abdallah ragab
 */

#ifndef SECH_PRIVATE_H_
#define SECH_PRIVATE_H_

static void Private_Sechduler();

typedef struct{
    void(*pf)(void);
    u32 Periodiciy;
    u32 FirstDelay;
}TCB_t;

TCB_t Task1;
TCB_t Task2;
TCB_t Task3;

TCB_t Task_Arr[NO_OF_TASKS]={NULL};

#endif /* SECH_INTERFACE_H_ */
