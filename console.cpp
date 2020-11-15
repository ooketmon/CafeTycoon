#include "console.hpp"
#define WIDTH 65
#define HEIGHT 25

void Console::gotoXY(int x, int y) {
    printf("\033[%d;%df", y, x);
    fflush(stdout);
}

void Console::printColorString(const char *str, int color) {
    printf("\033[%dm%s\033[0m", color, str);
}

void Console::setBackground(int color) {
    color += 10;
    printf("\033[%dm", color);
}

void Console::printDot(int x, int y, int color) {
    gotoXY(x, y);
    setBackground(color);
    printColorString(" ");
}

void Console::gotoEnd() { gotoXY(1, HEIGHT + 1); }
