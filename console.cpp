#include "console.hpp"
#include <iostream>
#include <termios.h>
#include <unistd.h>

#define WIDTH 65
#define HEIGHT 25

void Console::gotoXY(int x, int y) {
    printf("\033[%d;%df", y, x);
    fflush(stdout);
}

int Console::linux_kbhit(void) {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

string Console::inputPassword(int maxsize) {
    string password;
    int index = 0;

    while (1) {
        password[index++] = linux_kbhit();
        if (password[index] == BACK - 10) {
            if (index > 0) {
                printf("\b \b");
                index--;
            }
            continue;

        } else if (password[index] == ENTER) {
            break;
        } else if (index >= maxsize) {
            continue;
        } else if (password[index] == ESC) {
            return NULL;
        } else {
            cout << "*";
            index++;
        }
    }

    return password;
}

string Console::input(int maxsize) {

    string str;
    int index = 0;

    while (1) {

        str[index] = linux_kbhit();
        if (str[index] == BACK - 10) {
            if (index > 0) {
                printf("\b \b");
                index--;
            }
            continue;

        } else if (str[index] == ENTER) {
            break;
        } else if (index >= maxsize) {
            continue;
        } else if (str[index] == ESC) {
            return NULL;
        } else {
            cout << str[index];
            index++;
        }
    }
    str[index] = '\0';
    return str;
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
