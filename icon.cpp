#include <windows.h>

int main(){
    POINT point;
    HWND hwnd;
    RECT Rect;
    int a,b;
    int t=0;

    while(1){

        a = GetSystemMetrics(11)/2;
        b = GetSystemMetrics(12)/2;

        GetCursorPos(&point);
        hwnd = GetDesktopWindow();
        GetWindowRect(hwnd, &Rect);

        DrawIcon(GetWindowDC(hwnd), point.x-a, point.y-b, LoadIconW(NULL, (LPCWSTR)0x7F01));

        if(t%50==0){
            DrawIcon(GetWindowDC(hwnd), rand()%( Rect.right - Rect.left ), rand()%(Rect.bottom - Rect.top ), LoadIconW(NULL, (LPCWSTR)0x7F03));
        }

        ReleaseDC(hwnd, GetWindowDC(hwnd));

        t++;
        Sleep(10);
    }
}