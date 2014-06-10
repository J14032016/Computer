#include <windows.h>

#define KEYSTATE 1

void setCapsLock(int bState)
{
	BYTE keyState[256];

	GetKeyboardState((LPBYTE)&keyState);
	if((bState && !(keyState[VK_CAPITAL] & 1)) ||
		(!bState && (keyState[VK_CAPITAL] & 1)))
	{
		keybd_event(VK_CAPITAL, 0x45,
			KEYEVENTF_EXTENDEDKEY | 0, 0);
		keybd_event(VK_CAPITAL, 0x45,
			KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	}
}

int main()
{
	setCapsLock(KEYSTATE);
	return 0;
}
