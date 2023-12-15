#include <windows.h>

//gcc desktopcolor.cpp -o desktopcolor -lgdi32

int main(){

    HWND DesktopWindow;
    HDC WindowDC;
    RECT Rect;
    while(1){

        DesktopWindow = GetDesktopWindow();
        WindowDC = GetWindowDC(DesktopWindow);

        GetWindowRect(DesktopWindow, &Rect);

        BitBlt(WindowDC, 0, 0, Rect.right - Rect.left, Rect.bottom - Rect.top, WindowDC, 0, 0, 0x330008u);
        Sleep(1500);
        ReleaseDC(DesktopWindow, WindowDC);
    }

}