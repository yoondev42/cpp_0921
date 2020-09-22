// 12_nullptr.cpp
// : C++11에 추가된 기능입니다.

// #define NULL (void*)0
#include <iostream>
using namespace std;

int main() {
  int* p = nullptr;
  
  // int a = NULL; // NULL은 정수로 암묵적인 캐스팅이 허용되고, 오류의 원인이 될 수 있습니다.
  // int a = nullptr;
  char* p2 = nullptr;
  
  // 0을 대입하는 것도 유효합니다.
  p = 0;
  p2 = 0;

  bool b = nullptr;


}