#include <Windows.h>

typedef struct {
	_In_ DWORD dwProcessId;
	_Out_ HWND hWnd;
} HANDLE_DATA;

static FORCEINLINE BOOL IsMainWindow(HWND hWnd)
{
	return (!GetWindow(hWnd, GW_OWNER)) && IsWindowVisible(hWnd);
}

static BOOL CALLBACK EnumWindowsCallback(HWND hWnd, LPARAM lParam)
{
	HANDLE_DATA* hdCallbackData;
	DWORD dwProcessId;
	hdCallbackData = (HANDLE_DATA*)lParam;
	(VOID)GetWindowThreadProcessId(hWnd, &dwProcessId);
	if (hdCallbackData->dwProcessId != dwProcessId || !IsMainWindow(hWnd)) {
		return TRUE;
	}
	hdCallbackData->hWnd = hWnd;
	return FALSE;
}

HWND APIENTRY GetMainWindow(DWORD dwProcessId)
{
	HANDLE_DATA hdCallbackData;
	hdCallbackData.dwProcessId = dwProcessId;
	hdCallbackData.hWnd = NULL;
	(VOID)EnumWindows(EnumWindowsCallback, (LPARAM)&hdCallbackData);
	return hdCallbackData.hWnd;
}
