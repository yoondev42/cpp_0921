// foo.cpp

// 구현부
#include "foo.h"
// 상호 호출을 고려해서, 포함하는 것이 좋다.

#include <stdio.h>

extern void goo()
{
  foo();
  printf("goo\n");
}

extern void foo()
{
  goo();
  printf("foo\n");
}



extern int add(int a, int b)
{
  return a + b;
}

extern int sub(int a, int b)
{
  return a - b;
}

// 전역 변수 / 전역 함수 - 연결(Linkage)
//  1. extern(기본)
//  : 다른 파일에서 해당 함수나 변수를 참조할 수 있는가?
//   External Linkage
//  2. static
//  : 다른 파일에서 해당 함수나 변수를 참조할 수 없다.
//    오직 같은 파일에서만 참조가 가능하다.
//   Internal Linkage

// 함수 내 변수(storage class)
//  1. auto - 스택에 저장되는 메모리
//  2. static - 정적 메모리
//   : 함수가 처음 호출되는 시점에 생성되고, 더 이상 사용되지 않을 때 파괴된다.