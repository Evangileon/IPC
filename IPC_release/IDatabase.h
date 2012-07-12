#pragma once
#include "can_msg_t.h"

class IDatabase
{
public:
	IDatabase(void);
	virtual ~IDatabase(void);
	
	virtual void ExcuteSQL(CString &) = 0;
	virtual void WriteFmtMsg(CAN_MSG_T *msg) = 0;
	virtual void Open(CString &) = 0;
	virtual void Close() = 0;
};

class IQuery
{
public:
	IQuery(void);
	virtual ~IQuery(void) = 0;

	virtual int numFields() = 0;

    virtual int fieldIndex(const char* szField) = 0;
    virtual const char* fieldName(int nCol) = 0;

    virtual const char* fieldDeclType(int nCol) = 0;
    virtual int fieldDataType(int nCol) = 0 ;

    virtual const char* fieldValue(int nField) = 0;
    virtual const char* fieldValue(const char* szField) = 0;

	virtual bool fieldIsNull(int nField) = 0;
    virtual bool fieldIsNull(const char* szField) = 0;

    virtual bool eof() = 0;
    virtual void nextRow() = 0;

    virtual void finalize() = 0;
};

class IDBException
{
public:
	IDBException(void);
	virtual ~IDBException(void) = 0;

	virtual const int errorCode() = 0;
	virtual const char* errorMessage() = 0;
};

class DBAdaptee
{
public:
	DBAdaptee::DBAdaptee();

};