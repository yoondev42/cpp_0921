
// Decay
// 1. 배열
// 2. 함수

// int arr[2][3]   =>   int[2][3]   =>  [ int[3] ][ int[3] ]
//     arr     디케이=>   &arr[0]     =>   &int[3]    =>   int (*)[3]

// 디케이 예외
//  1. &
//  2. sizeof
//  3. 레퍼런스

int (*foo())[3] {
  static int arr[2][3] = { 0, };
  return arr;
}

int add(int a, int b) {
  return a + b;
}

// 1. add의 타입은 무엇입니까?
//   => int(int a, int b)

// 2. 함수 포인터 타입
//   => int(*)(int a, int b)

// 3. 함수의 Decay
//   => 함수의 이름은 함수 포인터 타입으로 해석된다.

int main() {
  // int (*p)(int, int) = &add;

  int (*p)(int, int) = add;
}
