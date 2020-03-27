#include <Windows.h>

#include "Linker.h"
#include "Utils.h"

#undef LOADER_BUILD_VALIDATION

#define BUILD_NUMBER_OFFSET	0x143132868
#define BUILD_NUMBER_STRING	"406510"
#define JZ_INSTRUCTION_ADDR 0x15E36E1E8

#define LOADER_TITLE   TEXT("nativePC Loader")
#define LOADER_VERSION TEXT("1.0.0")

BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved)
{
	UNREFERENCED_PARAMETER(lpvReserved);

	static HMODULE hLibrary;

	HWND hWnd;
	TCHAR lpBuf[256];

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hinstDLL);

		hWnd = GetMainWindow(GetCurrentProcessId());
		if (!hWnd) {
			MessageBox(NULL, TEXT("Couldn't find the main window of Monster Hunter: World."), LOADER_TITLE, MB_OK);
			return FALSE;
		}
		GetWindowText(hWnd, lpBuf, 256);
		lstrcat(lpBuf, TEXT(" // ") LOADER_TITLE);

		hLibrary = LoadLibrary(TEXT("C:\\Windows\\System32\\hid.dll"));
		if (!hLibrary) {
			lstrcat(lpBuf, TEXT(" - Failed to load hid.dll"));
			SetWindowText(hWnd, lpBuf);
			return TRUE;
		}

		if (!LinkFunctions(hLibrary)) {
			lstrcat(lpBuf, TEXT(" - Failed to link hid.dll"));
			SetWindowText(hWnd, lpBuf);
			return TRUE;
		}

#ifdef LOADER_BUILD_VALIDATION
		if (lstrcmpA((LPCSTR)BUILD_NUMBER_OFFSET, BUILD_NUMBER_STRING) != 0) {
			lstrcat(lpBuf, TEXT(" - Incompatible Game Version"));
			SetWindowText(hWnd, lpBuf);
			return TRUE;
		}
#endif

		if (*((BYTE*)JZ_INSTRUCTION_ADDR) == 0x74) {
			*((BYTE*)JZ_INSTRUCTION_ADDR) = 0xEB;
			lstrcat(lpBuf, TEXT(" - Version ") LOADER_VERSION);
			SetWindowText(hWnd, lpBuf);
			return TRUE;
		}
		break;
	case DLL_PROCESS_DETACH:
		if (hLibrary) {
			FreeLibrary(hLibrary);
		}
		break;
	}

	return TRUE;
}
