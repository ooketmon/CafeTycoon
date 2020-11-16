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

<<<<<<< HEAD
// Pseudo Code
// signUp
// if(회원가입 선택)
// {
//    signUp 실행
// }

// signUp () {
//     cout << "아이디 입력하세요" << endl;
//     cin >> userID >> endl;
//     cout << "비밀 번호 입력하세요" << endl;
//     cin >> userPW >> endl;
//     cout << "비밀 번호 다시 입력하세요(확인용)" << endl;
//     cin >> userPW1 >> endl;
//     //비밀번호 확인
//     if (userPW != userPW1) {
//         cout << "비밀번호가 일치하지 않습니다. 첫 단계로 돌아갑니다." < endl;
//         signUp
//     }
//     디렉토리 User 생성 -> 공유 사능하도록 권한 부여
//     txt 파일 이름 -> 아이디
//     내용 -> 비밀번호
// }

// signIn {
//     1. 아이디 입력 받음
//     2. 비밀번호 입력받음
//     ==============
//     아이디가 디렉토리 User 내의 txt 파일로 존재하는지 검사
//     있다면 - > 비밀번호 txt 파일 내의 정보랑 맞는지 확인
//          -> 맞다면 : 다음 화면으로 넘어감
//          -> 틀리다면 경고문 출력 -> signIn 다시
//     없다면 -> 경고문 출력
// }

=======
>>>>>>> 7b7566a9dc7611982af6cf6fcde508118f7a4228
#endif
