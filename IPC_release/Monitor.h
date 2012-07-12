#pragma once

#include "OutputWnd.h"

class CMonitor
{
public:
	CMonitor(void);
	~CMonitor(void);
	CMonitor(COutputList *m_output);
protected:
	COutputList *screen;
public:
	void Log(CString info);
	void SetScreen(COutputList * m_output);
};

