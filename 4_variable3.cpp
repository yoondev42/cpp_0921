// 4_variable3.cpp

// typedef 
//  => 기존 타입에 대한 alias를 만든다.
#if 0
typedef int DWORD;
typedef struct node {

} NODE;

typedef void (*FP)(int, int);
#endif

#include <cstdint>
#include <stdio.h>
// using
//  C++11에서 추가된 문법
//  => typedef와 동일하게, 타입에 대한 별칭을 만드는 것이 가능합니다.
//  => template 문법!
using DWORD = int;
using NODE = struct node {

};

using FP = void(*)(int, int);

int main() {
  // DWORD a;
  // NODE n;

  // FP fp;

  printf("%lu\n", sizeof(char));
  printf("%lu\n", sizeof(short));
  printf("%lu\n", sizeof(int));
  printf("%lu\n", sizeof(long));
  printf("%lu\n", sizeof(long long));

  char c;    // 1
  short s;   // 2
  int i;     // 4

  long d;    // 4? 8?

  // C++11
  long long a; // 8    // C++11

}