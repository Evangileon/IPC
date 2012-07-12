#include "StdAfx.h"
#include "MConfig.h"

//#include <MsXml.h>
#include <cstring>


CMConfig::CMConfig(void)
{
	Initialize();
	
	CString strFolderPath = _T(".\\config");
	if (!PathIsDirectory(strFolderPath)) 
	{ 
		CreateDirectory(strFolderPath, NULL); 
	}
	
	FileName = _T(".\\config\\configuration.ini");

	//WCHAR buffer[1024];
	StationNBR = GetPrivateProfileInt(_T("StationConfig"), _T("Number"), 19, FileName);
	StationNBR = (StationNBR > 0) ? StationNBR : 19;
	m_bNativeDB = GetPrivateProfileInt(_T("DatabaseConfig"), _T("DBServer"), TRUE, FileName);
	m_bNativeDB = !(!m_bNativeDB);

	m_bReal = TRUE;
	m_bVirtue = FALSE;

#ifdef _DEBUG
	WritePrivateProfileString(_T("Test"), _T("first"), _T("success"), FileName);
#endif
}


CMConfig::~CMConfig(void)
{
}


int CMConfig::Save(void)
{
	FileName = _T(".\\config\\configuration.ini");
	Save(FileName);
	return 0;
}


int CMConfig::Save(CString FileName)
{
	WritePrivateProfileString(_T("StationConfig"), _T("Number"), _T("")+StationNBR, FileName);
	WritePrivateProfileString(_T("DatabaseConfig"), _T("DBServer"), _T("")+m_bNativeDB, FileName);
	return 0;
}

void CMConfig::Initialize()
{
	//strConfigs->insert(_T("Prioty")
}

CMConfig* CMConfig::_instance = 0;

CMConfig* CMConfig::Instance(void)
{
	if(_instance == 0)
		_instance = new CMConfig;
	return _instance;
}


void CMConfig::ExitInstance(BOOL m_bSave)
{
	if(m_bSave == TRUE)
		CMConfig::Instance()->Save();
	if(_instance != 0)
		delete _instance;
}
