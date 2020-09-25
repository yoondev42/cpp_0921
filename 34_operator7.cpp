#include <iostream>
using namespace std;

// 1. 복사 생성자를 제공하지 않을 경우, 컴파일러는 자동으로 복사 생성자를 제공한다.
//   => 멤버에 대한 복사만 수행한다.
// 2. 대입 연산자를 제공하지 않을 경우, 컴파일러는 자동으로 대입 연산자를 제공한다.

class Point {
public:
  Point(int a = 0, int b = 0) : x(a), y(b) {}

  Point(const Point& rhs) : x(rhs.x), y(rhs.y) {
    cout << "Point(const Point& rhs)" << endl;
  }

  // 대입 연산자는 자기 자신의 대한 참조를 반환해야 한다.
  // 그래야 연쇄적으로 대입 연산을 수행할 수 있다.
  Point& operator=(const Point& rhs) {
    x = rhs.x;
    y = rhs.y;
    cout << "operator=(const Point& rhs)" << endl;

    return *this;
  }

private:
  int x, y;
};

int main() {
  Point p1(10, 20);
  Point p2 = p1;      // Point(const Point&)

  Point p3;
  p3 = p1;            // 대입 연산자가 호출된다.

  p3 = p2 = p1; // 대입 연산은 연쇄 호출이 가능해야 한다.
  // p2 = p1 => p2
  // p2.operator=(p2) -> p2
  // p3.operator=(p2) -> p3

}


#if 0
int main() {
  int a = 10;  // 초기화(복사 생성자)

  int b;
  b = 10;      // 대입(대입 연산자)
}
#endif