#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  char temp[256] = "\0";

  s21_strncpy(temp, str1, s21_strlen(str1));

  for (int i = 0; temp[i] != '\0' && result == s21_NULL; i++) {
    for (int j = 0; str2[j] != '\0'; j++) {
      if (temp[i] == str2[j]) {
        result = (char *)(str1 + i);
        break;
      }
    }
  }

  return result;
}
