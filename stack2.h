// stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>

// 아래의 스택은 int 타입에 대해서만 가능합니다.
// template을 도입하면, int 뿐 아니라
// 모든 타입에 대한 stack을 제공하는 것이 가능합니다.

// 핵심: 일반적인 클래스는 헤더와 소스로 분리하는 것이 가능합니다.
// => 템플릿 클래스는 오직 헤더를 통해서만 제공해야 합니다.

// Stack: class template
// => Stack<int>    : class type
// => Stack<double> : class type

template <typename T>
class Stack
{
public:
  Stack();
  Stack(int size);
  ~Stack();

  void push(const T &v);
  T pop();

private:
  T *buff;
  int top;
};

template <typename T>
Stack<T>::Stack()
{
  buff = new T[10];
  top = 0;
}

template <typename T>
Stack<T>::Stack(int size)
{
  buff = new T[size];
  top = 0;
}

template <typename T>
Stack<T>::~Stack()
{
  std::cout << "~Stack()" << std::endl;
  delete[] buff;
}

template <typename T>
void Stack<T>::push(const T &v)
{
  buff[top++] = v;
}

template <typename T>
T Stack<T>::pop()
{
  return buff[--top];
}

#endif