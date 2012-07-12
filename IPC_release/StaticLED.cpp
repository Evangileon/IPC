// StaticLED.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_release.h"
#include "StaticLED.h"


// CStaticLED

IMPLEMENT_DYNAMIC(CStaticLED, CStatic)

CStaticLED::CStaticLED()
{
	m_nID = 0;
	m_nColor = ID_COLOR_GRAY;
	m_bBright = FALSE;
	m_nTimerInterval = 500;
	//CBitmap bitmap;
	//bitmap.LoadBitmap(IDB_BITMAP_LINE); 
	//BITMAP_RED = 
	hRed = LoadBitmap(::AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP_RED));
	hGreen = LoadBitmap(::AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP_GREEN));
	hYellow = LoadBitmap(::AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP_YELLOW));
	hBlue = LoadBitmap(::AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP_BLUE));
	hGray = LoadBitmap(::AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP_GRAY));
}

CStaticLED::~CStaticLED()
{
}


BEGIN_MESSAGE_MAP(CStaticLED, CStatic)
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CStaticLED 消息处理程序




void CStaticLED::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(m_nTimerInterval==0)
		return;
	if(m_bShrink == FALSE)
		return;

	if(m_bBright = TRUE)
	{
		SetLED(ID_COLOR_GRAY, TRUE);
		m_bBright = FALSE;
	}
	else
	{
		SetLED(m_nColor, TRUE);
		m_bBright = TRUE;
	}

	CStatic::OnTimer(nIDEvent);
}


void CStaticLED::SetLED(int nColor, BOOL bShrink)
{
	
	if(nColor == ID_COLOR_GRAY)
	{
		m_bBright = FALSE;
		m_bShrink = FALSE;
		///HBITMAP h = CBitmapGray.Instance()->
		//HBITMAP h= ::LoadBitmap(::AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP1));//IDB_BITMAP1是Bitmap资源
		SetBitmap(hGray);
		return;
	}

	m_nColor = nColor;
	m_bShrink = bShrink;
	switch(m_nColor)
	{
	case ID_COLOR_RED:
		SetBitmap(hRed);
		break;
	case ID_COLOR_GREEN:
		SetBitmap(hGreen);
		break;
	case ID_COLOR_BLUE:
		SetBitmap(hBlue);
		break;
	case ID_COLOR_YELLOW:
		SetBitmap(hYellow);
		break;
	default:
		break;
	}

	//CStatic::dr
}


void CStaticLED::SetShrink(BOOL bShrink)
{
	this->m_bShrink = bShrink;
}
