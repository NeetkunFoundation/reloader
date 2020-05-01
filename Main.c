#include <Windows.h>

#include "Linker.h"
#include "Utils.h"

#define JZ_INSTRUCTION_ADDR 0x164E276F0+0x68

BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved)
{
	static HMODULE hLibrary;
	UNREFERENCED_PARAMETER(lpvReserved);

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hinstDLL);
		hLibrary = LoadLibrary(TEXT(".\\nativePC\\amd_ags_x64.dll"));
		if (!(hLibrary && LinkFunctions(hLibrary))) {
			return TRUE;
		}
		if (*((BYTE*)JZ_INSTRUCTION_ADDR) == 0x74) {
			*((BYTE*)JZ_INSTRUCTION_ADDR) = 0xEB;
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
