// DBCenter.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_release.h"
#include "DBCenter.h"


// CDBCenter
IMPLEMENT_DYNAMIC(CDBCenter, CObject)

// CDBCenter 诊断

#ifdef _DEBUG
void CDBCenter::AssertValid() const
{
	CObject::AssertValid();
}

void CDBCenter::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);
}
#endif //_DEBUG

CDBCenter::CDBCenter()
{
	m_ADOdb = 0;
#if 0
	try
	{
		m_SQLitedb = new CppSQLite3DB;
		CFileFind fFind;
		if(!fFind.FindFile(dbFileName))
		{
			theApp.Log(_T("未找到数据库文件，新建history.db"));
			m_SQLitedb->open(dbFileName);//创建文件
			theApp.Log(_T("history.db建立完成"));
			if(m_SQLitedb->tableExists(_T("test_tbl")) == false)
			{
				theApp.Log(_T("No file, table do exist!"));
				m_SQLitedb->execDML(_T("CREATE TABLE test_tbl(id INTEGER PRIMARY KEY AUTOINCREMENT,\
							byte0 TEXT(4), byte1 TEXT(4), byte2 TEXT(4), byte3 TEXT(4), byte4 TEXT(4), \
							byte5 TEXT(4), byte6 TEXT(4), byte7 TEXT(4));"));
				m_SQLitedb->execDML(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
							values('0xFF', '0xFF','0xFF','0xFF','0xFF','0xFF','0xFF','0xFF')"));
				m_SQLitedb->execDML(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
							values('0xAA', '0xAA','0xAA','0xAA','0xAA','0xAA','0xAA','0xAA')"));	
				m_SQLitedb->execDML(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
							values('0xAA', '0xAA','0xAA','0xAA','0xAA','0xAA','0xAA','0xAA')"));	
				m_SQLitedb->execDML(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
							values('0xAA', '0xAA','0xAA','0xAA','0xAA','0xAA','0xAA','0xAA')"));	
			}
			/*db->execDML("CREATE TABLE log_tbl(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,\
			   name TEXT(10), age INT(2));");*/
			//db->execDML("insert into log_tbl values(1, '俞俊', 23)");
			theApp.Log(_T("创建db成功！"));
		}
		else
		{
			//strcpy_s(str, (char *)dbFileName.GetBuffer());
			//AfxMessageBox((char *)dbFileName.GetBuffer());
			DeleteFile(dbFileName);//创建文件
			m_SQLitedb->open(dbFileName);
			if(m_SQLitedb->tableExists(_T("test_tbl")) == false)
			{
				theApp.Log(_T("File exist, table do exist!"));
				m_SQLitedb->execDML(_T("CREATE TABLE test_tbl(id INTEGER PRIMARY KEY AUTOINCREMENT,\
							byte0 TEXT(4), byte1 TEXT(4), byte2 TEXT(4), byte3 TEXT(4), byte4 TEXT(4), \
							byte5 TEXT(4), byte6 TEXT(4), byte7 TEXT(4));"));
				m_SQLitedb->execDML(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
							values('0xFF', '0xFF','0xFF','0xFF','0xFF','0xFF','0xFF','0xFF')"));
				m_SQLitedb->execDML(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
							values('0xAA', '0xAA','0xAA','0xAA','0xAA','0xAA','0xAA','0xAA')"));	
				m_SQLitedb->execDML(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
							values('0xAA', '0xAA','0xAA','0xAA','0xAA','0xAA','0xAA','0xAA')"));	
				m_SQLitedb->execDML(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
							values('试验', '0xAA','0xAA','0xAA','0xAA','0xAA','0xAA','0xAA')"));	
				theApp.Log(_T("打开db成功！"));
			}
		}
	}
	catch(CppSQLite3Exception& e)
	{
		AfxMessageBox(CString(e.errorMessage()));
	}
#endif
	TCHAR *dbFileName = ".\\history\\history.db";
	TCHAR *dbFileFolder = ".\\history";

	try
	{
		m_SQLitedb = new CppSQLite3DB;
		m_db = m_SQLitedb;

		if (!PathIsDirectory(dbFileFolder)) 
		{ 
			CreateDirectory(dbFileFolder, NULL); 
		}
		CFileFind fFind;
		if(!fFind.FindFile(dbFileName))
		{
			theApp.Log(_T("未找到数据库文件，新建history.db"));
			m_SQLitedb->Open(dbFileName);//创建文件
			theApp.Log(_T("history.db建立完成"));
		}
		else
		{
			m_SQLitedb->Open(dbFileName);//打开文件
			theApp.Log(_T("history.db打开完成"));
		}

		if(m_SQLitedb->tableExists(_T("test_tbl")) == false)
		{
			theApp.Log(_T("Neither file nor table do exist!"));
			m_SQLitedb->execDML(_T("CREATE TABLE test_tbl(id INTEGER PRIMARY KEY AUTOINCREMENT,\
						byte0 TEXT(4), byte1 TEXT(4), byte2 TEXT(4), byte3 TEXT(4), byte4 TEXT(4), \
						byte5 TEXT(4), byte6 TEXT(4), byte7 TEXT(4));"));
			m_SQLitedb->execDML(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
						values('0xFF', '0xFF','0xFF','0xFF','0xFF','0xFF','0xFF','0xFF')"));
			m_SQLitedb->execDML(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
						values('0xAA', '0xAA','0xAA','0xAA','0xAA','0xAA','0xAA','0xAA')"));	
			m_SQLitedb->execDML(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
						values('0xAA', '0xAA','0xAA','0xAA','0xAA','0xAA','0xAA','0xAA')"));	
			m_SQLitedb->execDML(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
						values('测试', '0xAA','0xAA','0xAA','0xAA','0xAA','0xAA','0xAA')"));	
		}
			
		theApp.Log(_T("创建db成功！"));
	}
	catch(CppSQLite3Exception& e)
	{
		if(e.errorCode() == 1)
		{
			theApp.Log(CString(e.errorMessage()));
		}
		else
		{
			AfxMessageBox(CString(e.errorMessage()));
		}
	}

}

CDBCenter::~CDBCenter()
{
	this->Flush();

	if(m_SQLitedb != 0)
	{
		delete m_SQLitedb;
		m_SQLitedb = 0;
	}

	if(m_ADOdb != 0)
	{
		delete m_ADOdb;
		m_ADOdb = 0;
	}
	
	m_db = 0;
}


// CDBCenter 成员函数


int CDBCenter::WriteSQL(CString& sql)
{
	//SYSTEMTIME st;
	//CString strDate,strTime;
	//GetLocalTime(&st);

	//strDate.Format(_T("%4d-%2d-%2d"),st.wYear,st.wMonth,st.wDay);
	//strTime.Format(_T("%2d:%2d:%2d"),st.wHour,st.wMinute,st.wSecond);

	//CString text = strDate + _T(" ") + strTime + msg;
	m_DataQueue.AddTail(sql);

	/*if(m_DataQueue.GetCount() >= MaxQueue)
	{
		this->Flush();//缓冲区满再刷出增加程序难度，目前只实现定时刷出
	}*/

	return 0;
}

CDBCenter* CDBCenter::_instance = 0;

CDBCenter* CDBCenter::Instance()
{
	if(_instance == 0)
		_instance = new CDBCenter;
	return _instance;
}


void CDBCenter::Flush(void)
{
	//只刷出当前队列中的消息，意味着还可以往队列中添加消息，但不会再此时刷出
	CSingleLock singleLock(&m_CritSection);
	if (singleLock.Lock())
	{
		int count = m_DataQueue.GetCount();
		for(int i = 0; i < count; i++)
		{
			CString sql = m_DataQueue.GetHead();
			m_db->Excute(sql);
			m_DataQueue.RemoveHead();  //将队列刷入数据库，并删除已刷元素
		}

		singleLock.Unlock();
	}
}


BOOL CDBCenter::Query(CString szSQL)
{
	return m_db->Query(szSQL);
}


BOOL CDBCenter::QueryAll(void)
{
	return m_db->Query(_T("select * from test_tbl order by id;"));
}


void CDBCenter::WriteFmtMsg(CAN_MSG_T* msg)
{
	CString sql;
	sql.Format(_T("insert into test_tbl (byte0, byte1, byte2, byte3, byte4, byte5, byte6, byte7) \
				values('%2.2XH', '%2.2XH','%2.2XH','%2.2XH','%2.2XH','%2.2XH','%2.2XH','%2.2XH')"),
				msg->data[0], msg->data[1], msg->data[2], msg->data[3], msg->data[4], 
				msg->data[5], msg->data[6], msg->data[7]);
	this->WriteSQL(sql);
}


void CDBCenter::ExitInstance(void)
{
	if(_instance != 0)
		delete _instance;
}
