// 22_static2.cpp
#include <iostream>
using namespace std;


// 일반 멤버 변수(데이터) / 함수
// => 필드(데이터) / 메소드(method)

// 정적 멤버 변수(데이터) / 정적 멤버 함수
// => 클래스 필드(변수, 데이터) / 메소드

class User {
  int data = 0;           // C++11, field initialization

  // static int data2 = 0;
  // => 정적 멤버 데이터에 대한 초기화는 반드시 외부 정의를 통해 이루어져야 합니다.
  static int data2;

  // => 정적 멤버 데이터에 대해서 필드 초기화를 허용하는 경우
  // static const int data3 = 42;
  static constexpr int data3 = 42;
};

// 구현 파일(.cpp) / static 제외
int User::data2 = 0; // !!

int main() {

}

#if 0
// - 정적 멤버 함수
// => 클래스의 일반 멤버 데이터에 접근하는 것이 불가능합니다.

// - 일반 멤버 함수
// => 자신의 멤버 데이터에 접근도 할 수 있고, 정적 멤버 데이터에 접근도 가능하다.

class User {
public:
  void goo() {
    data = 0;
    cnt = 0;
  }

  static void foo() {
    // 정적 멤버 함수에서 정적 멤버 변수의 접근은 문제가 없습니다.
    cnt = 0;  
    
    // 일반 멤버 변수에 접근할 수 있을까요?
    // data = 0;
    // compile error!
  }

private:
  int data;
  static int cnt;
};

int User::cnt = 0;

int main() {

}
#endif