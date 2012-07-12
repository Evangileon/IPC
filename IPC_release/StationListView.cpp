// StationListView.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_release.h"
#include "StationListView.h"
#include "MainFrm.h"
#include "IPC_releaseView.h"


// CStationListView

IMPLEMENT_DYNAMIC(CStationListView, CDockablePane)

CStationListView::CStationListView()
{
	m_nSelStation = 1;
}

CStationListView::~CStationListView()
{
}


BEGIN_MESSAGE_MAP(CStationListView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
//	ON_WM_LBUTTONDOWN()
ON_COMMAND(ID_POPUP_ITEM_CHECK, &CStationListView::OnPopupItemCheck)
END_MESSAGE_MAP()



// CStationListView 消息处理程序



void CStationListView::FillStationView(int nStation)
{
	m_wndStationView.InsertColumn(0,_T("工位"),LVCFMT_LEFT,50); //插入列
	m_wndStationView.InsertColumn(1,_T("状态"),LVCFMT_LEFT,50); //
	
	for(int i=0; i < nStation; i++)
	{
		m_wndStationView.InsertItem(i, _T(""));
		//m_wndStationView.InsertItem(1, _T("Build"));
		CString str;
		str.Format(_T("%d"), i+1);
		m_wndStationView.SetItemText(i, 0, str);
		m_wndStationView.SetItemText(i, 1, _T("离线"));
	}
}

int CStationListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// 创建视图:
	const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS;

	if (!m_wndStationView.Create(dwViewStyle, rectDummy, this, 5))
	{
		TRACE0("未能创建文件视图\n");
		return -1;      // 未能创建
	}

	LONG lStyle;
    lStyle = GetWindowLong(m_wndStationView.m_hWnd, GWL_STYLE);//获取当前窗口style
    lStyle &= ~LVS_TYPEMASK; //清除显示方式位
    lStyle |= LVS_REPORT; //设置style
    SetWindowLong(m_wndStationView.m_hWnd, GWL_STYLE, lStyle);//设置style

	// 加载视图图像:
	//m_FileViewImages.Create(IDB_FILE_VIEW, 16, 0, RGB(255, 0, 255));
	//m_wndFileView.SetImageList(&m_FileViewImages, TVSIL_NORMAL);

	//OnChangeVisualStyle();


	// 所有命令将通过此控件路由，而不是通过主框架路由:
	//m_wndToolBar.SetRouteCommandsViaFrame(FALSE);

	// 填入一些静态树视图数据(此处只需填入虚拟代码，而不是复杂的数据)
	m_wndStationView.SetExtendedStyle(LVS_EX_FLATSB
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	

	FillStationView(CMConfig::Instance()->StationNBR);
	//AdjustLayout();


	return 0;
}


void CStationListView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (GetSafeHwnd() == NULL)
	{
		return;
	}
	
	CRect rectClient;
	GetClientRect(rectClient);
	m_wndStationView.SetWindowPos(NULL, rectClient.left + 1, rectClient.top + 1, rectClient.Width() - 2, rectClient.Height() - 2, SWP_NOACTIVATE | SWP_NOZORDER);
}


void CStationListView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此处添加消息处理程序代码

	CListCtrl* pWndList = (CListCtrl*) &m_wndStationView;
	ASSERT_VALID(pWndList);

	if (pWnd != pWndList)
	{
		//CDockablePane::OnContextMenu(pWnd, point);
		return;
	}

	if (point != CPoint(-1, -1))
	{
		// 选择已单击的项:
		CPoint ptList = point;
		ScreenToClient(&ptList);

		UINT flags = 0;
		int hListItem = pWndList->HitTest(ptList, &flags);
		if (hListItem != -1)
		{
			pWndList->SetSelectionMark(hListItem);
			this->m_nSelStation = hListItem + 1;

			pWndList->SetFocus();
			CMenu menu;
			menu.LoadMenu(IDR_POPUP_STATION); //读取资源
			menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON, point.x, point.y,this);
		}
	}

}


void CStationListView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDockablePane::OnPaint()
	CRect rectList;
	m_wndStationView.GetWindowRect(rectList);
	ScreenToClient(rectList);

	rectList.InflateRect(1, 1);
	dc.Draw3dRect(rectList, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));
}


void CStationListView::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);

	// TODO: 在此处添加消息处理程序代码
	m_wndStationView.SetFocus();
}


void CStationListView::OnHello()
{
	// TODO: 在此添加命令处理程序代码
}


//void CStationListView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CStationView* pWndList = (CStationView*) &m_wndStationView;
//	ASSERT_VALID(pWndList);
//	//AfxMessageBox(_T("test"));
//
//	if (point != CPoint(-1, -1))
//	{
//		// 选择已单击的项:
//		CPoint ptList = point;
//		ScreenToClient(&ptList);
//
//		UINT flags = 0;
//		int hListItem = pWndList->HitTest(ptList, &flags);
//		if (hListItem != -1)
//		{
//			int re = pWndList->SetSelectionMark(hListItem);
//
//			pWndList->SetFocus();
//			LVCOLUMN column;
//			pWndList->GetColumn(hListItem, &column);
//			CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
//			CIPC_releaseView *pView=(CIPC_releaseView *)pMain->GetActiveView();
//			pView->m_wndDialog.PostMessage(NM_SWITCHDLG, 1, 0);
//			AfxMessageBox(_T("test"));
//		}
//	}
//
//	CDockablePane::OnLButtonDown(nFlags, point);
//}


void CStationListView::OnPopupItemCheck()
{
	// TODO: 在此添加命令处理程序代码

	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	CIPC_releaseView *pView=(CIPC_releaseView *)pMain->GetActiveView();
	pView->m_wndDialog.PostMessage(NM_SWITCHDLG, 1, 0);	//待优化，如果已经可见则不再重画
}
