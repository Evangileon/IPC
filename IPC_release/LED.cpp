// LED.cpp : 实现文件
//

#include "stdafx.h"
#include "IPC_release.h"
#include "LED.h"


// CLED

IMPLEMENT_DYNAMIC(CLED, CStatic)

CLED::CLED()
{
	m_bBright = TRUE;  
	m_nShape = ID_SHAPE_ROUND;
    m_nTimerInterval = 500;   
    //m_nPrevTimerInterval = 0;   
}

CLED::~CLED()
{
}


BEGIN_MESSAGE_MAP(CLED, CStatic)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CLED 消息处理程序




void CLED::SetLED(CWnd* pWnd, UINT nIDColor, UINT nIDShape)
{
	
	this->m_hWnd = pWnd->m_hWnd;
	m_nColor = nIDColor;   
	m_nShape = nIDShape;

	//AfxMessageBox(

	// Get the Device Context
	CClientDC dc(this);
	
	// Get the rectangle of the window where we are going to draw
	CRect rcClient;
	GetClientRect(&rcClient);

	// If the pen has been selected already, then we have to delete it
	// so that it doesnt throw an assertion

	if(m_PenBright.m_hObject!=NULL)
		m_PenBright.DeleteObject();

	if(m_BrushBright.m_hObject!=NULL)
		m_BrushBright.DeleteObject();

	if(m_PenDark.m_hObject!=NULL)
		m_PenDark.DeleteObject();

	if(m_BrushDark.m_hObject!=NULL)
		m_BrushDark.DeleteObject();	

	// If the user has selected RED as the color of the LED
	if(m_nColor==ID_LED_RED)
	{
		// I'm creating a light shade of red here for displaying the bright
		// LED. You can change the values to any colour that you want
		m_PenBright.CreatePen(0,1,RGB(250,0,0));
		m_BrushBright.CreateSolidBrush(RGB(250,0,0));

		// Here i'm creating a dark shade of red. You can play with the values to
		// see the effect on the LED control

		m_PenDark.CreatePen(0,1,RGB(150,0,0));
		m_BrushDark.CreateSolidBrush(RGB(150,0,0));
	}
	else if(m_nColor==ID_LED_GREEN)
	{
		// If the user has selected GREEN as the color of the LED

		m_PenBright.CreatePen(0,1,RGB(0,250,0));
		m_BrushBright.CreateSolidBrush(RGB(0,250,0));

		m_PenDark.CreatePen(0,1,RGB(0,150,0));
		m_BrushDark.CreateSolidBrush(RGB(0,150,0));
	}
	else if(m_nColor==ID_LED_BLUE)
	{
		// If the user has selected BLUE as the color of the LED

		m_PenBright.CreatePen(0,1,RGB(0,0,250));
		m_BrushBright.CreateSolidBrush(RGB(0,0,250));

		m_PenDark.CreatePen(0,1,RGB(0,0,150));
		m_BrushDark.CreateSolidBrush(RGB(0,0,150));
	}
	else if(m_nColor==ID_LED_YELLOW)
	{
		// If the user has selected YELLOW as the color of the LED

		m_PenBright.CreatePen(0,1,RGB(200,200 ,0));
		m_BrushBright.CreateSolidBrush(RGB(200,200,0));

		m_PenDark.CreatePen(0,1,RGB(150,150,0));
		m_BrushDark.CreateSolidBrush(RGB(150,150,0));
	}


	if(m_bBright==TRUE)
	{
		// If we have to switch on the LED to display the bright colour select
		// the bright pen and brush that we have created above

		dc.SelectObject(&m_PenBright);
		dc.SelectObject(&m_BrushBright);

		m_BrushCurrent.m_hObject = m_BrushBright.m_hObject;

		//m_bBright = FALSE;
	}
	else
	{
		// If we have to switch off the LED to display the dark colour select
		// the bright pen and brush that we have created above

		dc.SelectObject(&m_PenDark);
		dc.SelectObject(&m_BrushDark);

		m_BrushCurrent.m_hObject = m_BrushDark.m_hObject;

		//m_bBright = TRUE;
	}

	// If the round shape has been selected for the control 
	if(m_nShape==ID_SHAPE_ROUND)
	{
		// Draw the actual colour of the LED
		//dc.Ellipse(rcClient);

		// Draw a thick dark gray coloured circle
		CPen Pen;
		Pen.CreatePen(0,2,RGB(128,128,128));
		dc.SelectObject(&Pen);
		
		dc.Ellipse(rcClient);

		// Draw a thin light gray coloured circle
		Pen.DeleteObject();
		Pen.CreatePen(0,1,RGB(192,192,192));
		dc.SelectObject(&Pen);
		dc.Ellipse(rcClient);

		// Draw a white arc at the bottom
		Pen.DeleteObject();
		Pen.CreatePen(0,1,RGB(255,255,255));
		dc.SelectObject(&Pen);

		// The arc function is just to add a 3D effect for the control
		CPoint ptStart,ptEnd;
		ptStart = CPoint(rcClient.Width()/2,rcClient.bottom);
		ptEnd	= CPoint(rcClient.right,rcClient.top);

		dc.MoveTo(ptStart);
		dc.Arc(rcClient,ptStart,ptEnd);

		CBrush Brush;
		Brush.CreateSolidBrush(RGB(255,255,255));
		dc.SelectObject(&Brush);

		// Draw the actual ellipse
		//AfxMessageBox(_T("在执行"));
		if(dc.Ellipse(rcClient.left+4,rcClient.top+4,rcClient.left+6,rcClient.top+6) == TRUE)
		{

			//AfxMessageBox(_T("执行成功"));
		}
	}
	else if(m_nShape==ID_SHAPE_SQUARE)
	{
		// If you have decided that your LED is going to look square in shape, then

		// Draw the actual rectangle
		dc.FillRect(rcClient,&m_BrushCurrent);

		// The  code below gives a 3D look to the control. It does nothing more

		// Draw the dark gray lines
		CPen Pen;
		Pen.CreatePen(0,1,RGB(128,128,128));
		dc.SelectObject(&Pen);

		dc.MoveTo(rcClient.left,rcClient.bottom);
		dc.LineTo(rcClient.left,rcClient.top);
		dc.LineTo(rcClient.right,rcClient.top);
		
		Pen.DeleteObject();

		// Draw the light gray lines
		Pen.CreatePen(0,1,RGB(192,192,192));
		dc.SelectObject(&Pen);

		dc.MoveTo(rcClient.right,rcClient.top);
		dc.LineTo(rcClient.right,rcClient.bottom);
		dc.LineTo(rcClient.left,rcClient.bottom);	
	}
}


void CLED::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CStatic::OnPaint()
}


void CLED::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(m_nTimerInterval==0)
		return;

	// Get the Device Context
	CClientDC dc(this);
	
	// Get the rectangle of the window where we are going to draw
	CRect rcClient;
	GetClientRect(&rcClient);

	// If the pen has been selected already, then we have to delete it
	// so that it doesnt throw an assertion

	if(m_PenBright.m_hObject!=NULL)
		m_PenBright.DeleteObject();

	if(m_BrushBright.m_hObject!=NULL)
		m_BrushBright.DeleteObject();

	if(m_PenDark.m_hObject!=NULL)
		m_PenDark.DeleteObject();

	if(m_BrushDark.m_hObject!=NULL)
		m_BrushDark.DeleteObject();	

	// If the user has selected RED as the color of the LED
	if(m_nColor==ID_LED_RED)
	{
		// I'm creating a light shade of red here for displaying the bright
		// LED. You can change the values to any colour that you want
		m_PenBright.CreatePen(0,1,RGB(250,0,0));
		m_BrushBright.CreateSolidBrush(RGB(250,0,0));

		// Here i'm creating a dark shade of red. You can play with the values to
		// see the effect on the LED control

		m_PenDark.CreatePen(0,1,RGB(150,0,0));
		m_BrushDark.CreateSolidBrush(RGB(150,0,0));
	}
	else if(m_nColor==ID_LED_GREEN)
	{
		// If the user has selected GREEN as the color of the LED

		m_PenBright.CreatePen(0,1,RGB(0,250,0));
		m_BrushBright.CreateSolidBrush(RGB(0,250,0));

		m_PenDark.CreatePen(0,1,RGB(0,150,0));
		m_BrushDark.CreateSolidBrush(RGB(0,150,0));
	}
	else if(m_nColor==ID_LED_BLUE)
	{
		// If the user has selected BLUE as the color of the LED

		m_PenBright.CreatePen(0,1,RGB(0,0,250));
		m_BrushBright.CreateSolidBrush(RGB(0,0,250));

		m_PenDark.CreatePen(0,1,RGB(0,0,150));
		m_BrushDark.CreateSolidBrush(RGB(0,0,150));
	}
	else if(m_nColor==ID_LED_YELLOW)
	{
		// If the user has selected YELLOW as the color of the LED

		m_PenBright.CreatePen(0,1,RGB(200,200 ,0));
		m_BrushBright.CreateSolidBrush(RGB(200,200,0));

		m_PenDark.CreatePen(0,1,RGB(150,150,0));
		m_BrushDark.CreateSolidBrush(RGB(150,150,0));
	}


	if(m_bBright==TRUE)
	{
		// If we have to switch on the LED to display the bright colour select
		// the bright pen and brush that we have created above

		dc.SelectObject(&m_PenBright);
		dc.SelectObject(&m_BrushBright);

		m_BrushCurrent.m_hObject = m_BrushBright.m_hObject;

		m_bBright = FALSE;
	}
	else
	{
		// If we have to switch off the LED to display the dark colour select
		// the bright pen and brush that we have created above

		dc.SelectObject(&m_PenDark);
		dc.SelectObject(&m_BrushDark);

		m_BrushCurrent.m_hObject = m_BrushDark.m_hObject;

		m_bBright = TRUE;
	}

	// If the round shape has been selected for the control 
	if(m_nShape==ID_SHAPE_ROUND)
	{
		// Draw the actual colour of the LED
		dc.Ellipse(rcClient);

		// Draw a thick dark gray coloured circle
		CPen Pen;
		Pen.CreatePen(0,2,RGB(128,128,128));
		dc.SelectObject(&Pen);
		
		dc.Ellipse(rcClient);

		// Draw a thin light gray coloured circle
		Pen.DeleteObject();
		Pen.CreatePen(0,1,RGB(192,192,192));
		dc.SelectObject(&Pen);
		dc.Ellipse(rcClient);

		// Draw a white arc at the bottom
		Pen.DeleteObject();
		Pen.CreatePen(0,1,RGB(255,255,255));
		dc.SelectObject(&Pen);

		// The arc function is just to add a 3D effect for the control
		CPoint ptStart,ptEnd;
		ptStart = CPoint(rcClient.Width()/2,rcClient.bottom);
		ptEnd	= CPoint(rcClient.right,rcClient.top);

		dc.MoveTo(ptStart);
		dc.Arc(rcClient,ptStart,ptEnd);

		CBrush Brush;
		Brush.CreateSolidBrush(RGB(255,255,255));
		dc.SelectObject(&Brush);

		// Draw the actual ellipse
		dc.Ellipse(rcClient.left+4,rcClient.top+4,rcClient.left+6,rcClient.top+6);
	}
	else if(m_nShape==ID_SHAPE_SQUARE)
	{
		// If you have decided that your LED is going to look square in shape, then

		// Draw the actual rectangle
		dc.FillRect(rcClient,&m_BrushCurrent);

		// The  code below gives a 3D look to the control. It does nothing more

		// Draw the dark gray lines
		CPen Pen;
		Pen.CreatePen(0,1,RGB(128,128,128));
		dc.SelectObject(&Pen);

		dc.MoveTo(rcClient.left,rcClient.bottom);
		dc.LineTo(rcClient.left,rcClient.top);
		dc.LineTo(rcClient.right,rcClient.top);
		
		Pen.DeleteObject();

		// Draw the light gray lines
		Pen.CreatePen(0,1,RGB(192,192,192));
		dc.SelectObject(&Pen);

		dc.MoveTo(rcClient.right,rcClient.top);
		dc.LineTo(rcClient.right,rcClient.bottom);
		dc.LineTo(rcClient.left,rcClient.bottom);	
	}

	CStatic::OnTimer(nIDEvent);
}
