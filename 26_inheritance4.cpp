#include <iostream>
using namespace std;

class Animal {
protected:
  int color;
};

// 자식 클래스는 부모의 protected로 제공되는 멤버 데이터 또는 멤버 함수를 public으로 변경할 수 있다.
class Dog : public Animal {
public:
  using Animal::color;
};

int main() {
  // Animal a;
  Dog a;

  a.color = 42; 
}


#if 0
// Animal 객체는 생성이 불가능하지만, Animal의 자식은 Dog의 객체는 생성 가능하게 하고 싶다.
// => protected 생성자
//  : 자신 타입의 객체는 생성할 수 없지만, 파생 클래스의 객체는 생성 할 수 있다.
class Animal {
protected:
  Animal() {}
};

class Dog : public Animal {

};

int main() {
  // Animal a;
  Dog d;
}
#endif