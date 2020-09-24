// 27_virtual.cpp
#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
  string name;
  int age;
};

class Dog : public Animal {
public:
  int color;
};

class Cat : public Animal {
public:
};

// Downcasting: 부모의 포인터 타입을 자식의 포인터 타입으로 변경하는 것
int main() {
  Dog d;
  Animal* p = &d;

  p->age = 42;  // OK! - 부모의 속성입니다.
  
  p->color = 100; // error!


}


// Upcasting: 자식의 주소를 부모의 포인터를 통해 참조하는 것
#if 0
//   Base
//    |
//  Derived
// : 부모 클래스와 자식 클래스는 is-a 관계가 성립한다.
// => Derived is a Base
//  = Dog is a Animal

int main() {
  Dog d;
  Cat c;
  
  Animal* p = &d;
  p = &c;
  
  // 자식 객체의 주소를 부모 타입의 포인터를 통해 참조하는 것은 암묵적으로 허용한다.
  //  => Upcasting
}
#endif