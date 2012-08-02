#pragma once


// CDialogDBSetting 对话框

class CDialogDBSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogDBSetting)

public:
	CDialogDBSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogDBSetting();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADOSETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit_SQLServer_PWD;
	CEdit m_edit_SQLServer_Usr;
	CEdit m_edit_SQLServer_Name;
	CIPAddressCtrl m_IP_SQLServer;
	afx_msg void OnBnClickedRadioSettingNative();
	afx_msg void OnBnClickedRadioSettingServer();

	BOOL m_bNativeDB;
	BOOL m_bServerDB;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	void EnableServerControls(BOOL m_bEnable);
};
