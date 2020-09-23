
// 18_initializer_list.cpp
//  초기화 리스트

class Point {
  Point(int a, int b) : x(a), y(b) {

  }

  Point() : x(0), y(0) {

  }

private:
  int x;
  int y;
};

int main() {
  Point p(10, 20);

  Point p2;
}



#if 0
// say hello

// naming convention
// 1. say_hello       => Unix, C, C++ 표준 라이브러리
// 2. sayHello        => Java
// 3. SayHello        => C#

// coding style - block
if (n > 0)
{

}

if (n > 0) {

}

#endif



#include <iostream>
using namespace std;

// C++에서 멤버 데이터를 초기화하는 방법.
// 1. 생성자의 함수 블록안에서 멤버 데이터를 초기화 - 대입
// 2. 생성자의 파라미터 리스트 뒤에 :을 적고, 멤버 데이터를 초기화하는 방법 - 초기화
//   => 초기화 리스트
//     1) 멤버 데이터가 상수인 경우
//     2) 멤버 데이터가 참조인 경우
//     3) 멤버 데이터 객체가 기본 생성자를 제공하지 않을 경우
//    : 위의 경우가 아니더라도, 멤버 데이터에 대한 초기화는 초기화리스트를 사용하는 것이 좋다.

class Point
{
public:
  // 아래 코드에서 초기화의 순서 => 멤버 데이터의 선언 순서를 따릅니다.
  //   : 초기화 리스트의 초기화 순서를 멤버 데이터의 순서로 작성하는 것이 관례입니다.
  // 1. y, x
  // 2. x, y
  Point(int a, int b) : x(a), y(b)
  {
  }

private:
  int x;
  int y;
};

class Rect {
public:
  // Point는 기본 생성자가 제공되고 있지 않기 때문에, 초기화리스트를 통한 명시적인 초기화가 필요합니다.
  Rect(): p1(10, 20) {

  }

  Rect(int x, int y): p1(x, y) {

  }

private:
  Point p1; //  = Point(10, 20);  // C++11 필드 초기화

  // Point p1 = Point(x, y);  
  // C++11 필드 초기화를 사용할 경우, 생성자의 인자에 대한 전달이 불가능하다.
};

int main() {
  Rect r;
}




#if 0
class Point {
public:
  // 방법 2. 초기화입니다.
  // Point(int a, int b): x(a), y(b) {

  //   // 방법 1. 대입입니다.
  //   x = a;
  //   y = b;
  // }

  Point(int a, int b): x(a), y(b) {
    // x = a;
    // y = b;
  }

private:
  const int x;  // 상수이므로, 초기화리스트 필요합니다.
  int& y;       // 참조이므로, 초기화리스트 필요합니다.
};

int main() {
  Point p(1, 2);

  // 초기화 - 객체를 만들면서, 값을 넣는 작업
  int a = 3;

  // 대입 - 객체를 만든 후에 값을 넣는 작업
  int a;
  a = 3;

  // 초기화가 반드시 필요한 경우
  // 1. 상수
  // const int n;
  // n = 30;
  const int n = 30;

  // 2. 참조
  // int& r;
  // r = a;
  int& r = a;
}
#endif