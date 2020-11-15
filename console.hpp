#ifndef __CONSOLE_HPP__
#define __CONSOLE_HPP__

#include <stdio.h>
#include <string>
using namespace std;

#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define LIGHTGRAY 37
#define GRAY 90
#define LIGHTRED 91
#define LIGHTGREEN 92
#define LIGHTYELLOW 93
#define LIGHTBLUE 94
#define LIGHTMAGENTA 95
#define LIGHTCYAN 96

class Console {
  private:
    int x;
    int y;

  public:
    int getX() { return x; }
    int getY() { return y; }
    void gotoXY(int x, int y);
    void printColorString(const char *str, int color = 39);
    void setBackground(int color = 49);
    void printDot(int x, int y, int color);
    void gotoEnd();
};

#endif //__CONSOLE_HPP__
