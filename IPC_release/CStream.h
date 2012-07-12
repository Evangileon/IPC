// CStream.h : 由 Microsoft Visual C++ 创建的 ActiveX 控件包装类的声明

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CStream

class CStream : public COleDispatchDriver
{
public:
	CStream() {}		// 调用 COleDispatchDriver 默认构造函数
	CStream(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CStream(const CStream& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// 特性
public:

// 操作
public:

	long get_Size()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL get_EOS()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	long get_Position()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Position(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Type()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Type(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_LineSeparator()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_LineSeparator(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_State()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_Mode()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Mode(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Charset()
	{
		CString result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Charset(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT Read(long NumBytes)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, NumBytes);
		return result;
	}
	void Open(VARIANT Source, long Mode, long Options, LPCTSTR UserName, LPCTSTR Password)
	{
		static BYTE parms[] = VTS_VARIANT VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Source, Mode, Options, UserName, Password);
	}
	void Close()
	{
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void SkipLine()
	{
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Write(VARIANT Buffer)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Buffer);
	}
	void SetEOS()
	{
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void CopyTo(LPDISPATCH DestStream, long CharNumber)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_I4 ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, DestStream, CharNumber);
	}
	void Flush()
	{
		InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void SaveToFile(LPCTSTR FileName, long Options)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName, Options);
	}
	void LoadFromFile(LPCTSTR FileName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
	}
	CString ReadText(long NumChars)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, NumChars);
		return result;
	}
	void WriteText(LPCTSTR Data, long Options)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Data, Options);
	}
	void Cancel()
	{
		InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


};
