#include <windows.h>

int main(){

    while(true){
        if(MessageBoxA(
         0,
         "Are you gay?",
         "MEMZ",
         0x34u) == 6 ){
            MessageBoxA(0, "HAHA! You are Gay!", "You are Gay!",  MB_ICONSTOP|MB_OK);
            break;  
        }
        else{
            MessageBoxA(0, "ERROR", "Try Again", MB_ICONERROR|MB_OK);
        }     
    }
        
}