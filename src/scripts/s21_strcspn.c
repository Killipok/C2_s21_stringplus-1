#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t back = s21_strlen(str1);
  char temp[256] = "\0";

  s21_strncpy(temp, str1, s21_strlen(str1));
  for (int i = 0; temp[i] != '\0' && back == s21_strlen(str1); i++) {
    for (int j = 0; str2[j] != '\0'; j++) {
      if (temp[i] == str2[j]) {
        back = i;
        break;
      }
    }
  }

  return back;
}
