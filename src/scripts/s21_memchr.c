#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *ptr = str;
  int flag = 0;

  if (ptr != s21_NULL) {
    for (s21_size_t i = 0; i < n; i++) {
      if (ptr[i] == c && c != '\0') {
        ptr += i;
        flag = 1;
        break;
      }
    }
    if (!flag) {
      ptr = s21_NULL;
    }
  }
  return (void *)ptr;
}
