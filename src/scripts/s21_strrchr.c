#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;

  if (str != s21_NULL) {
    do {
      if (c == *str) res = (char *)str;
      str++;
    } while (*str != '\0');
  }

  return res;
}
