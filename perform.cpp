#include "perform.hpp"
#include "console.hpp"
#include <fcntl.h>
#include <iostream>
#include <pwd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <user.hpp>

using namespace std;
using namespace Perform;

#define PERMS 0755

Data::Data() {

    struct passwd *info;

    if (((info = getpwuid(getuid())) == NULL)) {
        perror("getpwuid() error!");
        exit(-1);
    }

    dataPath = "/home/";
    dataPath += info->pw_name;
    dataPath += "/Data/";

    if (access(dataPath.c_str(), F_OK) == -1) {
        //폴더가 존재하지 않을시;
        if (mkdir(dataPath.c_str(), PERMS) == -1) {
            perror("mkdir() error!");
            exit(-2);
        }
    }
}

bool Data::signUp() {
    string id;
    string pw;
    string pwPath;

    int fd = 0;
    ssize_t wsize;

    while (1) {
        cout << "ID : ";
        id = dataPath;
        id += Console::input();

        if (mkdir(id.c_str(), PERMS) == -1) {
            cout << "already exiting id";
        } else {
            break;
        }
    }

    cout << "PW : ";
    pw = Console::input(1);
    pwPath = id + "/pw.dat";

    fd = open(pwPath.c_str(), O_CREAT | O_WRONLY, PERMS);
    if (fd == -1) {
        cout << "Sign Up error please Retry";
        perror("open() error!");
        rmdir(id.c_str());
        return false;
    }

    wsize = write(fd, (char *)pw.c_str(), pw.length());

    close(fd);

    if (wsize == -1) {
        cout << "Sign Up error please Retry";
        perror("write() error!");
        remove(pwPath.c_str());
        rmdir(id.c_str());
        return false;
    }

    return true;
}

bool Data::signIn() {
    string id;
    string pw;
    string originPw;
    string pwPath;
    char *temp;
    int pwCount = 1;

    int fd = 0;
    struct stat fileinfo;

    // 아이디 입력
    while (1) {
        cout << "ID : ";
        id = dataPath;
        id += Console::input();

        if (access(dataPath.c_str(), F_OK) != -1) {
            //폴더가 존재할떄
            break;
        }
    }

    //비밀번호 불러오기;

    pwPath = id + "/pw.dat";
    fd = open(pwPath.c_str(), O_RDONLY);

    if (fd == -1) {
        cout << "Sign In error please Retry";
        perror("open() error!");
        return false;
    }

    if (fstat(fd, &fileinfo) == -1) {
        cout << "Sign In error please Retry";
        perror("fstat() error!");
        return false;
    }

    temp = (char *)malloc(fileinfo.st_size);
    if (read(fd, (char *)temp, fileinfo.st_size) == -1) {
        cout << "Sign In error please Retry";
        perror("read() error!");
        return false;
    }
    originPw = temp;
    close(fd);

    //비밀번호 입력
    while (1) {
        if (pwCount > 5)
            return false;

        cout << "PW : ";
        pw = Console::input(1);

        if (pw == originPw)
            break;
    }

    return true;
}

// Constructor
Store::Store() {
    int cursor; // 커서값이 있다고 생각하자
    printItem(level);
}

//상점 품목 표시
//커서 첫 위치 조정해야함
int Store::printItem(int level) {
    menu1 = access(path_menu1, F_OK);
    menu2 = access(path_menu2, F_OK);
    menu3 = access(path_menu3, F_OK);
    menu4 = access(path_menu4, F_OK);

    if (menu1 == -1) { //구매기록없음
        if (level >= lev_menu1) {
            cout << "          1. 홍차" << endl;
        } else {
            cout << "[Locked]  1. 홍차 " << endl;
        }
    } else { // 구매기록 있음
        cout << " [Owned]  1. 홍차 " << endl;
    }
    cout << endl;

    if (menu2 == -1) { //구매기록없음
        if (level >= lev_menu2) {
            cout << "          2. 레몬 에이드" << endl;
        } else {
            cout << "[Locked]  2. 레몬 에이드 " << endl;
        }
    } else { // 구매기록 있음
        cout << " [Owned]  2. 레몬 에이드 " << endl;
    }
    cout << endl;

    if (menu3 == -1) { //구매기록없음
        if (level >= lev_menu3) {
            cout << "          3. 카페모카" << endl;
        } else {
            cout << "[Locked]  3. 카페모카 " << endl;
        }
    } else { // 구매기록 있음
        cout << " [Owned]  3. 카페모카 " << endl;
    }
    cout << endl;

    if (menu4 == -1) { //구매기록없음
        if (level >= lev_menu4) {
            cout << "          4. 카라멜 마키야또" << endl;
        } else {
            cout << "[Locked]  4. 카라멜 마키야또" << endl;
        }
    } else { // 구매기록 있음
        cout << " [Owned]  4. 카라멜 마키야또" << endl;
    }
    cout << endl;

    return 0;
}

int Store::buyItem(int cursor) {
    // 레시피를 소유하고 있지 않음
    switch (cursor) {
    case 1:
        if (level >= lev_menu1 && money >= cost_menu1) {
            cout << "해당 레시피를 구매하시겠습니까? 잔액에서" << cost_menu1
                 << "원이 차감됩니다." << endl;
            cout << "구매하시려면 Enter 자판을 눌러주세요. 아니라면  왼쪽 "
                    "방향키를 눌러주세요."
                 << endl;
            switch (cursor) {
                int fd = 0;
            case "Enter": //엔터키가 눌렸을 때
                fd = open(path_menu1, O_RDWR | O_CREAT);
                if (fd == -1) {
                    perror("file open() error!");
                    exit(-1);
                }
                close(fd);
                cout << "구매가 완료되었습니다." << endl;

            case "왼쪽": // 왼쪽 방향키가 눌렸을 때
                printItem(level);
            }
        } else {
            cout << "구매 조건이 충족되지 않았습니다. 상점 초기 화면으로 "
                    "돌아갑니다."
                 << endl;
            printItem(level);
        }
        break;
    case 2:
        if (level >= lev_menu2 && money >= cost_menu2) {
            cout << "해당 레시피를 구매하시겠습니까? 잔액에서" << cost_menu1
                 << "원이 차감됩니다." << endl;
            cout << "구매하시려면 Enter 자판을 눌러주세요. 아니라면 방향키를 "
                    "눌러주세요."
                 << endl;
            switch (cursor) {
                int fd = 0;
            case "Enter": //엔터키가 눌렸을 때
                fd = open(path_menu2, O_RDWR | O_CREAT);
                if (fd == -1) {
                    perror("file open() error!");
                    exit(-1);
                }
                close(fd);
                cout << "구매가 완료되었습니다." << endl;

            case "왼쪽": // 왼쪽 방향키가 눌렸을 때
                printItem(level);
            }
        } else {
            cout << "구매 조건이 충족되지 않았습니다. 상점 초기 화면으로 "
                    "돌아갑니다."
                 << endl;
            printItem(level);
        }
        break;
    case 3:
        if (level >= lev_menu3 && money >= cost_menu3) {
            cout << "해당 레시피를 구매하시겠습니까? 잔액에서" << cost_menu1
                 << "원이 차감됩니다." << endl;
            cout << "구매하시려면 Enter 자판을 눌러주세요. 아니라면 방향키를 "
                    "눌러주세요."
                 << endl;
            switch (cursor) {
                int fd = 0;
            case "Enter": //엔터키가 눌렸을 때
                fd = open(path_menu3, O_RDWR | O_CREAT);
                if (fd == -1) {
                    perror("file open() error!");
                    exit(-1);
                }
                close(fd);
                cout << "구매가 완료되었습니다." << endl;

            case "왼쪽": // 왼쪽 방향키가 눌렸을 때
                printItem(level);
            }
        } else {
            cout << "구매 조건이 충족되지 않았습니다. 상점 초기 화면으로 "
                    "돌아갑니다."
                 << endl;
            printItem(level);
        }
        break;
    case 4:
        if (level >= lev_menu3 && money >= cost_menu3) {
            cout << "해당 레시피를 구매하시겠습니까? 잔액에서" << cost_menu1
                 << "원이 차감됩니다." << endl;
            cout << "구매하시려면 Enter 자판을 눌러주세요. 아니라면 방향키를 "
                    "눌러주세요."
                 << endl;
            switch (cursor) {
                int fd = 0;
            case "Enter": //엔터키가 눌렸을 때
                fd = open(path_menu4, O_RDWR | O_CREAT);
                if (fd == -1) {
                    perror("file open() error!");
                    exit(-1);
                }
                close(fd);
                cout << "구매가 완료되었습니다." << endl;

            case "왼쪽": // 왼쪽 방향키가 눌렸을 때
                printItem(level);
            }
        } else {
            cout << "구매 조건이 충족되지 않았습니다. 상점 초기 화면으로 "
                    "돌아갑니다."
                 << endl;
            printItem(level);
        }
        break;
    }
    // 샀다는 거 반환해야함 (벡터나 배열에 넣어주자) -> 깃허브 CafeTycoon에
    // 올라온 User 파일을 보았더니 recipe라는 벡터로 저장하는 것으로 보였으나 왜
    // 길이가 2이지,,? 라는 생각이 들어서 어떻게 쓰려고 만든 벡터인지 모르겠음
    // 다시 display 함수 호출해야하는지 첫화면으로 돌아가는지 모르겠음
}
