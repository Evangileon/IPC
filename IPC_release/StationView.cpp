// StationView.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_release.h"
#include "StationView.h"


// CStationView

IMPLEMENT_DYNAMIC(CStationView, CListCtrl)

CStationView::CStationView()
{

}

CStationView::~CStationView()
{
}


BEGIN_MESSAGE_MAP(CStationView, CListCtrl)
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, &CStationView::OnLvnItemchanged)
END_MESSAGE_MAP()



// CStationView 消息处理程序


BOOL CStationView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	BOOL bRes = CListCtrl::OnNotify(wParam, lParam, pResult);

	NMHDR* pNMHDR = (NMHDR*)lParam;
	ASSERT(pNMHDR != NULL);

	if (pNMHDR && pNMHDR->code == TTN_SHOW && GetToolTips() != NULL)
	{
		GetToolTips()->SetWindowPos(&wndTop, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOSIZE);
	}

	return bRes;
}

//void CStationView::OnSize(UINT nType, int cx, int cy)
//{
//	CListCtrl::OnSize(nType, cx, cy);
//
//	// TODO: 在此处添加消息处理程序代码
//
//}


//void CStationView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	//AfxMessageBox(_T("test2"));
//	//CListCtrl* pWndList = this;
//	//ASSERT_VALID(pWndList);
//
//	/*if (point != CPoint(-1, -1))
//	{
//		// 选择已单击的项:
//		CPoint ptList = point;
//		ScreenToClient(&ptList);
//
//		UINT flags = 0;
//		int hListItem = this->HitTest(ptList, &flags);
//		if (hListItem != -1)
//		{
//			int re = this->SetSelectionMark(hListItem);
//
//			this->SetFocus();
//			theApp.SelStation = hListItem + 1;
//			CString str;
//			//str.Format(_T("NO = %d"), hListItem);
//			//AfxMessageBox(str);
//
//			SendDlgItemMessage(IDC_TAB_MAIN, TCN_SELCHANGE, 0, 0);
//		}
//	}*/
//
//	CListCtrl::OnLButtonDown(nFlags, point);
//}


void CStationView::OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if(pNMLV->iItem <0)
		return;	
	if(pNMLV->uChanged==LVIF_STATE) 
	{
		if(pNMLV->uNewState) 
		{
			int hListItem = pNMLV->iItem;
			if (hListItem != -1)
			{
				theApp.SelStation = hListItem + 1;
				CString str;
				str.Format(_T("NO = %d"), hListItem);
				theApp.Log(str);
				CView *pView=(this->GetParentFrame()->GetActiveView());
				//pView->m_wndDialog.PostMessage(NM_SWITCHDLG, 0, 0);
				pView->PostMessage(NM_SWITCHDLG, 1, 0);
				
			}
		}
	}

	*pResult = 0;
}
