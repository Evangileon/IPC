// CRecordset.h : 由 Microsoft Visual C++ 创建的 ActiveX 控件包装类的声明

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CRecordset
namespace IPC
{

class CRecordset0 : public COleDispatchDriver
{
public:
	CRecordset0() {}		// 调用 COleDispatchDriver 默认构造函数
	CRecordset0(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRecordset0(const CRecordset0& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

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
	long get_AbsolutePosition()
	{
		long result;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_AbsolutePosition(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3e8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void putref_ActiveConnection(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	void put_ActiveConnection(VARIANT newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	VARIANT get_ActiveConnection()
	{
		VARIANT result;
		InvokeHelper(0x3e9, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	BOOL get_BOF()
	{
		BOOL result;
		InvokeHelper(0x3ea, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	VARIANT get_Bookmark()
	{
		VARIANT result;
		InvokeHelper(0x3eb, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Bookmark(VARIANT newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x3eb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	long get_CacheSize()
	{
		long result;
		InvokeHelper(0x3ec, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_CacheSize(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3ec, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_CursorType()
	{
		long result;
		InvokeHelper(0x3ed, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_CursorType(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3ed, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_EOF()
	{
		BOOL result;
		InvokeHelper(0x3ee, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Fields()
	{
		LPDISPATCH result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_LockType()
	{
		long result;
		InvokeHelper(0x3f0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_LockType(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3f0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_MaxRecords()
	{
		long result;
		InvokeHelper(0x3f1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_MaxRecords(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3f1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_RecordCount()
	{
		long result;
		InvokeHelper(0x3f2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void putref_Source(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x3f3, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	void put_Source(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x3f3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT get_Source()
	{
		VARIANT result;
		InvokeHelper(0x3f3, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void AddNew(VARIANT FieldList, VARIANT Values)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3f4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &FieldList, &Values);
	}
	void CancelUpdate()
	{
		InvokeHelper(0x3f5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Close()
	{
		InvokeHelper(0x3f6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Delete(long AffectRecords)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3f7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, AffectRecords);
	}
	VARIANT GetRows(long Rows, VARIANT Start, VARIANT Fields)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3f8, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Rows, &Start, &Fields);
		return result;
	}
	void Move(long NumRecords, VARIANT Start)
	{
		static BYTE parms[] = VTS_I4 VTS_VARIANT ;
		InvokeHelper(0x3f9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, NumRecords, &Start);
	}
	void MoveNext()
	{
		InvokeHelper(0x3fa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void MovePrevious()
	{
		InvokeHelper(0x3fb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void MoveFirst()
	{
		InvokeHelper(0x3fc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void MoveLast()
	{
		InvokeHelper(0x3fd, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Open(VARIANT Source, VARIANT ActiveConnection, long CursorType, long LockType, long Options)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x3fe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Source, &ActiveConnection, CursorType, LockType, Options);
	}
	void Requery(long Options)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3ff, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Options);
	}
	void _xResync(long AffectRecords)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x60030022, DISPATCH_METHOD, VT_EMPTY, NULL, parms, AffectRecords);
	}
	void Update(VARIANT Fields, VARIANT Values)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x401, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Fields, &Values);
	}
	long get_AbsolutePage()
	{
		long result;
		InvokeHelper(0x417, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_AbsolutePage(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x417, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_EditMode()
	{
		long result;
		InvokeHelper(0x402, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	VARIANT get_Filter()
	{
		VARIANT result;
		InvokeHelper(0x406, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Filter(VARIANT newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x406, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	long get_PageCount()
	{
		long result;
		InvokeHelper(0x41a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_PageSize()
	{
		long result;
		InvokeHelper(0x418, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_PageSize(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x418, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Sort()
	{
		CString result;
		InvokeHelper(0x407, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Sort(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x407, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Status()
	{
		long result;
		InvokeHelper(0x405, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	long get_State()
	{
		long result;
		InvokeHelper(0x41e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH _xClone()
	{
		LPDISPATCH result;
		InvokeHelper(0x60030030, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void UpdateBatch(long AffectRecords)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x40b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, AffectRecords);
	}
	void CancelBatch(long AffectRecords)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x419, DISPATCH_METHOD, VT_EMPTY, NULL, parms, AffectRecords);
	}
	long get_CursorLocation()
	{
		long result;
		InvokeHelper(0x41b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_CursorLocation(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x41b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH NextRecordset(VARIANT * RecordsAffected)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x41c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, RecordsAffected);
		return result;
	}
	BOOL Supports(long CursorOptions)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x40c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CursorOptions);
		return result;
	}
	VARIANT get_Collect(VARIANT Index)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xfffffff8, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms, &Index);
		return result;
	}
	void put_Collect(VARIANT Index, VARIANT newValue)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xfffffff8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &Index, &newValue);
	}
	long get_MarshalOptions()
	{
		long result;
		InvokeHelper(0x41d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_MarshalOptions(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x41d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void Find(LPCTSTR Criteria, long SkipRecords, long SearchDirection, VARIANT Start)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_VARIANT ;
		InvokeHelper(0x422, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Criteria, SkipRecords, SearchDirection, &Start);
	}
	void Cancel()
	{
		InvokeHelper(0x41f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPUNKNOWN get_DataSource()
	{
		LPUNKNOWN result;
		InvokeHelper(0x420, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	void putref_DataSource(LPUNKNOWN newValue)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x420, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	void _xSave(LPCTSTR FileName, long PersistFormat)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x60040003, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName, PersistFormat);
	}
	LPDISPATCH get_ActiveCommand()
	{
		LPDISPATCH result;
		InvokeHelper(0x425, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void put_StayInSync(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x427, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_StayInSync()
	{
		BOOL result;
		InvokeHelper(0x427, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	CString GetString(long StringFormat, long NumRows, LPCTSTR ColumnDelimeter, LPCTSTR RowDelimeter, LPCTSTR NullExpr)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x426, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, StringFormat, NumRows, ColumnDelimeter, RowDelimeter, NullExpr);
		return result;
	}
	CString get_DataMember()
	{
		CString result;
		InvokeHelper(0x428, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_DataMember(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x428, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long CompareBookmarks(VARIANT Bookmark1, VARIANT Bookmark2)
	{
		long result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x429, DISPATCH_METHOD, VT_I4, (void*)&result, parms, &Bookmark1, &Bookmark2);
		return result;
	}
	LPDISPATCH Clone(long LockType)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x40a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, LockType);
		return result;
	}
	void Resync(long AffectRecords, long ResyncValues)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x400, DISPATCH_METHOD, VT_EMPTY, NULL, parms, AffectRecords, ResyncValues);
	}
	void Seek(VARIANT KeyValues, long SeekOption)
	{
		static BYTE parms[] = VTS_VARIANT VTS_I4 ;
		InvokeHelper(0x42a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &KeyValues, SeekOption);
	}
	void put_Index(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x42b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Index()
	{
		CString result;
		InvokeHelper(0x42b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void Save(VARIANT Destination, long PersistFormat)
	{
		static BYTE parms[] = VTS_VARIANT VTS_I4 ;
		InvokeHelper(0x421, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Destination, PersistFormat);
	}


};
}