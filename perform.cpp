#include "perform.hpp"
#include "console.hpp"
#include <fcntl.h>
#include <iostream>
#include <pwd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

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
        perror("creat() error!");
        rmdir(id.c_str());
        return false;
    }

    wsize = write(fd, (char *)pw.c_str(), pw.length());

    close(fd);

    if (wsize == -1) {
        cout << "Sign Up error please Retry";
        perror("open() error!");
        remove(pwPath.c_str());
        rmdir(id.c_str());
        return false;
    }

    return true;
}

bool Data::signIn() {
    string id;
    string pw;
    string pwPath;

    int fd = 0;
    ssize_t wsize;

    while (1) {
        cout << "ID : ";
        id = dataPath;
        id += Console::input();

        if (access(dataPath.c_str(), F_OK) != -1) {
            //폴더가 존재할떄
            cout << "PW : ";
            pw = Console::input(1);
            pwPath = id + "/pw.dat";

            fd = open(pwPath.c_str(), O_WRONLY, PERMS);

            if (fd != -1) {
                cout << "Sign Up error please Retry";
                perror("open() error!");
                rmdir(id.c_str());
                return false;
            }

        }
    }

    wsize = write(fd, (char *)pw.c_str(), pw.length());

    close(fd);

    if (wsize == -1) {
        cout << "Sign Up error please Retry";
        perror("creat() error!");
        remove(pwPath.c_str());
        rmdir(id.c_str());
        return false;
    }

    return true;
}
