#pragma once


// CLED
#define CIRCLE 0
#define SQUARE 1
#define ELLIPSE 2

#define ID_LED_RED		2001 
#define ID_LED_GREEN	2002 
#define ID_LED_BLUE		2003 
#define ID_LED_YELLOW	2004 
 
// The constants needed to define the shape of the LED 
#define ID_SHAPE_ROUND	3001 
#define ID_SHAPE_SQUARE	3002

class CLED : public CStatic
{
	DECLARE_DYNAMIC(CLED)

public:
	CLED();
	virtual ~CLED();

protected:
	//UINT m_nID; 
	UINT m_nColor;
	UINT m_nShape; 
	BOOL m_bBright; 
	CWnd *m_pWnd; 
	int m_nTimerInterval,m_nPrevTimerInterval;
	CPen m_PenBright,m_PenDark;
	CBrush m_BrushBright,m_BrushDark,m_BrushCurrent;

public:
	void SwitchOn(); 
	void SwitchOff(); 
	//void SetLED(CWnd *pWnd,UINT nIDColor); 

private:
	//void ResetLED(UINT nIDColor, UINT nIDShape, int nTimerInterval); 

protected:
	DECLARE_MESSAGE_MAP()
public:
	void SetLED(CWnd* pWnd, UINT nIDColor, UINT nIDShape);
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


