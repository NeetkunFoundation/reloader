#include <Windows.h>

#define NUM_FUNCTIONS 36

LPVOID lpOrigProcs[NUM_FUNCTIONS];

static LPCSTR lpImportNames[] = {
	"agsDeInit",
	"agsDriverExtensionsDX11_BeginUAVOverlap",
	"agsDriverExtensionsDX11_CreateBuffer",
	"agsDriverExtensionsDX11_CreateDevice",
	"agsDriverExtensionsDX11_CreateFromDevice",
	"agsDriverExtensionsDX11_CreateTexture1D",
	"agsDriverExtensionsDX11_CreateTexture2D",
	"agsDriverExtensionsDX11_CreateTexture3D",
	"agsDriverExtensionsDX11_Destroy",
	"agsDriverExtensionsDX11_DestroyDevice",
	"agsDriverExtensionsDX11_EndUAVOverlap",
	"agsDriverExtensionsDX11_GetMaxClipRects",
	"agsDriverExtensionsDX11_IASetPrimitiveTopology",
	"agsDriverExtensionsDX11_MultiDrawIndexedInstancedIndirect",
	"agsDriverExtensionsDX11_MultiDrawIndexedInstancedIndirectCountIndirect",
	"agsDriverExtensionsDX11_MultiDrawInstancedIndirect",
	"agsDriverExtensionsDX11_MultiDrawInstancedIndirectCountIndirect",
	"agsDriverExtensionsDX11_NotifyResourceBeginAllAccess",
	"agsDriverExtensionsDX11_NotifyResourceEndAllAccess",
	"agsDriverExtensionsDX11_NotifyResourceEndWrites",
	"agsDriverExtensionsDX11_NumPendingAsyncCompileJobs",
	"agsDriverExtensionsDX11_SetClipRects",
	"agsDriverExtensionsDX11_SetDepthBounds",
	"agsDriverExtensionsDX11_SetDiskShaderCacheEnabled",
	"agsDriverExtensionsDX11_SetMaxAsyncCompileThreadCount",
	"agsDriverExtensionsDX11_SetViewBroadcastMasks",
	"agsDriverExtensionsDX11_WriteBreadcrumb",
	"agsDriverExtensionsDX12_CreateDevice",
	"agsDriverExtensionsDX12_CreateFromDevice",
	"agsDriverExtensionsDX12_Destroy",
	"agsDriverExtensionsDX12_DestroyDevice",
	"agsDriverExtensionsDX12_PopMarker",
	"agsDriverExtensionsDX12_PushMarker",
	"agsDriverExtensionsDX12_SetMarker",
	"agsInit",
	"agsSetDisplayMode",
};

BOOL APIENTRY LinkFunctions(HMODULE hLibrary)
{
	DWORD i;
	if (!hLibrary)
		return FALSE;
	for (i = NUM_FUNCTIONS; i;) {
		--i;
		lpOrigProcs[i] = (LPVOID)GetProcAddress(hLibrary, lpImportNames[i]);
	}
	return TRUE;
}

EXTERN_C VOID agsDeInit(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_BeginUAVOverlap(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_CreateBuffer(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_CreateDevice(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_CreateFromDevice(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_CreateTexture1D(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_CreateTexture2D(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_CreateTexture3D(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_Destroy(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_DestroyDevice(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_EndUAVOverlap(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_GetMaxClipRects(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_IASetPrimitiveTopology(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_MultiDrawIndexedInstancedIndirect(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_MultiDrawIndexedInstancedIndirectCountIndirect(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_MultiDrawInstancedIndirect(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_MultiDrawInstancedIndirectCountIndirect(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_NotifyResourceBeginAllAccess(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_NotifyResourceEndAllAccess(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_NotifyResourceEndWrites(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_NumPendingAsyncCompileJobs(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_SetClipRects(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_SetDepthBounds(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_SetDiskShaderCacheEnabled(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_SetMaxAsyncCompileThreadCount(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_SetViewBroadcastMasks(VOID);
EXTERN_C VOID agsDriverExtensionsDX11_WriteBreadcrumb(VOID);
EXTERN_C VOID agsDriverExtensionsDX12_CreateDevice(VOID);
EXTERN_C VOID agsDriverExtensionsDX12_CreateFromDevice(VOID);
EXTERN_C VOID agsDriverExtensionsDX12_Destroy(VOID);
EXTERN_C VOID agsDriverExtensionsDX12_DestroyDevice(VOID);
EXTERN_C VOID agsDriverExtensionsDX12_PopMarker(VOID);
EXTERN_C VOID agsDriverExtensionsDX12_PushMarker(VOID);
EXTERN_C VOID agsDriverExtensionsDX12_SetMarker(VOID);
EXTERN_C VOID agsInit(VOID);
EXTERN_C VOID agsSetDisplayMode(VOID);
