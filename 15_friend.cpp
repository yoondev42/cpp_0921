// 15_stack.cpp

#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
  // Stack s;
  Stack() {
    buff = new T[10];
    top = 0;
  }

  // Stack s(24) / Stack s{24}
  Stack(int size) {
    buff = new T[size];
    top = 0;
  }

  ~Stack() {
    delete[] buff;  
  }

  void push(const T& v) {
    buff[top++] = v;
  }

  T pop() {
    return buff[--top];
  }

  
  friend void foo(Stack<int>* s);

  // 멤버 함수가 아니라 일반 함수 입니다.
  // friend 함수에 대한 선언과 정의를 동시에 하는 것도 가능하다.
  friend void goo(Stack<T>* s) {

  }

  friend class Calculator;
  
private:
  void print() {
    cout << "Stack" << endl;
  }

  T* buff;
  int top;
};


// 일반적인 객체 지향 언어에서는 외부에서 클래스의 private에 접근할 수 있는 방법을 제공하지 않습니다.
// C++은 가능한 문법이 존재합니다.
// => friend
//  1) 함수
//  2) 클래스

class Calculator {
public:
  Calculator() {
    s.top = 0;  // friend class는 가능하다!
  }

private:
  Stack<int> s;
};


void foo(Stack<int>* s) {
  s->top = 0;

  s->print();
}


int main() {
  Stack<int> s1;
  Stack<double> s2(32);

  s1.push(10);
  s1.push(20);
  s1.push(30);

  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
}