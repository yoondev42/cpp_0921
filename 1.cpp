#include <stdio.h>

// $ cc 1.c
// $ g++ 1.cpp
//         cc, cxx

int main() {
  printf("Hello, C\n");
}


// Compiler
//  Windows: Microsoft Visual C++ - cl.exe
//      GNU: gcc(mingwc)
//     LLVM: clang

// Lightweight Virtual Machine - LLVM

// C / C++
//   1.c     ->   1.o(object file)  ->     a.exe(a.out)
//         compile                linking

// LLVM
//   1.c    ->   I.L(중간 언어) -> 1.o -> a.exe
//   ObjC
//   swift
//   kotlin

// Java / C# - Write Once, Run Anywhere
//  Hello.java -> Hello.class(byte code) -> java Hello 
//          compile(javac)

//  jRuby
//  jython
//  Scala / Kotlin

// bytecode: 자바 가상 머신이 해석할 수 있는 기계어

