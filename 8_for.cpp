// 8_for.cpp
#include <iostream>
using namespace std;

int foo() {
  return 42;
}

enum State {
  SUCCESS,
  FAILED
};

State goo() {
  return SUCCESS;
}

int main() {
  State state = goo();
  switch (state) {
    case SUCCESS:
      cout << "success" << endl;
      break;
    case FAILED:
      cout << "failed" << endl;
      break;
  }

  // C++17 - switch-case with initializer
  switch (State state = goo(); state) {
    case SUCCESS:
      cout << "success" << endl;
      break;
    case FAILED:
      cout << "failed" << endl;
      break;
  }

  int ret = foo();
  if (ret == 0) {
    printf("ret가 0일때의 동작\n");
  }
  printf("ret: %d\n", ret);

  // g++ 8_for.cpp -std=c++17
  // C++17 => 초기화 구문이 추가된 제어문(if-statement with initializer)
  if (int ret2 = foo(); ret2 == 0) {
    printf("ret2가 0일때의 동작\n");
  }
  // printf("ret: %d\n", ret2);  - ret2는 if 블록을 벗어나면 파괴된다.

  

}



#if 0
int main() {
  int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  for (int i = 0 ; i < 10 ; ++i) {
    cout << x[i] << endl;
  }

  // C++11 - ranged for
  //  Java, C#, Swift, Kotlin ...
  for (auto n : x) {
    cout << n << endl;
  }
}
#endif