
// 13_complex.cpp
// Object Oriented Programming
//  => 객체 지향 프로그래밍 C++

#include <iostream>
using namespace std;


#if 0
void add(int ar, int ai, int br, int bi) {
  int sum_r = ar + br;
  int sum_i = ai + bi;

  // 문제점
  // 함수의 반환값은 1개 입니다.
  // => 함수에서 인자를 통해 결과를 전달 받는 것도 가능합니다.
}
#endif

#if 0
// 결과를 전달 받기 위해 사용하는 파라미터: out paramter
void add(int ar, int ai, int br, int bi, int* sr, int* si) {
  int sum_r = ar + br;
  int sum_i = ai + bi;

  *sr = sum_r;
  *si = sum_i;
}

// 복소수의 타입이 존재한다면, 복잡도를 줄일 수 있습니다.

int main() {
  // 2+2i
  int ar = 1, ai = 1; // 1+1i
  int br = 2, bi = 2; // 2+2i

  int sr, si;
  add(ar, ai, br, bi, &sr, &si);
  cout << sr << "+" << si << "i" << endl;
}
#endif

// 새로운 복소수 타입을 설계하자.
// => 프로그램에 필요한 타입을 먼저 설계하고, 해당 타입을 이용해서 프로그래밍을 하는 것
struct Complex {
  int re;
  int im;  
};

Complex add(const Complex& a, const Complex& b) {
  Complex ret = { a.re + b.re, a.im + b.im };
  return ret;
}

// 객체(object) - 새로운 타입의 인스턴스
int main() {
  Complex a = { 1, 1 };   // 1 + 1i
  Complex b = { 2, 2 };   // 2 + 2i

  Complex ret = add(a, b);
  cout << ret.re << "+" << ret.im << "i" << endl;
}