#include <iostream>
using namespace std;

// C++11 - rvalue reference
// 1. C++에서는 왼쪽에 올 수 있는 값을 lvalue => 왼쪽과 오른쪽 모두 가능합니다.
//           오른쪽에 올 수 있는 값을 rvalue => 오른쪽만 가능합니다.

// 2. 
// Type&       => lvalue reference type: lvalue만 참조 가능하다.
// Type&&      => rvalue reference type: rvalue만 참조 가능하다.
// const Type& => lvalue / rvalue 참조 가능

int main() {
  int n = 30;
  int n2 = n;

  int&& r = 30; 
  cout << r << endl;

  // int& r = n;
  // 일반적인 참조 타입은 lvalue만 참조 가능합니다.

  // int& r = 30;      // error! rvalue 참조는 불가능합니다.

  // const int& r1 = 30;   // const&는 rvalue 참조가 가능합니다.
  // const int& r2 = n;    // const&는 lvalue 참조도 가능합니다.
}