#pragma once

#include <vector>
#include <hash_map>

using namespace std;

class CMConfig
{
public:
	CMConfig(void);
	virtual ~CMConfig(void);
	int Save(void);
	int Save(CString FileName);
	const static int Prio_Admin = 5;
	const static int Prio_Guest = 2;

protected:
	CString FileName;
	hash_map<CString, CString> *strConfigs;
	hash_map<CString, int> *intConfigs;
public:
	int StationNBR;
	int Priority;

	BOOL m_bReal;
	BOOL m_bVirtue;
	BOOL m_bNativeDB;
	BOOL m_bServerDB;
	CString m_szSQLServer_Name;
	CString m_szSQLServer_IP;
	CString m_szSQLServer_Pwd;
	CString m_szSQLServer_Usr;

private:
	void Initialize();

//Singleton
private:
	static CMConfig *_instance;
public:
	
	static CMConfig* Instance(void);
	static void ExitInstance(BOOL m_bSave = FALSE);
};

