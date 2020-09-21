// 4_variable2.cpp
#include <iostream>
using namespace std;

struct Point {
  int x;
  int y;
};

#if 0
int main() {
  // 일반 변수 타입 - =, () 
  int n1 = 10;
  int n2(10);

  cout << n1 << ", " << n2 << endl;

  // 배열 / 구조체 - {}
  int x[3] = { 1, 2, 3 };
  struct Point p = { 10, 20 };
}
#endif

#if 0
// -std=c++1y    => c++11/14
// -std=c++1z    => c++17
int main() {
  // C++98/03
  int n0(10);
  int x0[3] = { 1, 2, 3};
  Point p0 = { 10, 20 };

  // C++11 - Uniform Initialization
  // Copy Initialization
  int n1 = { 10 };
  int x1[3] = { 1, 2, 3 };
  Point p1 = { 10, 20 };

  // 등호 없이 사용하는 것도 가능합니다. - Direct Initialization
  int n2{20};
  int x2[3]{ 1, 2, 3 };
  Point p2{10, 20};
}
#endif
// 강타입 언어
//  - 암묵적인 타입 변환을 허용하지 않는다.

#if 0
int main() {
  // int n1 = 3.14;
  // char c1 = 300;

  // Preventing Narrow 
  //  : C++11에서는 컴파일 오류로 알려줍니다.
  int n2 = { 3.14 };
  char c2 = { 300 }; 
}
#endif

// auto / decltype - C++11
// auto: 타입 추론 키워드
//  => C 언어에서는 다른 의미로 사용되던 키워드입니다.
// decltype: 기존의 변수와 동일한 타입의 변수를 만들 수 있습니다.

int main() {
  // int a = 30;
  // auto a = 3.14;

  // auto a{3.14}; - Direct Initialization
  double a = { 3.14 };
  printf("%f\n", a);

  // auto는 반드시 우항이 필요하다.
  // auto b; - error!

  decltype(a) b = a;
  
  decltype(b) c;
}
