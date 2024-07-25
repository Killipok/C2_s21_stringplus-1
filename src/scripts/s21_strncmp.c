#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;

  while (*str1 != '\0' && *str2 != '\0' && n--) {
    if (*str1 != *str2) {
      res = *str1 - *str2;  // разница между символами по ASCII
      break;
    }
    str1++;
    str2++;
  }

  while (n--) {  // n > strlen(str1) or n > strlen(str2)
    if (*str1 == '\0')
      res = -*str2;
    else if (*str2 == '\0')
      res = *str1;
    break;
  }

  return res;
}
