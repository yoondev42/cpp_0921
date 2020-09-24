
// Thread는 동시성 오류가 발생할 수 있습니다.
// 1. 프로세스는 처음 시작될 때 1개의 스레드를 가집니다.
//    main을 수행합니다.
//    => main thread / primary thread

// 2. 프로세스가 종료하면, 프로세스 내의 모든 스레드는 종료됩니다.
// 3. main 함수가 반환하면, 프로세스는 종료합니다.
// 4. 스레드는 자신만의 스택을 가진다.
//    스택에 생성되는 지역 변수는 공유되지 않는다.
#include <pthread.h>
#include <stdio.h>

int n;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* foo(void* arg) {  
  printf("foo\n");

  for (int i = 0 ; i < 1000000; ++i) {
    //------
    pthread_mutex_lock(&mutex);
    n += 1;
    // n의 값을 1 증가하는 연산은 '원자'적이지 않습니다.
    // 1. n의 값을 레지스터로 로드합니다.
    // 2. 레지스터의 값을 증가한다.
    // 3. 레지스터의 값을 n에 복사한다.
    //------ 임계 영역: Critical Section
    //                - 오직 1개의 스레드만 진입할 수 있도록 동기화한다. => 상호배제(mutual exclustion) => mutex
    pthread_mutex_unlock(&mutex);
  }

  return 0;
}

int main() {
  pthread_t thread[2];

  pthread_create(&thread[0], NULL, &foo, NULL);
  pthread_create(&thread[1], NULL, &foo, NULL);

  // pthread_join - 스레드가 종료할 때까지 대기한다.
  pthread_join(thread[0], 0);
  pthread_join(thread[1], 0);

  printf("foo: %d\n", n);


}