#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  int lenght = 0;
  while (str[lenght] != '\0') {
    lenght++;
  }
  return lenght;
}
