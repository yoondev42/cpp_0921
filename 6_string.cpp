// 6_string.cpp

// C의 문자열 - null terminated char array
//   char[]
//   char*
//   const char*

int main()
{
  char str[6] = "hello";
  // 'h', 'e', 'l', 'l', 'o', '\0'

  char *pstr = str;

  char *s = "hello";

  // conversion from string literal to 'char *' is deprecated
  s[0] = 'x';
}