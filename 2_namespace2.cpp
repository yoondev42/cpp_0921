
namespace Audio {
  namespace Sample {
    namespace Sound {
      void init() {}
    }
  }
}

namespace Video {
  void init() {}
}

// using namespace Audio;
// using namespace Video;

using Audio::Sample::Sound::init;

int main() {
  init();
}