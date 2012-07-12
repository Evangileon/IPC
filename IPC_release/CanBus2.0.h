 /*****************************************************************************\
*  This is a part of the Advantech Source Code.
*  Copyright (C) 1997 Advantech Corporation.
*  All rights reserved.
*
*  PROGRAM: CanBusEx.h -> PCL-841 driver
*  PURPOSE: Device Functions subroutines.
*
*
*  HISTORY:
*    2002-10-08 Created by TangBo( Support CANBUS 2.0A and 2.0B Protocol )
\*****************************************************************************/

#ifndef _INC_CANBUS2_0_
#define _INC_CANBUS2_0_

#include "wtypes.h"

#ifdef _WIN31
#define FLOAT   float
#define CHAR    char
#define USHORT  unsigned short
#define SHORT   short
#define ULONG   unsigned long
#endif
#ifdef __cplusplus
extern "C"
{
#endif

#define     PUBLIC   extern
#define     PRIVATE  static

#if !defined(_WIN31)
   #define FEXPORT __declspec (dllexport)
   #define FTYPE  CALLBACK
#else
   #define FEXPORT extern
   #define FTYPE  FAR PASCAL
#endif

/**************************************************************************
// define the wParam in user window message
***************************************************************************/

#define CAN_TRANSFER             0  // CAN Section
#define CAN_RECEIVE              1
#define CAN_ERROR                2
#define CAN_WAKEUP               3  // Only can used in canbus 20.B

// Added by TangBo 2002.10.08
/****************************************************************************
    Define maximum canbus prots number
*****************************************************************************/
#define	MAX_CANBUS_PORT         10 //

#define	CANBUS_SYSCLOCK         16 // 16MHz, used to calculate baudrate

/****************************************************************************
    Can Bus work mode define
*****************************************************************************/
#define CANBUS_PROTOCOL_20A      0  // protocol 2.0A
#define CANBUS_PROTOCOL_20B      1  // protocol 2.0B
#define CANBUS_RESETMODE         1  // Reset mode status
#define CANBUS_WORKMODE          0  // work mode status

/****************************************************************************
    SJA1000 PeliCAN Mode Register Offset Declaration
*****************************************************************************/
#define PELICAN_MODE_REGISTER                0
#define PELICAN_COMMAND_REGISTER             1
#define PELICAN_STATUS_REGISTER              2
#define PELICAN_INTERRUPTSTATUS_REGISTER     3
#define PELICAN_INTERRUPTMASK_REGISTER       4
#define PELICAN_RESERVED1_REGISTER           5
#define PELICAN_BUSTIME0_REGISTER            6
#define PELICAN_BUSTIME1_REGISTER            7
#define PELICAN_OUTCONTROL_REGISTER          8
#define PELICAN_RESERVED2_REGISTER           9
#define PELICAN_RESERVED3_REGISTER           10
#define PELICAN_ARBITRATECATCH_REGISTER      11
#define PELICAN_ERRORCODECATCH_REGISTER      12
#define PELICAN_ERRORALARMLIMIT_REGISTER     13
#define PELICAN_RXERRORCOUNT_REGISTER        14
#define PELICAN_TXERRORCOUNT_RETGISTER       15
#define PELICAN_ACCEPTCODE0_REGISTER         16
#define PELICAN_ACCEPTCODE1_REGISTER         17
#define PELICAN_ACCEPTCODE2_REGISTER         18
#define PELICAN_ACCEPTCODE3_REGISTER         19
#define PELICAN_ACCEPTMASK0_REGISTER         20
#define PELICAN_ACCEPTMASK1_REGISTER         21
#define PELICAN_ACCEPTMASK2_REGISTER         22
#define PELICAN_ACCEPTMASK3_REGISTER         23
#define PELICAN_RXFRAMEINFOR_REGISTER        16
#define PELICAN_RXIDENTIFY1_REGISTER         17
#define PELICAN_RXIDENTIFY2_REGISTER         18
#define PELICAN_RXIDENTIFY3_REGISTER         19
#define PELICAN_RXIDENTIFY4_REGISTER         20
// Standard frame format data register offset
#define PELICAN_RXSFFDATA1_REGISTER          19    
// extended frame format data register offset
#define PELICAN_RXEFFDATA1_REGISTER          21
#define PELICAN_TXFRAMEINFOR_REGISTER        16
#define PELICAN_TXIDENTIFY1_REGISTER         17
#define PELICAN_TXIDENTIFY2_REGISTER         18
#define PELICAN_TXIDENTIFY3_REGISTER         19
#define PELICAN_TXIDENTIFY4_REGISTER         20
// Standard frame format data register offset
#define PELICAN_TXSFFDATA1_REGISTER          19
// extended frame format data register offset
#define PELICAN_TXEFFDATA1_REGISTER          21
#define PELICAN_RXINFORCOUNT_REGISTER        29
#define PELICAN_RXBUFFERADDRESS_REGISTER     30    
#define PELICAN_TIMERDIVIDE_REGISTER         31

/***************************************************************************
    Define board vendor ID
**************************************************************************/
#define    AAC      0x0000                     //Advantech
#define    MB       0x1000                     //Keithley/MetraByte
#define    BB       0x2000                     //Burr Brown
#define    GRAYHILL 0x3000                     //Grayhill
#define    KGS      0x4000

/****************************************************************************
    Define DAS I/O Board ID.
****************************************************************************/
#define      NONE           0x00              // not available
	
//\\\\\\\\\\\\\\\\\\\ V2.1 //////////////////////
// Notes:
// change the software defined ID from Board ID to Product ID.
// Board ID is especially used as the term of hardware dip-switch ID.
//
//Advantech Product ID
///////////////////// V2.1 \\\\\\\\\\\\\\\\\\\\\\/
//Advantech board ID
#define      BD_DEMO        (AAC | 0x00)     // demo board
#define      BD_PCL711      (AAC | 0x01)     // PCL-711 board
#define      BD_PCL812      (AAC | 0x02)     // PCL-812 board
#define      BD_PCL812PG    (AAC | 0x03)     // PCL-812PG board
#define      BD_PCL718      (AAC | 0x04)     // PCL-718 board
#define      BD_PCL818      (AAC | 0x05)     // PCL-818 board
#define      BD_PCL814      (AAC | 0x06)     // PCL-814 board
#define      BD_PCL720      (AAC | 0x07)     // PCL-722 board
#define      BD_PCL722      (AAC | 0x08)     // PCL-720 board
#define      BD_PCL724      (AAC | 0x09)     // PCL-724 board
#define      BD_AD4011      (AAC | 0x0a)     // ADAM 4011 Module
#define      BD_AD4012      (AAC | 0x0b)     // ADAM 4012 Module
#define      BD_AD4013      (AAC | 0x0c)     // ADAM 4013 Module
#define      BD_AD4021      (AAC | 0x0d)     // ADAM 4021 Module
#define      BD_AD4050      (AAC | 0x0e)     // ADAM 4050 Module
#define      BD_AD4060      (AAC | 0x0f)     // ADAM 4060 Module
#define      BD_PCL711B     (AAC | 0x10)     // PCL-711B
#define      BD_PCL818H     (AAC | 0x11)     // PCL-818H
#define      BD_PCL814B     (AAC | 0x12)     // PCL-814B
#define      BD_PCL816      (AAC | 0x13)     // PCL-816
#define      BD_814_DIO_1   (AAC | 0x14)     // PCL-816/814B 8255 DIO module
#define      BD_814_DA_1    (AAC | 0x15)     // PCL-816/814B 12 bit D/A module
#define      BD_816_DA_1    (AAC | 0x16)     // PCL-816/814B 16 bit D/A module
#define      BD_PCL830      (AAC | 0x17)     // PCL-830 9513A Counter Card
#define      BD_PCL726      (AAC | 0x18)     // PCL-726 D/A card
#define      BD_PCL727      (AAC | 0x19)     // PCL-727 D/A card
#define      BD_PCL728      (AAC | 0x1a)     // PCL-728 D/A card
#define      BD_AD4052      (AAC | 0x1b)     // ADAM 4052 Module
#define      BD_AD4014D     (AAC | 0x1c)     // ADAM 4014D Module
#define      BD_AD4017      (AAC | 0x1d)     // ADAM 4017 Module
#define      BD_AD4080D     (AAC | 0x1e)     // ADAM 4080D Module
#define      BD_PCL721      (AAC | 0x1f)     // PCL-721 32-bit Digital in
#define      BD_PCL723      (AAC | 0x20)     // PCL-723 24-bit Digital in
#define      BD_PCL818L     (AAC | 0x21)     // PCL-818L
#define      BD_PCL818HG    (AAC | 0x22)     // PCL-818HG
#define      BD_PCL1800     (AAC | 0x23)     // PCL-1800
#define      BD_PAD71A      (AAC | 0x24)     // PCIA-71A
#define      BD_PAD71B      (AAC | 0x25)     // PCIA-71B
#define      BD_PCR420      (AAC | 0x26)     // PCR-420
#define      BD_PCL731      (AAC | 0x27)     // PCL-731 48-bit Digital I/O card
#define      BD_PCL730      (AAC | 0x28)     // PCL-730 board
#define      BD_PCL813      (AAC | 0x29)     // PCL-813 32-channel A/D card
#define      BD_PCL813B     (AAC | 0x2a)     // PCL-813B 32-channel A/D card
#define      BD_PCL818HD    (AAC | 0x2b)     // PCL-818HD
#define      BD_PCL725      (AAC | 0x2c)     // PCL-725 digital I/O card
#define      BD_PCL732      (AAC | 0x2d)     // PCL-732 high speed DIO card
#define      BD_AD4018      (AAC | 0x2e)     // ADAM 4018 Module
#define      BD_814_TC_1    (AAC | 0x2f)     // PCL-816/814B 16 bit TC module
#define      BD_PAD71C      (AAC | 0x30)     // PCIA-71C
#define      BD_AD4024      (AAC | 0x31)     // ADAM 4024
#define      BD_AD5017      (AAC | 0x32)     // ADAM 5017
#define      BD_AD5018      (AAC | 0x33)     // ADAM 5018
#define      BD_AD5024      (AAC | 0x34)     // ADAM 5024
#define      BD_AD5051      (AAC | 0x35)     // ADAM 5051
#define      BD_AD5060      (AAC | 0x36)     // ADAM 5060
#define      BD_PCM3718     (AAC | 0x37)     // PCM-3718
#define      BD_PCM3724     (AAC | 0x38)     // PCM-3724
#define      BD_MIC2718     (AAC | 0x39)     // MIC-2718
#define      BD_MIC2728     (AAC | 0x3a)     // MIC-2728
#define      BD_MIC2730     (AAC | 0x3b)     // MIC-2730
#define      BD_MIC2732     (AAC | 0x3c)     // MIC-2732
#define      BD_MIC2750     (AAC | 0x3d)     // MIC-2750
#define      BD_MIC2752     (AAC | 0x3e)     // MIC-2752
#define      BD_PCL733      (AAC | 0x3f)     // PCL-733
#define      BD_PCL734      (AAC | 0x40)     // PCL-734
#define      BD_PCL735      (AAC | 0x41)     // PCL-735
#define      BD_AD4018M     (AAC | 0x42)     // ADAM 4018M Module
#define      BD_AD4080      (AAC | 0x43)     // ADAM 4080 Module
#define      BD_PCL833      (AAC | 0x44)     // PCL-833
#define      BD_PCA6157     (AAC | 0x45)     // PCA-6157
#define      BD_PCA6149     (AAC | 0x46)     // PCA-6149
#define      BD_PCA6147     (AAC | 0x47)     // PCA-6147
#define      BD_PCA6137     (AAC | 0x48)     // PCA-6137
#define      BD_PCA6145     (AAC | 0x49)     // PCA-6145
#define      BD_PCA6144     (AAC | 0x4a)     // PCA-6144
#define      BD_PCA6143     (AAC | 0x4b)     // PCA-6143
#define      BD_PCA6134     (AAC | 0x4c)     // PCA-6134
#define      BD_AD5056      (AAC | 0x4d)     // ADAM 5056 for Device Net
#define      BD_DN5017      (AAC | 0x4e)     // ADAM 5017 for Device Net
#define      BD_DN5018      (AAC | 0x4f)     // ADAM 5018 for Device Net
#define      BD_DN5024      (AAC | 0x50)     // ADAM 5024 for Device Net
#define      BD_DN5051      (AAC | 0x51)     // ADAM 5051 for Device Net
#define      BD_DN5056      (AAC | 0x52)     // ADAM 5056 for Device Net
#define      BD_DN5060      (AAC | 0x53)     // ADAM 5060 for Device Net
#define      BD_PCL836      (AAC | 0x54)     // PCL-836
#define      BD_PCL841      (AAC | 0x55)     // PCL-841
#define      BD_DN5050      (AAC | 0x56)     // ADAM 5050 for DeviceNet
#define      BD_DN5052      (AAC | 0x57)     // ADAM 5052 for DeviceNet
#define      BD_AD5050      (AAC | 0x58)     // ADAM 5050 for RS-485
#define      BD_AD5052      (AAC | 0x59)     // ADAM 5052 for RS-485
#define      BD_PCM3730     (AAC | 0x5a)     // PCM-3730
#define      BD_AD4011D     (AAC | 0x5b)     // ADAM 4011D
#define      BD_AD4016      (AAC | 0x5c)     // ADAM 4016
#define      BD_AD4053      (AAC | 0x5d)     // ADAM 4053
#define      BD_PCI1750     (AAC | 0x5e)     // PCI-1750
#define      BD_PCI1751     (AAC | 0x5f)     // PCI-1751
#define      BD_PCI1710     (AAC | 0x60)     // PCI-1710
#define      BD_PCI1712     (AAC | 0x61)     // PCI-1712
#define      BD_AD5068      (AAC | 0x62)     // ADAM 5068
#define      BD_AD5013      (AAC | 0x63)     // ADAM 5013
#define      BD_AD5017H     (AAC | 0x64)     // ADAM 5017H
#define      BD_AD5080      (AAC | 0x65)     // ADAM 5080 
#define      BD_MIC2760     (AAC | 0x66)     // MIC-2760
#define      BD_PCI1710HG   (AAC | 0x67)     // PCI-1710HG
#define      BD_PCI1713     (AAC | 0x68)     // PCI-1713
#define      BD_PCI1753     (AAC | 0x69)     // PCI-1753
#define      BD_PCI1760     (AAC | 0x6a)     // PCI-1760
#define      BD_PCI1720     (AAC | 0x6b)     // PCI-1720
#define      BD_PCL752      (AAC | 0x6c)     // PCL-772
#define      BD_PCM3718H    (AAC | 0x6d)     // PCM-3718H
#define      BD_PCM3718HG   (AAC | 0x6e)     // PCM-3718HG
#define      BD_DN5068      (AAC | 0x6f)     // ADAM 5068 for Device Net
#define      BD_DN5013      (AAC | 0x70)     // ADAM 5013 for Device Net
#define      BD_DN5017H     (AAC | 0x71)     // ADAM 5017H for Device Net
#define      BD_DN5080      (AAC | 0x72)     // ADAM 5080 for Device Net (unavailable)
#define      BD_PCI1711     (AAC | 0x73)     // PCI-1711
#define      BD_PCI1711L    (AAC | 0x75)     // PCI-1711
#define      BD_PCI1716     (AAC | 0x74)     // PCI-1716
#define      BD_PCI1731     (AAC | 0x75)     // PCI-1731
#define      BD_AD5051D     (AAC | 0x76)     // ADAM 5051D 
#define      BD_AD5056D     (AAC | 0x77)     // ADAM 5056D 
#define      BD_DN5051D     (AAC | 0x78)     // ADAM 5051D for Device Net
#define      BD_DN5056D     (AAC | 0x79)     // ADAM 5056D for Device Net
#define      BD_SIMULATE    (AAC | 0x7a)     // Simulate IO
#define      BD_PCI1754     (AAC | 0x7b)     // PCI-1754
#define      BD_PCI1752     (AAC | 0x7c)     // PCI-1752
#define      BD_PCI1756     (AAC | 0x7d)     // PCI-1756
#define      BD_PCL839      (AAC | 0x7e)     // PCL-839
#define      BD_PCM3725     (AAC | 0x7f)     // PCM-3725
#define      BD_PCI1762     (AAC | 0x80)     // PCI-1762
#define      BD_PCI1721     (AAC | 0x81)     // PCI-1721
#define      BD_PCI1761     (AAC | 0x82)     // PCI-1761
#define      BD_PCI1723     (AAC | 0x83)     // PCI-1723
#define      BD_AD4019      (AAC | 0X84)     // ADAM 4019 Module
#define      BD_AD5055      (AAC | 0X85)     // ADAM 5055 Module
#define      BD_AD4015      (AAC | 0X86)     // ADAM 4015 Module
#define      BD_PCI1730     (AAC | 0x87)     // PCI-1730
#define      BD_PCI1733     (AAC | 0x88)     // PCI-1733
#define      BD_PCI1734     (AAC | 0x89)     // PCI-1734
#define      BD_MIC2750A    (AAC | 0x8A)     // MIC-2750A
#define      BD_MIC2718A    (AAC | 0x8B)     // MIC-2718A
#define      BD_AD4017P     (AAC | 0X8c)     // ADAM 4017P Module
#define      BD_AD4051      (AAC | 0X8d)     // ADAM 4051 Module
#define      BD_AD4055      (AAC | 0X8e)     // ADAM 4055 Module
#define      BD_AD4018P     (AAC | 0x8f)     // ADAM 4018P Module
#define      BD_PCI1710L    (AAC | 0x90)     // PCI-1710L
#define      BD_PCI1710HGL  (AAC | 0x91)     // PCI-1710HGL
#define      BD_AD4068      (AAC | 0x92)     // ADAM-4068
#define      BD_PCM3712     (AAC | 0x93)     // PCM-3712
#define      BD_PCM3723     (AAC | 0x94)     // PCM-3723

#ifdef _WIN32_WCE
//Add by Ann.He 03/02/21
#define      BD_DATALGR_KR1     (AAC | 0x81)     // PCM-KR1
//end
#endif

//\\\\\\\\\\\\\\\\\\\ V2.0B /////////////////////
#define      BD_PCI1780     (AAC | 0x95)     // PCI-1780
#define      BD_CPCI3756    (AAC | 0x96)     // CPCI-3756
///////////////////// V2.0B \\\\\\\\\\\\\\\\\\\\\/

//\\\\\\\\\\\\\\\\\\\ V2.0C /////////////////////
#define      BD_PCI1755     (AAC | 0x97)     // PCI-1755
#define      BD_PCI1714     (AAC | 0x98)     // PCI-1714
///////////////////// V2.0B ////////////////////

//\\\\\\\\\\\\\\\\\\\ V2.1 /////////////////////
#define      BD_PCI1757     (AAC | 0x99)     // PCI-1757
///////////////////// V2.1 ////////////////////

//\\\\\\\\\\\\\\\\\\\ V2.1a /////////////////////
#define      BD_MIC3716    (AAC | 0x9A)     // MIC-3716
#define      BD_MIC3761    (AAC | 0x9B)     // MIC-3761
#define      BD_MIC3753    (AAC | 0x9C)     // MIC-3753
#define      BD_MIC3780    (AAC | 0x9D)     // MIC-3780
///////////////////// V2.1a ////////////////////

#define      BD_PCI1724    (AAC | 0x9E)     // PCI-1724
#define      BD_AD4015T    (AAC | 0x9F)     // ADAM 4015T Module
#define      BD_UNO2052    (AAC | 0xA0)     // UNO  2052 Module
#define      BD_PCI1680    (AAC | 0xA1)     // PCI-1680

//\\\\\\\\\\\\\\\\\\\ V2.2 /////////////////////
#define      BD_PCL839P    (AAC | 0xA2)     // PCI-839+
#define      BD_PCI1758UDI     (AAC | 0xA3)     // PCI-1758UDI
#define      BD_PCI1758UDO     (AAC | 0xA4)     // PCI-1758UDO
#define      BD_PCI1747     (AAC | 0xA5)     // PCI-1747
#define      BD_PCM3780     (AAC | 0xA6)     // PCM-3780 
#define      BD_MIC3747     (AAC | 0xA7)     // MIC-3747
#define      BD_PCI1758UDIO    (AAC | 0xA8)     // PCI-1758UDIO
///////////////////// V2.2 ////////////////////


#define      BD_MICRODAC    (GRAYHILL | 0x1) // Grayhill MicroDAC Board ID
#define      BD_GIA10       (KGS | 0x01)     // KGS GIA-10 module Board ID

/*****************************************************************************
    Define Expansion Board ID.
*****************************************************************************/
#define AAC_EXP            (AAC | 0x00000100)   //Advantech expansion bits

//define Advantech expansion board ID.
#define      BD_PCLD780     0x00000000          // PCLD-780
#define      BD_PCLD789     (AAC_EXP | 0x0)     // PCLD-789
#define      BD_PCLD779     (AAC_EXP | 0x1)     // PCLD-779
#define      BD_PCLD787     (AAC_EXP | 0x2)     // PCLD-787
#define      BD_PCLD8115    (AAC_EXP | 0x3)     // PCLD-8115
#define      BD_PCLD770     (AAC_EXP | 0x4)     // PCLD-770
#define      BD_PCLD788     (AAC_EXP | 0x5)     // PCLD-788
#define      BD_PCLD8710    (AAC_EXP | 0x6)     // PCLD-8710
#define      BD_PCLD8712    (AAC_EXP | 0x7)     // PCLD-8712


/**************************************************************************
    Define Status Code
***************************************************************************/
#define SUCCESS                  0
#define DrvErrorCode             1
#define KeErrorCode              100
#define DnetErrorCode            200
#define GeniDrvErrorCode         300
#define OPCErrorCode             1000
#define MemoryAllocateFailed     (DrvErrorCode + 0)
#define ConfigDataLost           (DrvErrorCode + 1)
#define InvalidDeviceHandle      (DrvErrorCode + 2)
#define AIConversionFailed       (DrvErrorCode + 3)
#define AIScaleFailed            (DrvErrorCode + 4)
#define SectionNotSupported      (DrvErrorCode + 5)
#define InvalidChannel           (DrvErrorCode + 6)
#define InvalidGain              (DrvErrorCode + 7)
#define DataNotReady             (DrvErrorCode + 8)
#define InvalidInputParam        (DrvErrorCode + 9)
#define NoExpansionBoardConfig   (DrvErrorCode + 10)
#define InvalidAnalogOutValue    (DrvErrorCode + 11)
#define ConfigIoPortFailed       (DrvErrorCode + 12)
#define CommOpenFailed           (DrvErrorCode + 13)
#define CommTransmitFailed       (DrvErrorCode + 14)
#define CommReadFailed           (DrvErrorCode + 15)
#define CommReceiveFailed        (DrvErrorCode + 16)
#define CommConfigFailed         (DrvErrorCode + 17)
#define CommChecksumError        (DrvErrorCode + 18)
#define InitError                (DrvErrorCode + 19)
#define DMABufAllocFailed        (DrvErrorCode + 20)
#define IllegalSpeed             (DrvErrorCode + 21)
#define ChanConflict             (DrvErrorCode + 22)
#define BoardIDNotSupported      (DrvErrorCode + 23)
#define FreqMeasurementFailed    (DrvErrorCode + 24)
#define CreateFileFailed         (DrvErrorCode + 25)
#define FunctionNotSupported     (DrvErrorCode + 26)
#define LoadLibraryFailed        (DrvErrorCode + 27)
#define GetProcAddressFailed     (DrvErrorCode + 28)
#define InvalidDriverHandle      (DrvErrorCode + 29)
#define InvalidModuleType        (DrvErrorCode + 30)
#define InvalidInputRange        (DrvErrorCode + 31)
#define InvalidWindowsHandle     (DrvErrorCode + 32)
#define InvalidCountNumber       (DrvErrorCode + 33)
#define InvalidInterruptCount    (DrvErrorCode + 34)
#define InvalidEventCount        (DrvErrorCode + 35)
#define OpenEventFailed          (DrvErrorCode + 36)
#define InterruptProcessFailed   (DrvErrorCode + 37)
#define InvalidDOSetting         (DrvErrorCode + 38)
#define InvalidEventType         (DrvErrorCode + 39)
#define EventTimeOut             (DrvErrorCode + 40)
#define InvalidDmaChannel        (DrvErrorCode + 41)
#define IntDamChannelBusy        (DrvErrorCode + 42)
//
#define CheckRunTimeClassFailed  (DrvErrorCode + 43)
#define CreateDllLibFailed       (DrvErrorCode + 44)
#define ExceptionError           (DrvErrorCode + 45)
#define RemoveDeviceFailed       (DrvErrorCode + 46)
#define BuildDeviceListFailed    (DrvErrorCode + 47)
#define NoIOFunctionSupport      (DrvErrorCode + 48)

//\\\\\\\\\\\\\\\\\\\ V2.0B /////////////////////
#define ResourceConflict        (DrvErrorCode + 49)
///////////////////// V2.0B \\\\\\\\\\\\\\\\\\\\\/

//\\\\\\\\\\\\\\\\\\\ V2.1 //////////////////////
#define InvalidClockSource		 (DrvErrorCode + 50)
#define InvalidPacerRate		 (DrvErrorCode + 51)
#define InvalidTriggerMode     (DrvErrorCode + 52)
#define InvalidTriggerEdge     (DrvErrorCode + 53)
#define InvalidTriggerSource   (DrvErrorCode + 54)
#define InvalidTriggerVoltage  (DrvErrorCode + 55)
#define InvalidCyclicMode      (DrvErrorCode + 56)
#define InvalidDelayCount      (DrvErrorCode + 57)
#define InvalidBuffer          (DrvErrorCode + 58)
#define OverloadedPCIBus       (DrvErrorCode + 59)
#define OverloadedInterruptRequest (DrvErrorCode + 60)
///////////////////// V2.1 \\\\\\\\\\\\\\\\\\\\\\/

//\\\\\\\\\\\\\\\\\\\ V2.0C /////////////////////
#define ParamNameNotSupported      (DrvErrorCode + 61)
///////////////////// V2.0C /////////////////////

/*#define NoSerialFunctionSupported   (DrvErrorCode + 49)
#define NoAiFunctionSupported      (DrvErrorCode + 50
#define NoAoFunctionSupported      (DrvErrorCode + 51)
#define NoDiFunctionSupported      (DrvErrorCode + 52)
#define NoDoFunctionSupported      (DrvErrorCode + 53)
#define NoAlarmFunctionSupported    (DrvErrorCode + 54)
#define NoCounterFunctionSupported  (DrvErrorCode + 55)
#define NoTempFunctionSupported      (DrvErrorCode + 56)
#define NoIOFunctionSupported      (DrvErrorCode + 57)*/
#define NoSerialFunctionSupported  (GeniDrvErrorCode + 5)
#define NoAiFunctionSupported      (GeniDrvErrorCode + 6)
#define NoAoFunctionSupported      (GeniDrvErrorCode + 7)
#define NoDiFunctionSupported      (GeniDrvErrorCode + 8)
#define NoDoFunctionSupported      (GeniDrvErrorCode + 9)
#define NoAlarmFunctionSupported   (GeniDrvErrorCode + 10)
#define NoCounterFunctionSupported (GeniDrvErrorCode + 11)
#define NoTempFunctionSupported    (GeniDrvErrorCode + 12)
#define NoIOFunctionSupported      (GeniDrvErrorCode + 13)

#define KeInvalidHandleValue     (KeErrorCode + 0)
#define KeFileNotFound           (KeErrorCode + 1)
#define KeInvalidHandle          (KeErrorCode + 2)
#define KeTooManyCmds            (KeErrorCode + 3)
#define KeInvalidParameter       (KeErrorCode + 4)
#define KeNoAccess               (KeErrorCode + 5)
#define KeUnsuccessful           (KeErrorCode + 6)
#define KeConInterruptFailure    (KeErrorCode + 7)
#define KeCreateNoteFailure      (KeErrorCode + 8)
#define KeInsufficientResources  (KeErrorCode + 9)
#define KeHalGetAdapterFailure   (KeErrorCode +10)
#define KeOpenEventFailure       (KeErrorCode +11)
#define KeAllocCommBufFailure    (KeErrorCode +12)
#define KeAllocMdlFailure        (KeErrorCode +13)
#define KeBufferSizeTooSmall     (KeErrorCode +14)

#define DNInitFailed              (DnetErrorCode + 1)
#define DNSendMsgFailed           (DnetErrorCode + 2)
#define DNRunOutOfMsgID           (DnetErrorCode + 3)
#define DNInvalidInputParam       (DnetErrorCode + 4)
#define DNErrorResponse           (DnetErrorCode + 5)
#define DNNoResponse              (DnetErrorCode + 6)
#define DNBusyOnNetwork           (DnetErrorCode + 7)
#define DNUnknownResponse         (DnetErrorCode + 8)
#define DNNotEnoughBuffer         (DnetErrorCode + 9)
#define DNFragResponseError       (DnetErrorCode + 10)
#define DNTooMuchDataAck          (DnetErrorCode + 11)
#define DNFragRequestError        (DnetErrorCode + 12)
#define DNEnableEventError        (DnetErrorCode + 13)
#define DNCreateOrOpenEventError  (DnetErrorCode + 14)
#define DNIORequestError          (DnetErrorCode + 15)
#define DNGetEventNameError       (DnetErrorCode + 16)
#define DNTimeOutError            (DnetErrorCode + 17)
#define DNOpenFailed              (DnetErrorCode + 18)
#define DNCloseFailed             (DnetErrorCode + 19)
#define DNResetFailed             (DnetErrorCode + 20)


/**************************************************************************
    Can Bus operation result Code Table
***************************************************************************/
#define CanErrorCode                2000
#define CANPortIsNotOpened          (CanErrorCode + 0)
#define CANInvalidFrameFormat       (CanErrorCode + 1)
#define CANInvalidPortIndex         (CanErrorCode + 2)
#define CANIncompatibleProtocol     (CanErrorCode + 3)
#define CANControllerInResetMode    (CanErrorCode + 4)
#define CANControllerInWorkMode     (CanErrorCode + 5)
#define CANInvalidDataLength        (CanErrorCode + 6)
#define CANBusError                 (CanErrorCode + 7)
#define CANTimeOut                  (CanErrorCode + 8)
#define CANInvalidParameter         (CanErrorCode + 9)
#define CANDataNotReady             (CanErrorCode + 10)
#define CANBusClosed                (CanErrorCode + 11)
#define CANOpenEventFailed          (CanErrorCode + 12)
#define CANCreateDeviceFailed       (CanErrorCode + 13)
#define CANPortOpenedAlready        (CanErrorCode + 14)
#define CANQueryRegistryFailed      (CanErrorCode + 15)
#define CANMapMemoryFailed          (CanErrorCode + 16)
#define CANPortIsNotInitialized     (CanErrorCode + 17)
#define CANPortInitializedAlready   (CanErrorCode + 18)
#define CANSetupPortFailed          (CanErrorCode + 19)

/****************************************************************************
    SJA1000 PeliCAN Mode Flag, Status ,Struct and Type Declaration
*****************************************************************************/
// in prelican mode, use two 2bytes code and mask to filter
#define PELICAN_DOUBLE_FILTER                 0
// in prelican mode, use a 4bytes code and mask to filter
#define PELICAN_SINGLE_FILTER                 8

typedef struct tag_PT_FilterSetting
{
   // filter type: 0 - two 2bytes accept code and accept mask
   //              8 - a 4 bytes accept code and accept mask
   DWORD       dwFilterType;       // Shengkui Modified(WORD --> DWORD), 2004-03-18
   UCHAR       uchAcceptCode0;         
   UCHAR       uchAcceptCode1;         
   UCHAR       uchAcceptCode2;         
   UCHAR       uchAcceptCode3;         
   UCHAR       uchAcceptMask0;         
   UCHAR       uchAcceptMask1;         
   UCHAR       uchAcceptMask2;         
   UCHAR       uchAcceptMask3;         
}PT_FilterSetting, FAR *LPT_FilterSetting;
typedef struct {
	WORD port;
	WORD numneeded;
} CAN_VXD_NUM, *PCAN_VXD_NUM;
typedef struct {
	WORD  port;
	PT_FilterSetting ssFilter;
} CAN_VXD_ACP20B, * PCAN_VXD_ACP20B;
typedef struct {
	WORD port;
	WORD protocoltype;
} CAN_VXD_PROTOCOL, * PCAN_VXD_PROTOCOL;
typedef struct {
	WORD port;
	UCHAR ff;
	UCHAR rtr;      /* EFF RTR 0 0 DLC.3 DLC.2 DLC.1 DLC.0 */
	ULONG id;       /* not present in standard frames */
	UCHAR dlen;
	UCHAR data[8];
} CAN_VXD_MSG_T, *PCAN_VXD_MSG_T;

// Data Frame Format
#define PELICAN_EFF                    0x80     // Extended Frame Format
#define PELICAN_SFF                    0x00     // Standard Frame format

// command regisger
// after wrote data to tx buffer, write this value to
// command reg to start transfer
#define PELICAN_TRANSFERREQUEST        0x01
// write this value to command register, stop transfer
#define PELICAN_TERMINATETRANSFER      0x02
// write this value to command register, release transfer
// buffer, then we can transfer other data
#define PELICAN_RELEASETXBUFFER        0x04
// write this value to command register, clear data overrun status
#define PELICAN_CLEAROVERRUN           0x08
// write this value to command register, the transfer data
// can receive by self at once, this is used to test
#define PELICAN_SELFRECEIVEREQUEST     0x10

// status register
// Ready, some data is in Rx FIFO 
#define PELICAN_DATAREADY              0x01
// Rx FIFO is full, and some data has lost
#define PELICAN_OVERRUN                0x02
// Tx Buffer is ready, we can write data to tx buffer
#define PELICAN_TXBUFFERREADY          0x04
// the last transfer is complete
#define PELICAN_TXSTATUS               0x08
// controller is receiving data from bus
#define PELICAN_RECEIVING              0x10
// controller is transfering data
#define PELICAN_TRANSFERING            0x20
// some error count is to its limit
#define PELICAN_ERRORSTATUS            0x40
// when bus is closed, this bit is set 
#define PELICAN_BUSSTATUS              0x80

typedef struct tag_PT_FrameBuffer
{
	// 0 - EFF, 1 - SFF, Only valid in 20A mode
   WORD        wFrameFormat;
	// if is a remote transfer request frame: TRUE - is, FALSE - Not
   BOOL        bRemoteRequestFrame;    
	// valid data's bytes count
   WORD        wDataLen;
	// when is sff, bit0 - bit 10 is valid
	// when is eff, bit0 - bit 28 is valid
   DWORD       dwID;                  
	// data buffer can contain upto 8 bytes data                                       
   UCHAR       auchData[ 9 ];
	// original data, this field is valid only when receive data
	// it contain the data read from register
   UCHAR       auchDataOriginal[ 14 ];
                                       
   
}PT_FrameBuffer, FAR* LPT_FrameBuffer;


// following declaration is used in CANGetControllerErrCodeEx

// when receiving, error occured
#define PELICAN_ERRCATCH_DIR_RX           0x20
// when transmiting, error occured
#define PELICAN_ERRCATCH_DIR_TX           0x00
// bits error
#define PELICAN_ERRCATCH_TYPE_BITSERROR   0x00
// format error
#define PELICAN_ERRCATCH_TYPE_FORMATERROR 0x40
// fill error
#define PELICAN_ERRCATCH_TYPE_FILLERROR   0x80
// other error
#define PELICAN_ERRCATCH_TYPE_OTHERERROR  0xc0

typedef struct tag_PT_ErrorCodeCatch
{
   
   WORD        wErrorType;					// error type
   WORD        wDirection;					// error direction   
   WORD        wErrorDesc;					// error description code
   UCHAR       uchErrorCode;				// value of error catch register
   UCHAR       auchErrMsg[ 128 ];
}PT_ErrorCodeCatch, FAR* LPT_ErrorCodeCatch;

// following declaration is used in CANGetArbitrationLostCatchMsgEx

typedef struct tag_PT_ArbitrationLostCatch
{
   // Arbitration Lost code
	WORD        wLostCode;
	// value of Arbitration Lost catch register
   UCHAR       uchErrorCode;           
   UCHAR       auchErrMsg[ 128 ];		
}PT_ArbitrationLostCatch, FAR* LPT_ArbitrationLostCatch;

// the interrupt mask value under prelican mode
// interrupt mask register status
#define PELICAN_INTRENABLE_RECEIVE              0x01
#define PELICAN_INTRENABLE_TRANSFER             0x02
#define PELICAN_INTRENABLE_ERRORALARM           0x04
#define PELICAN_INTRENABLE_OVERRUN              0x08
#define PELICAN_INTRENABLE_WAKEUP               0x10
#define PELICAN_INTRENABLE_PASSIVEERROR         0x20
#define PELICAN_INTRENABLE_ARBITRATIONLOST      0x40
#define PELICAN_INTRENABLE_CANBUSERROR          0x80

// interrupt status register status
// after a interrupt occured, we check the value of interrupt status register
#define PELICAN_INTRSTATUS_RECEIVE              0x01
#define PELICAN_INTRSTATUS_TRANSFER             0x02
#define PELICAN_INTRSTATUS_ERRORALARM           0x04
#define PELICAN_INTRSTATUS_OVERRUN              0x08
#define PELICAN_INTRSTATUS_WAKEUP               0x10
#define PELICAN_INTRSTATUS_PASSIVEERROR         0x20
#define PELICAN_INTRSTATUS_ARBITRATIONLOST      0x40
#define PELICAN_INTRSTATUS_CANBUSERROR          0x80

// define windows notification message id
#define WM_CANTRANSMITCOMPLETE   (WM_USER+205)
#define WM_CANMESSAGE            (WM_USER+206)
#define WM_CANERROR              (WM_USER+207)
// Only used in 2.0b mode
#define WM_CANWAKEUP             (WM_USER+208)

/**************************************************************************
    Function Declaration
***************************************************************************/

// CAN bus function declaration
FEXPORT LRESULT FTYPE CANPortOpen(
	WORD DevNum,
	WORD *wPort,
	WORD *wHostID,
	WORD *wBaudRate);

FEXPORT LRESULT FTYPE CANPortClose(WORD wPort);

FEXPORT LRESULT FTYPE CANInit( 
	WORD  Port,
	WORD  BTR0, 
	WORD  BTR1,
	UCHAR ucMask );

FEXPORT LRESULT FTYPE CANReset(WORD Port);

FEXPORT LRESULT FTYPE CANInpb(
	WORD Port,
	WORD Offset,
	UCHAR FAR *Data);

FEXPORT LRESULT FTYPE CANOutpb(
	WORD Port,
	WORD Offset,
	UCHAR Value);

FEXPORT LRESULT FTYPE CANSetBaud( 
	WORD Port,
	WORD BTR0,
	WORD BTR1 );

FEXPORT LRESULT FTYPE CANGetBaudRate(
	WORD Port,
	WORD *wBaudRate);

FEXPORT LRESULT FTYPE CANSetAcp(
	WORD Port,
	WORD Acp, 
	WORD Mask );

FEXPORT LRESULT FTYPE CANSetOutCtrl( 
	WORD Port,
	WORD OutCtrl );

FEXPORT LRESULT FTYPE CANSetNormal( WORD Port );

FEXPORT LRESULT FTYPE CANHwReset(WORD Port);

FEXPORT LRESULT FTYPE CANSendMsg(
	WORD Port,
	UCHAR FAR *TxBuf,
	BOOL Wait);

FEXPORT LRESULT FTYPE CANQueryMsg(
	WORD Port,
	BOOL FAR *Ready,
	UCHAR FAR *RcvBuf);

FEXPORT LRESULT FTYPE CANWaitForMsg
(
	WORD	Port,
	PVOID	FAR RcvBuf,
	ULONG	uTimeValue
);

FEXPORT LRESULT FTYPE CANWaitForFIFOEvent(
	WORD Port,
	ULONG timeout,
	BOOL * bReady );

FEXPORT LRESULT FTYPE CANQueryID(
	WORD Port,
	BOOL FAR *Ready,
	UCHAR FAR *IDBuf);

FEXPORT LRESULT FTYPE CANWaitForID(
	WORD Port,
	UCHAR FAR *IDBuf,
	ULONG uTimeValue);

FEXPORT LRESULT FTYPE CANEnableMessaging(
	WORD Port,
	WORD Type,
	BOOL Enabled,
	HWND AppWnd,
	UCHAR FAR *RcvBuf);

FEXPORT LRESULT FTYPE CANGetEventName(
	WORD Port,
	CHAR *RcvBuf);

FEXPORT LRESULT FTYPE CANEnableEvent(
	USHORT Port,
	BOOL Enabled);

FEXPORT LRESULT FTYPE CANCheckEvent(
	USHORT Port,
	DWORD Milliseconds);

FEXPORT LRESULT FTYPE CANEnableRxInt(WORD Port);

FEXPORT LRESULT FTYPE CANReadFile(
	WORD Port,
	DWORD NumNeeded,
	PVOID FAR RcvBuf,
	PDWORD pNumReturned );

FEXPORT LRESULT FTYPE CANWriteFile(
	WORD Port,
	BOOL FAR *Ready,
	PVOID FAR SendBuf);

FEXPORT LRESULT FTYPE CANSetBufferPtr(
	WORD Port,
	PVOID FAR pOutputBuffer,
	ULONG PakNum,
	BOOL FAR *Ready );

FEXPORT LRESULT FTYPE CANSetCountPtr(
	WORD Port,
	PULONG FAR pCountBuffer,
	BOOL FAR *Ready );

FEXPORT LRESULT FTYPE CANSetProtocolType(
	WORD wPort, 
	WORD wProtocolType );

FEXPORT LRESULT FTYPE CANGetErrorMessage
(
    LRESULT  lError,
    PUCHAR   puchErrMsg
);

FEXPORT LRESULT FTYPE CANGetProtocolType
(
   WORD wPort,
   WORD *pwProtocolType
);

/****************************************************************************
    Declaration of new CAN bus function supported can bus protocol 2.0B
    Above declaration code support can bus protocol 2.0A and protocol 2.0B
*****************************************************************************/
FEXPORT LRESULT FTYPE CANGetControllerErrorCodeEx(
	WORD Port,
	LPT_ErrorCodeCatch lpssErrorCodeCatch );

// get arbitrate lost catch information
FEXPORT LRESULT FTYPE CANGetArbitrationLostCatchMsgEx(
	WORD Port,
	LPT_ArbitrationLostCatch lpssArbLostCatch );

FEXPORT LRESULT FTYPE CANSetIntrMaskEx(
	WORD Port,
	UCHAR uchInterruptMask );

FEXPORT LRESULT FTYPE CANSetAcpEx( 
	WORD Port,
	LPT_FilterSetting lpssFilter );

// Set Can controller into sleep mode
FEXPORT LRESULT FTYPE CANWakeUpEx(
	WORD Port,
	BOOL bWakeUp );

FEXPORT LRESULT FTYPE CANSelectDevice
(
	HWND hCaller,
	BOOL GetModule,
	ULONG *DeviceNum,
	UCHAR *Description
	);
#define FID_CANPortOpen                  0
#define FID_CANPortClose                 1
#define FID_CANInit				         2
#define FID_CANSetProtocolType           3
#define FID_CANHwReset					 4
#define FID_CANReset	                 5
#define FID_CANInpb                      6
#define FID_CANOutpb	                 7
#define FID_CANSetBaud		             8
#define FID_CANGetBaudRate               9
#define FID_CANSetAcp	                10
#define FID_CANSetAcpEx                 11
#define FID_CANSetIntrMaskEx            12
#define FID_CANSetOutCtrl               13
#define FID_CANSetNormal                14
#define FID_CANSendMsg                  15
#define FID_CANQueryMsg                 16
#define FID_CANWaitForMsg               17
#define FID_CANWaitForFiFoEvent         18
#define FID_CANQueryID                  19
#define FID_CANWaitForID                20
#define FID_CANEnableMessaging          21
#define FID_CANGetEventName             22
#define FID_CANEnableEvent              23
#define FID_CANCheckEvent		        24
#define FID_CANReadFile		            25
#define FID_CANWriteFile				26
#define FID_CANEnableRxInt				27
#define FID_CANSetBufferPtr				28
#define FID_CANSetCountPtr				29
#define FID_CANGetProtocolType			30
#define FID_CANGetControllerErrorCodeEx 31
#define FID_CANGetArbitrationLostCatchMsgEx 32
#define FID_CANGetErrorMessage			33
#define FID_CANWakeUpEx					34
typedef struct _CAN_PORT_NUM
{
	WORD Port;
	WORD HostID;
	WORD Baudrate;
} CAN_PORT_NUM, *PCAN_PORT_NUM;

typedef struct _CAN_INIT_STRUCT
{
	WORD Port;
	WORD BTR0;
	WORD BTR1;
	WORD IntMask;
} CAN_INIT_STRUCT, *PCAN_INIT_STRUCT;

typedef struct _CAN_PROTOCOL
{
	WORD Port;
	WORD ProtocolType;
} CAN_PROTOCOL, *PCAN_PROTOCOL;

typedef struct _CAN_Inpb_IN
{
	WORD Port;
	WORD Offset;
} CAN_Inpb_IN, *PCAN_Inpb_IN;

typedef struct _CAN_Outpb_IN
{
	WORD Port;
	WORD Offset;
	UCHAR Value;
} CAN_Outpb_IN, *PCAN_Outpb_IN;

typedef struct _CAN_SETBAUD_STRUCT
{
	WORD Port;
	WORD BTR0;
	WORD BTR1;
} CAN_SETBAUD_STRUCT, *PCAN_SETBAUD_STRUCT;

typedef struct _CAN_SETACP_STRUCT
{
	WORD Port;
	WORD Acp;
	WORD Mask;
} CAN_SETACP_STRUCT, *PCAN_SETACP_STRUCT;

typedef struct _CAN_SEND_STRUCT
{
	WORD wPort;
	UCHAR FAR *ucTxBuf;
	BOOL bWait;
} CAN_SEND_STRUCT, *PCAN_SEND_STRUCT;

typedef struct _CAN_RCV_STRUCT
{
	BOOL  FAR *Ready;
	UCHAR FAR *RcvBuf;
} CAN_RCV_STRUCT, *PCAN_RCV_STRUCT;

typedef struct _CAN_WAITMSG_STRUCT
{
	WORD Port;
	ULONG Time;
} CAN_WAITMSG_STRUCT, *PCAN_WAITMSG_STRUCT;

typedef struct _CAN_ENABLE_MSG_STRUCT
{
	WORD Port;
	WORD Type;
	BOOL Enabled;
	HWND AppWnd;
	UCHAR FAR *RcvBuf;
} CAN_ENABLE_MSG_STRUCT, *PCAN_ENABLE_MSG_STRUCT;

typedef struct _CAN_READFILE_IN_STRUCT
{
	WORD Port;
	DWORD Numneeded;
} CAN_READFILE_IN_STRUCT, *PCAN_READFILE_IN_STRUCT;

typedef struct _CAN_READFILE_OUT_STRUCT
{
	PVOID FAR RcvBuf;
	PDWORD pNumReturned;
} CAN_READFILE_OUT_STRUCT, *PCAN_READFILE_OUT_STRUCT;

typedef struct _CAN_WRITEFILE_IN_STRUCT
{
	WORD Port;
	PVOID FAR SendBuf;
} CAN_WRITEFILE_IN_STRUCT, *PCAN_WRITEFILE_IN_STRUCT;

typedef struct _CAN_SETBUF_IN_STRUCT
{
	WORD Port;
	PVOID FAR pOutputBuffer;
	ULONG PakNum;
} CAN_SETBUF_IN_STRUCT, *PCAN_SETBUF_IN_STRUCT;

typedef struct _CAN_SETCOUNT_IN_STRUCT
{
	WORD Port;
	PULONG FAR pCountBuffer;
} CAN_SETCOUNT_IN_STRUCT, *PCAN_SETCOUNT_IN_STRUCT;

#ifdef __cplusplus
}
#endif

#endif
