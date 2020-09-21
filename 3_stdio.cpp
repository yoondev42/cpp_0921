// 3_stdio.cpp


#include <iostream>
// using namespace std;

// 생각해 볼 점
// 1. printf / scanf 함수
//    std::cout / std::cin 정체?
// 2. scanf는 변수의 값을 변경하기 위한 함수입니다.
//    => 주소를 인자로 전달합니다.
//    std::cin은 주소를 전달하지 않습니다.
//    어떤 원리로 값을 변경시킬 수 있는 것인가요?
// 3. std::cout / std::cin에 대해서 서식을 지정하지 않습니다.
//    서식을 지정하지 않아도, 출력이 가능한가요?
// 4. std::endl 정체?

int main() {
  int n1 = 42;
  char n2 = 'a';
  double n3 = 3.14;

  std::cout << n1 << ", " << n2 << ", " <<  n3 << std::endl;
}

#if 0
int main() {
  double n = 0;

  // 1) 서식을 지정하지 않습니다.
  // 2) 주소를 전달하지 않습니다.
  std::cin >> n;

  // - 서식을 지정하지 않습니다.
  std::cout << n;
  std::cout << std::endl;
}
#endif



#if 0
#include <stdio.h>

int main() {
  int n = 0;

  scanf("%d", &n);
  printf("%d\n", n);
}
#endif