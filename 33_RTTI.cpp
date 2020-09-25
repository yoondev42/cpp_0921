
// C++ RTTI(Run Time Type Information)
// => 실행 시간에 객체의 타입을 조사한다.
#include <iostream>
using namespace std;

class Animal
{
public:
  virtual ~Animal() {}
};

class Dog : public Animal
{
public:
  int color;

  void cry()
  {
    cout << "Dog cry" << endl;
    color = 100;
  }
};

#if 0
void foo(Animal* p) {
  // p가 Dog 라면
  if (typeid(*p) == typeid(Dog)) {
    Dog* pDog = static_cast<Dog*>(p);
    pDog->cry();
  } else {
    cout << "Dog 타입이 아닙니다." << endl;
  }
}
#endif

// 만약 foo로 전달되는 인자 p에 대해서, Animal의 자식 중에 Dog만 전달되는 것이 보장된다면
// 런타임에 타입을 체크하는 오버헤드가 있는 dynamic_cast 보다, static_cast가 효율적이다.
void foo(Animal *p)
{
  // dynamic_cast: '실행 시간에 객체의 타입을 체크'합니다.
  //                실제 타입이 아니라면, null을 반환합니다.
  //  => 가상 함수 테이블에 존재하는 type_info를 이용합니다.
  //  => 가상 함수가 존재하지 않는 클래스에서는 사용할 수 없다.
  //   : 'Animal' is not polymorphic
  Dog *pDog = dynamic_cast<Dog *>(p);
  if (pDog) {
    pDog->cry();
  }

  // static_cast는 실제 객체의 타입을 체크하지 않습니다.
  //  => 컴파일 타임에 캐스트가 수행됩니다.
#if 0
  Dog *pDog = static_cast<Dog *>(p);
  pDog->cry();
#endif
  // Animal 객체를 대상으로 해당 함수가 호출되면, 미정의 동작이 발생합니다.
}

// RTTI의 문제점
// : type_info의 이름이 표준으로 동일하지 않다.
//  => 많은 프레임워크들은 직접 RTTI를 구현합니다.
//  => 정적 멤버 데이터(변수) / 정적 멤버 함수를 이용하면 구현하는 것이 가능합니다.

int main()
{
  Animal a;
  foo(&a); // 6Animal / class Animal

  Dog d;
  foo(&d); // 3Dog / class Dog
}

// RTTI 정리
// 1. type_info객체를 typeid(객체) / typeid(클래스)으로 꺼낼 수 있다.
// 2. typeid(객체): type_info객체는 가상 함수 테이블을 통해 관리됩니다.
//    객체가 '가상 함수 테이블'을 가지고 있지 않은 경우, 컴파일러는 변수 타입에 대한 type_info를 제공합니다.

#if 0
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
#endif