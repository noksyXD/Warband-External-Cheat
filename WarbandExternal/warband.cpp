#include <Windows.h>
#include "warband.h"
int otoblock = 0;
float zoomdistance = 0;
bool otoblockx = false;
void warband::runWarband(HANDLE hProcessxx) {
	if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
		otoblock = !otoblock;
		if (otoblock) { // enable server-side autoblock support
			DWORD bytes;
			BYTE hexs[5] = { 0x00,0x00,0x00,0x00,0x00 };
			Sleep(100);
			WriteProcessMemory(hProcessxx, (PVOID)0x0087C2F4, hexs, 5, (SIZE_T*)&bytes);
		}
		else if (!otoblock) { // disable server-side autoblock support
			DWORD bytes;
			BYTE hexs[5] = { 0x01,0x00,0x00,0x00,0x00 };
			Sleep(500);
			WriteProcessMemory(hProcessxx, (PVOID)0x0087C2F4, hexs, 5, (SIZE_T*)&bytes);
		}
	}
	// change the zoom value **max = 1.69 min = 0.69 on default**
	if (GetAsyncKeyState(VK_NUMPAD4)) {
		zoomdistance += 0.002;
		WriteProcessMemory(hProcessxx, (PVOID)0x00DD8178, &zoomdistance, sizeof(float), NULL); 
		WriteProcessMemory(hProcessxx, (PVOID)0x03147328, &zoomdistance, sizeof(float), NULL);
		BYTE nop[1] = { 0x90 };
		WriteProcessMemory(hProcessxx, (PVOID)0x005D8B9F, &nop, sizeof(nop), NULL);

		WriteProcessMemory(hProcessxx, (PVOID)0x005D8BA0, &nop, sizeof(nop), NULL);
		WriteProcessMemory(hProcessxx, (PVOID)0x005D8BA1, &nop, sizeof(nop), NULL);
		WriteProcessMemory(hProcessxx, (PVOID)0x005D8BA2, &nop, sizeof(nop), NULL);
	}
	if (GetAsyncKeyState(VK_NUMPAD3)) {
		if (zoomdistance > 0.69)
			zoomdistance -= 0.002;
		WriteProcessMemory(hProcessxx, (PVOID)0x00DD8178, &zoomdistance, sizeof(float), NULL);
		WriteProcessMemory(hProcessxx, (PVOID)0x03147328, &zoomdistance, sizeof(float), NULL);
		BYTE nop[1] = { 0x90 };
		WriteProcessMemory(hProcessxx, (PVOID)0x005D8B9F, &nop, sizeof(nop), NULL);

		WriteProcessMemory(hProcessxx, (PVOID)0x005D8BA0, &nop, sizeof(nop), NULL);
		WriteProcessMemory(hProcessxx, (PVOID)0x005D8BA1, &nop, sizeof(nop), NULL);
		WriteProcessMemory(hProcessxx, (PVOID)0x005D8BA2, &nop, sizeof(nop), NULL);
	}
	if (!zoomdistance == 0) {
		WriteProcessMemory(hProcessxx, (PVOID)0x00DD8178, &zoomdistance, sizeof(float), NULL);
		WriteProcessMemory(hProcessxx, (PVOID)0x03147328, &zoomdistance, sizeof(float), NULL);
		BYTE nop[1] = { 0x90 };
		WriteProcessMemory(hProcessxx, (PVOID)0x005D8B9F, &nop, sizeof(nop), NULL);

		WriteProcessMemory(hProcessxx, (PVOID)0x005D8BA0, &nop, sizeof(nop), NULL);
		WriteProcessMemory(hProcessxx, (PVOID)0x005D8BA1, &nop, sizeof(nop), NULL);
		WriteProcessMemory(hProcessxx, (PVOID)0x005D8BA2, &nop, sizeof(nop), NULL);

	}
	

}

