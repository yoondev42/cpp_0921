
#include <iostream>
using namespace std;

// 어떤 함수가 객체를 리턴할 때
// 1. 값 타입으로 반환하면 임시 객체가 생성되어서 반환합니다.
// 2. 참조 타입으로 반환하면 임시 객체가 생성되지 않습니다.

class Point {
public:
  int x;
  int y;
};


// 아래처럼 사용하면 안됩니다!
Point& goo() {
  Point p;          // 지역 객체는 함수가 종료되는 시점에 파괴됩니다. 파괴되는 메모리에 참조를 통해 접근할 경우, 미정의 동작이 발생합니다.
  return p;
}

// 아래처럼 만들었을 경우, 임시 객체가 생성됩니다.
// => 아래 코드를 임시 객체를 반환하는 형태로 사용하면, 불필요한 임시 객체의 생성을 컴파일러가 최적화해줍니다. - RVO
// => 클래스이름() 의 문법을 통해 임시객체를 생성할 수 있습니다.
// => 최신 컴파일러는 이름을 부여한 객체에 대해서도 최적화가 가능합니다 - NRVO
Point foo() {
  Point p;
  return p;

  // return Point();
}

int main() {

}


#if 0
Point p;  // p는 전역 객체입니다.

Point foo() { return p; }
Point& goo() { return p; }

int main() {
  // foo().x = 10;  // error! - 임시 객체에 값을 할당하는 것이 불가능합니다.
  goo().x = 10;     // ok!
                    // 임시 객체가 아니라 전역 객체 p에 대한 참조 입니다.
}
#endif