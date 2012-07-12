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

// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "OutputWnd.h"
#include "StationListView.h"
#include "IPC_releaseView.h"
#include "resource.h"

//所有Ribbon控件消息响应函数映射到CMainFrame中
class CMainFrame : public CFrameWndEx
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
//public:

// 操作
//public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CMFCRibbonBar     m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;
	CMFCToolBarImages m_PanelImages;
	CMFCRibbonStatusBar  m_wndStatusBar;
	COutputWnd        m_wndOutput;
	CStationListView  m_wndStationView;

	//CIPC_releaseView *m_pIPC_ClassView;

//  交互
	//CTabCtrl *m_tab;
	

	BOOL CreateTabWindow();

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	DECLARE_MESSAGE_MAP()

	BOOL CreateDockingWindows();
	void SetDockingWindowIcons(BOOL bHiColorIcons);
public:
//	void OnClickTest(void);
//	afx_msg void OnButton2();
	virtual void DoDataExchange(CDataExchange* pDX);
	afx_msg void OnButtonGlobal();
//	afx_msg void OnButtonOpencan();
	afx_msg void OnButtonOpencan();
	afx_msg void OnButtonDataCheck();
	afx_msg void OnUpdateCheckRecvStandard(CCmdUI *pCmdUI);
	afx_msg void OnCheckRecvStandard();
	afx_msg void OnCheckRecvRemote();
	afx_msg void OnUpdateCheckRecvRemote(CCmdUI *pCmdUI);
	afx_msg void OnCheckSendStandard();
	afx_msg void OnUpdateCheckSendStandard(CCmdUI *pCmdUI);
	afx_msg void OnCheckSendRemote();
	afx_msg void OnUpdateCheckSendRemote(CCmdUI *pCmdUI);
	afx_msg void OnButtonSaveconfig();
};


