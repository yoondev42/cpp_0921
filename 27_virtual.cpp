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