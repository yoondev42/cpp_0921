#include <iostream>
using namespace std;
// stack 만들기
//  => Last In First out(후입선출) 방식의 자료 구조 입니다.


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