#include <windows.h>

//gcc playsound.cpp -o playsound -lwinmm

int main(){

    LPCSTR sound[2] = {"SystemExclamation", "SystemHand"};

    while(1){

        int num = rand() % 2;
        PlaySoundA(sound[num], NULL, 1);
        Sleep(1500);

    }


}