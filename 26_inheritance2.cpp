#include <iostream>
using namespace std;
// 상속과 접근 지정자
//  접근 지정자          Class 멤버함수       /       자식 클래스      /      외부
//  1. public              O                        O                  O
//  2. protected           O                        O                  X
//  3. private             O                        X                  X

class Base {
private:
  int data1;
public:
  int data2;
protected:     // 1. 자식 클래스가 접근 가능하다. 2. 외부에서 접근이 불가능하다.
  int data3;
};

class Derived : public Base {
public:
  void foo() {
    data2 = 10;
    
    // data1 = 20;
    // = 부모의 멤버 데이터 중 private은 접근이 불가능하다.
    data3 = 20;
  }
};

int main() {
  Derived d;
  d.foo();

  Base b;
  // b.data3 = 30;

  

}