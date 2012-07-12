#pragma once

#include <hash_map>
#include <hash_set>

using namespace std;

//工控机与工位的通信协议

#define NONE_PROCTOL       0

#define PROCTOL_MOVE       1
#define PROCTOL_MOVEX      2
#define PROCTOL_MOVEY      3
#define PROCTOL_MOVEZ      4

#define PROCTOL_SEIZE      5
#define PROCTOL_LEASE      6

#define PROCTOL_RESET      7



#define PROCTOL_POSX       11
#define PROCTOL_POSY       12
#define PROCTOL_POSZ       13
#define PROCTOL_STATUS     14
#define PROCTOL_HAND       15




typedef struct _Proctol_ID {
	char *proctStr;
	int  ID;
}Proctol_ID;

class CProctol
{
public:
	CProctol(void);
	~CProctol(void);

	static hash_map<CString&, int> *proctol;
	//static hash_set<CString> proctol; 
	int ParseRecv(CString& msg);
	void ParseSend(int nCmd, CString& strMsg);
};
