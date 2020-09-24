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

#include <vector>
#include <list>
#include <string>
#include <map>

// 동일 부모를 가진 다양한 타입을 하나의 컨테이너에서 관리하는 것이 가능하다.
// => "A", "B"가 동일 부모를 가진다면, 부모의 참조타입을 기반으로 하는 컨테이너를 통해 관리하는 것이 가능하다.
int main() {
  Dog d;
  Cat c;

  list<Animal*> v;  // Cat, Dog
  v.push_back(&d);
  v.push_back(&c);

  map<std::string, Animal*> m;
  m["개"] = &d;
  m["고양이"] = &c;
}




#if 0
int main() {
  Dog d;
  Cat c;

  is_older_than_10(&d);
  is_older_than_10(&c);
}
#endif