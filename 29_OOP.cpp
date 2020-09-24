#include <iostream>
#include <vector>
using namespace std;
// 객체지향 설계 - Design Pattern

// Design Pattern
//  = 건축학: 잘 만들어진 건물에는 공통된 설계적 특징이 존재한다.
//  = 소프트웨어 - 에릭감마
//    => 잘 만들어진 소프트웨어는 일련의 설계적 공통점이 존재한다.
//    => 23가지 패턴 정리(객체 지향 설계): 1995년
//        GoF's Design Pattern: 에릭감마 외 3명 => Gang of Four(GoF)

// 1. 각 도형을 타입화한다.

// 2. Rect와 Circle의 공통의 부모를 도입하자.
// => 동종 타입을 하나의 컨테이너를 통해 관리하는 것이 가능하다.

// 3. 파생 클래스의 공통의 특징은 기반 클래스에 있어야 한다.
// => 부모의 포인터를 통해 자식의 기능을 이용할 수 있다.

// 4. 파생 클래스가 override하는 함수는 반드시 가상 함수이어야 한다.

// - 객체 지향 설계의 특징
// 캡슐화: 여러 개의 타입을 하나의 타입으로 만들고, 접근 지정자를 통해 안전하게 접근할 수 있도록 제어한다.
// 상속성: 기존 클래스의 특징을 물려 받아서, 새로운 특징을 추가하여 확장할 수 있다.
// 다형성

// - 객체 지향 설계의 5대 원칙(SOLID), 로버트 마틴 정리
//  SRP(단일 책임의 원칙), 'OCP(개방 폐쇄의 원칙)', LSP(리스코프 치환 원칙), ISP(인터페이스 분리 원칙), DIP(의존 관계 역전 원칙)



class Shape {
public:
  virtual ~Shape() {}

  virtual void draw() { cout << "Shape draw" << endl; }
};

class Rect : public Shape {
public:
  void draw() { cout << "Rect draw" << endl; }
};

class Circle : public Shape {
public:
  void draw() { cout << "Circle draw" << endl; }
};

class Triangle : public Shape {
public:
  void draw() { cout << "Triangle draw" << endl; }
};

int main() {
  vector<Shape*> v;
  int cmd;

  while (1) {
    cin >> cmd;
    if (cmd == 1)      v.push_back(new Rect);
    else if (cmd == 2) v.push_back(new Circle);
    else if (cmd == 3) v.push_back(new Triangle);
    else if (cmd == 9) {
      // 아래 코드는 새로운 타입이 추가되어도, 수정될 필요가 없습니다.
      // => OCP를 만족한다.
      // => 개방 폐쇄의 원칙(Open-Close Principle)
      //  : 확장에는 열려 있고, 수정에는 닫혀 있어야 한다.
      //    "새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다."

      // 다형성(polymorphism): s가 어떤 객체를 참조하는지에 따라 다른 함수를 호출하게 되는 것
      // => 다형성은 OCP를 만족한다.
      for (auto s : v) {
        s->draw();
      }
    }
  }
}