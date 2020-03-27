#include <Windows.h>

#define NUM_FUNCTIONS 44

LPVOID lpOrigProcs[NUM_FUNCTIONS];

static LPCSTR lpImportNames[] = {
	"HidD_FlushQueue",
	"HidD_FreePreparsedData",
	"HidD_GetAttributes",
	"HidD_GetConfiguration",
	"HidD_GetFeature",
	"HidD_GetHidGuid",
	"HidD_GetIndexedString",
	"HidD_GetInputReport",
	"HidD_GetManufacturerString",
	"HidD_GetMsGenreDescriptor",
	"HidD_GetNumInputBuffers",
	"HidD_GetPhysicalDescriptor",
	"HidD_GetPreparsedData",
	"HidD_GetProductString",
	"HidD_GetSerialNumberString",
	"HidD_Hello",
	"HidD_SetConfiguration",
	"HidD_SetFeature",
	"HidD_SetNumInputBuffers",
	"HidD_SetOutputReport",
	"HidP_GetButtonCaps",
	"HidP_GetCaps",
	"HidP_GetData",
	"HidP_GetExtendedAttributes",
	"HidP_GetLinkCollectionNodes",
	"HidP_GetScaledUsageValue",
	"HidP_GetSpecificButtonCaps",
	"HidP_GetSpecificValueCaps",
	"HidP_GetUsageValue",
	"HidP_GetUsageValueArray",
	"HidP_GetUsages",
	"HidP_GetUsagesEx",
	"HidP_GetValueCaps",
	"HidP_InitializeReportForID",
	"HidP_MaxDataListLength",
	"HidP_MaxUsageListLength",
	"HidP_SetData",
	"HidP_SetScaledUsageValue",
	"HidP_SetUsageValue",
	"HidP_SetUsageValueArray",
	"HidP_SetUsages",
	"HidP_TranslateUsagesToI8042ScanCodes",
	"HidP_UnsetUsages",
	"HidP_UsageListDifference"
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

EXTERN_C VOID HidD_FlushQueue(VOID);
EXTERN_C VOID HidD_FreePreparsedData(VOID);
EXTERN_C VOID HidD_GetAttributes(VOID);
EXTERN_C VOID HidD_GetConfiguration(VOID);
EXTERN_C VOID HidD_GetFeature(VOID);
EXTERN_C VOID HidD_GetHidGuid(VOID);
EXTERN_C VOID HidD_GetIndexedString(VOID);
EXTERN_C VOID HidD_GetInputReport(VOID);
EXTERN_C VOID HidD_GetManufacturerString(VOID);
EXTERN_C VOID HidD_GetMsGenreDescriptor(VOID);
EXTERN_C VOID HidD_GetNumInputBuffers(VOID);
EXTERN_C VOID HidD_GetPhysicalDescriptor(VOID);
EXTERN_C VOID HidD_GetPreparsedData(VOID);
EXTERN_C VOID HidD_GetProductString(VOID);
EXTERN_C VOID HidD_GetSerialNumberString(VOID);
EXTERN_C VOID HidD_Hello(VOID);
EXTERN_C VOID HidD_SetConfiguration(VOID);
EXTERN_C VOID HidD_SetFeature(VOID);
EXTERN_C VOID HidD_SetNumInputBuffers(VOID);
EXTERN_C VOID HidD_SetOutputReport(VOID);
EXTERN_C VOID HidP_GetButtonCaps(VOID);
EXTERN_C VOID HidP_GetCaps(VOID);
EXTERN_C VOID HidP_GetData(VOID);
EXTERN_C VOID HidP_GetExtendedAttributes(VOID);
EXTERN_C VOID HidP_GetLinkCollectionNodes(VOID);
EXTERN_C VOID HidP_GetScaledUsageValue(VOID);
EXTERN_C VOID HidP_GetSpecificButtonCaps(VOID);
EXTERN_C VOID HidP_GetSpecificValueCaps(VOID);
EXTERN_C VOID HidP_GetUsageValue(VOID);
EXTERN_C VOID HidP_GetUsageValueArray(VOID);
EXTERN_C VOID HidP_GetUsages(VOID);
EXTERN_C VOID HidP_GetUsagesEx(VOID);
EXTERN_C VOID HidP_GetValueCaps(VOID);
EXTERN_C VOID HidP_InitializeReportForID(VOID);
EXTERN_C VOID HidP_MaxDataListLength(VOID);
EXTERN_C VOID HidP_MaxUsageListLength(VOID);
EXTERN_C VOID HidP_SetData(VOID);
EXTERN_C VOID HidP_SetScaledUsageValue(VOID);
EXTERN_C VOID HidP_SetUsageValue(VOID);
EXTERN_C VOID HidP_SetUsageValueArray(VOID);
EXTERN_C VOID HidP_SetUsages(VOID);
EXTERN_C VOID HidP_TranslateUsagesToI8042ScanCodes(VOID);
EXTERN_C VOID HidP_UnsetUsages(VOID);
EXTERN_C VOID HidP_UsageListDifference(VOID);
