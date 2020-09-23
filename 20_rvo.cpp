
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

Point p;  // p는 전역 객체입니다.

// Point foo() { return p; }
Point& foo() { return p; }

int main() {
  foo().x = 10;  // error! - 임시 객체에 값을 할당하는 것이 불가능합니다.
}