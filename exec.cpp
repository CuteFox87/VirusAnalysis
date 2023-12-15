#include <windows.h>
#include <stdio.h>

int main(){
    
    int numArgs;
    LPWSTR *args = CommandLineToArgvW(GetCommandLineW(), &numArgs);

    if(numArgs > 1){
        MessageBoxA(0, "hi", "hi", MB_ICONERROR|MB_OK);

        for(int i = 0; i<10; i++)printf("%d\n", i);

        Sleep(5000);

        return 0;
    }


    ShellExecuteA(NULL, NULL, "mouse", "happy", NULL, 0); // create in current disk root
    return 0;
}