// 2_namespace.cpp

// 1. cpp
// 2. 헤더 파일 / 함수

// namespace: 이름 충돌을 방어하기 위해 사용한다.
//  이름 충돌: 동일한 프로그램 내에서 동일한 심볼을 사용할 때 발생한다.
//     1.c - MBfoo() / mbCount
//     2.c - foo() / count
//   => C언어에서는 이름 충돌을 방지하기 위해, 심볼의 접두로 다른 이름을 사용한다. 

// Java - package

#include <iostream>
// 표준 라이브러리는 모든 함수와 심볼이 std의 이름 공간에 두도록 약속한다.
using namespace std;
// 방법 3. using 지시어
//   - std 이름공간에 있는 모든 요소를 직접 사용할 수 있다.

int main() {
  cout << "Hello, C++" << endl;
}

// 방법 2. using 선언을 이용한다.
#if 0
using std::cout;
using std::endl;

int main() {
  cout << "Hello, C++" << endl;
}
#endif

// 방법 1. 이름 공간을 명시적으로 표현한다.
#if 0
int main() {
  std::cout << "Hello, C++" << std::endl;
}
#endif


