// 7_function6.cpp

#include <iostream>
using namespace std;


// 함수 포인터를 반환하는 함수 또는 배열 포인터를 반환하는 함수를 만들 경우 표현식이 매우 복잡합니다.


// 타입은 변수명을 제외한 나머지입니다.
// int a;         =>     int
// int arr[3];    =>     int[3]
// int arr[2][3]; =>     int[2][3];


// 배열은 디케이(decay) 됩니다.
// => 배열의 이름은 배열의 첫번째 원소의 주소로 해석된다.
//     : arr -> &arr[0]
// => 디케이가 발생하지 않는 경우
//    1) sizeof
//    2) &     

#if 0
int *foo() {
  static int arr[3] = { 1, 2, 3 };
  return arr;
}

int (*goo())[3] {
  static int arr[2][3] = { 0, };
  return arr;
  // &arr[0]
  // = &int[3] -> int(*)[3]
}

int (*hoo())[2] {
  static int arr[2] = { 0, };
  return &arr;
  //     &int[2]  -> int (*)[2]
}
#endif

// typedef int(*AP)[3];
#if 0
using AP = int(*)[3];
AP goo() {
  static int arr[2][3] = { 0, };
  return arr;
  // &arr[0]
  // = &int[3] -> int(*)[3]
}
#endif

auto goo() -> int(*)[3] {
  static int arr[2][3] = { 0, };
  return arr;
}

template <typename T>
auto square(T a) -> T {
  return a * a;
}

int main() {
  int arr[3] = { 1, 2, 3 };

  int *p = arr;

  // arr의 타입은? int*가 아닙니다.
  printf("%ld\n", sizeof(int*)); // 8
  printf("%ld\n", sizeof(arr));  // 12
}








#if 0
int square(int a) {
  return a * a;
}


// C++11 - 반환 타입을 함수의 파라미터 리스트 뒤에 적는 새로운 문법이 적용
// => 후위 반환 형식(trailing return type)
// => Swift, Kotlin, Go, Rust ...
auto square(int a) -> int {
  return a * a;
}

int main() {
  cout << square(4) << endl;
}

#endif