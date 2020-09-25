#include <iostream>
#include <string>
using namespace std;


class Point {
public:
  Point(int a, int b) : x(a), y(b) {}

  friend Point operator+(const Point& lhs, const Point& rhs);  
  friend ostream& operator<<(std::ostream& os, const Point& p);
  friend istream& operator>>(std::istream& is, Point& p);
private:
  int x;
  int y;
};

// 연산자 재정의 함수
Point operator+(const Point& lhs, const Point& rhs) {
  Point ret(lhs.x + rhs.x, lhs.y + rhs.y);
  return ret;
}

// 사용자 정의 타입을 cout을 통해 출력하기 위해서는 아래 함수를 제공해야 합니다.
// cout: 객체 - std::ostream 타입
ostream& operator<<(std::ostream& os, const Point& p) {
  os << p.x << ", " << p.y;
  
  return os;
  // 연쇄 호출을 통해 사용할 수 있습니다.
}

// cin: std::istream
istream& operator>>(std::istream& is, Point& p) {
  is >> p.x >> p.y;
  return is;
}

#if 0
ostream& operator<<(ostream& (*__pf)(ostream&)) {
  __pf(*this);
  return *this;
}
#endif

ostream& xendl(ostream& os) {
  os << '\n';
  return os;
}

ostream& tab(ostream& os) {
  os << '\t';
  return os;
}

ostream& menu(ostream& os) {
  os << "1. 짜장면" << endl;
  os << "2. 김치찌개" << endl;
  os << "3. 비빔밥" << endl;
  return os;
}

// IO manipulator
//  : 함수를 정의하면, 사용자도 편리하게 입력 조정자를 구현할 수 있습니다.
//  endl, hex, oct ...
// => 정체: 함수였다.

int main() {
  cout << menu;

  cout << tab << hex << 10;

  // xendl(cout);

  cout << xendl << xendl;
  // 1. cout.operator<<(xendl);
  // 2. xendl(cout);

  // cout << endl;
  // cout.operator<<(endl);
}

/*
int main() {
  int n = 0;
  Point pt(0, 0);

  cin >> pt;
  cout << pt << endl;
  // ?
}
*/

#if 0
int main() {
  Point p1(1, 1);
  Point p2(2, 2);

  Point p3 = p1 + p2;

  int n = 100;

  // cout << n;
  // cout.operator<<(n);

  cout << p3 << " - Point " << endl;
  // cout.operator<<(p3).operator<<(", ").operator(endl);



  // cout.operator(const Point&)
  //  => 사용자는 자신이 만든 클래스가 아닌 연산자 재정의 함수를 멤버 함수로 제공할 수 없다.
  //  => 일반 함수 버전으로 제공하면 됩니다.

}
#endif