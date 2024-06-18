#include "memory.h"

void memory::HackActivate(HANDLE hProc, BYTE* addr, BYTE* buf, unsigned int size)
{
	DWORD oldProtect;
	VirtualProtectEx(hProc, addr, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	WriteProcessMemory(hProc, addr, buf, size, NULL);
	VirtualProtectEx(hProc, addr, size, oldProtect, &oldProtect);
}