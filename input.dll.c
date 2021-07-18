#include <windows.h>

extern __declspec(dllexport) void mouseInput(LONG x, LONG y, DWORD dwFlags, DWORD mouseData)
{
    INPUT input = {0};
    input.type = INPUT_MOUSE;
    input.mi.dx = x;
    input.mi.dy = y;
    input.mi.mouseData = mouseData;
    input.mi.dwFlags = dwFlags;
    input.mi.time = 0;
    input.mi.dwExtraInfo = GetMessageExtraInfo();

    SendInput(1, &input, sizeof(input));
}

extern __declspec(dllexport) void keyboardInput(char keyChar, DWORD dwFlags)
{
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = dwFlags;
    input.ki.wScan = MapVirtualKey(LOBYTE(VkKeyScan(keyChar)), 0);

    SendInput(1, &input, sizeof(input));
}

extern __declspec(dllexport) void keyboardKeyPress(char keyChar, unsigned int timeMs)
{
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = MapVirtualKey(LOBYTE(VkKeyScan(keyChar)), 0);

    SendInput(1, &input, sizeof(input));

    if (timeMs > 0)
    {
        Sleep(timeMs);
        input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(input));
    }
}
