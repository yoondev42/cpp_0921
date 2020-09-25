
// C++ RTTI(Run Time Type Information)
// => 실행 시간에 객체의 타입을 조사한다.
#include <iostream>
using namespace std;

class Animal {
public:
  virtual ~Animal() {}

};

class Dog : public Animal {

};

// RTTI 정리
// 1. type_info객체를 typeid(객체) / typeid(클래스)으로 꺼낼 수 있다.
// 2. typeid(객체): type_info객체는 가상 함수 테이블을 통해 관리됩니다.
//    객체가 가상 함수 테이블을 가지고 있지 않은 경우, 컴파일러는 변수 타입에 대한 type_info를 제공합니다.

// p = new Dog;
// p = new Animal;
void foo(Animal* p) {
  // p가 실제로 어떤 타입의 객체를 가르키는지 조사하는 방법: RTTI
  // 1. type_info객체를 꺼낸다.
  const type_info& t = typeid(*p);
  cout << t.name() << endl;
  // - 이름의 규칙은 표준에서 정의하지 않는다.
  //   컴파일러의 구현에 의존하다.

  // p가 Animal이면,
  if (typeid(*p) == typeid(Animal)) {
    cout << "p는 Animal 타입입니다." << endl;
  } 

  // p가 Dog이면,
  if (typeid(*p) == typeid(Dog)) {
    cout << "p는 Dog 타입입니다." << endl;
  } 
}

int main() {
  Animal a;
  foo(&a);  // 6Animal

  Dog d;
  foo(&d);  // 3Dog
}
