// 31_abstract.cpp
#if 0
#include <iostream>
using namespace std;

// 순수 가상 함수를 한개 이상 가지고 있는 클래스를 추상 클래스(abstract class)라고 합니다.
// 1. 추상 클래스 타입은 인스턴스화가 불가능합니다.
//   - 객체 생성이 불가능합니다.

// 상속
// 1. 다형성을 구현하기 위함.
//    부모의 기능을 자식이 오버라이딩 함으로써, 부모의 포인터(참조) 타입을 통해 해당 기능을 이용하는 다형성을 구현하기 위함

// 2. 부모의 참조(포인터, 참조) 타입을 통해 자식 객체를 참조할 수 있다.
//    => 1개의 컨테이너를 통해 자식 객체를 보관하는 것이 가능하다.


// Java: abstract class Shape {}
class Shape {
  int x, y;
public:
  virtual ~Shape() {}

  // draw의 구현을 제공하지 않는다.
  // => 순수 가상 함수(pure virtual function)
  virtual void draw() = 0;
  // => 부모가 구현을 제공할 필요가 없고, 인스턴스화에 대한 필요도 없고, 자식이 반드시 해당 멤버 함수를 구현(오버라이딩)해야 한다면, 
  //     순수 가상함수로 만들면 좋다.
};

// 부모 추상 클래스가 제공하는 순수 가상 함수를 오버라이딩 하지 않으면(구현을 제공하지 않는다면)
// 자식 클래스도 추상 클래스가 된다.
class Rect : public Shape {
public:
  // 반드시 제공해야 합니다.
  void draw() override {
    cout << "Rect draw" << endl;
  }
};

int main() {
  // Shape s;
  Rect r;
}
#endif

/*
1) 함수의 크기는 0 인가요?
2) 함수의 작동원리에 대해서 간단히 설명 부탁드립니다.
*/
#if 0
class Animal {
  int a;
  int b;
public:
  void foo() {}
  // 1000개
};

// 함수
// 1. 함수의 메모리 사용량?
//   => 기계어 코드가 생성되는 만큼
//      '오버헤드'로 생각하지 않는다.

void foo() {
  cout << "foo" << endl;  
}
#endif


#if 0
int add(int a, int b) {
  return a + b;
}

int main()
{
  int c = add(10, 20);
}
#endif

