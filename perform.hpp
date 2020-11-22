#ifndef __PERFORM_HPP__
#define __PERFORM_HPP__

#include <string>

using namespace std;

namespace Perform {
class Data {
  private:
    string username;
    string dataPath;

  public:
    Data();
    bool signUp(); //회원가입
    bool signIn(); //로그인
};

class Store {
  private:
    int level = user.level; //사용자 레벨
    int money = user.money; //사용자 소유금액

    //구매여부 확인
    int menu1, menu2, menu3, menu4;

    //경로
    char *path_menu1 = "/home/id(???)/recipes/menu1"; //경로 수정해야함!!
    char *path_menu2 = "/home/id(???)/recipes/menu2";
    char *path_menu3 = "/home/id(???)/recipes/menu3";
    char *path_menu4 = "/home/id(???)/recipes/menu4";

    //레시피 가격
    int cost_menu1 = 1;
    int cost_menu2 = 2;
    int cost_menu3 = 3;
    int cost_menu4 = 4;

    //최소 레벨 조건
    int lev_menu1 = 2;
    int lev_menu2 = 3;
    int lev_menu3 = 4;
    int lev_menu4 = 5;

  public:
    Store();
    int printItem(int level);
    int buyItem(int cursor);
    int isMyItem(int cursor);
};

} // namespace Perform

#endif //__PERFORM_HPP__
