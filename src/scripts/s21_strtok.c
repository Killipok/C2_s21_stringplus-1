#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *next;  // текущая позиция str

  if (str) {  // первый вызов функции для этой строки
    next = str;
    while (*next && s21_strchr(delim, *next)) *next++ = '\0';
  }

  if (!*next)  // пустой
    str = s21_NULL;
  else  // next != '\0' (непустой)
    str = next;

  while (*next &&
         !s21_strchr(delim, *next))  // пропускаем все символы-неразделители
    ++next;
  while (*next && s21_strchr(delim, *next))  // если найден разделитель
    *next++ = '\0';

  return str;
}
