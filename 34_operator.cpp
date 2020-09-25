// 34_operator.cpp
// => C++언어의 핵심 기능
// => 연산자 오버로딩에 대해서 정확하게 이해해야 합니다.
#include <iostream>
#include <string>
using namespace std;

// 연산자 오버로딩
// "사용자 정의 타입도 표준 타입처럼 동작해야 한다."
// => 연산자 오버로딩의 원리
//    ; 특정 연산자를 사용하였을 경우, 호출되는 함수를 정의하면 된다.

// 1. 외부 함수 버전
#if 0
class Point {
public:
  Point(int a, int b) : x(a), y(b) {}

  friend Point operator+(const Point& lhs, const Point& rhs);  
private:
  int x;
  int y;
};

// 연산자 재정의 함수
Point operator+(const Point& lhs, const Point& rhs) {
  Point ret(lhs.x + rhs.x, lhs.y + rhs.y);
  return ret;
}
#endif

// 2. 멤버 함수 버전
class Point {
public:
  Point(int a, int b) : x(a), y(b) {}

  // 멤버 함수
  // - 첫번째 인자: 암묵적으로 this를 통해 전달된다.
  Point operator+(const Point& rhs) {
    return Point(x + rhs.x, y + rhs.y);
  }
private:
  int x;
  int y;
};

// 연산자 오버로딩의 결과로 멤버 데이터의 변경이 필요하지 않다면,
// 일반 함수 버전을 사용하는 경우가 많습니다.(절대적이지 않습니다.)

int main() {
  Point p1(1, 1);
  Point p2(2, 2);

  Point p3 = p1 + p2; // p1.operator+(p2);  - 멤버 함수 버전을 먼저 찾습니다.
                      // operator+(p1, p2); - 없다면, 함수 버전을 찾습니다.
                      
}



#if 0
int main() {
  int a = 10;
  int b = 20;

  int c = a + b;
  cout << c << endl;

  string s1 = "hello";
  string s2 = "world";
  string s3 = s1 + s2;

  cout << s3 << endl;
}
#endif
