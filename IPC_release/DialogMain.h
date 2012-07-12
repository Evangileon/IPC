#pragma once

#include "stdafx.h"
#include "resource.h"
#include "DialogBasic.h"
#include "DialogPipeline.h"
#include "CANCenter.h"
#include "DialogData.h"
// CDialogMain 对话框

class CDialogMain : public CDialog
{
	DECLARE_DYNAMIC(CDialogMain)

public:
	CDialogMain(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogMain();

// 对话框数据
	enum { IDD = IDD_DIALOG_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	CDialogPipeline m_dialogPipeline;//生产线视图
	CDialogBasic m_dialogBasic;//单工位视图
	CDialogData m_dialogData;//数据库视图
	CDialog *pDialog[3];
	int m_CurSelTab;
	int m_iMinWidth;
	int m_iMinHeight;
	int m_iClientWidth;
	int m_iClientHeight;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	BOOL CreateTab(void);
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	afx_msg LRESULT OnNmSwitchdlg(WPARAM wParam, LPARAM lParam);//切换视图相应函数
public:
//	afx_msg void OnButtonGlobal();
};
