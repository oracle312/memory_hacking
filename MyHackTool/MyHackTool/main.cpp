#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <tlhelp32.h>
#include "offset.h"
#include "memory.h"

int main()
{
	SetConsoleTitle(TEXT("MyHackTool"));
	cout << "[!] Ÿ�� ���μ����� ��ٸ��� ��... :F" << endl;
	while (true)
	{
		Sleep(100);
		HWND hWnd = FindWindow(NULL, L"AssaultCube");
		if (hWnd)
		{
			cout << "[1] ���μ����� ã�ҽ��ϴ� !! :D" << endl;
			DWORD targetProcess = GetWindowThreadProcessId(hWnd, &procID);
			if (targetProcess)
			{
				cout << "[2] PID�� �������µ� �����߽��ϴ� !! :D" << endl;
				hAndle = OpenProcess(PROCESS_ALL_ACCESS, 0, procID);
				BASE_ADDR = GetModuleBaseAddress(procID, L"ac_client.exe");
				PLAYER_BASE = BASE_ADDR + 0x0017E0A8;
				cout << "Target PID : " << procID << endl << "ModuleBaseAddr : " << BASE_ADDR << endl << "PlayerBase : " << PLAYER_BASE << endl;
				HotKeyActivate = true;
				break;
			}
		}
	}

	if (HotKeyActivate == true)
	{
		cout << "==================== HOT KEYS ====================" << endl;
		cout << "[NUMPAD 1] : HP 999" << " || " << "[NUMPAD 2] : ź�๫��" << endl;
		cout << "[NUMPAD 3] : �������" << " || " << "[NUMPAD 4] : �ѱ�ݵ�����" << endl;
		while (true)
		{
			Sleep(100);
			if (GetAsyncKeyState(VK_NUMPAD1))
			{
				DWORD oldProtect;
				VirtualProtectEx(hAndle, (BYTE*)PLAYER_BASE, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
				ReadProcessMemory(hAndle, (BYTE*)PLAYER_BASE, &pAddress, sizeof(pAddress), NULL);
				pAddress += 0xEC;
				newValue = 999;
				WriteProcessMemory(hAndle, (BYTE*)pAddress, &newValue, sizeof(newValue), NULL);
				VirtualProtectEx(hAndle, (BYTE*)PLAYER_BASE, 1, oldProtect, &oldProtect);
			}
			
			if (GetAsyncKeyState(VK_NUMPAD2))
			{
				memory::HackActivate(hAndle, (BYTE*)(BASE_ADDR + 0xC73EF), (BYTE*)"\x90\x90", 2);
			}

			if (GetAsyncKeyState(VK_NUMPAD3))
			{
				DWORD oldProtect;
				VirtualProtectEx(hAndle, (BYTE*)PLAYER_BASE, 1, PAGE_EXECUTE_READWRITE, &oldProtect);
				ReadProcessMemory(hAndle, (BYTE*)PLAYER_BASE, &pAddress, sizeof(pAddress), NULL);
				pAddress += 0x164;
				newValue = 0;
				WriteProcessMemory(hAndle, (BYTE*)pAddress, &newValue, sizeof(newValue), NULL);
				VirtualProtectEx(hAndle, (BYTE*)PLAYER_BASE, 1, oldProtect, &oldProtect);
			}

			if (GetAsyncKeyState(VK_NUMPAD4))
			{
				memory::HackActivate(hAndle, (BYTE*)(BASE_ADDR + 0xC8BA0), (BYTE*)"\xC2\x08\x00", 3);
			}
		}
	}
}