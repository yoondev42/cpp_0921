// function override
#include <iostream>
using namespace std;

// 함수 오버로딩 - 파라미터의 타입 또는 개수가 다를 경우, 동일 이름의 함수하는 것이 가능하다.
//            => 네임 맹글링(name mangling)을 통해 다른 이름으로 처리한다.
// 함수 오버라이딩
//   : 부모와 동일한 함수를 자식 클래스에서도 제공하는 것이 가능합니다.

class Animal {
public:
  virtual void cry() { cout << "Animal cry" << endl; }  // 1
};

// 상속: 부모클래스로부터 멤버 데이터와 멤버 함수를 물려받는다.
class Dog : public Animal {
public:
  virtual void cry() { cout << "Dog cry" << endl; }     // 2
};

// 변수: 실행 시간에 변하는 값

// 함수 바인딩
//  정의: 어떤 함수를 호출할 지 결정하는 것
// 1. 정적 바인딩(static binding) 
//   - '컴파일 타임'에 컴파일러가 결정하는 것
//     : 변수가 어떤 타입의 값을 가지고 있을 지 알 수 없다.
//       변수가 선언된 타입을 기반으로 컴파일러는 어떤 함수를 호출할지 결정한다.
//   => 컴파일러가 결정하기 때문에, 의도한대로 동작하지 않을 수 있다.
//      별도의 타입 체크가 필요하지 않고, 컴파일러가 인라인 최적화를 수행할 수 있다.
//   => C++

// 2. 동적 바인딩(dynamic binding)
//   - '실행 시간(런타임)'에 어떤 함수를 호출할지를 변수의 타입을 기반으로 결정하는 것.
//   => 의도한 대로 동작한다.
//      실행시간에 함수 호출을 위해 추가적인 타입 체크가 필요하므로, 상대적으로 오버헤드가 있다.
//   => Java
//   => 멤버함수의 호출
//       정적 바인딩 -> 동적 바인딩으로 바꾸는 키워드가 있습니다.
//        => virtual

int main() {
  Dog d;
  Animal* p = &d;

  p->cry();  // 1? 2?
}


#if 0
int main() {
  Animal a;     
  a.cry();    // 1

  Dog d;
  d.cry();    // 2
}
#endif