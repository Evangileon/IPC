#ifndef ADLOGGER_can_msg_t_INC
#define ADLOGGER_can_msg_t_INC

// #############################################################################
// *****************************************************************************
//                  Copyright (c) 2001, Advantech Automation Corp.
//      THIS IS AN UNPUBLISHED WORK CONTAINING CONFIDENTIAL AND PROPRIETARY
//               INFORMATION WHICH IS THE PROPERTY OF ADVANTECH AUTOMATION CORP.
//
//    ANY DISCLOSURE, USE, OR REPRODUCTION, WITHOUT WRITTEN AUTHORIZATION FROM
//               ADVANTECH AUTOMATION CORP., IS STRICTLY PROHIBITED.
// *****************************************************************************
// #############################################################################
//
// File:    can_msg_t.h
// Author:  li.le
// Created: 11/12/2003
//
// Description:  Define the class can_msg_t
// -----------------------------------------------------------------------------
#define SUCCESS                  0

typedef struct {
	UCHAR rtr;      /* EFF RTR 0 0 DLC.3 DLC.2 DLC.1 DLC.0 */
	ULONG id;       /* not present in standard frames */
	UCHAR dlen;
	UCHAR data[8];
}CAN_MSG_T, *PCAN_MSG_T;

typedef struct {
	UCHAR ff;
	UCHAR rtr;      /* EFF RTR 0 0 DLC.3 DLC.2 DLC.1 DLC.0 */
	ULONG id;       /* not present in standard frames */
	UCHAR dlen;
	UCHAR data[8];
}CAN_MSG_T_EX, *PCAN_MSG_T_EX;

#endif // #ifndef ADLOGGER_can_msg_t_INC
