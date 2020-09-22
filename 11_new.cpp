// 11_new.cpp

#include <iostream>
#include <cstdlib>
using namespace std;

// 변수가 생성되는 Storage class
// 1. 정적 메모리
//    - 전역 변수
//    - 내부 정적 변수
//    => 프로그램 시작에 초기화 되고, 프로그램이 종료될 때까지 유지된다.
//    => 실행 파일의 용량에 영향을 준다.

// 40000 byte
int data[10000]; // = { 1, 2, 3, 4, 5, };
// 전역 변수를 사용하지 않았을 때: 16k
// 초기화되지 않은 전역 변수를 사용할 때: 16k
// 초기화된 전역 변수를 사용할 때: 65k

// 2. 스택 메모리
//    - 지역 변수(자동 변수)
//    - 함수가 시작되는 시점에 생성되고, 함수가 끝나는 시점에 파괴된다.
//    - 생성과 파괴의 비용이 거의 없다.

// 3. 힙 메모리
//    - 동적 메모리 할당
//    - 개발자가 원하는 시점에 할당하고, 개발자가 원하는 시점에 해지할 수 있다.
//    - 할당과 해지의 비용이 크다.
//    - 메모리 누수의 위험성이 있다.

// 1) malloc/free는 함수이지만 new/delete는 연산자 입니다.
// 2) malloc은 size를 전달하지만, new는 타입을 전달합니다.
// 3) new는 캐스팅이 필요하지 않습니다.
// 4) free를 통해 해지하는 것이 아니라, delete를 통해 해지하면 됩니다.

void foo() {
  // char b;
  // vs
  // char arr[1000];

  // char* p = static_cast<char*>(malloc(sizeof(char) * 64));
  // free(p); // 더이상 필요하지 않을 때 해지한다.

  // char* p = new char[64];
  // C++에서는 동적 메모리 할당을 위한 새로운 연산자가 도입되었습니다.
  // malloc -> new
  // free   -> delete

  // int*
  int* p2 = new int;
  delete p2;

  // int*
  int* p = new int[64];
  // delete 통해 전달된 메모리가 연속된 메모리 인지, 단일 메모리인지 알 수 없다.
  // 연속된 메모리인 경우 
  // delete p;  // 누수가 발생합니다.
  delete[] p;   // !!

  // delete: 단일 메모리
  // delete[]: 연속된 메모리
}

int main() {
  foo();
}