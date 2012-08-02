#include "StdAfx.h"
#include "ADODatabase.h"


CADODatabase::CADODatabase(void)
{
}


CADODatabase::~CADODatabase(void)
{
	m_pConnection->Close();
	m_pConnection.Release();
	m_pRecordset->Close();
	m_pRecordset.Release();
}


BOOL CADODatabase::Open(LPCTSTR DbString, LPCTSTR UserID, LPCTSTR Password)
{
	return OpenConnection(DbString, UserID, Password);
}


BOOL CADODatabase::OpenConnection(CString strConnection, CString UserID, CString Password)
{
	HRESULT hr = ::CoInitialize(NULL);
	if (!SUCCEEDED(hr)) // 初始化失败
	{
		TRACE(_T("初始化COM失败\n"));
		return FALSE;
	}

	_bstr_t strConnect(strConnection);
	_bstr_t strUserID(UserID);
	_bstr_t strPassword(Password);

	try
	{
		// 创建Connection对象
		hr = m_pConnection.CreateInstance("ADODB.Connection");
		
		if (SUCCEEDED(hr))
		{
			// 连接数据库
			if (SUCCEEDED(m_pConnection->Open(strConnect, strUserID, strPassword, adModeReadWrite)))
			{
				return TRUE;
			}
		}
	}
	catch (_com_error e)
	{
		TRACE(_T("连接数据库发生错误%s\n"), e.ErrorMessage());
	}
	
	return FALSE;
}


BOOL CADODatabase::Close(void)
{
	if(CloseConnection()==FALSE)
	{
		AfxMessageBox(_T("关闭数据库错误"));
		return FALSE;
	}
	return TRUE;
}


BOOL CADODatabase::CloseConnection(void)
{
	if (m_pConnection == NULL)
	{
		// 如果连接已经为空
		return TRUE;
	}
	try
	{
		m_pConnection->Close();
		m_pConnection = NULL;
		return TRUE;
	}
	catch (_com_error e)
	{
		TRACE(_T("关闭数据库发生错误：%s\n"), e.ErrorMessage());
	}
	return FALSE;
}


_RecordsetPtr CADODatabase::Select(CString sql)
{
	_bstr_t CommandText(sql);  // 生成要执行的sql语句字符串
	m_pRecordset.CreateInstance("ADODB.Recordset");  // 生成_RecordsetPtr实例
	m_pRecordset->Open(CommandText,  // 连接数据库查询
		m_pConnection.GetInterfacePtr(),
		adOpenDynamic,
		adLockBatchOptimistic,
		adCmdText);
	return m_pRecordset;
}


BOOL CADODatabase::Excute(LPCTSTR sql)
{
	_bstr_t CommandText(sql);
	_variant_t RecordsAffected;
	m_pConnection->Execute(CommandText, &RecordsAffected, adCmdText);
	return TRUE;
}


BOOL CADODatabase::Query(LPCTSTR sql)
{
	return FALSE;
}


BOOL CADODatabase::DbEOF(void)
{
	return this->m_pRecordset->adoEOF;
}


void CADODatabase::NextRow(void)
{
	//TODO: insert return statement here
	m_pRecordset->MoveNext();
}


LPCTSTR CADODatabase::GetFieldByString(LPCTSTR field)
{
	//TODO: insert return statement here
	_bstr_t FieldText(field);
	CString temp = m_pRecordset->GetCollect(FieldText);
	return temp;
}

LPCTSTR CADODatabase::GetFieldByIndex(int index)
{
	//TODO: insert return statement here
	//_bstr_t FieldText(field);
	//CString temp = m_pRecordset->GetCollect(FieldText);
	CString temp = m_pRecordset->GetCollect(index);
	return temp;
}

void CADODatabase::Finalize(void)
{
}

void CADODatabase::Reset(void)
{
}