// 4_variable2.cpp
#include <iostream>
using namespace std;

struct Point {
  int x;
  int y;
};

#if 0
int main() {
  // 일반 변수 타입 - =, () 
  int n1 = 10;
  int n2(10);

  cout << n1 << ", " << n2 << endl;

  // 배열 / 구조체 - {}
  int x[3] = { 1, 2, 3 };
  struct Point p = { 10, 20 };
}
#endif


int main() {
  // C++98/03
  int n0(10);
  int x0[3] = { 1, 2, 3};
  Point p0 = { 10, 20 };

  // C++11 - Uniform Initialization
  // Copy Initialization
  int n1 = { 10 };
  int x1[3] = { 1, 2, 3 };
  Point p1 = { 10, 20 };

  // 등호 없이 사용하는 것도 가능합니다. - Direct Initialization
  int n2{20};
  int x2[3]{ 1, 2, 3 };
  Point p2{10, 20};
}
