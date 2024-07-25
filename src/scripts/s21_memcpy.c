#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *my_dest = (char *)dest;
  const char *my_src = (const char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    my_dest[i] = my_src[i];
  }
  return my_dest;
}
