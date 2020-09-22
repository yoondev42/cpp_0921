// stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>

// 아래의 스택은 int 타입에 대해서만 가능합니다.
// template을 도입하면, int 뿐 아니라 
// 모든 타입에 대한 stack을 제공하는 것이 가능합니다.

// 핵심: 일반적인 클래스는 헤더와 소스로 분리하는 것이 가능합니다.
// => 템플릿 클래스는 오직 헤더를 통해서만 제공해야 합니다.

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

Stack::Stack()
{
  buff = new int[10];
  top = 0;
}

Stack::Stack(int size)
{
  buff = new int[size];
  top = 0;
}

Stack::~Stack()
{
  std::cout << "~Stack()" << std::endl;
  delete[] buff;
}

void Stack::push(int v)
{
  buff[top++] = v;
}

int Stack::pop()
{
  return buff[--top];
}


#endif