#include <stdio.h>

// 4. Template Function

// int square(int a) { return a * a; }
// double square(double a) { return a * a; }
// 위의 코드를 제공하는 사람은 결국 2개의 함수를 제공해야 합니다.
// 함수를 제공할 때, 알고리즘(로직)은 동일하고, 타입만 다른 경우, '템플릿'을 이용하면 편리합니다.

// C++ Template
//  => 컴파일 타임에 컴파일러가 코드를 생성하는 기술

// template <typename T>
// T square(T a) { return a * a; }

template <class T>
T square(T a) { return a * a; }
// 위의 템플릿을 기반으로 아래 코드가 생성됩니다.
// int square(int a) { return a * a; }
// double square(double a) { return a * a; }

int main() {
  printf("%d\n", square(3));       // square(int)
  printf("%lf\n", square(3.14));   // square(double)
  printf("%d\n", square('a'));     // square(char)
}