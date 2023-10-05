/*
  * File:  MFLASH_Interface.h 
 *	SWC:    MFLASH
 *	Version: 1.0 
 *  Created on: 03-09-2023 
 *  Author: Abdallah Ragab 
 */
#ifndef MFLASH_INTERFACE
#define MFLASH_INTERFACE

u8 MFlash_u8EraseSector(u8 Copy_u32Sector) ;
u8 MFlash_u8Write(u32 Copy_u32Address,u32* Ptr_u32Data,u32 Copy_u32Size  ) ;

#define MFLASH_Sector_0		0	 /* Sector at address 0x08000000  */
#define MFLASH_Sector_1		1	 /* Sector at address 0x08004000  */
#define MFLASH_Sector_2		2	 /* Sector at address 0x08008000  */
#define MFLASH_Sector_3		3	 /* Sector at address 0x0800C000  */
#define MFLASH_Sector_4		4	 /* Sector at address 0x08010000  */
#define MFLASH_Sector_5 	5	 /* Sector at address 0x08020000  */

#define MFLASH_Sector_5_START 	0x08020000	 /* Sector at address 0x08020000  */
#define MFLASH_Sector_5_END 	0x0803FFFF	 /* Sector at address 0x08020000  */

#endif // MFLASH_INTERFACE
