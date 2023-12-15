#include <windows.h>
#include <random>
#include <winuser.h>

int main(){


    while(1){
        INPUT pInput;
        pInput.type = INPUT_KEYBOARD;
        pInput.ki.wVk = rand() % 42 + 48;
        SendInput(1, &pInput, sizeof(INPUT));
        Sleep(10);
    }

}
