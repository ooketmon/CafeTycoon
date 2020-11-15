#include "perform.hpp"
#include "console.hpp"
#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;
using namespace Perform;

#define PATH "~/cafeTycon/Data"
#define PERMS 0755

void Data::checkData() {
    if (access(PATH, F_OK) == -1) {
        //폴더가 존재하지 않을시;
        if (mkdir(PATH, 0755)) {
            perror("mkdir() error!");
            exit(-2);
        }
    }
}

bool signUp() {
    string id, pw;
    cout << "ID : ";
    Console::input();
}
