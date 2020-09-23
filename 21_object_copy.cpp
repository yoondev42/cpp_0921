// 21_object_copy.cpp
// => 매우 중요한 내용입니다.
#include <iostream>
using namespace std;

// 내부에 포인터를 기반으로 하는 멤버가 존재한다면, 동적 할당된 메모리가 존재한다면, 기본 복사 생성자는 얕은 복사의 문제가 있습니다.
// => 반드시! 복사 생성자를 재정의 해야 한다.
// 1) 깊은 복사(Deep copy)
// 2) 참조 계수를 사용한 복사 기술

class Person {
public:
  Person(const char* n, int a) : age(a) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);

    ref = new int;
    *ref = 1;  
  }

  ~Person() {
    if (--*ref == 0) {
      delete[] name;  
      delete ref;
    }
  }

  Person(const Person& rhs) : name(rhs.name), age(rhs.age), ref(rhs.ref) {
    ++*ref;
  }

private:
  char* name;
  int age;

  int* ref;
};

int main() {
  Person p1("Tom", 42);
  Person p2(p1);
  Person p3(p1);
}


#if 0
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
  // valgrind --tool=memcheck --leak-check=full ./a.out
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

  cout << "main end...\n" << endl;
}
#endif