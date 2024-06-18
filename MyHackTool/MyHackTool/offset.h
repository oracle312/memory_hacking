#include <TlHelp32.h>

using namespace std;

DWORD procID;
DWORD BASE_ADDR;
DWORD PLAYER_BASE;

HANDLE hAndle;

bool HotKeyActivate = false;

int pAddress;
int newValue;

DWORD GetModuleBaseAddress(DWORD pId, const wchar_t* moduleName)
{
	uintptr_t modBaseAddr = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pId);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(modEntry);
		if (Module32First(hSnap, &modEntry))
		{
			do
			{
				if (!_wcsicmp(modEntry.szModule, moduleName))
				{
					modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
	}
	CloseHandle(hSnap);
	return modBaseAddr;
}