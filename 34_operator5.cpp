// 34_operator5.cpp
#include <iostream>
using namespace std;

// 연산자 재정의 활용

int add(int a, int b) {
  return a + b;
}

// 1) 함수연산자도 재정의가 가능합니다. => 파라미터 개수를 사용자가 정의하는 것이 가능합니다.
//   - 함수 객체
template <typename T>
class Plus {
public:
  T operator()(const T& a, const T& b) const {
    return a + b;
  }
};

#include <functional>  // plus
using namespace std;

int main() {
  plus<int> p;
  printf("%d\n", p(10, 20));

  plus<string> p2;
  cout << p2("hello", "world") << endl;
}


#if 0
int main() {
  Plus plus;

  // STL에서 정책을 전달하는 방법
  // 1. 함수
  // 2. 함수 객체 - 생성자/소멸자 등 다양한 동작을 정의하는 것이 가능합니다. 
  int result2 = plus(10, 20);
  printf("%d\n", result2);

  int result = add(10, 20);
  printf("%d\n", result);
}
#endif