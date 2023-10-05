/*
 * SECH_Interface.h
 *	SWC:
 *	Version:
 *  Created on: Jun 11, 2023
 *      Author: Abdallah ragab
 */

#ifndef SECH_INTERFACE_H_
#define SECH_INTERFACE_H_

void SECH_StartOs(void);
void SECH_voidCreatTask(u8 Copy_u8TaskPriority,u32 Copy_u8Periodicity,void(*pf)(void),u32 Copy_u32_FirstDelay);


#endif /* SECH_INTERFACE_H_ */
