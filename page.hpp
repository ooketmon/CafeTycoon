#ifndef __PAGE_HPP__
#define __PAGE_HPP__

#include "console.hpp"
#include <stdlib.h>

class Page {
  private:
    int num;
    // 현재 페이지 : 0 - 메인화면, 1 - 로그인창
  public:
    void clear();
};

#endif
