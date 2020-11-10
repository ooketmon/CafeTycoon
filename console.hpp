#ifndef __CONSOLE_HPP__
#define __CONSOLE_HPP__

#include <string>
using namespace std;

class Console{
    private:
        int x;
        int y;
    public:
        int getX(){return x;}
        int getY(){return y;}
        void gotoXY(int x, int y);
        void printColorString(string str,int color = 39);
        void setBackground(int color = 49);
};

#endif //__CONSOLE_HPP__