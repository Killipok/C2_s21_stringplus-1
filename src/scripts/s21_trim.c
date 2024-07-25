#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src != s21_NULL) {
    const char *default_chars = " \t\n\v\r\f";
    if (trim_chars == s21_NULL || *trim_chars == '\0') {
      trim_chars = default_chars;
    }

    const char *start_fragment = src;
    const char *end_fragment = src + s21_strlen(src) - 1;

    while (*start_fragment && s21_strchr(trim_chars, *start_fragment)) {
      start_fragment++;
    }

    while (end_fragment > start_fragment &&
           s21_strchr(trim_chars, *end_fragment)) {
      end_fragment--;
    }

    s21_size_t new_len = end_fragment - start_fragment + 1;
    result = (char *)malloc(new_len + 1);

    if (result != s21_NULL) {
      s21_strncpy(result, start_fragment, new_len);
      result[new_len] = '\0';
    }
  }
  return result;
}
