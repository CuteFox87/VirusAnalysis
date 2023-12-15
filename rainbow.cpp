#include <windows.h>
#include <stdio.h>

typedef struct{
    int temp;
    int (*func)();
}functable;

int func1(){
    puts("1");
}

int func2(){
    puts("2");
}

int func0(){
    puts("0");
}

functable table[3];
int main(){
    table[0].func = func0;
    table[1].func = func1;
    table[2].func = func2;

    for(int i =0;i<3;i++){
        table[i].func();
    }
}