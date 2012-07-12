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

// IPC_release.cpp : 定义应用程序的类行为。
//
#include <crtdbg.h>

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "IPC_release.h"
#include "MainFrm.h"
#include "CANCenter.h"
#include "DBCenter.h"
#include "MConfig.h"
#include "Station.h"
#include "StationManager.h"
#include "IPC_releaseDoc.h"
#include "IPC_releaseView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIPC_releaseApp

BEGIN_MESSAGE_MAP(CIPC_releaseApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CIPC_releaseApp::OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// CIPC_releaseApp 构造

CIPC_releaseApp::CIPC_releaseApp()
{
	m_bHiColorIcons = TRUE;

	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// 如果应用程序是利用公共语言运行时支持(/clr)构建的，则:
	//     1) 必须有此附加设置，“重新启动管理器”支持才能正常工作。
	//     2) 在您的项目中，您必须按照生成顺序向 System.Windows.Forms 添加引用。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: 将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("IPC_release.AppID.NoVersion"));

	// TODO: 在此处添加构造代码，
	
	
	//m_Config = new CMConfig;
	
	
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CIPC_releaseApp 对象

CIPC_releaseApp theApp;


// CIPC_releaseApp 初始化

BOOL CIPC_releaseApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// 使用 RichEdit 控件需要  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// 注册应用程序的文档模板。文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CIPC_releaseDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
		RUNTIME_CLASS(CIPC_releaseView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	//((CMainFrame *)pDocTemplate->Get)


	// 分析标准 shell 命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// 调度在命令行中指定的命令。如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// 仅当具有后缀时才调用 DragAcceptFiles
	//  在 SDI 应用程序中，这应在 ProcessShellCommand 之后发生

	InitStationClass();
	m_threadCANRead = AfxBeginThread(ThreadCANRead, CCANCenter::Instance(), 0, 0, CREATE_SUSPENDED);
	m_threadCANWrite = AfxBeginThread(ThreadCANWrite, CCANCenter::Instance(), 0, 0, CREATE_SUSPENDED);
	m_threadDBWrite = AfxBeginThread(ThreadDBWrite, CDBCenter::Instance(), 0, 0, CREATE_SUSPENDED);
	
	//m_threadCANRead->ResumeThread();
	m_threadCANWrite->ResumeThread();
	

	return TRUE;
}

int CIPC_releaseApp::ExitInstance()
{
	//TODO: 处理可能已添加的附加资源
	//delete m_Config;
	theApp.m_threadCANRead->SuspendThread();
	theApp.m_threadCANWrite->SuspendThread();
	theApp.m_threadDBWrite->SuspendThread();
	theApp.m_threadCANRead->ExitInstance();
	theApp.m_threadCANWrite->ExitInstance();
	theApp.m_threadDBWrite->ExitInstance();

	delete theApp.m_threadCANRead;
	delete theApp.m_threadCANWrite;
	delete theApp.m_threadDBWrite;
	
	
	//theApp.m_threadCAN->Delete();
	
	CCANCenter::ExitInstance();
	CDBCenter::ExitInstance();
	CMConfig::ExitInstance();
	ExitStationClass();
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CIPC_releaseApp 消息处理程序


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_TIMER()
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void CIPC_releaseApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CIPC_releaseApp 自定义加载/保存方法

void CIPC_releaseApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CIPC_releaseApp::LoadCustomState()
{
}

void CIPC_releaseApp::SaveCustomState()
{
}

// CIPC_releaseApp 消息处理程序





BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


//void CAboutDlg::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	CDialogEx::OnTimer(nIDEvent);
//}


void CIPC_releaseApp::InitStationClass(void)
{
	//初始化工位对象，并和CCANCenter关联
	(CCANCenter::Instance())->Config(CMConfig::Instance());

	m_StationMngr = new CStationManager(CMConfig::Instance()->StationNBR);
	CCANCenter::Instance()->AttachStations(m_StationMngr);
}




void CIPC_releaseApp::Log(CString info)
{
	this->m_Monitor.Log(info);
}


int CIPC_releaseApp::ExitStationClass(void)
{
	delete m_StationMngr;

	return 0;
}


UINT ThreadCANRead(LPVOID pThreadParam)
{
	CCANCenter *m_CAN = (CCANCenter *)pThreadParam;

	if(m_CAN->IsPortOpen() == false)
		m_CAN->Openport();

	//::WaitForSingleObject(m_CAN->m_CANOpened.m_hObject, INFINITE);
	while(1)
	{
		::Sleep(1);
		m_CAN->TestRecv();
		//m_CAN->ParseMsg();
		//m_CAN->ParseCAN(
		//m_CAN->Deliver((i % theApp.m_Config.StationNBR) + 1, _T("test"));
	}
	
	return 0;
}

UINT ThreadCANWrite(LPVOID pThreadParam)
{
	CCANCenter *m_CAN = (CCANCenter *)pThreadParam;
	//m_CAN->Openport();
	CEvent *m_WriteFinished = new CEvent(FALSE, FALSE);
	delete m_WriteFinished;

	while(1)
	{
		::WaitForSingleObject(m_CAN->m_WriteEvent.m_hObject, INFINITE);
		m_CAN->SendMsg();
	}
}

UINT ThreadDBWrite(LPVOID pThreadParam)
{
	CDBCenter *m_DB = (CDBCenter *)pThreadParam;
	while(1)
	{
		::Sleep(100);
		m_DB->Flush();
	}
}