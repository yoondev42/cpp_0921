// 9_reference.cpp

#include <iostream>
using namespace std;

#if 0
int main() {
  int n = 0;

  int* p = &n;

  *p = 10;

  cout << n << endl;
}
#endif

#if 1
// C++에는 레퍼런스(참조) 타입이라는 새로운 형태의 타입을 제공합니다.
int main() {
  int n = 0;
  // 이 순간 4바이트의 메모리가 할당됩니다.

  // int& r;
  // r = n;

  int& r = n;
  // 새로운 메모리를 할당하는 것이 아니라, 기존 메모리에 새로운 이름(r)을 부여합니다.
  // => 반드시 초기값을 제공해야 합니다.
  
  r = 10;
  // r과 n은 같은 메모리이기 때문에, n의 값이 변경됩니다.

  cout << n << endl;
  cout << &n << endl;
  cout << &r << endl;
}
#endif

