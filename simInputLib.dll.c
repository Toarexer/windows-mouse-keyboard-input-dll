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

extern __declspec(dllexport) void keyboardInput(short virtualKey, DWORD dwFlags)
{
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = dwFlags;
    input.ki.wScan = MapVirtualKey(virtualKey, 0);

    SendInput(1, &input, sizeof(input));
}

extern __declspec(dllexport) void keyboardInputC(char keyChar, DWORD dwFlags)
{
    keyboardInput(VkKeyScan(keyChar), dwFlags);
}

extern __declspec(dllexport) void keyboardKeyPress(short virtualKey, unsigned int timeMs)
{
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = MapVirtualKey(virtualKey, 0);

    SendInput(1, &input, sizeof(input));

    if (timeMs > 0)
    {
        Sleep(timeMs);
        input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(input));
    }
}

extern __declspec(dllexport) void keyboardKeyPressC(char keyChar, unsigned int timeMs)
{
    keyboardKeyPress(VkKeyScan(keyChar), timeMs);
}