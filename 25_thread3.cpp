
// C++98/03 - 표준 라이브러리에 스레드가 제공되지 않았습니다.
//  - Windows: Windows API - CreateThread
//  - Linux: System Call   - pthread_create

// C++11 - 표준 라이브러리에 '스레드 라이브러리'가 추가되었습니다.

#include <iostream>
#include <thread>  // C++11
#include <mutex>   // C++11
using namespace std;

mutex m;

class Car {
public:
  static int n;   // 전역 변수와 마찬가지로 '스레드 간에 공유'됩니다.
                  // => 동기화가 필요하다.
};

int Car::n = 0;

int n = 0;
void inc() {
  for (int i = 0 ; i < 1000000; ++i) {
    m.lock();
    // n += 1;
    Car::n += 1;
    m.unlock();
  }
}

int main() {
  thread t1(&inc);
  thread t2(&inc);

  t1.join();
  t2.join();
  cout << Car::n << endl;
}


#if 0
void start_routine() {
  cout << "Thread start routine" << endl;
  while (1) {
    cout << "\tthread..." << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
  }
}

// g++ 25_thread3.cpp -pthread
int main() {
  // start_routine();
  thread t(&start_routine);

  while (1) {
    cout << "main...\n" << endl;
    this_thread::sleep_for(chrono::seconds(1));
  }
}
#endif