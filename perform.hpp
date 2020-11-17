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
} // namespace Perform

#endif //__PERFORM_HPP__
