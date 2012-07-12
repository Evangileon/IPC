// DialogBasic.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_release.h"
#include "DialogBasic.h"
#include "afxdialogex.h"


// CDialogBasic 对话框

IMPLEMENT_DYNAMIC(CDialogBasic, CDialog)

CDialogBasic::CDialogBasic(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogBasic::IDD, pParent)
{
	BuildCollection();
}

CDialogBasic::~CDialogBasic()
{
}

void CDialogBasic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_BASIC__VY, m_edit_Vy);
	DDX_Control(pDX, IDC_EDIT_BASIC__VZ, m_edit_Vz);
	DDX_Control(pDX, IDC_EDIT_BASIC__Z, m_edit_z);
	DDX_Control(pDX, IDC_EDIT_BASIC_toX, m_edit_to_x);
	DDX_Control(pDX, IDC_EDIT_BASIC_toY, m_edit_to_y);
	DDX_Control(pDX, IDC_EDIT_BASIC_toZ, m_edit_to_z);
	DDX_Control(pDX, IDC_EDIT_BASIC_VX, m_edit_Vx);
	DDX_Control(pDX, IDC_EDIT_BASIC_X, m_edit_x);
	DDX_Control(pDX, IDC_EDIT_BASIC_Y, m_edit_y);
	DDX_Check(pDX, IDC_RADIO_REAL, CMConfig::Instance()->m_bReal);
	DDX_Check(pDX, IDC_RADIO_VIRTUE, CMConfig::Instance()->m_bVirtue);
}


BEGIN_MESSAGE_MAP(CDialogBasic, CDialog)
	ON_MESSAGE(NM_NOTIFYCTRL, &CDialogBasic::OnNmNotifyctrl)
END_MESSAGE_MAP()


// CDialogBasic 消息处理程序


afx_msg LRESULT CDialogBasic::OnNmNotifyctrl(WPARAM wParam, LPARAM lParam)
{
	int nCtrlClass = wParam;
	int nID = lParam;
	CString str;
	
	switch(nCtrlClass)
	{
	case ID_CLASS_EDIT_X:
		str.Format(_T("%d"), CCANCenter::Instance()->m_Stations->GetStationByID(nID).m_nX);
		m_edit_x.SetWindowText(str);
		m_edit_x.UpdateData(FALSE);
		break;
	case ID_CLASS_EDIT_Y:
		str.Format(_T("%d"), CCANCenter::Instance()->m_Stations->GetStationByID(nID).m_nY);
		m_edit_y.SetWindowText(str);
		m_edit_y.UpdateData(FALSE);
		break;
	case ID_CLASS_EDIT_Z:
		str.Format(_T("%d"), CCANCenter::Instance()->m_Stations->GetStationByID(nID).m_nZ);
		m_edit_z.SetWindowText(str);
		m_edit_z.UpdateData(FALSE);
		break;
	default:
		return 0;
	}

	//m_edit_set[nCtrlClass - ID_CLASS_EDIT]->SetWindowText(CCANCenter::Instance()->StationList->at(nID)->m_nX);
	
	return 0;
}


void CDialogBasic::BuildCollection(void)
{
	m_edit_set[ID_CLASS_EDIT_X - ID_CLASS_EDIT] = &m_edit_x;
	m_edit_set[ID_CLASS_EDIT_Y - ID_CLASS_EDIT] = &m_edit_y;
	m_edit_set[ID_CLASS_EDIT_Z - ID_CLASS_EDIT] = &m_edit_z;

	m_edit_set[ID_CLASS_EDIT_EX - ID_CLASS_EDIT] = &m_edit_to_x;
	m_edit_set[ID_CLASS_EDIT_EY - ID_CLASS_EDIT] = &m_edit_to_y;
	m_edit_set[ID_CLASS_EDIT_EZ - ID_CLASS_EDIT] = &m_edit_to_z;

	m_edit_set[ID_CLASS_EDIT_VX - ID_CLASS_EDIT] = &m_edit_Vx;
	m_edit_set[ID_CLASS_EDIT_VY - ID_CLASS_EDIT] = &m_edit_Vy;
	m_edit_set[ID_CLASS_EDIT_VZ - ID_CLASS_EDIT] = &m_edit_Vz;
}
