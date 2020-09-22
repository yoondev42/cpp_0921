// stack.h

// 1. include guard
//  => 헤더 파일의 중복 포함을 방지한다.
#ifndef STACK_H
#define STACK_H

class Stack
{
private:
  int *buff;
  int top;

public:
  Stack();
  Stack(int size);
  ~Stack();

  void push(int v);
  int pop();
};

#endif