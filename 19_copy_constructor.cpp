#include <iostream>
using namespace std;
// 19_copy_constructor.cpp
//   복사 생성자
//  1) 객체를 만들 때 자신의 타입으로 초기화하는 경우
//  2) 객체를 call by value로 사용할 경우
//  3) 함수가 객체를 값으로 반환할 경우

// 복사 생성자가 언제 호출되는가?
class User {
public:
  User() { cout << "User()" << endl; }
  User(const User&) { cout << "User(const User&)" << endl; }
  ~User() { cout << "~User()" << endl; }
};


User p;   // 전역 객체

// RVO - 값으로 반환을 해도, 불필요한 임시 객체 생성을 하지 않는다.
User foo() {
  return p;
}

// User()  - 전역 객체 생성자
// User(const User&) - 반환 객체(임시 객체) 복사 생성자를 통해 생성
// User(const User&)
// ~User()
// ~User()           - 임시 객체가 파괴된다.
// ~User() - 전역 객체 소멸자


// 1. User& foo() {}
// User()
// User(const User&)
// ~User()
// ~User()

// 2. User foo() {}
// User()
// User(const User&)
// ~User()
// ~User()

int main() {
  User u = foo();
}


// Call by value
//  1. 복사본에 추가적인 메모리 할당
//  2. 복사 생성자, 소멸자에 호출에 따른 성능 저하
// void foo(User user) {
// }
#if 0
void foo(const User& user) {
}

int main() {
  User user;  // User()
  foo(user);  // User(const User&)
              // ~User()
              // ~User()
}
#endif


#if 0
int main() {
  User u1;      // 기본 생성자
  
  User u2(u1);  // 복사 생성자
  User u3 = u1; // 복사 생성자

  User u4{u1};  // 복사 생성자
  User u5 = {u1}; // 복사 생성자
}
#endif








// 사용자가 생성자를 제공하지 않을 경우
// 1. 복사 생성자
// 2. 기본 생성자

// 사용자가 생성자를 한개라도 제공한 경우 - Point(int a, int b)
//  => 복사 생성자는 생성됩니다.

// 사용자가 복사 생성자만 제공한 경우
//  => 기본 생성자 X, 복사 생성자 X

#if 0
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
#endif