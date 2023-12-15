#include <windows.h>
#include <wchar.h>

BOOL __stdcall EnumFunc(HWND hWnd, LPARAM a2);
int __cdecl reverseString(LPWSTR lpString);
int doString();

int main(){
     while(true){
        Sleep(1000);
        doString();
    }
    return 0;
}

BOOL __stdcall EnumFunc(HWND hWnd, LPARAM a2)
{
    WCHAR *v2 = (WCHAR *)GlobalAlloc(0x40u, 0x4000u);
    if (SendMessageTimeoutW(hWnd, 0xDu, 0x2000u, (LPARAM)v2, 2u, 0x64u, 0))
    {
        reverseString(v2);
        SendMessageTimeoutW(hWnd, 0xCu, 0, (LPARAM)v2, 2u, 0x64u, 0);
    }
    GlobalFree(v2);
    return 1;
}

int doString()
{
    HWND DesktopWindow = GetDesktopWindow();
    EnumChildWindows(DesktopWindow, EnumFunc, 0);
    return 50;
}

int __cdecl reverseString(LPWSTR lpString)
{
    int result = lstrlenW(lpString);
    if (result > 1)
    {
        int v2 = 0;
        int v3 = --result;
        int v4 = 0;
        WCHAR v5;

        do
        {
            v5 = lpString[v4];
            lpString[v4++] = lpString[v3];
            lpString[v3--] = v5;
        } while (v4 < v3);

        do
        {
            if (lpString[v2] == L'\n' && lpString[v2 + 1] == L'\r')
            {
                lpString[v2] = L'\r';
                lpString[v2 + 1] = L'\n';
            }
            ++v2;
        } while (v2 < result);
    }

    return result;
}