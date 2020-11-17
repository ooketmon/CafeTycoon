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
    bool signUp();
    bool signIn();
};
} // namespace Perform

#endif //__PERFORM_HPP__
