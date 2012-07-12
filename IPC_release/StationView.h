#pragma once


//#include "IPC_releaseView.h"
// CStationView

class CStationView : public CListCtrl
{
	DECLARE_DYNAMIC(CStationView)

public:
	CStationView();
	virtual ~CStationView();

protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnSize(UINT nType, int cx, int cy);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLvnItemchanged(NMHDR *pNMHDR, LRESULT *pResult);
};



