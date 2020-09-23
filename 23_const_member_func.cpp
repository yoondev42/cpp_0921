#include <iostream>
using namespace std;
// 23_const_member_function
// => 상수 멤버 함수
//   1) 상수 멤버 함수 안에서는 모든 멤버 데이터는 상수 취급된다.
//   2) 동일한 이름으로 상수 멤버 함수와 비상수 멤버 함수를 동시에 제공하는 것이 가능합니다.

class Point {
public:
  const int* get_address_x() const {
    return &x;
  }
  // const int x;
  //  : 반환 타입을 int*가 아니라 const int* 로 해야합니다.
  
  void foo() {             // 1
    cout << "foo" << endl;
  }

  void foo() const {       // 2
    cout << "foo-const" << endl;
  }

  void goo() const;

private:
  int x;
};

// 상수 멤버 함수를 외부 정의할 때는 반드시 const를 명시해야 합니다.
void Point::goo() const {

}

int main() {
  Point p;
  p.foo();      // 1

  const Point& r = p;
  r.foo();     //  2

  const Point p2 = Point();
  p2.foo();    // 2
}


#if 0
class Point {
public:
  Point(int a, int b) : x(a), y(b) {
  }

  // 아래 멤버 함수와 같이, 멤버 변수의 값을 변경하지 않는 멤버 함수를 상수 멤버 함수로 만들 수 있습니다.
  void print() const {
    // x = 10;
    // error!
    //  => 상수 멤버 함수에서는 모든 멤버 데이터를 상수로 취급합니다.

    cout << x << ", " << y << endl;
  }

  void set(int a, int b) {
    x = a;
    y = b;
  }

private:
  int x;
  int y;
};

class Rect {
public:
  Rect(int a = 0, int b = 0, int c = 0, int d = 0)
   : x(a), y(b), w(c), h(d) {}

  int getArea() const {
    return w * h;
  }

private:
  int x, y, w, h;
};

void printArea(const Rect& r) {
  cout << r.getArea() << endl;
  // const&로 참조되는 객체에 대해서, 오직 상수 멤버 함수만 호출 가능하다.
}

int main() {
  Rect r(0, 0, 100, 30);
  // cout << r.getArea() << endl;
  printArea(r);
}
#endif


// 상수 멤버 함수는 왜 필요한가?
//  1) 상수 객체는 오직 상수 멤버 함수만 호출 가능하다.
//  2) const& 참조되는 객체는 오직 '상수 멤버 함수'만 호출 가능하다.

#if 0
int main() {
  // const int x = 10;

  const Point p(10, 20);  // 상수 객체
  // p.x = 20;
  // 1) 상수 객체는 멤버 데이터의 변경이 불가능합니다.
  // 2) 상수 객체는 오직 상수 멤버 함수에 대해서만 호출 가능합니다.

  // p.set(10, 20);
  // cout << p.x << endl;
  p.print();

  
  // p.x = 30;
}
#endif