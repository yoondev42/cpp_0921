#include <string>
#include <iostream>
using namespace std;

class String {
public:
  String(const char* s) {
    size = strlen(s);
    buff = new char[size + 1];
    strcpy(buff, s);
  }

  ~String() {
    delete[] buff;
  }

  String(const String& rhs) : size(rhs.size) {
    buff = new char[size + 1];
    strcpy(buff, rhs.buff);
  }

  // 1. 기존 자원에 대한 해지가 필요한가?
  // 2. 자기 자신에 대한 대입에 대한 예외 처리
  String& operator=(const String& rhs) {
    if (&rhs == this)
      return *this;

    delete[] buff;  // !!!
    size = rhs.size;
    buff = new char[size + 1];
    strcpy(buff, rhs.buff);

    return *this;
  }


  friend ostream& operator<<(ostream& os, const String& s) {
    os << s.buff;
    return os;
  }

private:
  char* buff;
  int size;
};


// String 클래스 만들기
int main() {
  String s1 = "hello";    // String(const char*)
  cout << s1 << endl;     // ostream& operator<<(ostream& s, const String&)

  String s2 = s1;         // String(const String&)
  cout << s2 << endl;

  String s3 = "world";    
  s3 = s1;                // String& operator=(const String& s)
  cout << s3 << endl;

  s3 = s3;

}