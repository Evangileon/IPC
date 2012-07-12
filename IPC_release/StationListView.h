#pragma once

#include "StationView.h"
#include "MConfig.h"

// CStationListView

class CStationListView : public CDockablePane
{
	DECLARE_DYNAMIC(CStationListView)

public:
	CStationListView();
	virtual ~CStationListView();

	//void AdjustLayout();
	void OnChangeVisualStyle();

protected:
	CStationView m_wndStationView;
	int m_nSelStation;
	int m_nDialogShowed;

protected:
	void FillStationView(int);

	DECLARE_MESSAGE_MAP()
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnPaint();
public:
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnHello();


	afx_msg void OnPopupItemCheck();
};


