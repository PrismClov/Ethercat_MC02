/*******************************************************************************
 LAN9252 - Hardware Abtraction Layer header file.

  Company:
    Microchip Technology Inc.

  File Name:
    9252_HW.h

  Description:
    This file contains the defines, function protypes for LAN9252 Hardware Abtraction Layer

  Change History:
    Version		Changes
	0.1			Initial version.
	0.2			-
	0.3			-
	0.4			-
	1.0			-
*******************************************************************************/

/*******************************************************************************
Copyright (c) 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/

#ifndef _9252_HW_H_
#define _9252_HW_H_

///////////////////////////////////////////////////////////////////////////////
// Includes

#include  "esc.h"

    #include "main.h"
    #include "tim.h"
    #include "spi.h"
    #include "gpio.h"

///////////////////////////////////////////////////////////////////////////////
// Defines, types

#define ESC_RD                    0x02 /**< \brief Indicates a read access to ESC or EEPROM*/
#define ESC_WR                    0x04 /**< \brief Indicates a write access to ESC or EEPROM.*/


///////////////////////////////////////////////////////////////////////////////
//9252 HW DEFINES
#define ECAT_REG_BASE_ADDR              0x0300

#define CSR_DATA_REG_OFFSET             0x00
#define CSR_CMD_REG_OFFSET              0x04
#define PRAM_READ_ADDR_LEN_OFFSET       0x08
#define PRAM_READ_CMD_OFFSET            0x0c
#define PRAM_WRITE_ADDR_LEN_OFFSET      0x10
#define PRAM_WRITE_CMD_OFFSET           0x14

#define PRAM_SPACE_AVBL_COUNT_MASK      0x1f
#define IS_PRAM_SPACE_AVBL_MASK         0x01


#define CSR_DATA_REG                    ECAT_REG_BASE_ADDR+CSR_DATA_REG_OFFSET
#define CSR_CMD_REG                     ECAT_REG_BASE_ADDR+CSR_CMD_REG_OFFSET
#define PRAM_READ_ADDR_LEN_REG          ECAT_REG_BASE_ADDR+PRAM_READ_ADDR_LEN_OFFSET
#define PRAM_READ_CMD_REG               ECAT_REG_BASE_ADDR+PRAM_READ_CMD_OFFSET
#define PRAM_WRITE_ADDR_LEN_REG         ECAT_REG_BASE_ADDR+PRAM_WRITE_ADDR_LEN_OFFSET
#define PRAM_WRITE_CMD_REG              ECAT_REG_BASE_ADDR+PRAM_WRITE_CMD_OFFSET

#define PRAM_READ_FIFO_REG              0x04
#define PRAM_WRITE_FIFO_REG             0x20

#define HBI_INDEXED_DATA0_REG           0x04
#define HBI_INDEXED_DATA1_REG           0x0c
#define HBI_INDEXED_DATA2_REG           0x14

#define HBI_INDEXED_INDEX0_REG          0x00
#define HBI_INDEXED_INDEX1_REG          0x08
#define HBI_INDEXED_INDEX2_REG          0x10

#define HBI_INDEXED_PRAM_READ_WRITE_FIFO    0x18

#define PRAM_RW_ABORT_MASK      (1 << 30)
#define PRAM_RW_BUSY_32B        (1 << 31)
#define PRAM_RW_BUSY_8B         (1 << 7)
#define PRAM_SET_READ           (1 << 6)
#define PRAM_SET_WRITE          0


//#define 

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Hardware timer settings

#define ECAT_TIMER_INC_P_MS              40000 /**< \brief 312 ticks per ms*/


///////////////////////////////////////////////////////////////////////////////
// Interrupt and Timer Defines

/* ESC 相关中断源：PDI / SYNC0 / SYNC1 / ECAT Timer。
   读 AL Event(0x0220) 或访问 ESC 关键区时必须全部屏蔽，保证读取原子性。
   使用嵌套计数，允许在已屏蔽的临界区内再次调用。 */
extern volatile uint8_t escIntNest;

#define ESC_INT_DISABLE_SOURCES() do { \
    HAL_NVIC_DisableIRQ(PDI_IRQ_EXTI_IRQn); \
    HAL_NVIC_DisableIRQ(EXTI0_IRQn); \
    HAL_NVIC_DisableIRQ(EXTI1_IRQn); \
    HAL_NVIC_DisableIRQ(TIM6_DAC_IRQn); \
} while (0)

#define ESC_INT_ENABLE_SOURCES() do { \
    HAL_NVIC_EnableIRQ(PDI_IRQ_EXTI_IRQn); \
    HAL_NVIC_EnableIRQ(EXTI0_IRQn); \
    HAL_NVIC_EnableIRQ(EXTI1_IRQn); \
    HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn); \
} while (0)

#ifndef DISABLE_ESC_INT
    #define DISABLE_ESC_INT() do { \
        uint32_t __escPrimask = __get_PRIMASK(); \
        __disable_irq(); \
        if (escIntNest++ == 0) ESC_INT_DISABLE_SOURCES(); \
        __set_PRIMASK(__escPrimask); \
    } while (0)
#endif
#ifndef ENABLE_ESC_INT
    #define ENABLE_ESC_INT() do { \
        uint32_t __escPrimask = __get_PRIMASK(); \
        __disable_irq(); \
        if (escIntNest && --escIntNest == 0) ESC_INT_ENABLE_SOURCES(); \
        __set_PRIMASK(__escPrimask); \
    } while (0)
#endif

//TODO
#ifndef HW_GetTimer
    #define HW_GetTimer()       __HAL_TIM_GET_COUNTER(&htim6) /**< \brief Access to the hardware timer*/
#endif

#ifndef HW_ClearTimer
    #define HW_ClearTimer()       __HAL_TIM_SET_COUNTER(&htim6,0) /**< \brief Clear the hardware timer*/
#endif

#endif // end of #ifdef PIC32_HW


///////////////////////////////////////////////////////////////////////////////
// Interrupt and Timer defines

#define HW_EscReadWord(WordValue, Address) HW_EscRead(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief 16Bit ESC read access*/
#define HW_EscReadDWord(DWordValue, Address) HW_EscRead(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief 32Bit ESC read access*/
#define HW_EscReadByte(ByteValue, Address) HW_EscRead(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1) /**< \brief 8Bit ESC read access*/
#define HW_EscReadMbxMem(pData,Address,Len) HW_EscRead(((MEM_ADDR *)(pData)),((UINT16)(Address)),(Len)) /**< \brief The mailbox data is stored in the local uC memory therefore the default read function is used.*/

#define HW_EscReadWordIsr(WordValue, Address) HW_EscReadIsr(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief Interrupt specific 16Bit ESC read access*/
#define HW_EscReadDWordIsr(DWordValue, Address) HW_EscReadIsr(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief Interrupt specific 32Bit ESC read access*/
#define HW_EscReadByteIsr(ByteValue, Address) HW_EscReadIsr(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1) /**< \brief Interrupt specific 8Bit ESC read access*/


#define HW_EscWriteWord(WordValue, Address) HW_EscWrite(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief 16Bit ESC write access*/
#define HW_EscWriteDWord(DWordValue, Address) HW_EscWrite(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief 32Bit ESC write access*/
#define HW_EscWriteByte(ByteValue, Address) HW_EscWrite(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1) /**< \brief 8Bit ESC write access*/
#define HW_EscWriteMbxMem(pData,Address,Len) HW_EscWrite(((MEM_ADDR *)(pData)),((UINT16)(Address)),(Len)) /**< \brief The mailbox data is stored in the local uC memory therefore the default write function is used.*/

#define HW_EscWriteWordIsr(WordValue, Address) HW_EscWriteIsr(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief Interrupt specific 16Bit ESC write access*/
#define HW_EscWriteDWordIsr(DWordValue, Address) HW_EscWriteIsr(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief Interrupt specific 32Bit ESC write access*/
#define HW_EscWriteByteIsr(ByteValue, Address) HW_EscWriteIsr(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1) /**< \brief Interrupt specific 8Bit ESC write access*/

///////////////////////////////////////////////////////////////////////////////


#if _9252_HW_
    #define PROTO
#else
    #define PROTO extern
#endif

	///////////////////////////////////////////////////////////////////////////////
	// Global variables extern

	///////////////////////////////////////////////////////////////////////////////
	// Global functions prototype

	PROTO UINT8 HW_Init(void);
	PROTO void HW_Release(void);
	PROTO UINT16 HW_GetALEventRegister(void);

	PROTO UINT16 HW_GetALEventRegister_Isr(void);

	PROTO void HW_ResetALEventMask(UINT16 intMask);
	PROTO void HW_SetALEventMask(UINT16 intMask);

	PROTO void HW_EscRead( MEM_ADDR * pData, UINT16 Address, UINT16 Len );
	PROTO void HW_EscReadIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

	PROTO void HW_EscWrite( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

	PROTO void HW_EscWriteIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

	PROTO void HW_DisableSyncManChannel(UINT8 channel);
	PROTO void HW_EnableSyncManChannel(UINT8 channel);
	PROTO TSYNCMAN ESCMEM *HW_GetSyncMan(UINT8 channel);
    PROTO void HW_SetLed(UINT8 RunLed,UINT8 ErrLed);

	///////////////////////////////////////////////////////////////////////////////
	// ESC Access macros

	#if _9252_PIC32HW_
		// Place-holder
	#endif //#if _9252_PIC32HW_

#undef    PROTO

