
// C++98/03 - 표준 라이브러리에 스레드가 제공되지 않았습니다.
//  - Windows: Windows API - CreateThread
//  - Linux: System Call   - pthread_create

// C++11 - 표준 라이브러리에 '스레드 라이브러리'가 추가되었습니다.

#include <iostream>
#include <thread>  // C++11
using namespace std;

void start_routine() {
  cout << "Thread start routine" << endl;
  while (1) {
    cout << "\tthread..." << endl;
    
    this_thread::sleep_for(chrono::seconds(1));
  }
}

int main() {
  // start_routine();
  thread t(&start_routine);

  while (1) {
    cout << "main...\n" << endl;
    this_thread::sleep_for(chrono::seconds(1));
  }
}