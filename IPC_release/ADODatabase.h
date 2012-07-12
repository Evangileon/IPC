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
	
	BOOL OpenConnection(CString strConnection);
	BOOL CloseConnection(void);
	_RecordsetPtr Select(CString sql);

	virtual BOOL Open(CString DBName);
	virtual BOOL Close(void);
	virtual BOOL Excute(CString sql);
	virtual BOOL Query(CString sql);
	virtual BOOL DbEOF(void);
	virtual void NextRow(void);
	virtual CString& GetFieldByString(CString field);
	virtual void Finalize(void);
	virtual void Reset(void);
};


