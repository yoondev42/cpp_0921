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
  //  => 멤버 함수는 this가 암묵적으로 전달된다.
  #if 0
  void set(Point* const this, int a, int b) {
    this->x = a;
    this->y = y;
  }
  #endif

  // 사용자가 작성한 코드
  void set(int a, int b) {
    this->x = a;
    this->y = b;
  }

  // 정적 멤버 함수는 멤버 변수에 접근이 불가능하다.
  // => this가 전달되지 않는다.
  static void foo() {

  }

  void print() {
    cout << "print: " << this << endl;
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

  cout << &p1 << endl;
  p1.print();



  Point p2;

  p1.set(10, 20);   // 컴파일러: set(&p1, 10, 20);
  p2.set(20, 30);   // 컴파일러: set(&p2, 20, 30);
}

#if 0
#include <stdio.h>

class User {
public:
	// thiscall
	// void f1(User* const this) {}
	void f1() { printf("f1\n"); }

	void f2(int a) { printf("f2: %d\n", a); }

	void f3(int a) { printf("f3: %d %d\n", a, data); }
	//                                        // this->data

private:
	int data;
};

int main() {
	User* p = nullptr;

	p->f1();  // f1(p); -> f1(NULL);
	p->f2(1);

	p->f3(1);
}
#endif

