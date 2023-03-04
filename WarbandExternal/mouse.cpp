#include <Windows.h>
#include <iostream>
using namespace std;
static void click()
{
	while (true) {
		if ((GetKeyState(0x56) & 0x8000) != 0) {
			float cps = 0;
			float clickgrad = 0;
			cps = 14;
			clickgrad = 13;

			float clickgrd = (clickgrad * 0.01);
			float e = 1000 / cps;
			float delay = e * clickgrd;

			float i = fabs(clickgrd - 1);
			float delay2 = e * i;

			INPUT    Input = { 0 };

			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
			::SendInput(1, &Input, sizeof(INPUT));

			Sleep(delay);

			::ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
			::SendInput(1, &Input, sizeof(INPUT));

			Sleep(delay2);
		}

		//cout << "anan" << endl;

	}

}