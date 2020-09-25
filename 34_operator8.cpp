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

  String& operator=(const String& rhs) {
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
}