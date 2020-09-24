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
  long color;
};

class Cat : public Animal {
public:
  // std::string address;
  char* address;
};

// Downcasting: 부모의 포인터 타입을 자식의 포인터 타입으로 변경하는 것
int main() {
  Dog d;
  Cat c;
  c.address = new char[5];
  strcpy(c.address, "hello, world");

  Animal* p = &c;

  p->age = 42;  // OK! - 부모의 속성입니다.
  
  // p->color = 100; // error!
  // Dog* p2 = p;  // 부모 포인터 타입을 자식 포인터 타입으로 암묵적인 캐스팅은 허용하지 않는다.

  Dog* p2 = static_cast<Dog*>(p);
  // 부모 포인터 타입을 자식 포인터 타입으로 명시적인 캐스팅이 필요하다.
  //  - static_cast

  p2->color = 100000000;  // 잘못된 자식 객체의 메모리에 접근하는 것이다. => 미정의 동작
                    // 잘못된 다운 캐스팅에 대한 위험을 방어하기 위해서는 실행 시간에 타입의 정보를 확인할 수 있어야 한다.
                    // => RTTI

  cout << c.address << endl;                    
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