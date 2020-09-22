#include <iostream>
using namespace std;
// stack 만들기
//  => Last In First out(후입선출) 방식의 자료 구조 입니다.

// Version 1. C언어 스타일로 만들기
//         : 전역 변수 / 함수

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