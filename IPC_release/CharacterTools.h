#pragma once
class CCharacterTools
{
public:
	CCharacterTools(void);
	~CCharacterTools(void);
	static int AnsiToUni(const char* szAnsi, wchar_t* wszUni);
	static int UniToAnsi(wchar_t* wszUni, char* szAnsi);
	static int UniToUTF8(wchar_t* wszUni, char* szU8);
	static int UTF8ToUni(char* szU8, wchar_t* wszUni);
};

