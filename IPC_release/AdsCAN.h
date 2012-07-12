#ifndef __ADSCAN_H__
#define __ADSCAN_H__

#include <windows.h>
#include <stddef.h>

#define _UNKNOWN void*
//-------------------------------------------------------------------------
// Data declarations

extern char Str1[]; // idb
extern char Name[]; // idb
extern _UNKNOWN unk_100094F8; // weak
extern char ProcName[]; // idb
extern char ValueName[]; // idb
extern char a03d[]; // idb
extern char aDevice[]; // idb
extern char SubKey[]; // idb
extern char aInvalidErrorCo[22]; // weak
extern char aCanNotSetupSpe[30]; // weak
extern char aPortIsInitiali[65]; // weak
extern char aPortIsNotIniti[54]; // weak
extern char aMapingMemoryOf[52]; // weak
extern char aSpecifiedPortS[66]; // weak
extern char aPortIsOpenedAl[65]; // weak
extern char aDllCanNotCreat[57]; // weak
extern char aOpenNotificati[41]; // weak
extern char aCanBusIsClosed[52]; // weak
extern char aNoDataInCanCon[42]; // weak
extern char aSpeifiedParame[33]; // weak
extern char aOperationIsTim[23]; // weak
extern char aSeriousCanBusE[31]; // weak
extern char aSpecifiedDataL[54]; // weak
extern char aCanControlle_0[69]; // weak
extern char aCanControllerI[69]; // weak
extern char aPortIndexIsInv[42]; // weak
extern char aFunctionCanNot[73]; // weak
extern char aSpecifiedFrame[47]; // weak
extern char aOperationIsSuc[25]; // weak
extern char aPortIsNotOpene[20]; // weak
extern char asc_1000B4B8[2]; // weak
extern char a03d03d[]; // idb
extern char asc_1000B4CC[2]; // weak
extern char Format[]; // idb
extern char aDevicename[]; // idb
extern char aModule[8]; // weak
extern char Caption[]; // idb
extern char aAdsdaq[7]; // weak
extern char a03d03dS[]; // idb
extern char a03d_1[]; // idb
extern void *off_1000BCF0; // weak
extern LPVOID off_1000BCF4; // idb
extern int dword_1000BD00; // weak
extern void **off_1000DD10; // weak
extern int dword_1000DD14; // weak
extern HINSTANCE hInstance; // idb
extern char Dest; // idb
extern int dword_1000E1E0; // weak
extern int dword_1000E1E4; // weak
extern int dword_1000E3BC; // weak
extern int dword_1000E3FC; // weak
extern unsigned __int32 Value; // idb
extern char *dword_1000E544; // idb
extern int dword_1000E560[]; // weak
extern int dword_1000E564[]; // weak
extern __int16 word_1000E568[]; // weak
extern char byte_1000E5DC[32]; // idb
extern HMODULE hModule; // idb
extern char String1[32]; // idb
extern HMODULE hLibModule; // idb
extern int dword_1000EA38; // weak
extern __int16 word_1000EA3C; // weak
extern int dword_1000EA4C; // weak
extern int dword_1000EA50; // weak
extern void *Dst; // idb
extern int dword_1000EA58; // weak
extern LPVOID lpMem; // idb
extern int dword_1000EA60; // weak
extern HANDLE hHeap; // idb
extern int dword_1000FCA8; // weak

//-------------------------------------------------------------------------
// Function declarations

BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);
int __stdcall CANPortOpen(signed __int16 a1, int a2, int a3, int a4);
int __stdcall CANPortClose(unsigned __int16 a1);
int __stdcall CANInit(__int16 a1, __int16 a2, __int16 a3, unsigned __int8 a4);
int __stdcall CANReset(unsigned __int16 a1);
int __stdcall CANInpb(int a1, __int16 a2, int a3);
int __stdcall CANOutpb(__int16 a1, __int16 a2, char a3);
int __stdcall CANSetBaud(__int16 a1, __int16 a2, __int16 a3);
int __stdcall CANGetBaudRate(unsigned __int16 a1, int a2);
int __stdcall CANSetAcp(__int16 a1, __int16 a2, __int16 a3);
int __stdcall CANSetAcpEx(unsigned __int16 a1, int a2);
int __stdcall CANSetIntrMaskEx(unsigned __int16 a1, unsigned __int8 a2);
int __stdcall CANSetOutCtrl(unsigned __int16 a1, unsigned __int16 a2);
int __stdcall CANSetNormal(unsigned __int16 a1);
int __stdcall CANHwReset(unsigned __int16 a1);
int __stdcall CANSendMsg(__int16 a1, int a2, int a3);
int __stdcall CANQueryMsg(unsigned __int16 a1, int a2, int a3);
int __stdcall CANWaitForMsg(__int16 a1, int a2, int a3);
int __stdcall CANWaitForFIFOEvent(__int16 a1, int a2, int a3);
int __stdcall CANQueryID(unsigned __int16 a1, int a2, int a3);
int __stdcall CANWaitForID(__int16 a1, int a2, int a3);
int __stdcall CANEnableMessaging(__int16 a1, __int16 a2, int a3, int a4, int a5);
int __stdcall CANGetEventName(unsigned __int16 a1, int a2);
int __stdcall CANEnableEvent(unsigned __int16 a1, int a2);
int __stdcall CANCheckEvent(unsigned __int16 a1, int a2);
int __stdcall CANReadFile(__int16 a1, int a2, int a3, int a4);
int __stdcall CANWriteFile(__int16 a1, int a2, int a3);
int __stdcall CANSetBufferPtr(__int16 a1, int a2, int a3, int a4);
int __stdcall CANSetCountPtr(__int16 a1, int a2, int a3);
int __stdcall CANEnableRxInt(unsigned __int16 a1);
int __stdcall CANGetProtocolType(unsigned __int16 a1, int a2);
int __stdcall CANSetProtocolType(int a1, __int16 a2);
int __stdcall CANGetControllerErrorCodeEx(unsigned __int16 a1, int a2);
int __stdcall CANGetArbitrationLostCatchMsgEx(unsigned __int16 a1, int a2);
signed int __stdcall CANGetErrorMessage(signed int a1, void *a2);
int __stdcall CANWakeUpEx(unsigned __int16 a1, int a2);
signed int __stdcall CANSelectDevice(HWND hWndParent, int a2, unsigned __int32 *a3, char *a4);
signed int __cdecl sub_10002320(unsigned __int32 Value, unsigned int a2, void *a3);
int __stdcall CANGetAddress(int a1);
signed int __cdecl DialogFunc(HWND hWnd, int a2, __int16 a3, int a4);
int __cdecl sub_10002590(unsigned __int32 Value, LPCSTR lpValueName, LPBYTE lpData, DWORD cbData); // idb
signed int __cdecl sub_100026A0(unsigned __int32 Value, unsigned __int32 a2, LPCSTR lpValueName, LPBYTE lpData, DWORD cbData);
int __cdecl sub_10002820(HWND hWnd); // idb
signed int __cdecl sub_10002AE0(HWND hWnd, LPARAM a2, unsigned __int32 Value);
// char *__cdecl _ultoa(unsigned __int32 Value, char *Dest, int Radix);
// int sprintf(char *Dest, const char *Format, ...);
// int __cdecl atoi(const char *Str);
char __cdecl sub_100044A6(int a1);
__int32 __cdecl sub_100044D3();
signed int __cdecl sub_1000461B(int a1);
BOOL __cdecl sub_10004678();
void __cdecl sub_10004CCC(signed int a1, int a2);
void __cdecl sub_10004D1E(signed int a1, int a2);
// _DWORD __cdecl _lock(_DWORD); weak
// _DWORD __cdecl _unlock(_DWORD); weak
void *__cdecl sub_100050E1(int a1, int a2);
void __cdecl sub_10005175();
int __cdecl sub_1000517A();
void __cdecl sub_100051FE();
int __cdecl sub_10005203();
// int __usercall sub_1000521E<eax>(int result<eax>, unsigned int a2);
int __cdecl sub_10005288();
int __cdecl sub_100052E0();
LPVOID __cdecl sub_10005345(unsigned int a1);
int __cdecl sub_100053AC();
int __cdecl sub_1000540B();
// __int32 __cdecl strtol(const char *Str, char **EndPtr, int Radix);
// char *__cdecl strchr(const char *Str, int Val);
// char *__cdecl strstr(const char *Str, const char *SubStr);
// int __cdecl strncmp(const char *Str1, const char *Str2, size_t MaxCount);
// _DWORD __cdecl __sbh_heap_init(_DWORD); weak
// _DWORD __cdecl __sbh_find_block(_DWORD); weak
unsigned int __cdecl sub_100060D2(unsigned int a1, int a2);
// _DWORD __cdecl __sbh_alloc_block(_DWORD); weak
LPVOID __cdecl sub_100068B0();
BOOL __cdecl sub_100069F4(void **lpMem);
void __cdecl sub_10006A4A(int a1);
int __cdecl sub_10006B0C(unsigned int a1, int a2, int a3);
void __cdecl sub_10006B63(int a1, int a2, int a3);
int __cdecl sub_10006BA8(unsigned int a1);
int __cdecl sub_10006DB0(int a1, unsigned int a2, unsigned int a3);
int __cdecl sub_10007330();
// _DWORD __cdecl flsall(_DWORD); weak
// void *__cdecl memset(void *Dst, int Val, size_t Size);
// int __cdecl unknown_libname_1(int, PVOID TargetFrame, int); idb
// _DWORD __cdecl _callnewh(_DWORD); weak
// void *__cdecl memcpy_0(void *Dst, const void *Src, size_t Size);
// LSTATUS __stdcall RegCloseKey(HKEY hKey);
// LSTATUS __stdcall RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
// LSTATUS __stdcall RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
// LSTATUS __stdcall RegEnumKeyExA(HKEY hKey, DWORD dwIndex, LPSTR lpName, LPDWORD lpcchName, LPDWORD lpReserved, LPSTR lpClass, LPDWORD lpcchClass, PFILETIME lpftLastWriteTime);
// void __stdcall InitCommonControls();
// int __stdcall lstrcmpA(LPCSTR lpString1, LPCSTR lpString2);
// FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
// LPSTR __stdcall lstrcpyA(LPSTR lpString1, LPCSTR lpString2);
// LPSTR __stdcall lstrcatA(LPSTR lpString1, LPCSTR lpString2);
// HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName);
// int __stdcall lstrlenA(LPCSTR lpString);
// BOOL __stdcall VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
// BOOL __stdcall HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
// DWORD __stdcall GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
// BOOL __stdcall FreeLibrary(HMODULE hLibModule);
// HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName);
// DWORD __stdcall GetEnvironmentVariableA(LPCSTR lpName, LPSTR lpBuffer, DWORD nSize);
// BOOL __stdcall GetVersionExA(LPOSVERSIONINFOA lpVersionInformation);
// BOOL __stdcall HeapDestroy(HANDLE hHeap);
// HANDLE __stdcall HeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize);
// void __stdcall EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
// void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
// LPVOID __stdcall HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
// LPVOID __stdcall VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
// int wsprintfA(LPSTR, LPCSTR, ...);
// INT_PTR __stdcall DialogBoxParamA(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam);
// int __stdcall MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
// BOOL __stdcall EndDialog(HWND hDlg, INT_PTR nResult);
// HWND __stdcall SetFocus(HWND hWnd);
// LRESULT __stdcall SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
// HWND __stdcall GetDlgItem(HWND hDlg, int nIDDlgItem);


#endif