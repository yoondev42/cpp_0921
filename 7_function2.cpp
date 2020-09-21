// 7_function2.cpp


// 1. 디폴트 파라미터
// 2. 함수 오버로딩(Function Overloading)
//  : 파라미터의 타입과 개수가 다르면, 동일한 이름을 가지는 함수를 여러개 만들 수 있습니다.
#if 0
#include <iostream>
using namespace std;

int square(int a) {
  return a * a;
}

double square(double d) {
  return d * d;
}


// 매크로 함수를 이용해서, 비슷한 동작을 수행하는 것이 가능합니다.
int main() {
  int a = 1;

  cout << square(++a) << endl;
  cout << square(3.14) << endl;
}
#endif

#if 0
#include <stdio.h>

// C언어 에서는 매크로 함수를 이용해서, 타입에 독립적인 함수를 제공하는 것이 가능하다.
// 1) 우선순위
// #define SQUARE(x) x * x
// 2) 부수효과(Side effect) - 미정의 동작
//   :연산의 결과로 변수의 값이 변경되는 것
// 3) 규칙 - 함수의 이름을 대문자로 사용해야 한다.
//          ADD_XXX

#define PI 3.14
#define SQUARE(x) ((x) * (x))

int main() {
  // printf("%lf\n", PI);
  // printf("%d\n", SQUARE(3));
  // printf("%lf\n", SQUARE(3.14));

  int x = 1;
  printf("%d\n", SQUARE(++x));
  //                   ((++x) * (++x)) // 미정의(Undefiend) 동작
  //                     - 컴파일러의 구현에 의존한다.


}
#endif

#include <iostream>
using namespace std;

// OK
void foo(int a) {}
void foo(double d) {}
void foo(int a, int b) {}

// 인자의 개수가 다르지만, 디폴트 파라미터가 있습니다.
// void goo(int a) {}
// void goo(int a, int b = 30) {}

// 어떤 함수와 연결될지에 대한 부분에, 반환 타입은 중요하지 않습니다.
// int hoo(int a) {}
// void hoo(int a) {}

int main() {
  // goo(42);
}

// C언어의 함수는 컴파일 시 이름이 유지된다.
// C++은 함수의 인자 정보를 토대로, 컴파일 시 함수의 이름이 변경된다. => 네임 맹글링(mangling) - 짓이기다

//                                          extern "C"                                            
//  foo(int)           -> _Z3fooi
//  foo(int, int)      -> _Z3fooii       ->   foo
//  foo(int, int, int) -> _Z3fooiii


// C언어에서 C++의 함수를 호출하는 것이 가능할까요?
// C++에서 C언어의 함수를 호출하는 것이 가능할까요?
//  => extern "C"
//    : C 함수의 심볼을 통해 함수를 제공한다.
//    - 함수의 네임 맹글링을 수행하지 않기 때문에, 오버로딩이 불가능해진다.
