#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;

  while (*str) {
    if (*str == (char)c) {
      result = (char *)str;
      break;
    }
    str++;
  }
  if (*str == '\0' && c == '\0') {
    result = (char *)str;
  }

  return result;
}
