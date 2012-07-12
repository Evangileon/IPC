// DialogPipeline.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_release.h"
#include "DialogPipeline.h"
#include "afxdialogex.h"


// CDialogPipeline 对话框

IMPLEMENT_DYNAMIC(CDialogPipeline, CDialog)

CDialogPipeline::CDialogPipeline(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogPipeline::IDD, pParent)
{
	BuildCollection();
}

CDialogPipeline::~CDialogPipeline()
{
}

void CDialogPipeline::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LED_1, m_LED_1);
	//  DDX_Control(pDX, IDC_LED_10, m_LED_2);
	DDX_Control(pDX, IDC_LED_10, m_LED_10);
	DDX_Control(pDX, IDC_LED_11, m_LED_11);
	DDX_Control(pDX, IDC_LED_12, m_LED_12);
	DDX_Control(pDX, IDC_LED_13, m_LED_13);
	DDX_Control(pDX, IDC_LED_14, m_LED_14);
	DDX_Control(pDX, IDC_LED_15, m_LED_15);
	DDX_Control(pDX, IDC_LED_16, m_LED_16);
	DDX_Control(pDX, IDC_LED_17, m_LED_17);
	DDX_Control(pDX, IDC_LED_18, m_LED_18);
	DDX_Control(pDX, IDC_LED_19, m_LED_19);
	DDX_Control(pDX, IDC_LED_2, m_LED_2);
	DDX_Control(pDX, IDC_LED_3, m_LED_3);
	DDX_Control(pDX, IDC_LED_4, m_LED_4);
	DDX_Control(pDX, IDC_LED_5, m_LED_5);
	DDX_Control(pDX, IDC_LED_6, m_LED_6);
	DDX_Control(pDX, IDC_LED_7, m_LED_7);
	DDX_Control(pDX, IDC_LED_8, m_LED_8);
	DDX_Control(pDX, IDC_LED_9, m_LED_9);
}


BEGIN_MESSAGE_MAP(CDialogPipeline, CDialog)
	ON_WM_PAINT()
	ON_MESSAGE(NM_NOTIFYCTRL, &CDialogPipeline::OnNmNotifyctrl)
END_MESSAGE_MAP()


// CDialogPipeline 消息处理程序


void CDialogPipeline::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CRect  rect;   
	GetClientRect(&rect);   
	CDC  dcMem;   
	dcMem.CreateCompatibleDC(&dc);   
	CBitmap  bmpBackground;   
	bmpBackground.LoadBitmap(IDB_BITMAP_LINE);  
	//IDB_BITMAP是你自己的图对应的ID
	BITMAP  bitmap;   
	bmpBackground.GetBitmap(&bitmap);   
	CBitmap  *pbmpOld=dcMem.SelectObject(&bmpBackground); 
	//dc.
	dc.StretchBlt(30,65,bitmap.bmWidth,bitmap.bmHeight,&dcMem,0,0,   
		bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);
}


afx_msg LRESULT CDialogPipeline::OnNmNotifyctrl(WPARAM wParam, LPARAM lParam)
{
	//theApp.Log(_T("notify"));
	int CtrlClass = wParam;
	int nID = lParam;
	if(CtrlClass == ID_CLASS_LED)
	{
		CStation tmp = (CCANCenter::Instance()->m_Stations->GetStationByID(nID));
		m_LED_set[nID - 1]->SetLED(tmp.m_Status);
		m_LED_set[nID - 1]->UpdateData(FALSE);
	}

	return 0;
}


int CDialogPipeline::NotifyStatus(int status)
{
	
	
	return 0;
}


void CDialogPipeline::BuildCollection(void)
{
	//m_LED_set = new vector<CStaticLED *>(theApp.m_Config.StationNBR);
	m_LED_set[0] = &m_LED_1;
	m_LED_set[1] = &m_LED_2;
	m_LED_set[2] = &m_LED_3;
	m_LED_set[3] = &m_LED_4;
	m_LED_set[4] = &m_LED_5;
	m_LED_set[5] = &m_LED_6;
	m_LED_set[6] = &m_LED_7;
	m_LED_set[7] = &m_LED_8;
	m_LED_set[8] = &m_LED_9;
	m_LED_set[9] = &m_LED_10;
	m_LED_set[10] = &m_LED_11;
	m_LED_set[11] = &m_LED_12;
	m_LED_set[12] = &m_LED_13;
	m_LED_set[13] = &m_LED_14;
	m_LED_set[14] = &m_LED_15;
	m_LED_set[15] = &m_LED_16;
	m_LED_set[16] = &m_LED_17;
	m_LED_set[17] = &m_LED_18;
	m_LED_set[18] = &m_LED_19;
}
