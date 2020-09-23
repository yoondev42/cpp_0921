#include <iostream>
using namespace std;
// 23_const_member_function
// => 상수 멤버 함수

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

// private:
  int x;
  int y;
};

// 상수 멤버 함수는 왜 필요한가?
int main() {
  // const int x = 10;

  const Point p(10, 20);  // 상수 객체
  // p.x = 20;
  // 1) 상수 객체는 멤버 데이터의 변경이 불가능합니다.
  cout << p.x << endl;

  
  // p.x = 30;
}