// DialogDBSetting.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_release.h"
#include "DialogDBSetting.h"
#include "afxdialogex.h"
#include "MConfig.h"


// CDialogDBSetting 对话框

IMPLEMENT_DYNAMIC(CDialogDBSetting, CDialogEx)

CDialogDBSetting::CDialogDBSetting(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogDBSetting::IDD, pParent)
{
	this->m_bNativeDB = TRUE;
	this->m_bServerDB = FALSE;
}

CDialogDBSetting::~CDialogDBSetting()
{
}

void CDialogDBSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SQLSERVER_PWD, m_edit_SQLServer_PWD);
	DDX_Control(pDX, IDC_EDIT_SQLSERVER_USR, m_edit_SQLServer_Usr);
	DDX_Control(pDX, IDC_EDIT_SQLSERVER_NAME, m_edit_SQLServer_Name);
	DDX_Control(pDX, IDC_IPADDRESS_SERVER, m_IP_SQLServer);
	DDX_Check(pDX, IDC_RADIO_SETTING_NATIVE, m_bNativeDB);
	DDX_Check(pDX, IDC_RADIO_SETTING_SERVER, m_bServerDB);
}


BEGIN_MESSAGE_MAP(CDialogDBSetting, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_SETTING_NATIVE, &CDialogDBSetting::OnBnClickedRadioSettingNative)
	ON_BN_CLICKED(IDC_RADIO_SETTING_SERVER, &CDialogDBSetting::OnBnClickedRadioSettingServer)
	ON_BN_CLICKED(IDOK, &CDialogDBSetting::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialogDBSetting 消息处理程序


void CDialogDBSetting::OnBnClickedRadioSettingNative()
{
	// TODO: 
	//this->GetDlgItem(IDC_RADIO_SETTING_NATIVE)
	EnableServerControls(FALSE);
}


void CDialogDBSetting::OnBnClickedRadioSettingServer()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	EnableServerControls(TRUE);
}


BOOL CDialogDBSetting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ÔÚ´ËÌí¼Ó¶îÍâµÄ³õÊ¼»¯
	this->m_bNativeDB = CMConfig::Instance()->m_bNativeDB;
	this->m_bServerDB = !CMConfig::Instance()->m_bNativeDB;
	
	if(m_bNativeDB = TRUE)
	{
		EnableServerControls(FALSE);
	}
	else
	{
		EnableServerControls(TRUE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// Òì³£: OCX ÊôÐÔÒ³Ó¦·µ»Ø FALSE
}


void CDialogDBSetting::OnBnClickedOk()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData();
	CMConfig::Instance()->m_bNativeDB = this->m_bNativeDB;
	CMConfig::Instance()->m_bServerDB = this->m_bServerDB;
	this->m_edit_SQLServer_Name.GetWindowText(CMConfig::Instance()->m_szSQLServer_Name);
	this->m_IP_SQLServer.GetWindowText(CMConfig::Instance()->m_szSQLServer_IP);
	this->m_edit_SQLServer_Usr.GetWindowText(CMConfig::Instance()->m_szSQLServer_Usr);
	this->m_edit_SQLServer_PWD.GetWindowText(CMConfig::Instance()->m_szSQLServer_Pwd);
	CDialogEx::OnOK();
}


void CDialogDBSetting::EnableServerControls(BOOL m_bEnable)
{
	m_edit_SQLServer_PWD.EnableWindow(m_bEnable);
	m_edit_SQLServer_Usr.EnableWindow(m_bEnable);
	m_edit_SQLServer_Name.EnableWindow(m_bEnable);
	m_IP_SQLServer.EnableWindow(m_bEnable);
}
