// DialogData.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_release.h"
#include "DialogData.h"
#include "afxdialogex.h"
#include "CppSQLite3.h"
#include "DBCenter.h"


// CDialogData 对话框

IMPLEMENT_DYNAMIC(CDialogData, CDialogEx)

CDialogData::CDialogData(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogData::IDD, pParent)
{

}

CDialogData::~CDialogData()
{
}

void CDialogData::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATE_FROM, m_DateFrom);
	DDX_Control(pDX, IDC_DATE_TO, m_DateTo);
	DDX_Control(pDX, IDC_TIME_FROM, m_TimeFrom);
	DDX_Control(pDX, IDC_TIME_TO, m_TimeTo);
	DDX_Control(pDX, IDC_LIST_DB, m_ListDB);
}


BEGIN_MESSAGE_MAP(CDialogData, CDialogEx)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON_DB_QUERY_ALL, &CDialogData::OnBnClickedButtonDbQueryAll)
	ON_BN_CLICKED(IDC_BUTTON_DBLIST_CLEAR, &CDialogData::OnBnClickedButtonDblistClear)
END_MESSAGE_MAP()


// CDialogData 消息处理程序


void CDialogData::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (GetSafeHwnd() == NULL)
	{
		return;
	}
	
	CRect rectClient;
	GetClientRect(rectClient);
	//m_wndListCtrl.SetWindowPos(NULL, rectClient.left + 1, rectClient.top + 1, rectClient.Width() - 2, rectClient.Height() - 2, SWP_NOACTIVATE | SWP_NOZORDER);
}


int CDialogData::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	
	
	

	return 0;
}


BOOL CDialogData::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_ListDB.SetExtendedStyle(LVS_EX_FLATSB
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);

	m_ListDB.InsertColumn(0, _T("ID"));
	//m_ListDB.InsertColumn(1, _T("日期"));
	//m_ListDB.InsertColumn(2, _T("时间"));
	m_ListDB.InsertColumn(1, const_cast<LPCTSTR>(_T("字节0")));
	m_ListDB.InsertColumn(2, _T("字节1"));
	m_ListDB.InsertColumn(3, _T("字节2"));
	m_ListDB.InsertColumn(4, _T("字节3"));
	m_ListDB.InsertColumn(5, _T("字节4"));
	m_ListDB.InsertColumn(6, _T("字节5"));
	m_ListDB.InsertColumn(7, _T("字节6"));
	m_ListDB.InsertColumn(8, _T("字节7"));

	AdjustColumnWidth();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDialogData::AdjustColumnWidth(void)
{
	CHeaderCtrl* pHeaderCtrl = this->m_ListDB.GetHeaderCtrl();
	 int nColumnCount = pHeaderCtrl->GetItemCount();              // 获得列数  
    for (int i = 0; i < nColumnCount; i++)  
    {  
        m_ListDB.SetColumnWidth(i, LVSCW_AUTOSIZE);  
        int nColumnWidth = m_ListDB.GetColumnWidth(i);     // 表头的宽度  
        m_ListDB.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);  // 数据的宽度  
        int nHeaderWidth = m_ListDB.GetColumnWidth(i);  
        m_ListDB.SetColumnWidth(i, nColumnWidth>nHeaderWidth?nColumnWidth:nHeaderWidth);  // 取较大值  
    }  
}


void CDialogData::OnBnClickedButtonDbQueryAll()
{
	// TODO: 测试数据库，请修改
	CppSQLite3Query* query = CDBCenter::Instance()->QueryAll();
	int index = 0;

	while (!query->eof())
	{
		m_ListDB.InsertItem(index, _T(""));

		CString str0(query->fieldValue(0));
		m_ListDB.SetItemText(index, 0, str0);

		CString str1(query->fieldValue(1));
		m_ListDB.SetItemText(index, 1, str1);

		CString str2(query->fieldValue(2));
		m_ListDB.SetItemText(index, 2, str2);

		CString str3(query->fieldValue(3));
		m_ListDB.SetItemText(index, 3, str3);

		CString str4(query->fieldValue(4));
		m_ListDB.SetItemText(index, 4, str4);

		CString str5(query->fieldValue(5));
		m_ListDB.SetItemText(index, 5, str5);

		CString str6(query->fieldValue(6));
		m_ListDB.SetItemText(index, 6, str6);

		CString str7(query->fieldValue(7));
		m_ListDB.SetItemText(index, 7, str7);

		CString str8(query->fieldValue(8));
		m_ListDB.SetItemText(index, 8, str8);

		index++;
		query->nextRow();
	}

	delete query;
}


void CDialogData::OnBnClickedButtonDblistClear()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ListDB.DeleteAllItems();
}
