
// 9_reference3.cpp
#include <iostream>
using namespace std;


// Built-in Type / 크기가 작은 타입(Empty object)
//     Call by Value
//          foo(Type t)
//     Call by Refrence(Pointer)
//          foo(Type* t)

// 크기가 큰 사용자 정의 타입
//     Call by Value
//          foo(const Type& t)
//     Call by Reference(Pointer)
//          foo(Type* t)


struct Image {
  char data[512];
};

void foo(const int& n) {
  cout << "int" << endl;
}

// C-Style
void foo(Image* image) {
  cout << "foo(Image)" << endl;
}

// C++ Style call by value  => const T&
// : const & 타입이므로, 복사의 비용이 발생하지 않는다.
void foo(const Image& image) {
  // image.data[0] = 'a';
  // const&는 참조를 통해 전달된 변수의 값을 변경하는 것이 불가능하다.
}

int main() {
  int n = 30;
  foo(30);

  
  Image image;
  printf("%ld\n", sizeof(image));
  // foo(&image);
  foo(image);

  // foo(30);  // foo(int)
  // foo(n);   // 모호성 오류!
}