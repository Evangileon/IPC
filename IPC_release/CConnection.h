// CConnection.h : 由 Microsoft Visual C++ 创建的 ActiveX 控件包装类的声明

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CConnection

class CConnection : public COleDispatchDriver
{
public:
	CConnection() {}		// 调用 COleDispatchDriver 默认构造函数
	CConnection(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CConnection(const CConnection& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// 特性
public:

// 操作
public:

	LPDISPATCH get_Properties()
	{
		LPDISPATCH result;
		InvokeHelper(0x1f4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_ConnectionString()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_ConnectionString(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_CommandTimeout()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_CommandTimeout(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_ConnectionTimeout()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ConnectionTimeout(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Version()
	{
		CString result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void Close()
	{
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH Execute(LPCTSTR CommandText, VARIANT * RecordsAffected, long Options)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT VTS_I4 ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, CommandText, RecordsAffected, Options);
		return result;
	}
	long BeginTrans()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void CommitTrans()
	{
		InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void RollbackTrans()
	{
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Open(LPCTSTR ConnectionString, LPCTSTR UserID, LPCTSTR Password, long Options)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ConnectionString, UserID, Password, Options);
	}
	LPDISPATCH get_Errors()
	{
		LPDISPATCH result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_DefaultDatabase()
	{
		CString result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_DefaultDatabase(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_IsolationLevel()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_IsolationLevel(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Attributes()
	{
		long result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Attributes(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_CursorLocation()
	{
		long result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_CursorLocation(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Mode()
	{
		long result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Mode(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Provider()
	{
		CString result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Provider(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_State()
	{
		long result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH OpenSchema(long Schema, VARIANT Restrictions, VARIANT SchemaID)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Schema, &Restrictions, &SchemaID);
		return result;
	}
	void Cancel()
	{
		InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


};
