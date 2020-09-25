
#include <iostream>
using namespace std;
// 연산자 재정의 활용

class Image {
public:
  Image() { cout << "Image 생성" << endl; }
  ~Image() { cout << "Image 파괴" << endl; }

  void draw() { cout << "Image draw" << endl; }
};

// 동적 메모리 할당을 통해 생성된 자원은 반드시 delete가 호출되어야 한다.
// 일반 포인터를 통해 사용할 경우, delete를 잊을 위험이 있다.
// => 포인터처럼 동작하는 클래스를 설계해서, 자동적으로 메모리가 관리되도록 하자.
//   : 스마트 포인터

// 핵심
//   - 언어의 동작에 새로운 기능을 추가하는 것은 불가능하다.
//   - 객체가 해당 기능을 대신하도록 변경한다면,
//        생성자를 통해 생성의 방법을 제어하고,
//        소멸자를 통해 파괴의 방법을 제어하고,
//        연산자 오버로딩을 통해 다양한 활용이 가능하다.

class Ptr {
public:
  Ptr(Image* p = nullptr) : obj(p) {}
  ~Ptr() {
    if (obj)
      delete obj;
  }

  Image& operator*() {
    return *obj;
  }

  Image* operator->() {
    return obj;
  }

private:
  Image* obj;
};

// 위에서 만든 Ptr은 Image에 대해서만 사용할 수 있습니다.
// C++은 범용적으로 사용할 수 있는 몇가지 스마트 포인터를 제공하고 있습니다.
#include <memory>
// shared_ptr: 참조 계수로 관리한다.

int main() {
  // Ptr p = new Image;
  shared_ptr<Image> p(new Image);
  shared_ptr<Image> p2 = p;

  (*p).draw();
  // (p.operator*()).draw();

  p->draw();
  // (p.operator->())->draw()
}


#if 0
int main() {
  Image* p = new Image;  // 생성자

  (*p).draw();     // *
  p->draw();       // ->

  delete p; // !         // 소멸자
}
#endif