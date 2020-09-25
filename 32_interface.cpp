// 32_interface.cpp
#include <iostream>
using namespace std;

// 약한 결합(느슨한 결합) - loosely coupling
//  => 교체 가능한 확장성 있는 디자인(설계)

// 1. 규칙을 먼저 설계한다.
//   "Car의 블랙박스 카메라가 가져야하는 기능에 대한 규칙(약속)" - 'interface' / protocol

class IBlackBoxCamera {
public:
  virtual ~IBlackBoxCamera() {}

  virtual void startRecording() = 0;
  virtual void stopRecording() = 0;
};

class Car {
public:
  void setBlackboxCamera(IBlackBoxCamera* p) { pCamera = p; }
  void startBlackboxCamera() {
    pCamera->startRecording();
  }

private:
  IBlackBoxCamera* pCamera;
};

//----------------------
// 2. 자동차에 연결하기 위한 모든 카메라는 반드시 IBlackBoxCamera 추상 클래스로부터 파생되어야 한다.
class Camera : public IBlackBoxCamera {
public:
  void startRecording() override { cout << "startRecording" << endl; }
  void stopRecording() override { cout << "stopRecording" << endl; }
};

// 3. IBlackBoxCamera의 추상 클래스의 파생 클래스는 기존의 코드를 수정하지 않고도 Car가 사용할 수 있다.
class FHDCamera : public IBlackBoxCamera {
public:
  void startRecording() override { cout << "startRecording" << endl; }
  void stopRecording() override { cout << "stopRecording" << endl; }
};

int main() {
  Camera c;
  FHDCamera c2;
  Car car;

  car.setBlackboxCamera(&c2);
  car.startBlackboxCamera();
}





#if 0
// 문제점
//  : Car의 카메라는 새로운 타입의 카메라로 교체하는 것이 불가능하다.
//   => Car 타입이 Camera 타입에 의존한다.
//   => Car 타입은 Camera와 강한 결합이 형성되어 있다.
//   강한 결합: 특정한 클래스가 다른 클래스를 이용할 때, 구체적인 타입에 의존하는 것
//    : 교체가 불가능하고, 확장성이 없다.

class Camera {
public:
  void startRecording() { cout << "startRecording" << endl; }
  void stopRecording() { cout << "stopRecording" << endl; }
};

class Car {
public:
  void setBlackboxCamera(Camera* p) { pCamera = p; }
  void startBlackboxCamera() {
    pCamera->startRecording();
  }

private:
  Camera* pCamera;
};
//----------------------------------------------

// 새로운 카메라가 개발되었습니다.
//  => OCP
//  => 수정에는 닫혀 있고, 확장에는 열려 있어야 한다.
//  => 새로운 기능이 추가되어도 기존 코드는 수정되면 안된다.

class FHDCamera {
public:
  void startRecording() { cout << "FHD startRecording" << endl; }
  void stopRecording() { cout << "FHD stopRecording" << endl; }
};


int main() {
  Camera camera;
  Car car;

  FHDCamera fhd;

  car.setBlackboxCamera(&fhd); // !?


  car.startBlackboxCamera();
}
#endif