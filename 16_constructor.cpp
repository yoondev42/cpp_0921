// 16_constructor
#include <iostream>
using namespace std;

// 생성자
// - 객체를 만들면 자동으로 생성자가 호출됩니다.
// 1. 클래스의 이름과 동일하며, 반환값을 가질 수 없고, 반환 타입을 표기하지도 않습니다.
// 2. 생성자를 제공하지 않을 경우, 컴파일러가 자동으로 기본 생성자(인자가 없는 생성자 - default constructor)를 제공해줍니다.
//   - 사용자가 생성자를 한 개 이상 제공할 경우, 기본 생성자는 생성되지 않습니다.

class Point {
public:
  Point() {
    x = 0;
    y = 0;
  }

  Point(int a, int b) {
    x = a;
    y = b;
  }

private:
  int x;
  int y;
};

int main() {
  Point p1(10, 20);
  Point p2{10, 20};  // C++11 Uniform Initialization

  // 배열
  Point arr[2];
  // Point arr[2] = { Point(10, 20), Point(20, 30) }
  // 위처럼 만들었을 경우, 기본 생성자를 호출합니다.
  // 기본 생성자가 없는 경우, 반드시 초기화를 수행해주어야 합니다.

}