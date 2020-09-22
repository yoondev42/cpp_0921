// stack.cpp

// 1. 클래스 선언에 대한 헤더를 포함한다.
#include "stack.h"
#include <iostream>

// 2. 생성자, 소멸자, 멤버 함수에 대한 구현을 제공한다.

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
