// DialogMedia.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_release.h"
#include "DialogMedia.h"
#include "afxdialogex.h"
#include "LED.h"


// CDialogMedia 对话框

IMPLEMENT_DYNAMIC(CDialogMedia, CDialog)

CDialogMedia::CDialogMedia(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogMedia::IDD, pParent)
{

}

CDialogMedia::~CDialogMedia()
{
}

void CDialogMedia::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CAP, m_editCaption);
	DDX_Control(pDX, IDC_EDIT_X, m_editX);
	DDX_Control(pDX, IDC_EDIT_Y, m_editY);
	DDX_Control(pDX, IDC_EDIT_Z, m_editZ);

	
	DDX_Control(pDX, IDC_EDIT_CAP10, m_editCap_10);
	DDX_Control(pDX, IDC_EDIT_CAP11, m_editCap_11);
	DDX_Control(pDX, IDC_EDIT_CAP12, m_editCap_12);
	DDX_Control(pDX, IDC_EDIT_CAP13, m_editCap_13);
	DDX_Control(pDX, IDC_EDIT_CAP14, m_editCap_14);
	DDX_Control(pDX, IDC_EDIT_CAP15, m_editCap_15);
	DDX_Control(pDX, IDC_EDIT_CAP16, m_editCap_16);
	DDX_Control(pDX, IDC_EDIT_CAP17, m_editCap_17);
	DDX_Control(pDX, IDC_EDIT_CAP18, m_editCap_18);
	DDX_Control(pDX, IDC_EDIT_CAP19, m_editCap_19);
	DDX_Control(pDX, IDC_EDIT_CAP2, m_editCap_2);
	DDX_Control(pDX, IDC_EDIT_CAP20, m_editCap_20);
	DDX_Control(pDX, IDC_EDIT_CAP21, m_editCap_21);
	DDX_Control(pDX, IDC_EDIT_CAP22, m_editCap_22);
	DDX_Control(pDX, IDC_EDIT_CAP23, m_editCap_23);
	DDX_Control(pDX, IDC_EDIT_CAP24, m_editCap_24);
	DDX_Control(pDX, IDC_EDIT_CAP25, m_editCap_25);
	DDX_Control(pDX, IDC_EDIT_CAP26, m_editCap_26);
	DDX_Control(pDX, IDC_EDIT_CAP27, m_editCap_27);
	DDX_Control(pDX, IDC_EDIT_CAP28, m_editCap_28);
	DDX_Control(pDX, IDC_EDIT_CAP29, m_editCap_29);
	DDX_Control(pDX, IDC_EDIT_CAP3, m_editCap_3);
	DDX_Control(pDX, IDC_EDIT_CAP30, m_editCap_30);
	DDX_Control(pDX, IDC_EDIT_CAP4, m_editCap_4);
	DDX_Control(pDX, IDC_EDIT_CAP5, m_editCap_5);
	DDX_Control(pDX, IDC_EDIT_CAP6, m_editCap_6);
	DDX_Control(pDX, IDC_EDIT_CAP7, m_editCap_7);
	DDX_Control(pDX, IDC_EDIT_CAP8, m_editCap_8);
	DDX_Control(pDX, IDC_EDIT_CAP9, m_editCap_9);

	DDX_Control(pDX, IDC_EDIT_X10, m_edit_X_10);
	DDX_Control(pDX, IDC_EDIT_X11, m__edit_X_11);
	DDX_Control(pDX, IDC_EDIT_X12, m__edit_X_12);
	DDX_Control(pDX, IDC_EDIT_X13, m__edit_X_13);
	DDX_Control(pDX, IDC_EDIT_X14, m__edit_X_14);
	DDX_Control(pDX, IDC_EDIT_X15, m__edit_X_15);
	DDX_Control(pDX, IDC_EDIT_X16, m__edit_X_16);
	DDX_Control(pDX, IDC_EDIT_X17, m__edit_X_17);
	DDX_Control(pDX, IDC_EDIT_X18, m__edit_X_18);
	DDX_Control(pDX, IDC_EDIT_X19, m__edit_X_19);
	DDX_Control(pDX, IDC_EDIT_X2, m__edit_X_2);
	DDX_Control(pDX, IDC_EDIT_X20, m__edit_X_20);
	DDX_Control(pDX, IDC_EDIT_X21, m__edit_X_21);
	DDX_Control(pDX, IDC_EDIT_X22, m__edit_X_22);
	DDX_Control(pDX, IDC_EDIT_X23, m__edit_X_23);
	DDX_Control(pDX, IDC_EDIT_X24, m__edit_X_24);
	DDX_Control(pDX, IDC_EDIT_X25, m__edit_X_25);
	DDX_Control(pDX, IDC_EDIT_X26, m__edit_X_26);
	DDX_Control(pDX, IDC_EDIT_X27, m__edit_X_27);
	DDX_Control(pDX, IDC_EDIT_X28, m__edit_X_28);
	DDX_Control(pDX, IDC_EDIT_X29, m__edit_X_29);
	DDX_Control(pDX, IDC_EDIT_X3, m__edit_X_3);
	DDX_Control(pDX, IDC_EDIT_X30, m__edit_X_30);
	DDX_Control(pDX, IDC_EDIT_X4, m__edit_X_4);
	DDX_Control(pDX, IDC_EDIT_X5, m__edit_X_5);
	DDX_Control(pDX, IDC_EDIT_X6, m__edit_X_6);
	DDX_Control(pDX, IDC_EDIT_X7, m__edit_X_7);
	DDX_Control(pDX, IDC_EDIT_X8, m__edit_X_8);
	DDX_Control(pDX, IDC_EDIT_X9, m__edit_X_9);
	DDX_Control(pDX, IDC_EDIT_Y10, m_edit_Y_10);
	DDX_Control(pDX, IDC_EDIT_Y11, m__edit_Y_11);
	DDX_Control(pDX, IDC_EDIT_Y12, m__edit_Y_12);
	DDX_Control(pDX, IDC_EDIT_Y13, m__edit_Y_13);
	DDX_Control(pDX, IDC_EDIT_Y14, m__edit_Y_14);
	DDX_Control(pDX, IDC_EDIT_Y15, m__edit_Y_15);
	DDX_Control(pDX, IDC_EDIT_Y16, m__edit_Y_16);
	DDX_Control(pDX, IDC_EDIT_Y17, m__edit_Y_17);
	DDX_Control(pDX, IDC_EDIT_Y18, m__edit_Y_18);
	DDX_Control(pDX, IDC_EDIT_Y19, m__edit_Y_19);
	DDX_Control(pDX, IDC_EDIT_Y2, m__edit_Y_2);
	DDX_Control(pDX, IDC_EDIT_Y20, m__edit_Y_20);
	DDX_Control(pDX, IDC_EDIT_Y21, m__edit_Y_21);
	DDX_Control(pDX, IDC_EDIT_Y22, m__edit_Y_22);
	DDX_Control(pDX, IDC_EDIT_Y23, m__edit_Y_23);
	DDX_Control(pDX, IDC_EDIT_Y24, m__edit_Y_24);
	DDX_Control(pDX, IDC_EDIT_Y25, m__edit_Y_25);
	DDX_Control(pDX, IDC_EDIT_Y26, m__edit_Y_26);
	DDX_Control(pDX, IDC_EDIT_Y27, m__edit_Y_27);
	DDX_Control(pDX, IDC_EDIT_Y28, m__edit_Y_28);
	DDX_Control(pDX, IDC_EDIT_Y29, m__edit_Y_29);
	DDX_Control(pDX, IDC_EDIT_Y3, m__edit_Y_3);
	DDX_Control(pDX, IDC_EDIT_Y30, m__edit_Y_30);
	DDX_Control(pDX, IDC_EDIT_Y4, m__edit_Y_4);
	DDX_Control(pDX, IDC_EDIT_Y5, m__edit_Y_5);
	DDX_Control(pDX, IDC_EDIT_Y6, m__edit_Y_6);
	DDX_Control(pDX, IDC_EDIT_Y7, m__edit_Y_7);
	DDX_Control(pDX, IDC_EDIT_Y8, m__edit_Y_8);
	DDX_Control(pDX, IDC_EDIT_Y9, m__edit_Y_9);
	DDX_Control(pDX, IDC_EDIT_Z10, m__edit_Z_10);
	DDX_Control(pDX, IDC_EDIT_Z11, m__edit_Z_11);
	DDX_Control(pDX, IDC_EDIT_Z12, m__edit_Z_12);
	DDX_Control(pDX, IDC_EDIT_Z13, m__edit_Z_13);
	DDX_Control(pDX, IDC_EDIT_Z14, m__edit_Z_14);
	DDX_Control(pDX, IDC_EDIT_Z15, m__edit_Z_15);
	DDX_Control(pDX, IDC_EDIT_Z16, m__edit_Z_16);
	DDX_Control(pDX, IDC_EDIT_Z17, m__edit_Z_17);
	DDX_Control(pDX, IDC_EDIT_Z18, m__edit_Z_18);
	DDX_Control(pDX, IDC_EDIT_Z19, m__edit_Z_19);
	DDX_Control(pDX, IDC_EDIT_Z2, m__edit_Z_2);
	DDX_Control(pDX, IDC_EDIT_Z20, m__edit_Z_20);
	DDX_Control(pDX, IDC_EDIT_Z21, m__edit_Z_21);
	DDX_Control(pDX, IDC_EDIT_Z22, m__edit_Z_22);
	DDX_Control(pDX, IDC_EDIT_Z23, m__edit_Z_23);
	DDX_Control(pDX, IDC_EDIT_Z24, m__edit_Z_24);
	DDX_Control(pDX, IDC_EDIT_Z25, m__edit_Z_25);
	DDX_Control(pDX, IDC_EDIT_Z26, m__edit_Z_26);
	DDX_Control(pDX, IDC_EDIT_Z27, m__edit_Z_27);
	DDX_Control(pDX, IDC_EDIT_Z28, m__edit_Z_28);
	DDX_Control(pDX, IDC_EDIT_Z29, m__edit_Z_29);
	DDX_Control(pDX, IDC_EDIT_Z3, m__edit_Z_3);
	DDX_Control(pDX, IDC_EDIT_Z30, m__edit_Z_30);
	DDX_Control(pDX, IDC_EDIT_Z4, m__edit_Z_4);
	DDX_Control(pDX, IDC_EDIT_Z5, m__edit_Z_5);
	DDX_Control(pDX, IDC_EDIT_Z6, m__edit_Z_6);
	DDX_Control(pDX, IDC_EDIT_Z7, m__edit_Z_7);
	DDX_Control(pDX, IDC_EDIT_Z8, m__edit_Z_8);
	DDX_Control(pDX, IDC_EDIT_Z9, m__edit_Z_9);

	DDX_Control(pDX, IDC_STATIC_LED, m_LED);
	DDX_Control(pDX, IDC_STATIC_LED2, m_LED_2);
	DDX_Control(pDX, IDC_STATIC_LED3, m_LED_3);
	DDX_Control(pDX, IDC_STATIC_LED4, m_LED_4);
	DDX_Control(pDX, IDC_STATIC_LED5, m_LED_5);
	DDX_Control(pDX, IDC_STATIC_LED6, m_LED_6);
	DDX_Control(pDX, IDC_STATIC_LED7, m_LED_7);
	DDX_Control(pDX, IDC_STATIC_LED8, m_LED_8);
	DDX_Control(pDX, IDC_STATIC_LED9, m_LED_9);
	DDX_Control(pDX, IDC_STATIC_LED10, m_LED_10);
	DDX_Control(pDX, IDC_STATIC_LED11, m_LED_11);
	DDX_Control(pDX, IDC_STATIC_LED12, m_LED_12);
	DDX_Control(pDX, IDC_STATIC_LED13, m_LED_13);
	DDX_Control(pDX, IDC_STATIC_LED14, m_LED_14);
	DDX_Control(pDX, IDC_STATIC_LED15, m_LED_15);
	DDX_Control(pDX, IDC_STATIC_LED16, m_LED_16);
	DDX_Control(pDX, IDC_STATIC_LED17, m_LED_17);
	DDX_Control(pDX, IDC_STATIC_LED18, m_LED_18);
	DDX_Control(pDX, IDC_STATIC_LED19, m_LED_19);
	DDX_Control(pDX, IDC_STATIC_LED20, m_LED_20);
	DDX_Control(pDX, IDC_STATIC_LED21, m_LED_21);
	DDX_Control(pDX, IDC_STATIC_LED22, m_LED_22);
	DDX_Control(pDX, IDC_STATIC_LED23, m_LED_23);
	DDX_Control(pDX, IDC_STATIC_LED24, m_LED_24);
	DDX_Control(pDX, IDC_STATIC_LED25, m_LED_25);
	DDX_Control(pDX, IDC_STATIC_LED26, m_LED_26);
	DDX_Control(pDX, IDC_STATIC_LED27, m_LED_27);
	DDX_Control(pDX, IDC_STATIC_LED28, m_LED_28);
	DDX_Control(pDX, IDC_STATIC_LED29, m_LED_29);
	DDX_Control(pDX, IDC_STATIC_LED30, m_LED_30);
}


BEGIN_MESSAGE_MAP(CDialogMedia, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDialogMedia 消息处理程序


BOOL CDialogMedia::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//AfxMessageBox(_T("对了"));
	CWnd *pWnd = (CWnd *)GetDlgItem(IDC_STATIC_LED);
	if(pWnd == NULL)
		AfxMessageBox(_T("坏了"));
	m_LED.SetLED(pWnd,ID_LED_RED,ID_SHAPE_ROUND);
	pLEDs[0] = &m_LED;
	m_editX.SetWindowTextW(_T("测试"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDialogMedia::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CRect rect;
	GetWindowRect(rect);
	ScreenToClient(rect);

	rect.InflateRect(1, 1);
	dc.Draw3dRect(rect, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));
}


void CDialogMedia::Set_X(int x)
{
	CString str;
	str.Format(_T("%d"), x);
	m_editX.SetWindowTextW(str);
}


void CDialogMedia::Set_Y(int y)
{
	CString str;
	str.Format(_T("%d"), y);
	m_editX.SetWindowTextW(str);
}


void CDialogMedia::Set_Z(int z)
{
	CString str;
	str.Format(_T("%d"), z);
	m_editX.SetWindowTextW(str);
}

void CDialogMedia::SetCordinate(int x, int y, int z)
{
	Set_X(x);
	Set_Y(y);
	Set_Z(z);
}

void CDialogMedia::SetLEDColor(UINT nIDColor)
{
	m_LED.SetLED(NULL, nIDColor, ID_SHAPE_ROUND);
}
