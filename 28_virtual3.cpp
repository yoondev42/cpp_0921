// 가상 소멸자???
#include <iostream>
using namespace std;


#include <string>

class User {
public:
  User()  { cout << "User()" << endl;  }
  virtual ~User() { cout << "~User()" << endl; }
  // 기반 클래스의 소멸자는 반드시 가상함수 이어야 합니다.
  // 기반 클래스의 소멸자가 가상 함수이면, 자식 클래스의 소멸자도 자동으로 가상입니다.
};
// => 클래스의 소멸자가 가상 함수가 아니라면, 상속하면 안됩니다.
//    클래스의 소멸자가 가상 함수로 제공된다면, 상속을 사용해도 됩니다.

class Student : public User {
public:
  Student()  { cout << "Student()" << endl;  }
  virtual ~Student() { cout << "~Student()" << endl; }
};

int main() {
  // User u;
  
  // Student s;

  // Student의 소멸자가 제대로 호출되지 않았습니다.
  // 이유?: 
  User* p = new Student;
  delete p;
  // 소멸자도 함수 입니다.
  // - 바인딩
  //   '정적 바인딩'
  //    => ~User()
}

