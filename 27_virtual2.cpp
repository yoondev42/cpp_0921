// 27_virtual2.cpp
#include <iostream>
using namespace std;

// Upcasting 활용
// 1. 동종(동일한 기반 클래스 타입을 사용하는 타입)을 처리하는 함수
// 2. 동종을 보관하는 컨테이너(컬렉션) - 자료구조
//                 STL
//                    vector / list / set / map / unoredred_map / stack / queue / deque ...

class Animal {
public:
  int age;
};

class Dog : public Animal {
};
class Cat : public Animal {
};

// 오직 Animal의 멤버 데이터 또는 멤버 함수를 사용해야 한다.
bool is_older_than_10(Animal* d) {
  return d->age > 10;
}

#if 0
int main() {
  Dog d;
  Cat c;

  is_older_than_10(&d);
  is_older_than_10(&c);
}
#endif