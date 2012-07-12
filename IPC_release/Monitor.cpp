#include "StdAfx.h"
#include "Monitor.h"


CMonitor::CMonitor(void)
{
}


CMonitor::~CMonitor(void)
{
}


void CMonitor::Log(CString info)
{
	if(screen == NULL)
		return;

	screen->AddString(info);
	screen->SetCurSel(screen->GetCount()-1);
}

CMonitor::CMonitor(COutputList *m_output)
{
	screen = m_output;
}


void CMonitor::SetScreen(COutputList *m_output)
{
	screen = m_output;
}
