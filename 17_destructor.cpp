// 17_destructor.cpp
#include <iostream>
using namespace std;

// 모든 객체는 생성될 때 생성자가 호출되고, 파괴될 때 소멸자가 호출됩니다.
// 소멸자 특징
// 1. 함수 이름은 ~클래스이름() 입니다.
// 2. 반환 타입을 표시하지 않고, 인자도 가질 수 없습니다.
// 3. 오직 한개만 만들 수 있습니다.
// 4. 사용자가 소멸자를 제공하지 않을 경우, 아무일도 수행하지 않는 컴파일러가 소멸자를 제공해줍니다.
// 5. 생성자에서 '자원'을 할당한 경우, 소멸자를 통해서 자원을 반납해야 합니다.
//       자원
//        1) 메모리 자원: 동적 메모리 할당(new, malloc)
//        2) 비메모리 자원: 파일, 스레드, 프로세스
//                      '운영체제의 자원'

// private 소멸자
//  => 힙에만 객체를 생성하고 싶다.
class User {
public:
  // this: 자기 자신을 가르키는 포인터
  //   => 멤버 함수에서만 사용할 수 있습니다.
  void release(/* User* p */) {
    // delete p;
    delete this;
  }

private:
  ~User() {
    cout << "~User()" << endl;
  }
};

int main() {
  // User user;
  // => 소멸자를 private 두면, 스택에 객체를 생성할 수 없다.

  User* p = new User;
  // delete p;
  // p->release(p);
  p->release();
}






//     - new -> delete
#if 0
class Person
{
public:
  Person(const char *s)
  {
    name = new char[strlen(s) + 1];
    strcpy(name, s);
  }

  ~Person()
  {
    delete[] name;
  }

private:
  char *name;
};
#endif


// Unix(Linux) 설계 철학: 모든 것은 '파일'이다.
//  - 프로세스가 시작될 때, 3개의 파일이 자동으로 오픈되어 있습니다.
//  0: 키보드          - stdin
//  1: 출력장치        - stdout
//  2: 에러장치(출력장치) - stderr

// printf / scanf / getchar / putchar
// FILE*
//  - 일반 파일을 열고, 닫을 수 있다.
//  fopen
//  fclose

#if 0
#include <stdio.h>
int main()
{
  int n;

  FILE* fp = fopen("a.txt", "w");
  // "r": 파일을 읽기모드로 연다.
  //      파일이 존재하지 않을 경우, NULL을 반환한다.
  // "w": 파일을 쓰기모드로 연다.
  //      파일이 존재하지 않을 경우, 새로 생성한다.
  //      파일이 존재할 경우, 파일의 크기를 0으로 조정한다.

  // 0번 파일로부터 입력을 받는다.
  // scanf("%d", &n);
  fscanf(stdin, "%d", &n);

  // 1번 파일에 출력한다.
  // printf("out: %d\n", n);
  // fprintf(stdout, "out: %d\n", n);
  fprintf(fp, "out: %d\n", n);

  fclose(fp);
}
#endif

#if 0
class Point {
public:
  Point() {
    cout << "Point()" << endl;
  }

  // ~Point() {
  //   cout << "~Point()" << endl;
  // }

private:
  int x;
  int y;
};

int main() {
  cout << "main()" << endl;
  
  Point p;       // stack
  
  cout << "main() 종료" << endl;
}
#endif