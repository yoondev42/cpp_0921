// 34_operator4.cpp

// C++ 연산자 재정의 중에서 많이 하는 연산자 재정의
//  => ++, --

#include <iostream>
using namespace std;

class Integer {
public:
  Integer(int a = 0) : n(a) {}

  // 사용자 정의 타입(클래스)
  //  - 전위 증가가 후위 증가보다 효율적이다.
  //    : 반환값의 타입이 참조이기 때문에 임시 객체가 생성되지 않는다.

  // operator++(): 전위 증가 - 자기 자신을 반환한다.
  Integer& operator++() {
    ++n;
    return *this;
  }

  // operator++(int): 후위 증가 - 복사본을 반환한다.
  Integer operator++(int) {
    // int ret = n++;
    // return Integer(ret);

    Integer temp = *this;  // 복사를 통해 생성한다.
    ++(*this);             // 이미 만들어놓은 전위 증가 함수를 사용한다. "정책을 재사용한다."
    return temp;
  }

  friend ostream& operator<<(ostream& os, const Integer& i);
private:
  int n;
};

ostream& operator<<(ostream& os, const Integer& i) {
  os << i.n;
  return os;
}


int main() {
  Integer n = 42;

  // ++n; 
  n++;
  ++++++++n;

  // cout을 통해서 Integer를 출력해야 한다.
  cout << n << endl; 

  // cout << ++n << endl;
  // cout << --n << endl;

}