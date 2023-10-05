
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/**************************************** Interfacing macros ****************************************/

#define EXTI_INTERRUPT_MASKED  		0
#define EXTI_INTERRUPT_NOT_MASKED   1


#define EXTI_RISING_EDGE            0
#define EXTI_FALLING_EDGE           1
#define EXTI_RISING_FALLING_EDGE    2
#define EXTI_LINE0                  0
#define EXTI_LINE1                  1
#define EXTI_LINE2                  2
#define EXTI_LINE3                  3
#define EXTI_LINE4                  4
#define EXTI_LINE5_9                5
#define EXTI_LINE10_15              6

/**************************************** Functions' prototypes ****************************************/
/******************************************************///
u8 EXTI_u8SetInterruptStatus(u8 Copy_u8EXTINumber, u8 Copy_u8EXTIStatus);

u8 EXTI_u8SetInterruptEdge(u8 Copy_u8EXTINumber, u8 Copy_u8EXTIEdge);


u8 EXTI_u8ClearInterruptPending(u8 Copy_u8EXTINumber);

u8 EXTI_u8IsInterruptActive(u8 Copy_u8EXTINumber, u8* Copy_pu8EXTIStatus);

void EXTI_voidChangeEXTISource(u8 Copy_u8IntPort,u8 Copy_u8IntNum);

u8 EXTI_u8SetInterruptCallback(u8 Copy_u8EXTINumber, void (*Copy_pfCallback)(void));

#endif /* EXTI_INTERFACE_H_ */
