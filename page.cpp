#include "page.hpp"

void Page::clear() { system("clear"); }

void Page::frame() {
    clear();
    for (int i = 1; i <= WIDTH; i++) {      //가로
        for (int j = 1; j <= HEIGHT; j++) { //세로
            Console::gotoXY(i, j);
            if (i == 1 || i == WIDTH || j == 1 || j == HEIGHT || i == 2 ||
                i == WIDTH - 1)
                Console::setBackground(LIGHTMAGENTA); //테두리
            else
                Console::setBackground(LIGHTGRAY);
            Console::printColorString(" ");
        }
    }
}

void Page::startPage() {
    clear();
    for (int i = 1; i <= WIDTH; i++) {      //가로
        for (int j = 1; j <= HEIGHT; j++) { //세로
            Console::gotoXY(i, j);
            if (i == 1 || i == WIDTH || j == 1 || j == HEIGHT || i == 2 ||
                i == WIDTH - 1)
                Console::setBackground(LIGHTGRAY); //테두리
            else
                Console::setBackground(LIGHTMAGENTA);
            Console::printColorString(" ");
        }
    }

    // c
    Console::printDot(11, 5, LIGHTGRAY);
    Console::printDot(12, 5, LIGHTGRAY);
    Console::printDot(10, 6, LIGHTGRAY);
    Console::printDot(10, 7, LIGHTGRAY);
    Console::printDot(10, 8, LIGHTGRAY);
    Console::printDot(11, 9, LIGHTGRAY);
    Console::printDot(12, 9, LIGHTGRAY);
    // a
    Console::printDot(15, 9, LIGHTGRAY);
    Console::printDot(15, 8, LIGHTGRAY);
    Console::printDot(15, 7, LIGHTGRAY);
    Console::printDot(15, 6, LIGHTGRAY);
    Console::printDot(16, 5, LIGHTGRAY);
    Console::printDot(17, 5, LIGHTGRAY);
    Console::printDot(18, 5, LIGHTGRAY);
    Console::printDot(19, 6, LIGHTGRAY);
    Console::printDot(19, 7, LIGHTGRAY);
    Console::printDot(19, 8, LIGHTGRAY);
    Console::printDot(19, 9, LIGHTGRAY);
    Console::printDot(16, 7, LIGHTGRAY);
    Console::printDot(17, 7, LIGHTGRAY);
    Console::printDot(18, 7, LIGHTGRAY);
    // f
    Console::printDot(22, 5, LIGHTGRAY);
    Console::printDot(22, 6, LIGHTGRAY);
    Console::printDot(22, 7, LIGHTGRAY);
    Console::printDot(22, 8, LIGHTGRAY);
    Console::printDot(22, 9, LIGHTGRAY);
    for (int i = 23; i < 26; i++)
        Console::printDot(i, 5, LIGHTGRAY);
    for (int i = 23; i < 26; i++)
        Console::printDot(i, 7, LIGHTGRAY);
    // e
    Console::printDot(28, 5, LIGHTGRAY);
    Console::printDot(28, 6, LIGHTGRAY);
    Console::printDot(28, 7, LIGHTGRAY);
    Console::printDot(28, 8, LIGHTGRAY);
    Console::printDot(28, 9, LIGHTGRAY);
    for (int i = 29; i < 32; i++)
        Console::printDot(i, 5, LIGHTGRAY);
    for (int i = 29; i < 32; i++)
        Console::printDot(i, 7, LIGHTGRAY);
    for (int i = 29; i < 32; i++)
        Console::printDot(i, 9, LIGHTGRAY);
    // t
    Console::printDot(15, 16, LIGHTGRAY);
    for (int i = 16; i < 20; i++)
        Console::printDot(i, 16, LIGHTGRAY);
    for (int i = 17; i < 21; i++)
        Console::printDot(17, i, LIGHTGRAY);
    // y
    Console::printDot(22, 16, LIGHTGRAY);
    Console::printDot(22, 17, LIGHTGRAY);
    Console::printDot(22, 18, LIGHTGRAY);
    Console::printDot(23, 18, LIGHTGRAY);
    Console::printDot(24, 18, LIGHTGRAY);
    Console::printDot(24, 19, LIGHTGRAY);
    Console::printDot(24, 20, LIGHTGRAY);
    Console::printDot(25, 18, LIGHTGRAY);
    Console::printDot(26, 18, LIGHTGRAY);
    Console::printDot(26, 17, LIGHTGRAY);
    Console::printDot(26, 16, LIGHTGRAY);
    // c
    Console::printDot(30, 16, LIGHTGRAY);
    Console::printDot(31, 16, LIGHTGRAY);
    Console::printDot(29, 17, LIGHTGRAY);
    Console::printDot(29, 18, LIGHTGRAY);
    Console::printDot(29, 19, LIGHTGRAY);
    Console::printDot(30, 20, LIGHTGRAY);
    Console::printDot(31, 20, LIGHTGRAY);
    // o
    Console::printDot(35, 16, LIGHTGRAY);
    Console::printDot(36, 16, LIGHTGRAY);
    Console::printDot(34, 17, LIGHTGRAY);
    Console::printDot(34, 18, LIGHTGRAY);
    Console::printDot(34, 19, LIGHTGRAY);
    Console::printDot(35, 20, LIGHTGRAY);
    Console::printDot(36, 20, LIGHTGRAY);
    Console::printDot(37, 19, LIGHTGRAY);
    Console::printDot(37, 18, LIGHTGRAY);
    Console::printDot(37, 17, LIGHTGRAY);
    // o
    Console::printDot(41, 16, LIGHTGRAY);
    Console::printDot(42, 16, LIGHTGRAY);
    Console::printDot(40, 17, LIGHTGRAY);
    Console::printDot(40, 18, LIGHTGRAY);
    Console::printDot(40, 19, LIGHTGRAY);
    Console::printDot(41, 20, LIGHTGRAY);
    Console::printDot(42, 20, LIGHTGRAY);
    Console::printDot(43, 19, LIGHTGRAY);
    Console::printDot(43, 18, LIGHTGRAY);
    Console::printDot(43, 17, LIGHTGRAY);
    // n
    for (int i = 16; i < 21; i++)
        Console::printDot(46, i, LIGHTGRAY);
    Console::printDot(47, 17, LIGHTGRAY);
    Console::printDot(48, 18, LIGHTGRAY);
    Console::printDot(49, 19, LIGHTGRAY);
    Console::printDot(50, 20, LIGHTGRAY);
    for (int i = 16; i < 21; i++)
        Console::printDot(50, i, LIGHTGRAY);

    Console::gotoEnd();
}

void Page::login() {
    frame();

    // i
    for (int i = 8; i < 12; i++)
        Console::printDot(14, i, LIGHTBLUE);
    for (int i = 12; i < 17; i++)
        Console::printDot(i, 8, LIGHTBLUE);
    for (int i = 12; i < 17; i++)
        Console::printDot(i, 11, LIGHTBLUE);
    // d
    for (int i = 8; i < 12; i++)
        Console::printDot(21, i, LIGHTBLUE);
    Console::printDot(22, 8, LIGHTBLUE);
    Console::printDot(23, 8, LIGHTBLUE);
    Console::printDot(24, 9, LIGHTBLUE);
    Console::printDot(24, 10, LIGHTBLUE);
    Console::printDot(23, 11, LIGHTBLUE);
    Console::printDot(22, 11, LIGHTBLUE);

    // p
    for (int i = 14; i < 18; i++)
        Console::printDot(12, i, LIGHTBLUE);
    Console::printDot(13, 14, LIGHTBLUE);
    Console::printDot(14, 14, LIGHTBLUE);
    Console::printDot(15, 15, LIGHTBLUE);
    Console::printDot(14, 16, LIGHTBLUE);
    Console::printDot(13, 16, LIGHTBLUE);
    // w
    Console::printDot(17, 14, LIGHTBLUE);
    Console::printDot(17, 15, LIGHTBLUE);
    Console::printDot(18, 16, LIGHTBLUE);
    Console::printDot(19, 17, LIGHTBLUE);
    Console::printDot(20, 16, LIGHTBLUE);
    Console::printDot(21, 15, LIGHTBLUE);
    Console::printDot(22, 16, LIGHTBLUE);
    Console::printDot(23, 17, LIGHTBLUE);
    Console::printDot(24, 16, LIGHTBLUE);
    Console::printDot(25, 15, LIGHTBLUE);
    Console::printDot(25, 14, LIGHTBLUE);

    for (int i = 30; i < 50; i++) {
        Console::printDot(i, 11, GRAY);
        Console::printDot(i, 17, GRAY);
    }

    // sign up | login
    Console::gotoXY(14, 22);
    Console::setBackground(LIGHTGRAY);
    Console::printColorString("SIGN UP", LIGHTMAGENTA);
    Console::gotoXY(33, 22);
    Console::setBackground(LIGHTGRAY);
    Console::printColorString("/", LIGHTMAGENTA);
    Console::gotoXY(46, 22);
    Console::setBackground(LIGHTGRAY);
    Console::printColorString("LOGIN", LIGHTMAGENTA);

    Console::gotoEnd();
}

// void Page::signUp() {}

void Page::mainPage() {
    frame();

    // STORE
    for (int i = 50; i < 53; i++) {
        Console::printDot(i, 9, LIGHTGREEN);
        Console::printDot(i, 8, LIGHTGREEN);
    }
    Console::printDot(53, 9, GRAY);
    Console::printDot(54, 9, GRAY);
    Console::printDot(53, 8, GRAY);
    Console::printDot(54, 8, GRAY);
    for (int i = 55; i < 58; i++) {
        Console::printDot(i, 9, LIGHTGREEN);
        Console::printDot(i, 8, LIGHTGREEN);
    }
    for (int i = 50; i < 58; i++) {
        Console::printDot(i, 7, LIGHTGREEN);
        Console::printDot(i, 4, LIGHTRED);
    }
    for (int i = 48; i < 60; i++)
        Console::printDot(i, 6, LIGHTRED);
    for (int i = 49; i < 59; i++)
        Console::printDot(i, 5, LIGHTYELLOW);
    Console::gotoXY(50, 10);
    Console::setBackground(LIGHTGRAY);
    Console::printColorString("  STORE", GREEN);

    Console::gotoEnd();
}
