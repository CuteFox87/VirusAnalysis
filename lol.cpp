#include <windows.h>

int main(){
    DWORD CurrentThreadId = GetCurrentThreadId();
    HHOOK hHook = SetWindowsHookExW(5, 0, 0, CurrentThreadId);
    MessageBoxW(NULL, L"Still using this computer?", L"lol", 0x1030u);
    UnhookWindowsHookEx(hHook);
}