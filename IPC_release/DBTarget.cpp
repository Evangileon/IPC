#include "StdAfx.h"
#include "DBTarget.h"


IDBTarget::IDBTarget(void)
{
}


IDBTarget::~IDBTarget(void)
{
}

#if 0
BOOL IDBTarget::DbEOF(void)
{
	return TRUE;
}


void IDBTarget::NextRow(void)
{
}


BOOL IDBTarget::Query(CString sql)
{
	return FALSE;
}


BOOL IDBTarget::Excute(CString sql)
{
	return FALSE;
}


CString& IDBTarget::GetFieldByString(CString field)
{
	//TODO: insert return statement here
	return CString("");
}


BOOL IDBTarget::Open(CString DbString, CString UserID, CString Password)
{
	return FALSE;
}


BOOL IDBTarget::Close(void)
{
	return FALSE;
}

void IDBTarget::Finalize(void)
{

}

void IDBTarget::Reset(void)
{

}

CString& IDBTarget::GetFieldByIndex(int index)
{
	//TODO: insert return statement here
	return CString("");
}
#endif