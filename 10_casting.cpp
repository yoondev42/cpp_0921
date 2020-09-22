// 10_casting.cpp
#include <iostream>
#include <cstdlib>
using namespace std;


// casting
//  1. C언어에서는 암묵적(implicit) / 명시적(explicit) 캐스팅이 존재합니다.
//  2. C언어의 명시적인 캐스팅은 대부분 성공합니다.
//     캐스팅이 '버그의 원인'이 되는 경우가 많습니다.
//  3. C++에서는 C 캐스팅의 문제점을 해결하기 위해서, 각 용도에 따른 4가지 종류의 캐스팅을 제공합니다.
//    1. static_cast => 일반적인 캐스팅, 연관성이 없는 타입간의 캐스팅은 허용되지 않습니다.
//                      void*를 다른 타입으로 캐스팅 하는 것은 허용한다.
//    2. dynamic_cast => 실행시간에 타입의 정보를 확인하고, 캐스팅합니다.(RTTI - Run Time Type Information)
//    3. const_cast   => 상수성 제거를 위해 사용합니다.
//    4. reinterpret_cast => 메모리를 재해석할 때 사용합니다. C의 캐스팅과 유사합니다.

int main() {
  int n = 10;
  // double* p = (double *)&n; // OK!

  // error: static_cast from 'int *' to 'double *' is not allowed
  // double* p = static_cast<double*>(&n);
  double* p = reinterpret_cast<double*>(&n);

  // int *p = (int *)malloc(sizeof(int) * 10);
  // int* p = static_cast<int*>(malloc(sizeof(int) * 10));

}



#if 0
int main() {
  // malloc
  int *p = (int *)malloc(sizeof(int) * 10);
  // 위의 경우는 반드시 필요한 경우의 캐스팅 입니다.

}
#endif


#if 0
int main() {
  const int c = 30;

  int* p = (int *)&c;

  *p = 24;

  cout << *p << endl;
  cout << c << endl;
}
#endif


#if 0
int main() {
  int n = 0;

  double* p = (double *)&n;

  *p = 3.14;  // 할당되지 않은 메모리에 값을 쓰는 문제가 발생합니다.

}
#endif



#if 0
int main() {
  double d = 3.14;
  int n = d;          // double -> int : 암묵적인 변환을 허용한다.

  int* p = (int*)&d;  // 명시적인 변환을 수행해야 합니다.

  cout << n << endl;
}
#endif