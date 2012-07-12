#include "StdAfx.h"
#include "Proctol.h"

static const Proctol_ID sendProctols[] = {
	{"M",  PROCTOL_MOVE},
	{"MX", PROCTOL_MOVEX},
	{"MY", PROCTOL_MOVEY},
	{"MZ", PROCTOL_MOVEZ},
	{"SEIZE", PROCTOL_SEIZE},
	{"LEASE", PROCTOL_LEASE},
	{"RESET", PROCTOL_RESET}
};

static const Proctol_ID recvProctols[] = {
	{"POSX",    PROCTOL_POSX},
	{"POSY",    PROCTOL_POSY},
	{"POSZ",    PROCTOL_POSZ},
	{"STATUS", PROCTOL_STATUS},
	{"HAND",   PROCTOL_HAND},
};

CProctol::CProctol(void)
{
	//proctol.
	//proctol = new hash_map<CString, int>(
}


CProctol::~CProctol(void)
{
}


int CProctol::ParseRecv(CString& msg)
{
	char *charMsg = (char *)msg.GetBuffer(msg.GetLength());
	int ret = NONE_PROCTOL;

	for(int i = 0;i < sizeof(recvProctols)/sizeof(Proctol_ID); i++)
	{
		if(strcmp(charMsg, recvProctols[i].proctStr) == 0)
		{
			ret = recvProctols[i].ID;
			break;
		}
	}
	
	return ret;
}


void CProctol::ParseSend(int nCmd, CString& strMsg)
{
	for(int i = 0;i < sizeof(sendProctols)/sizeof(Proctol_ID); i++)
	{
		if(nCmd == sendProctols[i].ID)
		{
			strMsg.Format(_T("%s"), sendProctols[i].proctStr);
			return;
		}
	}	
}
