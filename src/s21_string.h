#ifndef STRING_H
#define STRING_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define BUFFER_SIZE 4096

#define s21_size_t unsigned long long
#define s21_NULL (void *)0

/*--------------- string.h ---------------*/
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_trim(const char *src, const char *trim_chars);

/*--------------- string C# ---------------*/
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

/*--------------- sprintf ---------------*/
typedef struct {
  /* флаги */
  int minus;  // флаг -
  int plus;   // флаг +
  int space;  // пробел
  int hash;   // флаг #
  int zero;   // заполнить свободные места нулями
              /* ширина */
  int width;  // ширина поля
              /* точность */
  int precision;      // точность после запятой
  char length;        // спецификатор длины: h, l, L
  int number_system;  // система счисления
  int flag_to_size;  // отрицательное число или plus или space
  int dot;           // наличие точки (точность числа)
  int upper_case;  // верхний регистр спецификатора
  int g;           // спецификатор g
  int e;           // спецификатор e
  // char specifier;     // спецификатор: d, i, f....
} TOKEN;

// получение флагов, ширины и длины
const char *s21_get_flags(const char *format, TOKEN *token);
const char *s21_get_width(const char *format, int *width, va_list *args);
const char *s21_get_length(const char *format, TOKEN *token);
const char *s21_getting(TOKEN *token, const char *format, va_list *args);

// спецификатор decimal
s21_size_t s21_get_size_to_decimal(TOKEN *token, long int num);
char s21_get_num_char(int num, int upper);
int s21_decimal_to_string(TOKEN token, long int num, char *str_to_num,
                          s21_size_t size_to_decimal);
char *s21_print_decimal(char *str, TOKEN token, va_list *args);

// спецификатор u/X/x/o
TOKEN s21_set_number_system(TOKEN token, char format);
s21_size_t s21_get_buf_size_unsigned_decimal(TOKEN *token,
                                             unsigned long int num);
int s21_unsigned_decimal_to_string(char *buf, TOKEN token,
                                   unsigned long int num,
                                   s21_size_t size_to_num);
char *s21_print_u(char *str, TOKEN token, char format, va_list *args);

// спецификатор с
char *s21_print_c(char *str, TOKEN token, int symbol);

// спецификатор s
// char *s21_print_s(char *str, TOKEN token, va_list *args);

char *s21_parser(char *str, char *src, const char *format, TOKEN token,
                 va_list *args);
int s21_sprintf(char *str, const char *format, ...);

/*--------------- sscanf ---------------*/

#define BASE_8 "01234567"
#define BASE_10 "0123456789"
#define BASE_16 "0123456789AaBbCcDdEeFf"
#define BASE_FLOAT "0123456789.eE-+"

#define WIDTH_DEFAULT -1
#define LENGTH_DEFAULT ' '
#define STR_SIZE 300

struct token {
  int width;
  char length;
  char specifier;
  int is_skip;
  int write_symb;
};

void s21_write_count_sum(va_list args, struct token *current_token);

int s21_get_digits(const char **str, char *alphabet, char *dest, int max_width);

int s21_write_to_float_s(va_list args, struct token *current_token,
                         const char **str);

unsigned long int s21_convert_16_to_10(char *result);

unsigned int s21_convert_8_to_10(char *result);

int s21_put_sign_int(char *result, struct token *current_token, va_list args,
                     int sign);

int put_unsign_int_in_value(char *result, struct token *current_token,
                            va_list args, int sign);

int s21_write_to_int_s(va_list args, struct token *current_token,
                       const char **str);

int s21_put_char_in_var(va_list args, struct token *current_token,
                        char *result);
int s21_write_char_in_var(va_list args, struct token *current_token,
                          const char **str);
int s21_write_str_in_var(va_list args, struct token *current_token,
                         const char **str);

int s21_parsing(struct token *current_token, const char **format);
int s21_sscanf(const char *str, const char *format, ...);

#endif
