#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;

  if (needle == s21_NULL || *needle == '\0') {
    result = (char *)haystack;
  } else {
    s21_size_t needle_len = s21_strlen(needle);
    if (needle_len == 0) {
      result = (char *)haystack;
    } else {
      for (const char *h = haystack; *h != '\0'; h++) {
        if (s21_strncmp(h, needle, needle_len) == 0) {
          result = (char *)h;
          break;
        }
      }
    }
  }

  return result;
}
