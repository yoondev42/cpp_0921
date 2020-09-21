// 4_variable.cpp
#include <iostream>
using namespace std;

#if 0
struct node {
  int n;
  struct node *next;
};
typedef struct node Node;
#endif

struct node {
  int n;
  node *next;
};

// C 언어에서는 블록의 최상위에 변수를 정의했지만, C++에서는 제약이 존재하지 않습니다.
int main() {
  // struct node n;   // C style 구조체 변수 정의
  node n;             // C++에서는 struct를 명시적으로 표현하지 않아도 됩니다.

  // 변수 정의부
  int a = 10;
  double d = 3.14;

  // 코드 작성  
  a += 10;

  char c = 'a';
  c += 1;
}

#if 0
//       100: 10진수
//      0100: 8진수
//     0x100: 16진수
// 0b1110011: 2진수    ->  C++11

//    1111 0011
// 16 =>  0xF3
//  8 =>  0363

// 'C++11'에서는 2진수 표기를 제공합니다.
int main() {
  int n = 0b11110011;
  cout << hex << n << endl;
}
#endif