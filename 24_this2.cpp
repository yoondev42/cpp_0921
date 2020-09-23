// 24_this2.cpp
// 객체의 주소를 나타내는 this는 다양한 활용이 있습니다.
//  1) 이름 충돌시 멤버 변수에 접근하기 위해서 사용합니다.
//     ex) this->x = x;
//  2) this 반환 기법
#include <iostream>
using namespace std;
class Point {
public:
  // 인자가 멤버 변수의 이름과 동일할 경우, 멤버 변수가 가려진다. (Shadowing)
  // => 초기화 리스트에서 this에 접근할 수 없습니다.
  // Point(int x, int y) : this->x(x), this->y(y) {  - error!

  // Point(int x, int y) {
  //   this->x = x;
  //   this->y = y;
  // }
  Point(int x, int y) : x_(x), y_(y) {
  }

#if 0
  void move(int dx, int dy) {
    x_ += dx;
    y_ += dy;
  }
#endif
  Point* move(int dx, int dy) {
    x_ += dx;
    y_ += dy;

    return this;
  }

  Point& move2(int dx, int dy) {
    x_ += dx;
    y_ += dy;

    return *this;
  }

private:
  // C++ 표준에서 멤버 데이터의 이름 규칙입니다.
  int x_;
  int y_;

  // ex) int m_X; mX ...
};

int main() {
  Point p(10, 20);

  // void move(...)
  p.move(10, 20);
  p.move(10, 20);
  p.move(10, 20);
  p.move(10, 20);

  // 연속 호출이 가능합니다.
  // this를 반환하는 경우
  p.move(10, 20)->move(10, 20)->move(10, 20)->move(10, 20);

  // *this를 반환하는 경우
  p.move2(10, 20).move2(10, 20).move2(10, 20).move2(10, 20);

  // <<: 함수 호출
  cout << "a" << "b" << "c" << "d" << endl;
}