#include "page.hpp"

void Page::clear() { system("clear"); }

void Page::frame() {
    clear();
    Console cursor;
    for (int i = 1; i <= WIDTH; i++) {      //가로
        for (int j = 1; j <= HEIGHT; j++) { //세로
            cursor.gotoXY(i, j);
            if (i == 1 || i == WIDTH || j == 1 || j == HEIGHT || i == 2 ||
                i == WIDTH - 1)
                cursor.setBackground(LIGHTMAGENTA); //테두리
            else
                cursor.setBackground(LIGHTGRAY);
            cursor.printColorString(" ");
        }
    }
}

void Page::startPage() {
    clear();
    Console cursor;
    for (int i = 1; i <= WIDTH; i++) {      //가로
        for (int j = 1; j <= HEIGHT; j++) { //세로
            cursor.gotoXY(i, j);
            if (i == 1 || i == WIDTH || j == 1 || j == HEIGHT || i == 2 ||
                i == WIDTH - 1)
                cursor.setBackground(LIGHTGRAY); //테두리
            else
                cursor.setBackground(LIGHTMAGENTA);
            cursor.printColorString(" ");
        }
    }

    // c
    cursor.printDot(11, 5, LIGHTGRAY);
    cursor.printDot(12, 5, LIGHTGRAY);
    cursor.printDot(10, 6, LIGHTGRAY);
    cursor.printDot(10, 7, LIGHTGRAY);
    cursor.printDot(10, 8, LIGHTGRAY);
    cursor.printDot(11, 9, LIGHTGRAY);
    cursor.printDot(12, 9, LIGHTGRAY);
    // a
    cursor.printDot(15, 9, LIGHTGRAY);
    cursor.printDot(15, 8, LIGHTGRAY);
    cursor.printDot(15, 7, LIGHTGRAY);
    cursor.printDot(15, 6, LIGHTGRAY);
    cursor.printDot(16, 5, LIGHTGRAY);
    cursor.printDot(17, 5, LIGHTGRAY);
    cursor.printDot(18, 5, LIGHTGRAY);
    cursor.printDot(19, 6, LIGHTGRAY);
    cursor.printDot(19, 7, LIGHTGRAY);
    cursor.printDot(19, 8, LIGHTGRAY);
    cursor.printDot(19, 9, LIGHTGRAY);
    cursor.printDot(16, 7, LIGHTGRAY);
    cursor.printDot(17, 7, LIGHTGRAY);
    cursor.printDot(18, 7, LIGHTGRAY);
    // f
    cursor.printDot(22, 5, LIGHTGRAY);
    cursor.printDot(22, 6, LIGHTGRAY);
    cursor.printDot(22, 7, LIGHTGRAY);
    cursor.printDot(22, 8, LIGHTGRAY);
    cursor.printDot(22, 9, LIGHTGRAY);
    for (int i = 23; i < 26; i++)
        cursor.printDot(i, 5, LIGHTGRAY);
    for (int i = 23; i < 26; i++)
        cursor.printDot(i, 7, LIGHTGRAY);
    // e
    cursor.printDot(28, 5, LIGHTGRAY);
    cursor.printDot(28, 6, LIGHTGRAY);
    cursor.printDot(28, 7, LIGHTGRAY);
    cursor.printDot(28, 8, LIGHTGRAY);
    cursor.printDot(28, 9, LIGHTGRAY);
    for (int i = 29; i < 32; i++)
        cursor.printDot(i, 5, LIGHTGRAY);
    for (int i = 29; i < 32; i++)
        cursor.printDot(i, 7, LIGHTGRAY);
    for (int i = 29; i < 32; i++)
        cursor.printDot(i, 9, LIGHTGRAY);
    // t
    cursor.printDot(15, 16, LIGHTGRAY);
    for (int i = 16; i < 20; i++)
        cursor.printDot(i, 16, LIGHTGRAY);
    for (int i = 17; i < 21; i++)
        cursor.printDot(17, i, LIGHTGRAY);
    // y
    cursor.printDot(22, 16, LIGHTGRAY);
    cursor.printDot(22, 17, LIGHTGRAY);
    cursor.printDot(22, 18, LIGHTGRAY);
    cursor.printDot(23, 18, LIGHTGRAY);
    cursor.printDot(24, 18, LIGHTGRAY);
    cursor.printDot(24, 19, LIGHTGRAY);
    cursor.printDot(24, 20, LIGHTGRAY);
    cursor.printDot(25, 18, LIGHTGRAY);
    cursor.printDot(26, 18, LIGHTGRAY);
    cursor.printDot(26, 17, LIGHTGRAY);
    cursor.printDot(26, 16, LIGHTGRAY);
    // c
    cursor.printDot(30, 16, LIGHTGRAY);
    cursor.printDot(31, 16, LIGHTGRAY);
    cursor.printDot(29, 17, LIGHTGRAY);
    cursor.printDot(29, 18, LIGHTGRAY);
    cursor.printDot(29, 19, LIGHTGRAY);
    cursor.printDot(30, 20, LIGHTGRAY);
    cursor.printDot(31, 20, LIGHTGRAY);
    // o
    cursor.printDot(35, 16, LIGHTGRAY);
    cursor.printDot(36, 16, LIGHTGRAY);
    cursor.printDot(34, 17, LIGHTGRAY);
    cursor.printDot(34, 18, LIGHTGRAY);
    cursor.printDot(34, 19, LIGHTGRAY);
    cursor.printDot(35, 20, LIGHTGRAY);
    cursor.printDot(36, 20, LIGHTGRAY);
    cursor.printDot(37, 19, LIGHTGRAY);
    cursor.printDot(37, 18, LIGHTGRAY);
    cursor.printDot(37, 17, LIGHTGRAY);
    // o
    cursor.printDot(41, 16, LIGHTGRAY);
    cursor.printDot(42, 16, LIGHTGRAY);
    cursor.printDot(40, 17, LIGHTGRAY);
    cursor.printDot(40, 18, LIGHTGRAY);
    cursor.printDot(40, 19, LIGHTGRAY);
    cursor.printDot(41, 20, LIGHTGRAY);
    cursor.printDot(42, 20, LIGHTGRAY);
    cursor.printDot(43, 19, LIGHTGRAY);
    cursor.printDot(43, 18, LIGHTGRAY);
    cursor.printDot(43, 17, LIGHTGRAY);
    // n
    for (int i = 16; i < 21; i++)
        cursor.printDot(46, i, LIGHTGRAY);
    cursor.printDot(47, 17, LIGHTGRAY);
    cursor.printDot(48, 18, LIGHTGRAY);
    cursor.printDot(49, 19, LIGHTGRAY);
    cursor.printDot(50, 20, LIGHTGRAY);
    for (int i = 16; i < 21; i++)
        cursor.printDot(50, i, LIGHTGRAY);

    cursor.gotoEnd();
}

void Page::login() {
    frame();
    Console cursor;

    // i
    for (int i = 8; i < 12; i++)
        cursor.printDot(14, i, LIGHTBLUE);
    for (int i = 12; i < 17; i++)
        cursor.printDot(i, 8, LIGHTBLUE);
    for (int i = 12; i < 17; i++)
        cursor.printDot(i, 11, LIGHTBLUE);
    // d
    for (int i = 8; i < 12; i++)
        cursor.printDot(21, i, LIGHTBLUE);
    cursor.printDot(22, 8, LIGHTBLUE);
    cursor.printDot(23, 8, LIGHTBLUE);
    cursor.printDot(24, 9, LIGHTBLUE);
    cursor.printDot(24, 10, LIGHTBLUE);
    cursor.printDot(23, 11, LIGHTBLUE);
    cursor.printDot(22, 11, LIGHTBLUE);

    // p
    for (int i = 14; i < 18; i++)
        cursor.printDot(12, i, LIGHTBLUE);
    cursor.printDot(13, 14, LIGHTBLUE);
    cursor.printDot(14, 14, LIGHTBLUE);
    cursor.printDot(15, 15, LIGHTBLUE);
    cursor.printDot(14, 16, LIGHTBLUE);
    cursor.printDot(13, 16, LIGHTBLUE);
    // w
    cursor.printDot(17, 14, LIGHTBLUE);
    cursor.printDot(17, 15, LIGHTBLUE);
    cursor.printDot(18, 16, LIGHTBLUE);
    cursor.printDot(19, 17, LIGHTBLUE);
    cursor.printDot(20, 16, LIGHTBLUE);
    cursor.printDot(21, 15, LIGHTBLUE);
    cursor.printDot(22, 16, LIGHTBLUE);
    cursor.printDot(23, 17, LIGHTBLUE);
    cursor.printDot(24, 16, LIGHTBLUE);
    cursor.printDot(25, 15, LIGHTBLUE);
    cursor.printDot(25, 14, LIGHTBLUE);

    for (int i = 30; i < 50; i++) {
        cursor.printDot(i, 11, GRAY);
        cursor.printDot(i, 17, GRAY);
    }

    // sign up | login
    cursor.gotoXY(14, 22);
    cursor.setBackground(LIGHTGRAY);
    cursor.printColorString("SIGN UP", LIGHTMAGENTA);
    cursor.gotoXY(33, 22);
    cursor.setBackground(LIGHTGRAY);
    cursor.printColorString("/", LIGHTMAGENTA);
    cursor.gotoXY(46, 22);
    cursor.setBackground(LIGHTGRAY);
    cursor.printColorString("LOGIN", LIGHTMAGENTA);

    cursor.gotoEnd();
}

// void Page::signUp() {}

void Page::mainPage() {
    frame();
    Console cursor;

    // STORE
    for (int i = 50; i < 53; i++) {
        cursor.printDot(i, 9, LIGHTGREEN);
        cursor.printDot(i, 8, LIGHTGREEN);
    }
    cursor.printDot(53, 9, GRAY);
    cursor.printDot(54, 9, GRAY);
    cursor.printDot(53, 8, GRAY);
    cursor.printDot(54, 8, GRAY);
    for (int i = 55; i < 58; i++) {
        cursor.printDot(i, 9, LIGHTGREEN);
        cursor.printDot(i, 8, LIGHTGREEN);
    }
    for (int i = 50; i < 58; i++) {
        cursor.printDot(i, 7, LIGHTGREEN);
        cursor.printDot(i, 4, LIGHTRED);
    }
    for (int i = 48; i < 60; i++)
        cursor.printDot(i, 6, LIGHTRED);
    for (int i = 49; i < 59; i++)
        cursor.printDot(i, 5, LIGHTYELLOW);
    cursor.gotoXY(50, 10);
    cursor.setBackground(LIGHTGRAY);
    cursor.printColorString("  STORE", GREEN);

    cursor.gotoEnd();
}
