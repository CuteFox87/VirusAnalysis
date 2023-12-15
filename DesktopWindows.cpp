#include <windows.h>
#include <wingdi.h>

//#pragma comment(lib, "winmm.lib")

//gcc DesktopWindows.cpp -o DesktopWindows -lgdi32

int main(){

    HWND DesktopWindow;
    HDC WindowDC;
    RECT Rect;

    while(1){
        DesktopWindow = GetDesktopWindow();
        WindowDC = GetWindowDC(DesktopWindow);
        GetWindowRect(DesktopWindow, &Rect);
        StretchBlt(WindowDC, 50, 50, Rect.right-100, Rect.bottom-100, WindowDC, 0, 0, Rect.right, Rect.bottom, SRCCOPY);
        Sleep(100);
    }
    
    ReleaseDC(DesktopWindow, WindowDC);
}