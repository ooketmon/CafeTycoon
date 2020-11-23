#ifndef __PERFORM_HPP__
#define __PERFORM_HPP__

#include "user.hpp"
#include <string>
#include <vector>

using namespace std;

class Data {
  private:
    string username;
    string dataPath;

  public:
    Data();
    bool signUp(); //회원가입
    bool signIn(); //로그인
};

void gameover(int signum);
void *showTime(void *);

struct __MSG {
    long type;
    int data[2];
};
typedef struct __MSG Msg;

class Game {
  private:
    enum RECIPE {
        americano = 12,
        cafeLattee = 22,
        blackTea = 1010,
        cafeMocha = 122,
        lemonade = 2250,
        caramelMacchiato = 5522,
    };

    enum INGERDIENTS {
        shot1 = 1,
        shot2 = 2,
        shot3 = 3,
        water = 10,
        milk = 20,
        sparklingWater = 50,
        mochaSyrup = 100,
        lemonSyrup = 200,
        caramelSyrup = 500,
        blackTeaBag = 1000,
        ice = 2000,
        caramelDrizzle = 5000
    };

  public:
    // Game();
    void start(User &user);
};

#endif //__PERFORM_HPP__
