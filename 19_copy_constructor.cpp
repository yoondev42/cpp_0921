#include <iostream>
using namespace std;
// 19_copy_constructor.cpp
//   복사 생성자

// 사용자가 생성자를 제공하지 않을 경우
// 1. 복사 생성자
// 2. 기본 생성자

// 사용자가 생성자를 한개라도 제공한 경우 - Point(int a, int b)
//  => 복사 생성자는 생성됩니다.

// 사용자가 복사 생성자만 제공한 경우
//  => 기본 생성자 X, 복사 생성자 X

class Point {
public:
  // Point(): Point(0, 0) {}               // 1
  // Point(int a, int b) : x(a), y(b) {}   // 2

  // Default Parameter
  Point(int a = 0, int b = 0) : x(a), y(b) {}

  // 아래 형태가 복사 생성자 입니다.
  // => 사용자가 복사 생성자를 제공하면, 컴파일러는 제공하지 않습니다.
  // => 복사 생성자도 생성자이기 때문에, 초기화 리스트를 통해 초기화하는 것이 좋습니다.
  Point(const Point& p) : x(p.x), y(p.y) {
    cout << "Point(const Point&)" << endl;
  }

  void print() {
    cout << x << ", " << y << endl;
  }
private:
  int x;
  int y;
};

int main() {
  Point p1;         // 1
  Point p2(1, 2);   // 2

  // Point p3(42);     // error!
  Point p4(p2);
  // Point(Point)
  // 사용자가 만들지 않아도, 컴파일러가 자동으로 만들어주는 생성자를 사용합니다.
  // => 자신과 동일한 타입을 인자로 가지는 생성자 => '복사' 생성자
  //  : 컴파일러가 자동으로 생성하는 복사 생성자의 기본 동작은 각 멤버 변수를 동일한 값으로 복사합니다.

  p4.print();
}