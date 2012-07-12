// DialogMain.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_release.h"
#include "DialogMain.h"
#include "afxdialogex.h"


// CDialogMain 对话框

IMPLEMENT_DYNAMIC(CDialogMain, CDialog)

CDialogMain::CDialogMain(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogMain::IDD, pParent)
{

}

CDialogMain::~CDialogMain()
{
}

void CDialogMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_TAB_MAIN, m_wndTab);
}


BEGIN_MESSAGE_MAP(CDialogMain, CDialog)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_MESSAGE(NM_SWITCHDLG, &CDialogMain::OnNmSwitchdlg)
END_MESSAGE_MAP()


// CDialogMain 消息处理程序


BOOL CDialogMain::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetParentFrame()->RecalcLayout();
	//ResizeParentToFit();
	CreateTab();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CDialogMain::CreateTab(void)
{
	//创建两个对话框

	//m_dialogPipeline.Create(IDD_DIALOG_PIPELINE, GetDlgItem(IDC_TAB_MAIN));
	//m_dialogPipeline.ModifyStyle(0, WS_SIZEBOX);
	//m_dialogBasic.Create(IDD_DIALOG_BASIC, GetDlgItem(IDC_TAB_MAIN));
	//m_dialogBasic.ModifyStyle(0, WS_SIZEBOX);
	//设定在Tab内显示的范围
	m_dialogPipeline.Create(IDD_DIALOG_PIPELINE, this);
	//m_dialogPipeline.ConnectToCANCenter(CCANCenter::Instance());
	m_dialogBasic.Create(IDD_DIALOG_BASIC, this);
	m_dialogData.Create(IDD_DIALOG_DATA, this);

	CRect rw;
	//m_wndTab.GetWindowRect(rw);
	//m_iMinWidth = rw.Width();
	//m_iMinHeight = rw.Height();
	CRect rectClient;
	GetClientRect(rectClient);
	m_iClientWidth = rectClient.Width();
	m_iClientHeight = rectClient.Height();

	rectClient.top += 0;    //0隐藏表签，20显示标签
	rectClient.bottom -= 0;
	rectClient.left += 0;
	rectClient.right -= 0;
	m_dialogPipeline.MoveWindow(&rectClient);
	m_dialogBasic.MoveWindow(&rectClient);
	m_dialogData.MoveWindow(&rectClient);

	//把对话框对象指针保存起来
	pDialog[0] = &m_dialogPipeline;
	CCANCenter::Instance()->pDialog[0] = &m_dialogPipeline;
	pDialog[1] = &m_dialogBasic;
	CCANCenter::Instance()->pDialog[1] = &m_dialogPipeline;
	pDialog[2] = &m_dialogData;
	CCANCenter::Instance()->pDialog[2] = &m_dialogData;


	//显示初始页面
	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);
	pDialog[2]->ShowWindow(SW_HIDE);
	//保存当前选择
	m_CurSelTab = 0;
	
	return TRUE;
}


int CDialogMain::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	return 0;
}


//void CDialogMain::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	// TODO: 在此添加控件通知处理程序代码
//	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);  
//
//    //得到新的页面索引  
//    m_CurSelTab = m_wndTab.GetCurSel();  
//  
//    //把新的页面显示出来  
//    pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);  
//
//	*pResult = 0;
//}


void CDialogMain::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	CWnd *pWnd;
	CWnd *pDialog;
	CRect rect;
	/*pWnd = (CTabCtrl *)GetDlgItem(IDC_TAB_MAIN);*/
	//AfxMessageBox(_T("执行成功"));

	/*if(pWnd)
	{
		GetClientRect(rect);
		pWnd->MoveWindow(rect);
		pWnd->ShowWindow(SW_SHOW);
	}*/

	pDialog = (CDialogPipeline *)GetDlgItem(IDD_DIALOG_PIPELINE);
	if(pDialog)
	{
		GetClientRect(&rect);
		rect.top += 5;    //0隐藏表签，20显示标签
		rect.bottom -= 5;
		rect.left += 5;
		rect.right -= 5;
		pDialog->MoveWindow(&rect);
	}

	pDialog = (CDialogBasic *)GetDlgItem(IDD_DIALOG_BASIC);
	if(pDialog)
	{
		GetClientRect(&rect);
		rect.top += 5;    
		rect.bottom -= 5;
		rect.left += 5;
		rect.right -= 5;
		pDialog->MoveWindow(&rect);
	}
}



afx_msg LRESULT CDialogMain::OnNmSwitchdlg(WPARAM wParam, LPARAM lParam)
{
	//int nDialogIndex = wParam - 1;
	
	for(int i = 0; i < sizeof(pDialog)/sizeof(pDialog[0]); i++)
	{
		pDialog[i]->ShowWindow(SW_HIDE);
	}

	pDialog[wParam]->ShowWindow(SW_SHOW);

	return 0;
}


//void CDialogMain::OnButtonGlobal()
//{
//	// TODO: 在此添加命令处理程序代码
//	//SendMessage(NM_SWITCHDLG, 0);
//}
