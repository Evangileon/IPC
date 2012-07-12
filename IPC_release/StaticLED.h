#pragma once

#include "stdafx.h"

#define ID_COLOR_RED 1
#define ID_COLOR_GREEN 2
#define ID_COLOR_BLUE 3
#define ID_COLOR_YELLOW 4
#define ID_COLOR_GRAY 5
// CStaticLED

//状态灯，支持闪烁功能即调用SetShrink
class CStaticLED : public CStatic
{
	DECLARE_DYNAMIC(CStaticLED)

public:
	CStaticLED();
	virtual ~CStaticLED();

protected:
	DECLARE_MESSAGE_MAP()
public:
//	int m_nID;
protected:
	int m_nID;
	int m_nColor;
	int m_nTimerInterval,m_nPrevTimerInterval;
	BOOL m_bBright;
	BOOL m_bShrink;
	HBITMAP hRed;
	HBITMAP hGreen;
	HBITMAP hBlue;
	HBITMAP hYellow;
	HBITMAP hGray;

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void SetLED(int nColor, BOOL bShrink = FALSE);
	void SetShrink(BOOL bShrink);
};


