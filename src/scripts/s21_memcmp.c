#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *ptr1 = str1;
  const char *ptr2 = str2;
  int result = 0;

  for (s21_size_t i = 0; i < n; i++) {
    if (ptr1[i] != ptr2[i]) {
      result = ptr1[i] - ptr2[i];
      break;
    }
  }
  return result;
}
