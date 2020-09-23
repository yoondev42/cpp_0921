
// Thread는 동시성 오류가 발생할 수 있습니다.
// 1. 프로세스는 처음 시작될 때 1개의 스레드를 가집니다.
//    main을 수행합니다.
//    => main thread / primary thread

// 2. 프로세스가 종료하면, 프로세스 내의 모든 스레드는 종료됩니다.
// 3. main 함수가 반환하면, 프로세스는 종료합니다.

#include <pthread.h>
#include <stdio.h>

void* foo(void* arg) {
  printf("foo\n");

  return 0;
}

int main() {
  pthread_t thread[2];

  pthread_create(&thread[0], NULL, &foo, NULL);
  pthread_create(&thread[1], NULL, &foo, NULL);

  // pthread_join - 스레드가 종료할 때까지 대기한다.
  pthread_join(thread[0], 0);
  pthread_join(thread[1], 0);


}