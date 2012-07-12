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

// IPC_releaseView.cpp : CIPC_releaseView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "IPC_release.h"
#endif

#include "IPC_releaseDoc.h"
#include "IPC_releaseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIPC_releaseView

IMPLEMENT_DYNCREATE(CIPC_releaseView, CFormView)

BEGIN_MESSAGE_MAP(CIPC_releaseView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_VIEW_STATIONLIST, &CIPC_releaseView::OnViewStationlist)
	ON_MESSAGE(NM_SWITCHDLG, &CIPC_releaseView::OnNmSwitchdlg)
END_MESSAGE_MAP()

// CIPC_releaseView 构造/析构

CIPC_releaseView::CIPC_releaseView()
	: CFormView(CIPC_releaseView::IDD)
{
	// TODO: 在此处添加构造代码
	//m_pFrame = NULL; 
}

CIPC_releaseView::~CIPC_releaseView()
{
}

void CIPC_releaseView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CIPC_releaseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CIPC_releaseView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

}

void CIPC_releaseView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CIPC_releaseView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CIPC_releaseView 诊断

#ifdef _DEBUG
void CIPC_releaseView::AssertValid() const
{
	CFormView::AssertValid();
}

void CIPC_releaseView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CIPC_releaseDoc* CIPC_releaseView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIPC_releaseDoc)));
	return (CIPC_releaseDoc*)m_pDocument;
}
#endif //_DEBUG


// CIPC_releaseView 消息处理程序




//BOOL CIPC_releaseView::CreateTab(void)
//{
//	
//
//	return TRUE;
//}


int CIPC_releaseView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	CRect rect;
	GetClientRect(rect);
	
	m_wndDialog.Create(IDD_DIALOG_MAIN,this);
	CRect tmpRect;
	m_wndDialog.GetWindowRect(tmpRect);
	this->m_iMinHeight = tmpRect.Height();
	this->m_iMinWidth = tmpRect.Width();
	//m_wndDialog.MoveWindow(rect);
	m_wndDialog.ShowWindow(SW_SHOW);
	
	return 0;
}





void CIPC_releaseView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	CRect rect;
	GetClientRect(&rect);
	if(rect.Height() < this->m_iMinHeight)
		rect.bottom = rect.top + this->m_iMinHeight;
	if(rect.Width() < this->m_iMinWidth)
		rect.right = rect.left + this->m_iMinWidth;
	//m_wndDialog.MoveWindow(&rect);
	m_wndDialog.SetWindowPos (NULL, -1, -1, cx, cy, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
}


//void CIPC_releaseView::OnButton_Single()
//{
//	// TODO: 在此添加命令处理程序代码
//
//}


//void CIPC_releaseView::OnButton_AC()
//{
//	// TODO: 在此添加命令处理程序代码
//
//}


void CIPC_releaseView::OnViewStationlist()
{
	// TODO: 在此添加命令处理程序代码
	//AfxMessageBox(_T("asdfsdf"));
}


//afx_msg LRESULT CIPC_releaseView::OnMmListselect(WPARAM wParam, LPARAM lParam)
//{
//	pDialog[1]->ShowWindow(SW_HIDE);
//	m_wndTab.SetCurSel(1);
//	pDialog[0]->ShowWindow(SW_SHOW);
//	return 0;
//}


afx_msg LRESULT CIPC_releaseView::OnNmSwitchdlg(WPARAM wParam, LPARAM lParam)
{
	m_wndDialog.PostMessage(NM_SWITCHDLG, wParam, lParam);
	
	return 0;
}
