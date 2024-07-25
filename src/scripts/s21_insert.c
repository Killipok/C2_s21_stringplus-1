#include "../s21_string.h"

// вставить строку str в строку src, начиная с позиции start_index
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = s21_NULL;

  if (src != s21_NULL && str != s21_NULL) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    res = (char *)malloc((src_len + str_len + 1) * sizeof(char));

    if (res != s21_NULL && (long int)start_index <= (long int)src_len) {
      const char *a = src;
      s21_size_t i = 0;

      for (; (long int)(a - src) < (long int)start_index; a++, i++)
        res[i] = *a;  // записать до start_index

      for (const char *b = str; (long int)(b - str) < (long int)str_len;
           b++, i++)
        res[i] = *b;  // записать str

      for (; (long int)(a - src) < (long int)src_len; a++, i++)
        res[i] = *a;  // записать до конца src

      res[src_len + str_len] = '\0';  // конец строки
    } else {
      if (res) free(res);
      res = s21_NULL;  // обнуляем res перед возвратом s21_NULL
    }
  }

  return (void *)res;
}
