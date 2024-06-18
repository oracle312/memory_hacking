#include <Windows.h>

namespace memory
{
	void HackActivate(HANDLE hProc, BYTE* addr, BYTE* buf, unsigned int size);
}