#include <stdio.h>
#include <unistd.h> // unix standard - sleep
// #include <Windows.h>

// Thread
//  : 프로세스에 내에서 함수를 실행할 수 있는 실행 흐름. => OS의 자원

// C / C++
//------------------
// OS가 제공하는 서비스 - Windows API / system call   =>  System Programming


// System Call - Linux / Posix Thread => pthread(C 언어)
//  - 스레드는 함수를 실행하기 하기 때문에, 각 스레드마다 별도의 스택이 할당된다.

// g++ 1.cpp -pthread
#include <pthread.h>
// pthread_create
// int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)

void* start_routine(void* arg) {
  printf("Thread start routine...\n");

  while (1) {
    printf("Thread\n");
    sleep(1);
  }
}

// g++ 25_thread.cpp
int main() {
  pthread_t thread;
  pthread_create(&thread, 0, &start_routine, 0);
  // start_routine(0);

  while (1) {
    printf("main\n");
    sleep(1);
  }
}

#if 0
#include <stdio.h>
// #include <unistd.h> // unix standard - sleep
#include <Windows.h>

// Thread
//  : 프로세스에 내에서 함수를 실행할 수 있는 실행 흐름. => OS의 자원

// C / C++
//------------------
// OS가 제공하는 서비스 - Windows API / system call   =>  System Programming


// System Call - Linux / Posix Thread => pthread(C 언어)
//  - 스레드는 함수를 실행하기 하기 때문에, 각 스레드마다 별도의 스택이 할당된다.

// g++ 1.cpp -pthread
// #include <pthread.h>
// pthread_create
// int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)

// __cdecl: caller가 스택을 정리한다.
// __stdcall: callee가 스택을 정리한다.
//  ret 4
DWORD WINAPI start_routine(LPVOID arg) {
  printf("Thread start routine...\n");

  while (1) {
    printf("Thread\n");
    Sleep(1000);
  }

  return 0;
}

// g++ 25_thread.cpp
int main() {

  CreateThread(NULL, 0, &start_routine, 0, 0, 0);


  while (1) {
    printf("main\n");
    Sleep(1000);
  }
}

#endif