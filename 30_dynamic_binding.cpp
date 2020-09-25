// dynamic_binding.cpp

#include <iostream>
using namespace std;

// 1. override는 부모의 가상 함수에 대해서만 가능하다.
// 2. 부모의 protected 멤버 함수를 자식 클래스에서 pubilc 멤버 함수로 변경하는 것은 가능하다.

// 정적 바인딩: 컴파일러가 컴파일 타임에 Animal* p의 타입을 확인한다.
// 동적 바인딩: [런타임에 p 객체가 담고 있는 타입을 조사]해서, 호출한다.
//            -> 컴파일러가 삽입하는 코드


// 3. 클래스가 가상 함수를 하나라도 가진다면, 가상 함수 테이블을 참조하는 포인터가 필요합니다.
#if 0
class Animal {
  int a;
public:
  virtual void cry() { cout << "Animal cry" << endl; }
};

class Dog : public Animal {
  int b;
public:
  void cry() override { cout << "Dog cry" << endl; }
};
#endif

// 1. 컴파일 시간에는 p가 Animal*라는 정보 밖에 알 수 없습니다. 
//    Animal의 클래스를 조사해서, cry함수가 가상함수인지 아닌지를 판단합니다.
// 2. 가상함수가 아니라면, Animal::cry를 호출하는 기계어 코드를 작성합니다.
// 3. 가상함수라면 p가 가르키는 곳을 참조해서, 가상함수테이블의 주소를 꺼내고, cry는 순서상 첫번째
//    가상함수 이므로, 배열의 첫번째 값을 꺼내서 호출하는 기계어 코드를 작성합니다.
// 4. 프로그램이 실행할 때 3번에서 실행된 기계어 코드를 실행하므로, Dog::cry가 수행됩니다.

//------------------
// 가상 함수의 비용
// 1. 가상 함수를 가지는 모든 객체는 가상 함수 테이블을 참조하는 포인터를 가져야 합니다.
//   => 객체의 크기가 증가합니다(포인터의 크기 만큼)
// 2. 가상 함수 테이블의 크기(메모리 오버헤드)
//   => 가상 함수 개수 * 상속한 클래스 타입의 개수 * 함수 포인터 크기
// 3. 실제 함수를 호출할 때 가상 함수 테이블에 주소를 꺼내서 호출하므로, 일반적인 호출보다 약간 느립니다.
//   => 컴파일 타임에 바인딩되는 정적 바인딩은 인라인 최적화가 가능하지만, 가상 함수는 불가능합니다.


#if 0
int main() {
  cout << sizeof(Animal) << endl;
  cout << sizeof(Dog) << endl;

  Animal* p = new Dog;
  p->cry();
}
#endif


#if 0
class Animal {
public:
  virtual void cry() { cout << "Animal cry" << endl; }
};

class Dog : public Animal {
public:
  void cry() override { cout << "Dog cry" << endl; }
};


int main() {
  // Dog d;
  // d.cry(); // ok!

  Animal* p = new Dog; // dog cry
  p->cry();
  // 1. 컴파일 할 때 p가 가르키는 메모리를 조사하는 기계어 코드를 생성합니다.
  // 2. 실행 시간에 메모리를 조사한 후 함수 호출을 결정합니다.
}
#endif



#if 0
void foo() {}

int main() {
  foo();
}

(__TEXT,__text) section
__Z3foov:
0000000100003f90        pushq   %rbp
0000000100003f91        movq    %rsp, %rbp
0000000100003f94        popq    %rbp
0000000100003f95        retq
0000000100003f96        nopw    %cs:(%rax,%rax)
_main:
0000000100003fa0        pushq   %rbp
0000000100003fa1        movq    %rsp, %rbp
0000000100003fa4        callq   __Z3foov ## foo()
0000000100003fa9        xorl    %eax, %eax
0000000100003fab        popq    %rbp
0000000100003fac        retq
#endif

class Animal {
public:
  void foo() {}
};
class Dog : public Animal {
};

int main() {
  // Animal a;
  // a.foo();

  Dog d;
  Animal* p = &d;
  p->foo();

}

#if 0
(__TEXT,__text) section
_main:
0000000100003f70        pushq   %rbp
0000000100003f71        movq    %rsp, %rbp
0000000100003f74        subq    $0x10, %rsp
0000000100003f78        leaq    -0x8(%rbp), %rdi
0000000100003f7c        callq   0x100003f9a ## symbol stub for: __ZN6Animal3fooEv
0000000100003f81        xorl    %eax, %eax
0000000100003f83        addq    $0x10, %rsp
0000000100003f87        popq    %rbp
0000000100003f88        retq
0000000100003f89        nopl    (%rax)
__ZN6Animal3fooEv:
0000000100003f90        pushq   %rbp
0000000100003f91        movq    %rsp, %rbp
0000000100003f94        movq    %rdi, -0x8(%rbp)
0000000100003f98        popq    %rbp
0000000100003f99        retq


#endif

