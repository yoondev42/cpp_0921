
// STL이 제공하는 기본 컨테이너의 간단한 사용방법.
#include <iostream>
#include <vector>
#include <list>
// 위는 '선형적인 자료구조' 입니다.
// 1. vector: 연속된 메모리
//    => 임의 접근이 가능하다.
//    => '동적 배열': 실행 시간에 할당된 메모리가 부족하면, 자동으로 더 큰 크기로 할당한다.

// 2. list: 연결 리스트(연속된 메모리가 아닙니다.)
//    => 임의 접근이 불가능하다.

int main() {
  // std::list<int> v;
  std::vector<int> v;

  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  // list는 임의 접근이 불가능합니다.
  // v[2] = 10;
  // std::cout << v[2] << std::endl;

  // vector는 push_front 등의 중간 삽입이 지원되지 않는다.
  // v.push_front(24);

  for (auto e : v) {
    std::cout << e << std::endl;
  }
}

#if 0
int main() {
  // std::vector<int> v(4);  // vector의 메모리의 크기와 사이즈를 4개로 할당한다.
  // v.resize(0);
  std::vector<int> v;
  v.reserve(4);     // capacity만 늘린다.
  
  std::cout << "size:" << v.size() << std::endl;
  std::cout << "capacity: " << v.capacity() << std::endl;
  
  // size: 현재 가지고 있는 데이터의 크기
  // capacity: 현재 할당된 메모리의 크기
  //   => 모자르면, 재할당이 발생한다.
  //      크기의 2배씩 늘어난다.

  v.push_back(10);
  std::cout << "size:" << v.size() << std::endl;
  std::cout << "capacity: " << v.capacity() << std::endl;

  v.push_back(20);
  std::cout << "size:" << v.size() << std::endl;
  std::cout << "capacity: " << v.capacity() << std::endl;

  v.push_back(30);
  std::cout << "size:" << v.size() << std::endl;            // 3
  std::cout << "capacity: " << v.capacity() << std::endl;   // 4

  // 임의 접근은 배열처럼 사용할 수 있다.
  v[2] = 40;
  std::cout << v[2] << std::endl;

  for (int i = 0 ; i < v.size(); ++i) {
    std::cout << v[i] << std::endl;
  }

  // ranged for - C++11
  for (auto e : v) {
    std::cout << e << std::endl;
  }
}
#endif