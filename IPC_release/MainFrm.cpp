// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "IPC_release.h"
#include "StationListView.h"
#include "MConfig.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnUpdateApplicationLook)
	ON_WM_SETTINGCHANGE()
	ON_COMMAND(ID_BUTTON_GLOBAL, &CMainFrame::OnButtonGlobal)
	ON_COMMAND(ID_BUTTON_OPENCAN, &CMainFrame::OnButtonOpencan)
	ON_COMMAND(ID_BUTTON_DATA_CHECK, &CMainFrame::OnButtonDataCheck)
	ON_UPDATE_COMMAND_UI(ID_CHECK_RECV_STANDARD, &CMainFrame::OnUpdateCheckRecvStandard)
	ON_COMMAND(ID_CHECK_RECV_STANDARD, &CMainFrame::OnCheckRecvStandard)
	ON_COMMAND(ID_CHECK_RECV_REMOTE, &CMainFrame::OnCheckRecvRemote)
	ON_UPDATE_COMMAND_UI(ID_CHECK_RECV_REMOTE, &CMainFrame::OnUpdateCheckRecvRemote)
	ON_COMMAND(ID_CHECK_SEND_STANDARD, &CMainFrame::OnCheckSendStandard)
	ON_UPDATE_COMMAND_UI(ID_CHECK_SEND_STANDARD, &CMainFrame::OnUpdateCheckSendStandard)
	ON_COMMAND(ID_CHECK_SEND_REMOTE, &CMainFrame::OnCheckSendRemote)
	ON_UPDATE_COMMAND_UI(ID_CHECK_SEND_REMOTE, &CMainFrame::OnUpdateCheckSendRemote)
	ON_COMMAND(ID_BUTTON_SAVECONFIG, &CMainFrame::OnButtonSaveconfig)
END_MESSAGE_MAP()

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
	theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_OFF_2007_BLACK);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;
	// 基于持久值设置视觉管理器和样式
	OnApplicationLook(theApp.m_nAppLook);

	m_wndRibbonBar.Create(this);
	m_wndRibbonBar.LoadFromResource(IDR_RIBBON);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}

	CString strTitlePane1;
	CString strTitlePane2;
	bNameValid = strTitlePane1.LoadString(IDS_STATUS_PANE1);
	ASSERT(bNameValid);
	bNameValid = strTitlePane2.LoadString(IDS_STATUS_PANE2);
	ASSERT(bNameValid);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE1, strTitlePane1, TRUE), strTitlePane1);
	m_wndStatusBar.AddExtendedElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE2, strTitlePane2, TRUE), strTitlePane2);

	// 启用 Visual Studio 2005 样式停靠窗口行为
	CDockingManager::SetDockingMode(DT_SMART);
	// 启用 Visual Studio 2005 样式停靠窗口自动隐藏行为
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// 加载菜单项图像(不在任何标准工具栏上):
	CMFCToolBar::AddToolBarForImageCollection(IDR_MENU_IMAGES, theApp.m_bHiColorIcons ? IDB_MENU_IMAGES_24 : 0);

	// 创建停靠窗口
	if (!CreateDockingWindows())
	{
		TRACE0("未能创建停靠窗口\n");
		return -1;
	}

	
	m_wndStationView.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndStationView);
	m_wndOutput.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndOutput);
	theApp.m_Monitor.SetScreen(&m_wndOutput.m_wndOutputBuild);

	CreateTabWindow();


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

BOOL CMainFrame::CreateDockingWindows()
{
	BOOL bNameValid;

	CString strStationView;
	bNameValid = strStationView.LoadString(IDS_STATIONLIST_VIEW);
	ASSERT(bNameValid);
	if (!m_wndStationView.Create(strStationView, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_STATIONLIST, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT, AFX_CBRS_REGULAR_TABS, AFX_CBRS_RESIZE))
	{
		TRACE0("未能创建“文件视图”窗口\n");
		return FALSE; // 未能创建
	}


	// 创建输出窗口
	CString strOutputWnd;
	bNameValid = strOutputWnd.LoadString(IDS_OUTPUT_WND);
	ASSERT(bNameValid);
	if (!m_wndOutput.Create(strOutputWnd, this, CRect(0, 0, 100, 100), TRUE, ID_VIEW_OUTPUTWND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI, AFX_CBRS_REGULAR_TABS, AFX_CBRS_RESIZE))
	{
		TRACE0("未能创建输出窗口\n");
		return FALSE; // 未能创建
	}

	SetDockingWindowIcons(theApp.m_bHiColorIcons);
	return TRUE;
}

void CMainFrame::SetDockingWindowIcons(BOOL bHiColorIcons)
{

	HICON hOutputBarIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_OUTPUT_WND_HC : IDI_OUTPUT_WND), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
	m_wndOutput.SetIcon(hOutputBarIcon, FALSE);

}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_VS_2008:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(TRUE);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
	}

	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

	theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}

void CMainFrame::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CFrameWndEx::OnSettingChange(uFlags, lpszSection);
	m_wndOutput.UpdateFonts();
}


//void CMainFrame::OnClickTest(void)
//{
//	//AfxMessageBox(_T("测试成功！"));
//}


//void CMainFrame::OnButton2()
//{
//	// TODO: 在此添加命令处理程序代码
//	//AfxMessageBox(_T("测试成功！"));
//}


void CMainFrame::DoDataExchange(CDataExchange* pDX)
{
	// TODO: 在此添加专用代码和/或调用基类

	CFrameWndEx::DoDataExchange(pDX);
}

BOOL CMainFrame::CreateTabWindow()
{
	return TRUE;
}


void CMainFrame::OnButtonGlobal()
{
	// TODO: 在此添加命令处理程序代码
	CIPC_releaseView *pView=(CIPC_releaseView *)this->GetActiveView();
	pView->PostMessage(NM_SWITCHDLG, 0, 0);

	theApp.m_Monitor.Log(_T("test"));
}


void CMainFrame::OnButtonOpencan()
{
	// TODO: 在此添加命令处理程序代码
	//AfxMessageBox(_T("ohhhhhhhh"));
	theApp.Log(_T("正在打开CAN"));
	//theApp.m_threadCANRead->Run();
	if(CCANCenter::Instance()->IsPortOpen() == false)
		CCANCenter::Instance()->Openport();
	if(CCANCenter::Instance()->IsPortOpen() == true)
	{
		theApp.m_threadCANRead->ResumeThread();
		theApp.Log(_T("打开CAN成功"));
	}
}


void CMainFrame::OnButtonDataCheck()
{
	// TODO: 在此添加命令处理程序代码
	CIPC_releaseView *pView=(CIPC_releaseView *)this->GetActiveView();
	pView->PostMessage(NM_SWITCHDLG, 2, 0);
}


void CMainFrame::OnCheckRecvStandard()
{
	// TODO: 在此添加命令处理程序代码
	CCANCenter::Instance()->m_ChkSffR = TRUE;
}

void CMainFrame::OnUpdateCheckRecvStandard(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(CCANCenter::Instance()->m_ChkSffR);
}

void CMainFrame::OnCheckRecvRemote()
{
	// TODO: 在此添加命令处理程序代码
	CCANCenter::Instance()->m_ChkSffR = FALSE;
}


void CMainFrame::OnUpdateCheckRecvRemote(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(!(CCANCenter::Instance()->m_ChkSffR));
}


void CMainFrame::OnCheckSendStandard()
{
	// TODO: 在此添加命令处理程序代码
	CCANCenter::Instance()->m_ChkSffS = TRUE;
}


void CMainFrame::OnUpdateCheckSendStandard(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(CCANCenter::Instance()->m_ChkSffS);
}


void CMainFrame::OnCheckSendRemote()
{
	// TODO: 在此添加命令处理程序代码
	CCANCenter::Instance()->m_ChkSffS = FALSE;
}


void CMainFrame::OnUpdateCheckSendRemote(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(!(CCANCenter::Instance()->m_ChkSffS));
}


void CMainFrame::OnButtonSaveconfig()
{
	// TODO: 在此添加命令处理程序代码
	CMConfig::Instance()->Save();
}
