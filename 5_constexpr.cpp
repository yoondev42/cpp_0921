// 5_constexpr - C++11
//  : 컴파일 타임 상수를 지정할 때 사용한다.
//    컴파일 타임 상수를 만족하지 못할 때는 컴파일 오류가 발생한다.

// C - const(상수)
//  컴파일 타임 상수
//  런타임 상수       - 메모리 공간이 존재한다.
// #include <stdio.h>
#include <iostream>
using namespace std;

#if 0

int main() {
  const int a = 10;
  constexpr int b = 10;

  int n;
  cin >> n;

  const int c = n;
  // constexpr int d = n;  // error!
}
#endif

#if 1
int main() {
  constexpr int a = 42;
  int* p = (int *)&a;

  *p = 100;
                       //  C     C++
  printf("%d\n", *p);  // 100    100
  printf("%d\n", a);   // 100    42
}
#endif

// C++ - 멀티패러다임 언어
// 1) C언어
// 2) 객체 지향
// 3) 일반적(Generic) 프로그래밍 - template(컴파일 타임에 컴파일러가 코드를 생성하는 기술)