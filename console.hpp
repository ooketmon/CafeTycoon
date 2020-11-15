#ifndef __CONSOLE_HPP__
#define __CONSOLE_HPP__

#include <string>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ENTER 13
#define BACK 18 // 8
#define ESC 27

using namespace std;

class Console {
  private:
    int x;
    int y;

    int linux_kbhit(void); // 키입력 제어 함수

  public:
    int getX() { return x; }   // 현제 x 좌표
    int getY() { return y; }   // 현제 y 좌표
    void gotoXY(int x, int y); // x,y 좌표 변경
    void printColorString(string str,
                          int color = 39); // 글씨색 변경 Default : 기본색
    void setBackground(int color = 49); // 배경색 변경 Default : 기본색
    static string inputPassword(int maxsize); // 비밀번호 제어 함수
    static string input(int maxsize = 1024);  // 일반 입력 함수
};

#endif //__CONSOLE_HPP__
