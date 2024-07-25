#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *temp = (char *)malloc((len + 1) * sizeof(char));
  if (temp != s21_NULL) {
    s21_strncpy(temp, str, len + 1);
    for (s21_size_t i = 0; i < len; i++) {
      if (temp[i] >= 'A' && temp[i] <= 'Z') {
        temp[i] += 32;
      }
    }
    temp[len] = '\0';
  }
  return temp;
}
