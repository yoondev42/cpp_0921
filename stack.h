// stack.h

// 1. include guard
//  => 헤더 파일의 중복 포함을 방지한다.
#ifndef STACK_H
#define STACK_H

// 코딩 관례
class Stack
{
public:
  Stack();
  Stack(int size);
  ~Stack();

  void push(int v);
  int pop();

private:
  int *buff;
  int top;
};



#endif