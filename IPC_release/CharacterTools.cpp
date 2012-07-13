#include "StdAfx.h"
#include "CharacterTools.h"


CCharacterTools::CCharacterTools(void)
{
}


CCharacterTools::~CCharacterTools(void)
{
}


int CCharacterTools::AnsiToUni(const char* szAnsi, wchar_t* wszUni)
{
	int wcsLen = ::MultiByteToWideChar(CP_ACP, NULL, szAnsi, strlen(szAnsi), NULL, 0);
	::MultiByteToWideChar(CP_ACP, NULL, szAnsi, strlen(szAnsi), wszUni, wcsLen);
	wszUni[wcsLen] = '\0';

	return 0;
}


int CCharacterTools::UniToAnsi(wchar_t* wszUni, char* szAnsi)
{
	int ansiLen = ::WideCharToMultiByte(CP_ACP, NULL, (LPCWSTR)wszUni, wcslen(wszUni), NULL, 0, NULL, NULL);
	::WideCharToMultiByte(CP_ACP, NULL, wszUni, wcslen(wszUni), szAnsi, ansiLen, NULL, NULL);
	szAnsi[ansiLen] = '\0';  //最后加上'\0'

	return 0;
}


int CCharacterTools::UniToUTF8(wchar_t* wszUni, char* szU8)
{
	int u8Len = ::WideCharToMultiByte(CP_UTF8, NULL, wszUni, wcslen(wszUni), NULL, 0, NULL, NULL);
	::WideCharToMultiByte(CP_UTF8, NULL, wszUni, wcslen(wszUni), szU8, u8Len, NULL, NULL);
	szU8[u8Len] = '\0';

	return 0;
}


int CCharacterTools::UTF8ToUni(char* szU8, wchar_t* wszUni)
{
	int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0);
	::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszUni, wcsLen);
	wszUni[wcsLen] = '\0';
	
	return 0;
}
