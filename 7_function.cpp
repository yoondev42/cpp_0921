// 7_function.cpp

#include <iostream>
using namespace std;

#include <stdio.h>

#include "foo.h"

int main() {
  printf("%d\n", add());
}

// 1. 디폴트 파라미터(Default parameter)
//   1) 기본값을 지정하는 것을, 마지막 파라미터부터 해야 한다.
//   2) 함수를 만들 때, 선언(헤더파일)과 정의(소스파일)가 존재합니다.
//      기본값을 선언부에 제공해야 합니다.

#if 0
void foo(int a, int b = 20, int c = 30)
{
  cout << a << " " << b << " " << c << endl;
}

int main()
{
  // foo(10, 20, 30);
  // foo();
  foo(10, 100, 200);
  foo(10, 200);
  foo(10);
}
#endif