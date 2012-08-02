#pragma once
class IDBTarget
{
public:
	IDBTarget(void);
	virtual ~IDBTarget(void);
	virtual BOOL DbEOF(void) = 0;
	virtual void NextRow(void) = 0;
	virtual BOOL Query(LPCTSTR sql) = 0;
	virtual BOOL Excute(LPCTSTR sql) = 0;
	virtual LPCTSTR GetFieldByString(LPCTSTR field) = 0;
	virtual LPCTSTR GetFieldByIndex(int index) = 0;
	virtual BOOL Open(LPCTSTR DbString = _T(""), LPCTSTR UserID = _T(""), LPCTSTR Password = _T("")) = 0;
	virtual BOOL Close(void) = 0;
	virtual void Finalize(void) = 0;
	virtual void Reset(void) = 0;
};

