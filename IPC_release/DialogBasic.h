#pragma once


#include "NotifyClass.h"

// CDialogBasic 对话框

class CDialogBasic : public CDialog
{
	DECLARE_DYNAMIC(CDialogBasic)

public:
	CDialogBasic(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogBasic();

// 对话框数据
	enum { IDD = IDD_DIALOG_BASIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit_Vy;  //直接联系到控件
	CEdit m_edit_Vz;
	CEdit m_edit_z;
	CEdit m_edit_to_x;
	CEdit m_edit_to_y;
	CEdit m_edit_to_z;
	CEdit m_edit_Vx;
	CEdit m_edit_x;
	CEdit m_edit_y;

	CEdit *m_edit_set[9];

	/*CString m_Vy;
	CString m_Vz;
	CString m_z;
	CString m_to_x;
	CString m_to_y;
	CString m_to_z;
	CString m_Vx;
	CString m_x;
	CString m_y;*/
	

protected:
	afx_msg LRESULT OnNmNotifyctrl(WPARAM wParam, LPARAM lParam);//自定义消息响应函数，用于通知相应控件，如X轴坐标数值改变 
private:
	void BuildCollection(void);
};
