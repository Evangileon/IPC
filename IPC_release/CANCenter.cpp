#include "StdAfx.h"
#include "CANCenter.h"
#include "MConfig.h"
#include "resource.h"
#include "DBCenter.h"
#include "CanBus2.0.h"

using namespace std;

//Observer（观察者）设计模式

IMPLEMENT_DYNAMIC(CCANCenter, CObject)

// CCANCenter 诊断

#ifdef _DEBUG
void CCANCenter::AssertValid() const
{
	CObject::AssertValid();
}

void CCANCenter::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);
}
#endif //_DEBUG

CCANCenter::CCANCenter(void)
{
	m_DeviceNum = 0;
	m_DeviceName = _T("");
	m_HostID = 63;
	m_Port = 1;
	m_strSendMsg = _T("");
	m_strRecvMsg = _T("");
	m_send_ChkRemote = FALSE;
	m_recv_ChkRemote = FALSE;
	m_ChkSffS = TRUE;
	m_ChkSffR = TRUE;
	m_dwRecvId = 0;
	m_dwSendId = 0;
	
	m_result = 0;
	m_bIsPortOpen = false;
	m_nBTR0 = 0x00;                  //Baudrate 500k
	m_nBTR1 = 0x1C;
	m_nIntMask = (1 << 0)|(1 << 1)|(1 << 2)|(1 << 3);       //收，发，错误，溢出全为中断模式*/
	m_nOutCtrlCode = 250;
	m_dwSendId = 0;
	m_nAcpCode = 0;
	m_nAcpMask = 0xff;   // can receive all id
	m_wProtocolType = CANBUS_PROTOCOL_20A;
}

CCANCenter::CCANCenter(int nNum)
{

}

CCANCenter::~CCANCenter(void)
{
	
}

CCANCenter *CCANCenter::_instance = NULL;


CCANCenter* CCANCenter::Instance(void)
{
	if(_instance == NULL)
		_instance = new CCANCenter;
	return _instance;
}




void CCANCenter::Deliver(int nID, CString& msg)
{
	//将消息分发到控件
	m_Stations->SetStationStatus(nID, (nID % 5) + 1);  //测试代码，请修改
	NotifyCtrl(1, nID);

	int FirstComma = msg.Find(_T(','), 0);
	CString msgCmd = msg.Left(FirstComma); //comma前的字符串
	//int SecondComma = msg.Find(_T(','), FirstComma + 1);
	//CString msgID = msg.Mid(FirstComma + 1, SecondComma - FirstComma - 1);
	CString msgParam = msg.Right(msg.GetLength() - FirstComma - 1);
	
	int nCmd = this->m_Proctol.ParseRecv(msgCmd);
	//int nID = _ttoi(msgID.GetBuffer());

	Deliver(nID, nCmd, msgParam);
}


int CCANCenter::ParseMsg(CString& msg)
{
	
	
	return 0;
}




void CCANCenter::Config(CMConfig *m_config)
{
	//配置属性
	StationNBR = m_config->StationNBR;
	//pStationList = new vector<CStation *>(StationNBR);
}


void CCANCenter::ExitInstance(void)
{
	if(_instance != 0)
		delete _instance;
}


void CCANCenter::NotifyCtrl(int CtrlClass, int nID)
{
	//通知所有控件
	for(int i = 0; i < sizeof(pDialog)/sizeof(pDialog[0]); i++)
	{
		if(pDialog[i])
			pDialog[i]->PostMessage(NM_NOTIFYCTRL, CtrlClass, nID);
	}
}

/********************CAN相关函数***********************/
void CCANCenter::Openport() 
{
	//打开CAN口
	if( !Fun_PortOpen() )
		return;
	
	if( !Fun_CANSetProtocolType() )
		return;

	if( !Fun_HwReset() )
		return;

	if( !Fun_Init() )
		return;

	if( !Fun_SetOutCtrl() )
		return;

	if( !Fun_SetAcp() )
		return;

	if( !Fun_SetBaud() )
		return;

	if( !Fun_SetNormal() )
		return;
    CANEnableEvent(m_Port , TRUE );
	CANEnableRxInt(m_Port);

	EnableControls( TRUE );
}


//前缀为Fun_的函数均为CAN操作函数，实现主要是调用厂商提供的API

bool CCANCenter::Fun_PortOpen()
{
//	WORD BaudRate;

	if( m_bIsPortOpen == true )
	{
		return true;  // the port is open already
	}	

	m_result = CANPortOpen(	m_DeviceNum,
		                    (WORD *) &m_Port,
							(WORD *) &m_HostID,
							(WORD *) &m_BaudRate );
	if ( m_result == SUCCESS )
	{
		m_bIsPortOpen = true;

		/*m_pWnd = GetDlgItem(IDC_OPENPORT);
	   m_pWnd->EnableWindow(FALSE);

		m_pWnd = GetDlgItem(IDC_CLOSEPORT);
	   m_pWnd->EnableWindow(TRUE);

		m_pWnd = GetDlgItem(IDC_CAN20A);
	   m_pWnd->EnableWindow(TRUE);

		m_pWnd = GetDlgItem(IDC_CAN20B);
	   m_pWnd->EnableWindow(TRUE);*/
	}
	else
	{
		m_bIsPortOpen = false;
		CANGetErrorMessage( m_result, errorTemp );
		CString str;
		str.Format(_T("%S"), errorTemp);
		AfxMessageBox(str, NULL, MB_OK );
		return false;
	}
	
	//UpdateData(false);
	return true;
}


bool CCANCenter::Fun_CansetprotocoltypeA()
{
	
	m_result = CANSetProtocolType( m_Port, m_wProtocolType);

	if(m_result == SUCCESS)
	{
		return true;
	}
	else
	{
		m_bIsPortOpen = false;
		CANGetErrorMessage( m_result, errorTemp );
		CString str;
		str.Format(_T("%S"), errorTemp);
		AfxMessageBox(str, NULL, MB_OK );
		CANPortClose( m_Port);
		return false;
	}

	return true;
}


bool CCANCenter::Fun_HwReset()
{
	m_result = CANHwReset( m_Port );
	if ( m_result != SUCCESS )
	{
		m_bIsPortOpen = false;
		CANGetErrorMessage( m_result, errorTemp );
		CString str;
		str.Format(_T("%S"), errorTemp);
		AfxMessageBox(str, NULL, MB_OK );
		CANPortClose( m_Port);
		return false;
	}
	return true;
}

bool CCANCenter::Fun_Init()
{
	m_result = CANInit(  m_Port, m_nBTR0, m_nBTR1, (UCHAR) m_nIntMask );
	
	if ( m_result != SUCCESS)
	{
		m_bIsPortOpen = false;
		CANGetErrorMessage( m_result, errorTemp );
		CString str;
		str.Format(_T("%S"), errorTemp);
		AfxMessageBox(str, NULL, MB_OK );
		CANPortClose( m_Port);
		return false;
	}
	return true;
}

bool CCANCenter::Fun_SetOutCtrl()
{
	m_result = CANSetOutCtrl( m_Port, m_nOutCtrlCode );
	if ( m_result != SUCCESS )
	{
		m_bIsPortOpen = false;
		CANGetErrorMessage( m_result, errorTemp );
		CString str;
		str.Format(_T("%S"), errorTemp);
		AfxMessageBox(str, NULL, MB_OK );
		CANPortClose( m_Port);
		return false;
	}
	return true;
}

bool CCANCenter::Fun_SetAcp()
{
	if (m_wProtocolType == CANBUS_PROTOCOL_20A)
	{
		m_result = CANSetAcp( m_Port, m_nAcpCode, m_nAcpMask );

		if ( m_result != SUCCESS )
		{
			m_bIsPortOpen = false;
			CANGetErrorMessage( m_result, errorTemp );
			CString str;
			str.Format(_T("%S"), errorTemp);
			AfxMessageBox(str, NULL, MB_OK );
			CANPortClose( m_Port);
			return false;
		}
	}

	if (m_wProtocolType == CANBUS_PROTOCOL_20B)
	{
      PT_FilterSetting  ssFilterSetting;
      
      ssFilterSetting.dwFilterType  =  PELICAN_DOUBLE_FILTER;
      
      ssFilterSetting.uchAcceptCode0   =  255;
      ssFilterSetting.uchAcceptCode1   =  255;
      ssFilterSetting.uchAcceptCode2   =  255;
      ssFilterSetting.uchAcceptCode3   =  255;
      ssFilterSetting.uchAcceptMask0   =  0xff;
      ssFilterSetting.uchAcceptMask1   =  0xff;
      ssFilterSetting.uchAcceptMask2   =  0xff;
      ssFilterSetting.uchAcceptMask3   =  0xff;
      
      LRESULT  lCode;
      UCHAR    auchTemp[ 128 ];
      
      lCode    = CANSetAcpEx( m_Port, &ssFilterSetting );
      CANGetErrorMessage( lCode, auchTemp );
//      m_szMessage       = auchTemp;
	}
	
	return true;
}

bool CCANCenter::Fun_SetBaud()
{
	m_result = CANSetBaud(  m_Port, m_nBTR0, m_nBTR1);
	if ( m_result != SUCCESS )
	{
		m_bIsPortOpen = false;
		CANGetErrorMessage( m_result, errorTemp );
		CString str;
		str.Format(_T("%S"), errorTemp);
		AfxMessageBox(str, NULL, MB_OK );
		CANPortClose( m_Port);
		return false;
	}
//	WORD data;
//	m_result = CANGetBaudRate(  m_Port, 
//		&data);
	return true;
}

bool CCANCenter::Fun_SetNormal()
{
	m_result = CANSetNormal( m_Port );
	if ( m_result != SUCCESS )
	{
		m_bIsPortOpen = false;
		CANGetErrorMessage( m_result, errorTemp );
		CString str;
		str.Format(_T("%S"), errorTemp);
		AfxMessageBox(str, NULL, MB_OK );
		CANPortClose( m_Port);
		return false;
	}
	return true;
}

bool CCANCenter::Fun_SetBuffer()
{
	BOOL bReady = 0;

//	CANSetBufferPtr( m_Port, &m_g_Data, 1, &bReady );
	if ( m_wProtocolType == CANBUS_PROTOCOL_20A )
	{
		CANSetBufferPtr(m_Port, &m_g_Data, 1, &bReady);
	}
	if ( m_wProtocolType == CANBUS_PROTOCOL_20B )
	{
		CANSetBufferPtr(m_Port, &m_g_DataEx, 1, &bReady);
	}	

	if ( !bReady )
	{
		AfxMessageBox(_T("CAN set bufferptr error!"), NULL, MB_OK );
		return false;
	}
	return true;
}

void CCANCenter::SendMsg() 
{	
	//UpdateData( TRUE );
	
	CAN_MSG_T		msg;
	CAN_MSG_T_EX	msgex;
	BOOL bReady = FALSE;	
	
	if( m_wProtocolType == CANBUS_PROTOCOL_20A )
   {
		if ( (m_dwSendId > 2047)
         || (m_dwSendId < 0) )
		{
         AfxMessageBox(_T("Invalid message ID!"), NULL, MB_OK );
         return;
		}
      
      //msg.id = (m_dwSendId << 3) | 1;
      msg.id = m_dwSendId;
		msg.rtr = m_send_ChkRemote;
		
		if ( msg.rtr )
		{
			msg.dlen = 0;
		}
		else
		{
			msg.dlen = m_strSendMsg.GetLength();
		}
		
		strcpy_s((char*)msg.data, sizeof(msg.data), (char*)m_strSendMsg.GetBuffer(m_strSendMsg.GetLength()));
		
		CANWriteFile( m_Port, (BOOL *)&bReady, (PVOID)&msg );	
	}

	if( m_wProtocolType == CANBUS_PROTOCOL_20B )
	{
      // set frame format
      if ( m_ChkSffS )
      {
         msgex.ff  = PELICAN_SFF;

         if ( (m_dwSendId > 2047)
            || (m_dwSendId < 0) )
         {
            AfxMessageBox(_T("Invalid message ID!"), NULL, MB_OK );
            return;
		   }
      }
      else
      {
         msgex.ff  = PELICAN_EFF;

         if ( (m_dwSendId > 536870911) /*(2^29 - 1)*/
            || (m_dwSendId < 0) )
         {
            AfxMessageBox(_T("Invalid message ID!"), NULL, MB_OK );
            return;
		 }
      }
		//msgex.id   =  (m_bytSendID << 3) | 1;
		msgex.id   =  m_dwSendId;
		msgex.rtr  = m_send_ChkRemote;
		
		if ( msgex.rtr )
		{
			msgex.dlen = 0;
		}
		else
		{			
//			msgex.dlen = strlen((char *)msgex.data);
			msgex.dlen = m_strSendMsg.GetLength();
		}	

//		strcpy((char *)msgex.data,m_TxBuf.GetBuffer(8) );
		//strcpy( (char*)msgex.data, (char*)m_strSendMsg.GetBuffer(m_strSendMsg.GetLength()));
		strcpy_s((char*)msg.data, sizeof(msg.data), (char*)m_strSendMsg.GetBuffer(m_strSendMsg.GetLength()));

      LRESULT  lCode;
      UCHAR    auchTemp[ 128 ];
      lCode = CANWriteFile(m_Port, &bReady,(PVOID)&msgex );			
      CANGetErrorMessage( lCode, auchTemp );
//      m_szMessage       = auchTemp;
	}
	
	if ( !bReady )
	{
		AfxMessageBox(_T("CAN send message FAILURE!"), NULL, MB_OK );
	}
	else
	{
		AfxMessageBox(_T("CAN send message OK!"), NULL, MB_OK );	
	}		
}

void CCANCenter::EnableControls( BOOL beEnable )
{
	/*m_pWnd = GetDlgItem( IDC_SEND_ID );
	m_pWnd->EnableWindow( beEnable );

	m_pWnd = GetDlgItem( IDC_SEND_MSG );
	m_pWnd->EnableWindow( beEnable );

	m_pWnd = GetDlgItem( IDC_SEND_REMOTEFRM );
	m_pWnd->EnableWindow( beEnable );

	if( m_wProtocolType == CANBUS_PROTOCOL_20B )
	{		
		m_pWnd = GetDlgItem( IDC_SEND_STANDARDFRM );
		m_pWnd->EnableWindow( beEnable );
	}

	m_pWnd = GetDlgItem( IDC_SEND_MSG_BTN );
	m_pWnd->EnableWindow( beEnable );

	m_pWnd = GetDlgItem( IDC_RECV_MSG_BTN );
	m_pWnd->EnableWindow( beEnable );*/
}

bool CCANCenter::Fun_CANSetProtocolType()
{
	m_result = CANSetProtocolType( m_Port, m_wProtocolType );
	if ( m_result != SUCCESS )
	{
		m_bIsPortOpen = false;
		CANGetErrorMessage( m_result, errorTemp );
		CString str;
		str.Format(_T("%S"), errorTemp);
		AfxMessageBox(str, NULL, MB_OK );
		CANPortClose( m_Port);
		return false;
	}	
	return true;
}


void CCANCenter::RecvMsg(void)
{
	//接受并解析消息
	CAN_MSG_T		msg;
	CAN_MSG_T_EX   msgex;

	DWORD		cbReturned = 0;
	LRESULT	lCode;
	UCHAR    auchTemp[ 128 ];
	int		nLength;
	
	if ( m_wProtocolType == CANBUS_PROTOCOL_20A )
	{
		//m_result = CANReadFile( m_Port, 1, &msg, &cbReturned );  // Note:The function can't be used with CANSetBufferPtr()!
		
		m_result = CANWaitForMsg(m_Port, &msg, INFINITE);
		//cbReturned = TRUE;

		m_recv_ChkRemote = msg.rtr;
		
		if ( m_result )
		{
			//m_dwRecvId = (msg.id >> 3);
			m_dwRecvId = msg.id;
			if( msg.rtr == FALSE )
			{				
				m_strRecvMsg = "";
				nLength=msg.dlen;
				msg.data[nLength]='\0';//add by fjz
				m_strRecvMsg = msg.data;
			}
			else
			{
				m_strRecvMsg = "Remote Msg";
			}
		}
		else
		{
			AfxMessageBox(_T("CAN receive data error!"), 
				NULL, MB_OK );
		}	
	}
	
   if ( m_wProtocolType == CANBUS_PROTOCOL_20B )
   {		
      lCode = CANReadFile( m_Port, 1, &msgex, &cbReturned );

		m_recv_ChkRemote = msgex.rtr;

		if ( cbReturned ) 
		{			
			//m_bytRecvID = (BYTE) (msgex.id >> 3);
			m_dwRecvId = msgex.id;
			nLength = msgex.dlen;

			if ( msgex.ff == 0 )
			{
				m_ChkSffR = 1;    // Standard Frame
			}
			else 
			{
				m_ChkSffR = 0;    // Extended Frame
			}

			if( msgex.rtr == FALSE )
			{				
				//m_strRecvMsg = "";
				//m_strRecvMsg = msgex.data;
				
				if ( msgex.dlen == 0 )
				{
					m_strRecvMsg = "";
				}
				else
				{
					msgex.data[nLength]='\0';//add by fjz
					m_strRecvMsg = msgex.data;
				}
			}
			else
			{  // Remote Frame
				m_strRecvMsg = "Remote Msg";
			}
		}
		else 
		{
			AfxMessageBox(_T("Message is not ready!"),
				NULL,
				MB_OK );
		}
		CANGetErrorMessage( lCode, auchTemp );
//      m_szMessage = auchTemp;      
   }	

	//UpdateData( FALSE );
   if(this->m_result == SUCCESS)
   {
	   CString ref;
	   ref.Format(_T("ID = %d, %s"), msg.id, m_strRecvMsg);
	   AfxMessageBox(ref);
	   Deliver(msg.id, m_strRecvMsg);
   }
}


void CCANCenter::WriteMsg(CString& msg)
{
	//写线程触发事件
	m_strSendMsg = msg;
	m_WriteEvent.PulseEvent();
}


void CCANCenter::Deliver(int nID, int nCmd, CString strParam)
{
	//分发函数
	CStringArray strParams;
	SplitString(strParam, ',', strParams);
	char num[8]; 
	CString str0;
	CString str1;
	CString str2;
	
	switch(nCmd)
	{
	case PROCTOL_POSX:
		str0 = strParams.GetAt(0);
		strncpy_s(num, (char *)str0.GetBuffer(), 4);
		m_Stations->SetPosX(nID, CharsToInt(num, 0, 4));
		this->NotifyCtrl(ID_CLASS_EDIT_X, nID);
		break;
	case PROCTOL_POSY:
		str0 = strParams.GetAt(0);
		strncpy_s(num, (char *)str0.GetBuffer(), 4);
		m_Stations->SetPosY(nID, CharsToInt(num, 0, 4));
		this->NotifyCtrl(ID_CLASS_EDIT_Y, nID);
		break;
	case PROCTOL_POSZ:
		str0 = strParams.GetAt(0);
		strncpy_s(num, (char *)str0.GetBuffer(), 4);
		m_Stations->SetPosZ(nID, CharsToInt(num, 0, 4));
		this->NotifyCtrl(ID_CLASS_EDIT_Z, nID);
		break;
	case PROCTOL_STATUS:
		str0 = strParams.GetAt(0);
		strncpy_s(num, (char *)str0.GetBuffer(), 1);
		m_Stations->SetStationStatus(nID, (num[0] - '0'));
		this->NotifyCtrl(ID_CLASS_LED, nID);
		break;
	case PROCTOL_HAND:
		str0 = strParams.GetAt(0);
		strncpy_s(num, (char *)str0.GetBuffer(), 1);
		m_Stations->SetHand(nID, CharsToInt(num, 0, 1));
		this->NotifyCtrl(0, nID);
		break;
	default:
		return;
		break;
	}

	//this->NotifyCtrl(0, nID);
}

void CCANCenter::SplitString(CString str, TCHAR split,CStringArray& strGet)  
{  
	//str为待分割的CString，split为分割符如：， ¦或空格 strGet为输出参数，你得到的字符串存放在strGet中
	int pos = -1;
	pos = str.Find(split);
	while(pos != -1)
	{
		CString strSun;
		strSun = str.Left(pos);
		strGet.Add(strSun);
		str.Delete(0,pos);
		pos = str.Find(split);
	}
	if(str != "")
	{//最后剩下的字符串可能没有split这个标示，看你需要怎么处理了
		//这里也把他加入到strGet中
		strGet.Add(str);
	}
}


int CCANCenter::CharsToInt(char *str, int nStart, int nLength)
{
	//字符串转为整形
	unsigned char *tmp = (unsigned char *)str;
	int result = 0;
	result |= (int)tmp[nStart];
	for(int i = nStart + 1; i < nStart + 4 && i < nLength; i++)
	{
		result = result << 8;
		result |= (int)tmp[i];
	}
	
	return result;
}


void CCANCenter::WriteMsg(int nID, int nCmd, CString strParams)
{
	this->m_dwSendId = nID;
	CString strCmd;
	m_Proctol.ParseSend(nCmd, strCmd);
	this->m_strSendMsg = strCmd + "," + strParams;
	
	m_WriteEvent.PulseEvent();
}


bool CCANCenter::IsPortOpen(void)
{
	return this->m_bIsPortOpen;
}


void CCANCenter::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
	}
	else
	{	// loading code
	}
}



void CCANCenter::TestRecv(void)
{
	CAN_MSG_T		msg;
	CAN_MSG_T_EX   msgex;

	DWORD		cbReturned = 0;
	LRESULT	lCode;
	UCHAR    auchTemp[ 128 ];
	int		nLength;
	
	if ( m_wProtocolType == CANBUS_PROTOCOL_20A )
	{
		m_result = CANReadFile( m_Port, 1, &msg, &cbReturned );  // Note:The function can't be used with CANSetBufferPtr()!
		
		//m_result = CANWaitForMsg(m_Port, &msg, INFINITE);
		//cbReturned = TRUE;

		m_recv_ChkRemote = msg.rtr;
		
		if ( cbReturned )
		{
			//m_dwRecvId = (msg.id >> 3);
			m_dwRecvId = msg.id;
			if( msg.rtr == FALSE )
			{				
				m_strRecvMsg = "";
				nLength=msg.dlen;
				/*CStringArray strArray;
				CString str;
				str.Format(_T("%d"), msg.id);
				strArray.Add(str);*/
				CDBCenter::Instance()->WriteFmtMsg(&msg);
			}
			else
			{
				m_strRecvMsg = "Remote Msg";
			}
		}
		else
		{
			return;
		}	
	}
	
   if ( m_wProtocolType == CANBUS_PROTOCOL_20B )
   {		
      lCode = CANReadFile( m_Port, 1, &msgex, &cbReturned );

		m_recv_ChkRemote = msgex.rtr;

		if ( cbReturned ) 
		{			
			//m_bytRecvID = (BYTE) (msgex.id >> 3);
			m_dwRecvId = msgex.id;
			nLength = msgex.dlen;

			if ( msgex.ff == 0 )
			{
				m_ChkSffR = 1;    // Standard Frame
			}
			else 
			{
				m_ChkSffR = 0;    // Extended Frame
			}

			if( msgex.rtr == FALSE )
			{				
				//m_strRecvMsg = "";
				//m_strRecvMsg = msgex.data;
				
				if ( msgex.dlen == 0 )
				{
					m_strRecvMsg = "";
				}
				else
				{
					msgex.data[nLength]='\0';//add by fjz
					m_strRecvMsg = msgex.data;
				}
			}
			else
			{  // Remote Frame
				m_strRecvMsg = "Remote Msg";
			}
		}
		else 
		{
			return;
		}
		CANGetErrorMessage( lCode, auchTemp );
//      m_szMessage = auchTemp;      
   }	
}


void CCANCenter::AttachStations(CStationManager* m_Stations)
{
	this->m_Stations = m_Stations;
}

