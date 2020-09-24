#include <iostream>
using namespace std;

// 상속과 생성자 소멸자
// Base()
// Derived()
// ~Derived()
// ~Base()
#if 0
class Base
{
public:
  Base() { cout << "Base()" << endl; }
  Base(int a) { cout << "Base(int)" << endl; }
  ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
  // 기반 클래스의 기본 생성자를 호출하는 코드를 컴파일러가 추가해준다.
  // Derived() : Base()
  Derived()
  {
    cout << "Derived()" << endl;
  }

  Derived(int a) : Base(a)
  {
    cout << "Derived(int)" << endl;
  }

  ~Derived() { cout << "~Derived()" << endl; }
};
#endif

class Base
{
public:
  Base(int a) { cout << "Base(int)" << endl; }
  ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
  // Derived() : Base()
  // => 부모 클래스가 기본 생성자를 제공하지 않을 경우, 자식 클래스의 생성자에서 초기화 리스트를 통해 부모의 생성자를
  //    명시적으로 지정해야 한다.
  Derived() : Base(42)
  {
    cout << "Derived()" << endl;
  }

  ~Derived() { 
    cout << "~Derived()" << endl; 
    
    // 컴파일러는 자식의 소멸자의 마지막에 부모의 소멸자를 호출하는 코드를 삽입한다.
    // ~Base();
    // => 소멸자는 명시적으로 호출하는 것이 불가능하다.
  }
};

int main()
{
  Derived b;

}