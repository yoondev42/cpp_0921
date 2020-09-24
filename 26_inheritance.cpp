
// 26_inheritance.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. 상속의 기본 개념 
//  - 공통의 특징을 묶어서, 별도의 클래스를 설계합니다.

#if 1
class Person {
  string name;
  int age;
};

// Student는 Person을 상속한다.
// Person  - Base class(기본 클래스) / Super class
// Student - Derived class(파생 클래스) / Sub class
// => 상속을 하게 되면, 부모가 제공하는 멤버 데이터와 멤버 함수를 물려 받는다.
class Student : public Person {
  int id;
};

class Professor : public Person {
  int major;
};
#endif


#if 0
class Student {
  string name;
  int age;
  int id;
};

class Professor {
  string name;
  int age;
  int major;
};
#endif

int main() {
  cout << sizeof(Student) << endl;
  cout << sizeof(Professor) << endl;
}