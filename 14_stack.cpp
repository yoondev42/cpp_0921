#include <iostream>
using namespace std;
// stack 만들기
//  => Last In First out(후입선출) 방식의 자료 구조 입니다.


// Version 5. Stack 타입 - 초기화가 자동으로 수행되도록 합시다.
//                      => Constructor(생성자) 도입

class Stack {
private:  
  int* buff;
  int  top;

public:
  // 생성자: 객체가 생성되는 시점에 호출되는 함수
  // 1) 함수 이름이 클래스 이름과 동일합니다.
  // 2) 반환 값이 없고, 반환 타입를 표현하지 않습니다.
  // 3) 인자가 없어도 되고, 있어도 됩니다.
  // => 객체가 생성 후에 바로 사용될 수 있도록 준비한다.

  // Stack s;
  Stack() {
    cout << "객체가 생성되는 시점에 자동적으로 호출됩니다." << endl;
    buff = new int[10];
    top = 0;
  }

  // 사용자가 Stack의 크기를 결정하도록 하고 싶다.
  // 사용자가 전달한 인자의 크기를 생성자를 통해서 전달 받을 수 있습니다.

  // Stack s(64);
  Stack(int size) {
    buff = new int[size];
    top = 0;
  }

  void push(int v) {
    buff[top++] = v;
  }

  int pop() {
    return buff[--top];
  }
};

int main() {
  cout << "Stack s1, s2 생성 전" << endl;
  Stack s1(64), s2(32);
  Stack s3;

  cout << "Stack s1, s2 생성 후" << endl;
  
  s1.push(10);
  s1.push(20);
  s1.push(30);

  // s1.top = 10;  // !?!?!?!?!?!?!
  
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
}

#if 0
// Version 4. Stack 타입 - Stack의 상태를 push / pop이 통해서가 아니라, 직접 변경하면 문제가 발생합니다.
//                        "정보 은닉" => 접근 지정자(private / public)

// struct
//  : 외부에서 접근이 기본적으로 허용됩니다. - public
// class
//  : 외부에서 접근이 기본적으로 허용되지 않습니다. - private
//  => 객체를 생성하는 '틀'이라는 개념

class Stack {
// private
// 외부에서 접근이 불가능합니다.
//  - Stack의 멤버 함수를 통해서만 값의 변경이 가능합니다.
private:  
  // 멤버 변수
  int buff[10];
  int top;

// 외부에서 접근이 가능합니다.
public:
  void init() {
    top = 0;
  }

  // 구조체 내부의 필드값을 변경하는 함수를 구조체 내부에 둘 수 있습니다.
  // => push / pop을 호출한 객체의 필드에 암묵적으로 접근하는 것이 가능합니다.
  // 멤버 함수(메소드 - Method)
  void push(int v) {
    buff[top++] = v;
  }

  int pop() {
    return buff[--top];
  }
};

int main() {
  Stack s1, s2;
  // 사용하기 전에 초기화가 필요합니다.
  // s1.top = 0;
  // s2.top = 0;
  s1.init();
  s2.init();
  // Stack을 사용하기 위해서는 반드시 위의 함수가 호출되어야 합니다.
  //  => 자동으로 호출되도록 할 수 있을까?
  
  s1.push(10);
  s1.push(20);
  s1.push(30);

  // s1.top = 10;  // !?!?!?!?!?!?!
  
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
}
#endif

#if 0
// Version 3. Stack 타입 - 멤버 함수 도입
struct Stack {
  // 멤버 변수
  int buff[10];
  int top;

  // 구조체 내부의 필드값을 변경하는 함수를 구조체 내부에 둘 수 있습니다.
  // => push / pop을 호출한 객체의 필드에 암묵적으로 접근하는 것이 가능합니다.
  // 멤버 함수(메소드 - Method)
  void push(int v) {
    buff[top++] = v;
  }

  int pop() {
    return buff[--top];
  }
};

int main() {
  Stack s1, s2;
  // 사용하기 전에 초기화가 필요합니다.
  s1.top = 0;
  s2.top = 0;

  s1.push(10);
  s1.push(20);
  s1.push(30);

  s1.top = 10;  // !?!?!?!?!?!?!
  
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
}
#endif

#if 0
// Version 2. Stack 타입
struct Stack {
  int buff[10];
  int top;
};

void push(Stack* s, int v) {
  s->buff[s->top++] = v;
}

int pop(Stack* s) {
  return s->buff[--s->top];
}

int main() {
  Stack s1, s2;
  // 사용하기 전에 초기화가 필요합니다.
  s1.top = 0;
  s2.top = 0;

  push(&s1, 10);
  push(&s1, 20);
  push(&s1, 30);

  cout << pop(&s1) << endl;
  cout << pop(&s1) << endl;
  cout << pop(&s1) << endl;
}
#endif




// Version 1. C언어 스타일로 만들기
//         : 전역 변수 / 함수
//   => 프로그램 내에 스택이 2개 이상 필요한 경우, 전역 변수를 계속 추가해주어야 합니다.

#if 0
int buff[10] = { 0, };
int top = 0;
// 데이터를 꺼내거나 집어넣어야 하는 위치

void push(int v) {
  buff[top++] = v;
}

int pop() {
  return buff[--top];
}

int main() {
  push(10);
  push(20);
  push(30);

  cout << pop() << endl;
  cout << pop() << endl;
  cout << pop() << endl;
}
#endif