// 22_static.cpp
// 1) 정적 멤버 데이터
//   : 모든 객체가 공유하는 멤버 데이터
//     객체를 생성하지 않아도, 메모리에 존재합니다.
//     전역 변수와 유사하지만, 클래스의 접근 지정자를 지정하는 것이 가능하다.
// 2) 정적 멤버 함수
//   : 객체 없이 호출 될 수 있는 멤버 함수
//     객체가 없이도 호출이 가능하기 때문에, 일반 함수와 유사하다.
//     클래스의 접근 지정자를 지정하는 것이 가능하다.

#include <iostream>
// using namespace std;

// int count = 0;
class Car {
public:
  Car() {
    count++;
  }

  ~Car() {
    count--;
  }

  // 정적 멤버 함수
  //  : 정적 멤버 데이터에 접근할 수 있는 멤버 함수
  // => 객체를 생성하지 않아도, 호출 가능하다.
  static int getCount() {
    return count;
  }

private:
  // 정적 멤버 데이터(변수)
  //  : Car의 모든 객체가 공유하는 변수

  // 클래스 내부 선언
  static int count;
};

// 클래스 외부(소스 파일) 정의 - 링크 오류가 발생합니다.
int Car::count = 0;


int main() {
  Car c1;
  Car c2;


  std::cout << Car::getCount() << std::endl;

  // std::cout << Car::count << std::endl;
  // std::cout << c1.getCount() << std::endl;
  // 멤버 함수를 통해 정적 멤버 데이터에 접근할 수 있다.
  // => 객체를 생성하지 않는 경우, 정적 멤버 데이터에 접근할 수 없을 수 있다.
}



// static 멤버 데이터
// 1. 클래스 외부에 정의가 필요합니다.
// 2. 객체를 생성하지 않아도 메모리가 할당됩니다.
// 3. sizeof(객체)의 크기에 포함되지 않는다.
// 4. 접근 방법
//    Car::count  - 클래스 이름을 통해 접근 가능하다. - 더 선호된다.
//    c.count     - 객체를 통해 접근 가능하다.


#if 0
int main() {
  Car c1;
  Car c2;
  Car c3;

  // count = 4;
  std::cout << sizeof(Car) << std::endl;
  // std::cout << Car::count << std::endl;  // ?
  std::cout << c1.count << std::endl;
}
#endif