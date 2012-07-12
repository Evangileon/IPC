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

// IPC_releaseView.h : CIPC_releaseView 类的接口
//

#pragma once

#include "resource.h"

#include "MainFrm.h"
#include "DialogMain.h"
#include "IPC_releaseDoc.h"
#include <vector>

class CIPC_releaseView : public CFormView
{
protected: // 仅从序列化创建
	CIPC_releaseView();
	DECLARE_DYNCREATE(CIPC_releaseView)

public:
	enum{ IDD = IDD_IPC_RELEASE_FORM };

// 特性
public:
	CIPC_releaseDoc* GetDocument() const;

// 操作


// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CIPC_releaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CDialogMain m_wndDialog;
	int m_iMinWidth;
	int m_iMinHeight;

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	afx_msg void OnSize(UINT nType, int cx, int cy);

	afx_msg void OnViewStationlist();
protected:
	afx_msg LRESULT OnNmSwitchdlg(WPARAM wParam, LPARAM lParam);
};

#ifndef _DEBUG  // IPC_releaseView.cpp 中的调试版本
inline CIPC_releaseDoc* CIPC_releaseView::GetDocument() const
   { return reinterpret_cast<CIPC_releaseDoc*>(m_pDocument); }
#endif

