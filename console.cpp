#include "console.hpp"

void Console::gotoXY(int x, int y){
    printf("\033[%d;%df",y,x);
    fflush(stdout);
}

void printColorString(string str,int color){
    printf("\033[%dm%s\003[0m", color, str);
}

void setBackground(int color){
    printf("\033[%dm",color);
}