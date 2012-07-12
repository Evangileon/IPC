#pragma once


#include <vector>

#include "Station.h"
#include "MConfig.h"

#include "Proctol.h"
#include "NotifyClass.h"
#include "StationManager.h"

#include "can_msg_t.h"

//using namespace std;

class CCANCenter : CObject
{
	DECLARE_DYNAMIC(CCANCenter)

public:
	CCANCenter(void);
	~CCANCenter(void);
	CCANCenter(int nNum);

	CStationManager *m_Stations;
	int StationNBR;   //静态变量自动初始化为0
	CDialog *pDialog[3];

private:
	static CCANCenter *_instance;

public:
	static CCANCenter* Instance(void);
	static void ExitInstance(void);
	void Config(CMConfig *m_config);

public:
	void Deliver(int nID, CString& msg); //分发到各工位的类中
	void Deliver(int nID, int nCmd, CString strParam = 0);
	int ParseMsg(CString& msg);
	void WriteMsg(CString& msg);
	UCHAR errorTemp[128];
	
private:
	void NotifyCtrl(int CtrlClass, int value);


/****************CAN相关变量*********************/
public:
	UINT	m_DeviceNum;
	CString	m_DeviceName;
	UINT	m_HostID;
	UINT	m_Port;
	CString	m_strSendMsg;
	CString	m_strRecvMsg;
	BOOL	m_send_ChkRemote;
	BOOL	m_recv_ChkRemote;
	BOOL	m_ChkSffS;
	BOOL	m_ChkSffR;
	DWORD	m_dwRecvId;
	LONG	m_dwSendId;

/****************CAN相关函数*********************/
private:
	WORD m_wProtocolType;
	UINT m_nAcpCode;
	UINT m_nAcpMask;
	UINT m_nOutCtrlCode;
	UINT m_nIntMask;
	UINT m_nBTR0;
	UINT m_nBTR1;
	WORD m_BaudRate;
	bool m_beSuccess;
	CWnd * m_pWnd;
	bool m_bIsPortOpen;
	LRESULT m_result;
	CAN_MSG_T m_g_Data;
	CAN_MSG_T_EX m_g_DataEx;

	bool Fun_CANSetProtocolType();
	bool Fun_Init();
	bool Fun_HwReset();
	bool Fun_PortOpen();
	bool Fun_SetNormal();
	bool Fun_SetBaud();
	bool Fun_SetAcp();
	bool Fun_SetOutCtrl();
	bool Fun_SetBuffer();
	void EnableControls( BOOL beEnable );
	bool Fun_CansetprotocoltypeA();

public:
	void Openport();
	void SendMsg();
	void RecvMsg(void);
	bool IsPortOpen(void);
	void TestRecv(void);
	void WriteMsg(int nID, int nCmd, CString strParams = 0);

public:
	/******************互斥变量***********************/
	CCriticalSection m_WriteLock;
	CEvent  m_WriteEvent;
	CEvent  m_CANOpened;
	CEvent  m_WriteFinished;
	


/**************************操作协议*********************************/
private:
	CProctol m_Proctol;

/****************************其他辅助函数***********************************/
	void SplitString(CString str, wchar_t split,CStringArray& strGet);
	int CharsToInt(char * str, int nStart, int nLength);
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
	
public:
	void AttachStations(CStationManager* m_Stations);
};

