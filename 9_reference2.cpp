
#include <iostream>
using namespace std;

// call by value
#if 0
void inc(int x) {
  ++x;
}
#endif

#if 0
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
#endif

// 배열을 전달할 때, 배열의 이름을 통해 전달한다.
// 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석되기 때문에, 배열의 크기를 절대 알 수 없다.
// 따라서 포인터로 전달되는 배열은 반드시 사이즈에 대한 정보가 추가적으로 전달되어야 한다.
void print_array(int *x, int n)
{
  printf("%ld\n", sizeof(x)); // 8

  for (int i = 0; i < n; ++i)
  {
    cout << x[i] << endl;
  }
}

void print_array(int (&x)[10])
{
  printf("%ld\n", sizeof(x));
  int n = sizeof(x) / sizeof(x[0]);

  for (int i = 0; i < n; ++i)
  {
    cout << x[i] << endl;
  }
}

// int x[10] => int[10]


// print_array(x, 10)   -> print_array(int* x, int)
//  int* x = x;   - decay

// print_array(x)       -> print_array(int(&x)[10])
//  int (&x)[10] = x;

void print_array2(int (&arr)[2][3]) {
  
}

int main()
{
  int arr[2][3] = { 0, };
  print_array2(arr);

  int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // print_array(x, 10);

  print_array(x);
}