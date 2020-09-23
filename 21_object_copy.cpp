// 21_object_copy.cpp
// => 매우 중요한 내용입니다.
#include <iostream>
using namespace std;

// 내부에 포인터를 기반으로 하는 멤버가 존재한다면,
// => 복사 생성자를 재정의 해야 한다.
// 1) Deep copy

class Person {
public:
  Person(const char* n, int a) : age(a) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
  }

  ~Person() {
    delete[] name;
  }

#if 0
  Person(const Person& rhs) : name(rhs.name), age(rhs.age) {
  }
#endif
  Person(const Person& rhs) : age(rhs.age) {
    name = new char[strlen(rhs.name) + 1];
    strcpy(name, rhs.name);
  }

private:
  char* name;
  int age;
};

int main() {
  Person p1("Tom", 42);

  Person p2(p1);        // 객체를 '복사 생성자'를 통해 생성한다.
}