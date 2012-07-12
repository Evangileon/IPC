// CParameter.h : 由 Microsoft Visual C++ 创建的 ActiveX 控件包装类的声明

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CParameter

class CParameter : public COleDispatchDriver
{
public:
	CParameter() {}		// 调用 COleDispatchDriver 默认构造函数
	CParameter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CParameter(const CParameter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

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
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Name(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT get_Value()
	{
		VARIANT result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Value(VARIANT newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	long get_Type()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Type(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void put_Direction(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Direction()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Precision(unsigned char newValue)
	{
		static BYTE parms[] = VTS_UI1 ;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	unsigned char get_Precision()
	{
		unsigned char result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_UI1, (void*)&result, NULL);
		return result;
	}
	void put_NumericScale(unsigned char newValue)
	{
		static BYTE parms[] = VTS_UI1 ;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	unsigned char get_NumericScale()
	{
		unsigned char result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_UI1, (void*)&result, NULL);
		return result;
	}
	void put_Size(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Size()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void AppendChunk(VARIANT Val)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Val);
	}
	long get_Attributes()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Attributes(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}


};
