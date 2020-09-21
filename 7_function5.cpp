// C++11 - delete function

#include <stdio.h>

int gcd(int a, int b) {
  return b != 0 ? gcd(b, a % b) : a;
}

// 선언만 제공한다. => 링크 에러를 의도한다.
//              => 링크 오류는 문제의 원인을 찾아내기 어렵다.
#if 0
Undefined symbols for architecture x86_64:
  "gcd(double, double)", referenced from:
      _main in 7_function5-f8c32e.o
ld: symbol(s) not found for architecture x86_64
#endif

double gcd(double a, double b);
// Delete Function: 해당 함수를 호출하는 부분이 컴파일 오류가 발생한다.

int main() {
  printf("%d\n", gcd(2, 10));

  printf("%lf\n", gcd(2.2, 4.3)); // 암시적 형변환이 허용된다. 하지만 동작하지 않길 원한다.
}