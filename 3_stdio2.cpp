// 3_stdio2.cpp
#include <iostream>
#include <iomanip>  // setw

// - 입출력 조정자(IO manipulator)
// 주의할 점: 입출력 조정자가 적용된 이후로, cout/cin의 출력 상태가 유지된다.
// std::hex - 16진수
// std::oct - 8진수
// std::dec - 10진수

int main() {
  int n = 255;

  std::cout << std::hex << n << std::endl;
  std::cout << std::uppercase << n << std::endl;
  std::cout << std::setw(4) << n << std::endl;
  std::cout << std::setw(4) << std::setfill('0') << n << std::endl;

  printf("%04X\n", n);
  // 입출력 조정자는 함수의 형태로 되어 있다.

  // std::cout << std::dec << n << std::endl;

  // std::cout << n << std::endl;
  // std::cout << std::hex << n << std::endl;
  // std::cout << std::oct << n << std::endl;
}