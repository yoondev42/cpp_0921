
// 1. Default Paramter
// 2. Function Overloading
// 3. Inline Function

// #include <iostream>
// using namespace std;

// 함수를 호출하는 것이 아니라, 기계어를 함수의 호출부분에 붙임으로써,
// 함수 호출의 오버헤드를 없애는 것이 가능합니다.
//  => Inline
//  문제점: 실행 파일의 크기가 커질 수 있다.
//  => 짧은 구현을 가진 함수가 인라인화된다면, 코드의 메모리 사용량이 적어질 수 있습니다.
//  => Inline 키워드는 무조건 적용되는 키워드가 아닙니다.
#include <stdio.h>

inline int add(int a, int b) { 
  return a + b;
}

int main() {
  int ret = add(10, 20);
  printf("%d\n", ret);
}
