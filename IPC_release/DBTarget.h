#pragma once
class IDBTarget
{
public:
	IDBTarget(void);
	virtual ~IDBTarget(void);
	virtual BOOL DbEOF(void);
	virtual void NextRow(void);
	virtual BOOL Query(CString sql);
	virtual BOOL Excute(CString sql);
	virtual CString& GetFieldByString(CString field);
	virtual BOOL Open(CString DbString);
	virtual BOOL Close(void);
	virtual void Finalize(void);
	virtual void Reset(void);
};

