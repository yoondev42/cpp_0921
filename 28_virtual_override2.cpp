
#include <iostream>
using namespace std;

// C++11

class Base {
public:
  virtual void f1() {}
  virtual void ff2() {}
};

class Derived : public Base {
public:
  // 실수! f1, f2를 오버라이딩 하고자 했지만, 오타가 발생했다.
  //  => 의도하지 않은 오류가 발생할 수 있습니다.

  //  C++11에서 해당 멤버 함수가 부모의 함수를 재정의하였다. 라는 의도를 코드로 표현할 수 있습니다.
  //  => 컴파일 타임에 잘못된 오버라이딩을 감지할 수 있다.
  //  => override
  //    : 가상함수를 재정의할 때 부모의 동일 이름의 가상함수가 존재하지 않을 경우, 컴파일 오류가 발생합니다.
  //      사용하지 않아도, 컴파일 오류는 없지만, 쓰는 것이 좋습니다!
  virtual void ff1() {} // OK!
  virtual void ff2() override {}  // Error!
};

int main() {

}