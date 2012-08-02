#pragma once
#include "IDatabase.h"
#include "DBTarget.h"

using namespace ADODB;

class CADODatabase : IDBTarget
{
/********************************************
	数据库成员
*********************************************/
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	//_CommandPtr m_pCommand;

public:
	CADODatabase(void);
	~CADODatabase(void);
	
	BOOL OpenConnection(CString strConnection, CString UserID = _T(""), CString Password = _T(""));
	BOOL CloseConnection(void);
	_RecordsetPtr Select(CString sql);

	virtual BOOL Open(LPCTSTR DBString = _T(""), LPCTSTR UserID = _T(""), LPCTSTR Password = _T(""));
	virtual BOOL Close(void);
	virtual BOOL Excute(LPCTSTR sql);
	virtual BOOL Query(LPCTSTR sql);
	virtual BOOL DbEOF(void);
	virtual void NextRow(void);
	virtual LPCTSTR GetFieldByString(LPCTSTR field);
	virtual LPCTSTR GetFieldByIndex(int index);
	virtual void Finalize(void);
	virtual void Reset(void);
};


