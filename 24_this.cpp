// 24_this.cpp

#include <iostream>
using namespace std;

// 멤버 함수는 오직 한개만 만들어집니다.
// => 멤버 함수는 어떤 객체로부터 호출되었는지 알 수 있어야 합니다.
//  : 모든 멤버 함수는 this를 통해서 어떤 객체로부터 호출되었는지 알 수 있다.
//    thiscall

class Point {
public:

  // 컴파일러가 작성한 코드
  //  => 어떤 객체가 함수를 호출했는지 알 수 있도록, 전달되는 객체의 주소
  #if 0
  void set(Point* const this, int a, int b) {
    this->x = a;
    this->y = y;
  }
  #endif

  // 사용자가 작성한 코드
  void set(int a, int b) {
    x = a;
    y = b;
  }
private:
  int x;
  int y;
};


#if 0
  void set(Point* const this, int a, int b) {
    this->x = a;
    this->y = y;
  }
#endif

int main() {
  Point p1;
  Point p2;

  p1.set(10, 20);   // 컴파일러: set(&p1, 10, 20);
  p2.set(20, 30);   // 컴파일러: set(&p2, 20, 30);
}