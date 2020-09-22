
#include <iostream>
using namespace std;

// call by value
#if 0
void inc(int x) {
  ++x;
}
#endif

// call by pointer
void inc(int* p) {
  ++*p;
}

// call by reference
void inc(int& r) {
  ++r;
}

int main() {
  int n = 10;

  cin >> n;
  // cin에 n이 참조타입으로 전달되기 때문에 입력으로 인해 값이 변경되었던 것입니다.
  
  cout << n << endl;  // 10
  // inc(&n);
  inc(n);
  // => call by value처럼 보입니다.
  // => inc 함수를 통해 인자의 값이 변경되지 않는다고 생각할 수 있습니다.

  cout << n << endl;  // ?
}