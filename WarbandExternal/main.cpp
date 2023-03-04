#include <Windows.h>
#include <iostream>
#include <string>
#include "warband.h"
#include "wse2.h"
#include "mouse.cpp"
using namespace std;
HANDLE hProcess;
void setup(string inp) {
	LPCWSTR windowName = L"";
	if (inp._Equal("1"))
		windowName = L"Mount&Blade Warband";
	else if (inp._Equal("2"))
		windowName = L"Mount&Blade Warband WSE2";
	else {
		cout << "[ERROR] Enter a true input and retry" << endl;
		Sleep(4000);
		exit(-1);
	}
	HWND hWnd;
	cout << "[INFO] Listening for Warband...\n" << endl;
	while (!(hWnd = FindWindow(NULL, windowName))) {
		Sleep(100);
	}


	DWORD PID;
	while (!(GetWindowThreadProcessId(hWnd, &PID)))
		Sleep(100);

	while (!(hProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, 0, PID)))
		Sleep(100);
}

int main() {
	
	cout << "[INFO] Developed by wayt#2996\n" << endl;

	cout << "[INFO] Enter a warband mode (Default Warband: 1 | WSE2: 2)" << endl;
	string s;
	getline(cin, s);
	setup(s);
	if (s._Equal("1")) {
		cout << "[INFO] Autoblock enable/disable hotkey: Numpad 5\n" << endl;
		cout << "[INFO] Zoom increase hotkey: Numpad 4 | decrease hotkey: Numpad 3\n" << endl;
	}
	else if (s._Equal("2")) {
		cout << "[INFO] Autoblock enable/disable hotkey: Numpad 5\n" << endl;
		cout << "[INFO] Zoom increase hotkey: Numpad 4 | decrease hotkey: Numpad 3\n" << endl;
	}
	
	cout << "[INFO] Warband opened. Can you enable the right click spammer for autoblock? (y/n) [Hotkey is: V]" << endl;

	string inp;
	getline(cin, inp);
	
	if (inp._Equal("y")) {
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)click, 0, 0, 0);
	}
	else if (!inp._Equal("n")) {
		cout << "\n[ERROR] Please enter y or n and try again." << endl;
		exit(-1);
	}

	cout << "\n[INFO] Success! Listening for hotkeys..." << endl;

	while (true) {
		if (s._Equal("1"))
			warband::runWarband(hProcess);
		if (s._Equal("2"))
			wse2::runWse2(hProcess);
	}

	return 0;
}