#include "solution.hpp"

unsigned int StrLen(const char* c_str) {
  unsigned int num = 0;
  while (c_str[num] != '\0') {
    num++;
  }
  return num;
}
void StrCpy(char*& to, const char* from) {
  if (from == nullptr) {
    return;
  }
  char* c = new char[StrLen(from) + 1];
  int i = 0;
  while (from[i] != '\0') {
    c[i] = from[i];
    i++;
  }
  c[i] = '\0';
  delete[] to;
  to = c;
}