// 6_string.cpp

// C의 문자열 - null terminated char array
//   char[]
//   char*
//   const char*

// C++의 문자열 - std::string
// 1. 헤더 파일
#include <string>
#include <iostream>

// 2. C의 문자열은 복사를 위해서는 strcpy, 비교를 위해서는 strcmp 등의 문자열 함수를 사용해야 하는 번거로움이 있습니다.

int main()
{
  const char *s = "hello";
  char x[12];

  strcpy(x, s);
  printf("%s\n", x);

  // C의 문자열을 비교할 때는 strcmp를 사용해야 합니다.
  // if (s == x)  // 주소를 비교하는 연산입니다.
  if (strcmp(s, x) == 0)
  {
    printf("문자열의 내용이 동일합니다..\n");
  }

  std::string s1("hello");   // s1 = "hello";
  std::string x1(s1);        // x1 = s1;
  if (s1 == x1) {
    printf("문자열의 내용이 동일합니다..\n");
  }

  /*
  std::string s1 = "hello"; // 동작하지만, 복사가 수행됩니다.
  std::string s2("hello");  // OK!
  std::string s3{"hello"};

  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
  std::cout << s3 << std::endl;
  */
}

#if 0
int main()
{
  char str[6] = "hello";
  // 'h', 'e', 'l', 'l', 'o', '\0'

  char *pstr = str;

  char *s = "hello";

  // conversion from string literal to 'char *' is deprecated
  s[0] = 'x';
}
#endif