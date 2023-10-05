/*
  * File:  MFLASH_Private.h 
 *	SWC:    MFLASH
 *	Version: 1.0 
 *  Created on: 03-09-2023 
 *  Author: Abdallah Ragab 
 */
#ifndef MFLASH_PRIVATE
#define MFLASH_PRIVATE

static u8 MFlash_u8Unlock(void);
static void MFlash_voidLock(void) ;

#define FLASH_KEY1               0x45670123U
#define FLASH_KEY2               0xCDEF89ABU
typedef struct
{
  volatile u32 ACR;      /*!< FLASH access control register,   Address offset: 0x00 */
  volatile u32 KEYR;     /*!< FLASH key register,              Address offset: 0x04 */
  volatile u32 OPTKEYR;  /*!< FLASH option key register,       Address offset: 0x08 */
  volatile u32 SR;       /*!< FLASH status register,           Address offset: 0x0C */
  volatile u32 CR;       /*!< FLASH control register,          Address offset: 0x10 */
  volatile u32 OPTCR;    /*!< FLASH option control register ,  Address offset: 0x14 */
} FLASH_T;

#define MFLASH_SUPPORTED_SECTORS_MASK (MFLASH_Sector_0 | MFLASH_Sector_1 | MFLASH_Sector_2 | MFLASH_Sector_3 | MFLASH_Sector_4 | MFLASH_Sector_5)

#define FLASH_BASE_ADDRESS		0x40023C00

#define MFLASH			((FLASH_T *)FLASH_BASE_ADDRESS)
/*FLASH_CR BITS MASK*/
#define FLASH_CR_SNB		0x00000078

#endif // MFLASH_PRIVATE
