#include <windows.h>
#include <random>

using namespace std;

int main(){

    int a=0;

    while(true){
        tagPOINT p;

        if(GetKeyState(VK_ESCAPE) & 0x8000)
            break;
        
        GetCursorPos(reinterpret_cast<LPPOINT>(&p));

        //std::cout << p.x << " " << p.y << std::endl;

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