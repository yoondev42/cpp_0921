// 10_casting.cpp
#include <iostream>
#include <cstdlib>
using namespace std;


// casting
//  1. C언어에서는 암묵적(implicit) / 명시적(explicit) 캐스팅이 존재합니다.
//  2. C언어의 명시적인 캐스팅은 대부분 성공합니다.
//     캐스팅이 '버그의 원인'이 되는 경우가 많습니다.


int main() {
  // malloc
  int *p = (int *)malloc(sizeof(int) * 10);
  // 위의 경우는 반드시 필요한 경우의 캐스팅 입니다.

}


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