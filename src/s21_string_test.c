#include "s21_string.h"

#include "s21_tests.h"

START_TEST(s21_memchr_cmp) {
  char str[16] = "Hello World";
  int c = 'o';
  s21_size_t n = s21_strlen(str);
  ck_assert_str_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_no_cmp) {
  char str[16] = "Hello World";
  int c = 'a';
  s21_size_t n = s21_strlen(str);
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_str_less_n) {
  char str[16] = "I'm tired";
  int c = 'd';
  s21_size_t n = s21_strlen(str) + 4;
  ck_assert_str_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_str_empty) {
  char str[2] = "";
  int c = 'p';
  s21_size_t n = s21_strlen(str);
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_c_null) {
  char str[16] = "65tfhdf";
  int c = '\0';
  s21_size_t n = s21_strlen(str);
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_c_less_Zero) {
  char str[16] = "65tfhdf";
  int c = -6;
  s21_size_t n = s21_strlen(str);
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_n_eq_Zero) {
  char str[16] = "65tfhdf";
  int c = 't';
  s21_size_t n = 0;
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(s21_memchr_str_null) {
  char *str = s21_NULL;
  int c = 't';
  s21_size_t n = 0;
  ck_assert_ptr_null(s21_memchr(str, c, n));
}
END_TEST

// memcmp tests

START_TEST(s21_memcmp_part_cmp) {
  char str_1[5][16] = {"65tfhdf", "ajhesdtjf", "8273tq", "auerta", "u237tr"};
  char str_2[5][16] = {"65tfbvh", "ajhesdtgf", "8273aw", "auertp", "u2-7tr"};
  for (int i = 0; i < 5; i++) {
    s21_size_t n = s21_strlen(str_1[i]);
    int res_1 = s21_memcmp(str_1[i], str_2[i], n);
    int res_2 = memcmp(str_1[i], str_2[i], n);
    ck_assert_int_eq(res_1, res_2);
  }
}
END_TEST

START_TEST(s21_memcmp_len_less_n) {
  char str_1[16] = "aksudfd";
  char str_2[16] = "df";
  s21_size_t n = s21_strlen(str_1) + 4;
  int res_1 = s21_memcmp(str_1, str_2, n);
  int res_2 = memcmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_memcmp_n_eq_zero) {
  char str_1[16] = "asd45;wr";
  char str_2[16] = ":wr";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_memcmp(str_1, str_2, n), memcmp(str_1, str_2, n));
}
END_TEST

START_TEST(s21_memcmp_str1_null) {
  char *str_1 = "";
  char str_2[16] = ":wr";
  s21_size_t n = 2;
  int res_1 = s21_memcmp(str_1, str_2, n);
  int res_2 = memcmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_memcmp_str2_null) {
  char str_1[16] = "aksfaaf";
  char *str_2 = "";
  s21_size_t n = s21_strlen(str_1);
  int res_1 = s21_memcmp(str_1, str_2, n);
  int res_2 = memcmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_memcmp_full_cmp) {
  char str_1[16] = "memcmp test";
  char str_2[16] = "memcmp test";
  s21_size_t n = s21_strlen(str_1);
  ck_assert_int_eq(s21_memcmp(str_1, str_2, n), memcmp(str_1, str_2, n));
}
END_TEST

START_TEST(s21_memcmp_no_cmp) {
  char str_1[16] = "memcmp test";
  char str_2[16] = ";<w";
  s21_size_t n = s21_strlen(str_1);
  int res_1 = s21_memcmp(str_1, str_2, n);
  int res_2 = memcmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

// memcpy tests

START_TEST(s21_memcpy_default) {
  char dest_1[16] = "";
  char dest_2[16] = "";
  char src[5][16] = {"memcpy test", "some text", "adfaw45", "aijfa o",
                     "1q024578"};
  for (int i = 0; i < 5; i++) {
    s21_size_t n = s21_strlen(src[i]);
    s21_memcpy(dest_1, src[i], n);
    memcpy(dest_2, src[i], n);
    ck_assert_str_eq(dest_1, dest_2);
    dest_1[0] = '\0';
    dest_2[0] = '\0';
  }
}
END_TEST

START_TEST(s21_memcpy_dest_not_empty) {
  char dest_1[16] = "ahsdgf";
  char dest_2[16] = "ahsdgf";
  char src[16] = "trulyalya";
  s21_size_t n = s21_strlen(src);
  s21_memcpy(dest_1, src, n);
  memcpy(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(s21_memcpy_src_empty) {
  char dest_1[16] = "zsdfasd";
  char dest_2[16] = "zsdfasd";
  char src[16] = "";
  s21_size_t n = s21_strlen(src);
  s21_memcpy(dest_1, src, n);
  memcpy(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(s21_memcpy_n_eq_zero) {
  char dest_1[16] = "ashdf";
  char dest_2[16] = "ashdf";
  char src[16] = "jhagsdf";
  s21_size_t n = 0;
  s21_memcpy(dest_1, src, n);
  memcpy(dest_2, src, n);
  ck_assert_pstr_eq(dest_1, dest_2);
}
END_TEST

// memset tests

START_TEST(s21_memset_default) {
  char str_1[5][16] = {"ajsdhf", "1 23f ", "`9  283yjaf", "+*/++", "8Q oi"};
  char str_2[5][16] = {"ajsdhf", "1 23f ", "`9  283yjaf", "+*/++", "8Q oi"};
  int c = 56;
  for (int i = 0; i < 5; i++) {
    s21_size_t n = s21_strlen(str_1[i]) - 3;
    s21_memset(str_1[i], c, n);
    memset(str_2[i], c, n);
    ck_assert_str_eq(str_1[i], str_2[i]);
  }
}
END_TEST

START_TEST(s21_memset_NULL) {
  char *str_1 = s21_NULL;
  char *str_2 = s21_NULL;
  int c = 56;
  s21_size_t n = 0;
  s21_memset(str_1, c, n);
  memset(str_2, c, n);
  ck_assert_pstr_eq(str_1, str_2);
}
END_TEST

START_TEST(s21_memset_n_zero) {
  char str_1[16] = "s21_NULL";
  char str_2[16] = "s21_NULL";
  int c = 56;
  s21_size_t n = 0;
  s21_memset(str_1, c, n);
  memset(str_2, c, n);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(s21_memset_c_less_zero) {
  char str_1[16] = "trulala";
  char str_2[16] = "trulala";
  int c = -56;
  s21_size_t n = 2;
  s21_memset(str_1, c, n);
  memset(str_2, c, n);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

START_TEST(s21_memset_str_empty) {
  char str_1[16] = "\0";
  char str_2[16] = "\0";
  int c = 56;
  s21_size_t n = 13;
  s21_memset(str_1, c, n);
  memset(str_2, c, n);
  ck_assert_str_eq(str_1, str_2);
}
END_TEST

// strncat tests

START_TEST(s21_strncat_empty) {
  int n = 2;
  char s21_str[40] = "";
  char str[40] = "";
  char src[40] = "Be";

  ck_assert_str_eq(s21_strncat(s21_str, src, n), strncat(str, src, n));
}
END_TEST

START_TEST(s21_strncat_len0) {
  int n = 0;
  char s21_str[40] = "Be ";
  char str[40] = "Be ";
  char src[40] = "or not be";

  ck_assert_str_eq(s21_strncat(s21_str, src, n), strncat(str, src, n));
}
END_TEST

START_TEST(s21_strncat_limit) {
  int n = 9;
  char s21_str[40] = "Be ";
  char str[40] = "Be ";
  char src[40] = "or not be";

  char *s21_res = s21_strncat(s21_str, src, n);
  char *res = strncat(str, src, n);

  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(s21_strncat_outside) {
  int n = 25;
  char s21_str[40] = "Be ";
  char str[40] = "Be ";
  char src[40] = "or not be";

  ck_assert_str_eq(s21_strncat(s21_str, src, n), strncat(str, src, n));
}
END_TEST

START_TEST(s21_strncat_non_print) {
  int n = 8;
  char s21_str[40] = "Быть ";
  char str[40] = "Быть ";
  char src[40] = "\t\nпривет";

  ck_assert_str_eq(s21_strncat(s21_str, src, n), strncat(str, src, n));
}
END_TEST

// strchr test

START_TEST(s21_strchr_cmp) {
  char array_str[5][10] = {"qwertxews", "rtukuytf", "cbhnhhy", "ahgubvx",
                           "tuhgdh"};
  int array_symb[5] = {'w', 'r', 'h', 'x', 'u'};
  for (int i = 0; i < 5; i++)
    ck_assert_str_eq(s21_strchr(array_str[i], array_symb[i]),
                     strchr(array_str[i], array_symb[i]));
}
END_TEST

START_TEST(s21_strchr_no_cmp) {
  char *str = "z86hs-vbcx";
  int symb = 'o';
  ck_assert_pstr_eq(s21_strchr(str, symb), strchr(str, symb));
}
END_TEST

START_TEST(s21_strchr_less_zero) {
  char *str = "kuyuteasd";
  int symb = -1;
  ck_assert_pstr_eq(s21_strchr(str, symb), strchr(str, symb));
}
END_TEST

START_TEST(s21_strchr_null_symb) {
  char *str = "Hello World";
  int symb = '\0';
  ck_assert_pstr_eq(s21_strchr(str, symb), strchr(str, symb));
}
END_TEST

START_TEST(s21_strchr_empty_str) {
  char *str = "";
  int symb = 'a';
  ck_assert_pstr_eq(s21_strchr(str, symb), strchr(str, symb));
}
END_TEST

START_TEST(s21_strchr_empty_str_symb) {
  char *str = "";
  int symb = '\0';
  ck_assert_pstr_eq(s21_strchr(str, symb), strchr(str, symb));
}
END_TEST

START_TEST(test_s21_strchr_basic) {
  ck_assert_ptr_eq(s21_strchr("hello", 'e'), strchr("hello", 'e'));
}
END_TEST

START_TEST(test_s21_strchr_no_match) {
  ck_assert_ptr_eq(s21_strchr("hello", 'z'), strchr("hello", 'z'));
}
END_TEST

START_TEST(test_s21_strchr_empty_string) {
  ck_assert_ptr_eq(s21_strchr("", 'a'), strchr("", 'a'));
}
END_TEST

START_TEST(test_s21_strchr_first_char) {
  ck_assert_ptr_eq(s21_strchr("hello", 'h'), strchr("hello", 'h'));
}
END_TEST

START_TEST(test_s21_strchr_last_char) {
  ck_assert_ptr_eq(s21_strchr("hello", 'o'), strchr("hello", 'o'));
}
END_TEST

START_TEST(test_s21_strchr_null_char) {
  ck_assert_ptr_eq(s21_strchr("hello", '\0'), strchr("hello", '\0'));
}
END_TEST

START_TEST(test_s21_strchr_multiple_occurrences) {
  ck_assert_ptr_eq(s21_strchr("hello", 'l'), strchr("hello", 'l'));
}
END_TEST

// strncmp test

START_TEST(s21_strncmp_part_cmp) {
  char str_1[5][16] = {"65tfhdf", "ajhesdtjf", "8273tq", "auerta", "u237tr"};
  char str_2[5][16] = {"65tfbvh", "ajhesdtgf", "8273aw", "auertp", "u2-7tr"};
  for (int i = 0; i < 5; i++) {
    s21_size_t n = s21_strlen(str_1[i]);
    int res_1 = s21_strncmp(str_1[i], str_2[i], n);
    int res_2 = strncmp(str_1[i], str_2[i], n);
    ck_assert_int_eq(res_1, res_2);
  }
}
END_TEST

START_TEST(s21_strncmp_len_less_n) {
  char str_1[16] = "aksudfd";
  char str_2[16] = "df";
  s21_size_t n = s21_strlen(str_1) + 4;
  int res_1 = s21_strncmp(str_1, str_2, n);
  int res_2 = strncmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_strncmp_n_eq_zero) {
  char str_1[16] = "asd45;wr";
  char str_2[16] = ":wr";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(s21_strncmp_str1_null) {
  char *str_1 = "";
  char str_2[16] = ":wr";
  s21_size_t n = 2;
  int res_1 = s21_strncmp(str_1, str_2, n);
  int res_2 = strncmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_strncmp_str2_null) {
  char str_1[16] = "aksfaaf";
  char *str_2 = "";
  s21_size_t n = s21_strlen(str_1);
  int res_1 = s21_strncmp(str_1, str_2, n);
  int res_2 = strncmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_strncmp_full_cmp) {
  char str_1[16] = "strncmp test";
  char str_2[16] = "strncmp test";
  s21_size_t n = s21_strlen(str_1);
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(s21_strncmp_no_cmp) {
  char str_1[16] = "strncmp test";
  char str_2[16] = ";<w";
  s21_size_t n = s21_strlen(str_1);
  int res_1 = s21_strncmp(str_1, str_2, n);
  int res_2 = strncmp(str_1, str_2, n);
  ck_assert_int_eq(res_1, res_2);
}
END_TEST

START_TEST(s21_strncmp_first_empty) {
  int n = 3;
  char s21_str[40] = "";
  char str[40] = "noempty";

  ck_assert_int_eq(s21_strncmp(s21_str, str, n), strncmp(s21_str, str, n));
}
END_TEST

START_TEST(s21_strncmp_len0) {
  int n = 0;
  char s21_str[40] = "ava";
  char str[40] = "apa";

  ck_assert_int_eq(s21_strncmp(s21_str, str, n), strncmp(s21_str, str, n));
}
END_TEST

START_TEST(s21_strncmp_first_limit_match) {
  int n = 6;
  char s21_str[40] = "avatar";
  char str[40] = "avatar";

  ck_assert_int_eq(s21_strncmp(s21_str, str, n), strncmp(s21_str, str, n));
}
END_TEST

START_TEST(s21_strncmp_first_limit_no_match) {
  int n = 6;
  char s21_str[40] = "avatar";
  char str[40] = "aKaKat";

  ck_assert_int_eq(s21_strncmp(s21_str, str, n), strncmp(s21_str, str, n));
}
END_TEST

START_TEST(s21_strncmp_second_bigger) {
  int n = 10;
  char s21_str[40] = "avatar";
  char str[40] = "avatarr";

  ck_assert_int_eq(s21_strncmp(s21_str, str, n), strncmp(s21_str, str, n));
}
END_TEST

START_TEST(s21_strncmp_non_print) {
  int n = 4;
  char s21_str[40] = "\t\nпривет";
  char str[40] = "\t\nпри";

  ck_assert_int_eq(s21_strncmp(s21_str, str, n), strncmp(s21_str, str, n));
}
END_TEST

// strncpy test

START_TEST(s21_strncpy_default) {
  char dest_1[16] = "";
  char dest_2[16] = "";
  char src[5][16] = {"strncpy test", "some text", "adfaw45", "aijfa o",
                     "1q024578"};
  for (int i = 0; i < 5; i++) {
    s21_size_t n = s21_strlen(src[i]);
    s21_strncpy(dest_1, src[i], n);
    strncpy(dest_2, src[i], n);
    ck_assert_str_eq(dest_1, dest_2);
    dest_1[0] = '\0';
    dest_2[0] = '\0';
  }
}
END_TEST

START_TEST(s21_strncpy_dest_not_empty) {
  char dest_1[16] = "ahsdgf";
  char dest_2[16] = "ahsdgf";
  char src[16] = "trulyalya";
  s21_size_t n = s21_strlen(src);
  s21_strncpy(dest_1, src, n);
  strncpy(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(s21_strncpy_src_empty) {
  char dest_1[16] = "zsdfasd";
  char dest_2[16] = "zsdfasd";
  char src[16] = "";
  s21_size_t n = s21_strlen(src);
  s21_strncpy(dest_1, src, n);
  strncpy(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(s21_strncpy_n_eq_zero) {
  char dest_1[16] = "ashdf";
  char dest_2[16] = "ashdf";
  char src[16] = "jhagsdf";
  s21_size_t n = 0;
  s21_strncpy(dest_1, src, n);
  strncpy(dest_2, src, n);
  ck_assert_pstr_eq(dest_1, dest_2);
}
END_TEST
START_TEST(s21_strncpy_src_shorter) {
  char dest_1[16] = "ahsdgsdafgf";
  char dest_2[16] = "ahsdgsdafgf";
  char src[4] = "tro\0";
  s21_size_t n = s21_strlen(dest_1);
  s21_strncpy(dest_1, src, n);
  strncpy(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}

START_TEST(test_s21_strncpy_basic) {
  char dest[6] = {0};
  char expected[6] = {0};
  s21_strncpy(dest, "hello", 5);
  strncpy(expected, "hello", 5);
  expected[5] = '\0';  // Гарантируем, что строка завершена нулевым символом
  ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_s21_strncpy_empty) {
  char dest[1] = {0};
  char expected[1] = {0};
  s21_strncpy(dest, "", 1);
  strncpy(expected, "", 1);
  expected[0] = '\0';  // Гарантируем, что строка завершена нулевым символом
  ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_s21_strncpy_with_null_inside) {
  char dest[7] = {0};
  char expected[7] = {0};
  const char src_with_null[] = {'a', 'b', 'c', '\0', 'd', 'e'};
  s21_strncpy(dest, src_with_null, 6);
  strncpy(expected, src_with_null, 6);
  expected[6] = '\0';  // Гарантируем, что строка завершена нулевым символом
  ck_assert(memcmp(dest, expected, 6) == 0);
}
END_TEST

START_TEST(test_s21_strncpy_n_less_than_len) {
  char dest[6] = {0};
  char expected[6] = {0};
  s21_strncpy(dest, "hello", 3);
  strncpy(expected, "hello", 3);
  expected[3] = '\0';  // Гарантируем, что строка завершена нулевым символом
  ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_s21_strncpy_n_greater_than_len) {
  char dest[10] = {0};
  char expected[10] = {0};
  s21_strncpy(dest, "hello", 9);
  strncpy(expected, "hello", 9);
  expected[9] = '\0';  // Гарантируем, что строка завершена нулевым символом
  ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_s21_strncpy_larger_buffer) {
  char dest[10] = {0};
  char expected[10] = {0};
  s21_strncpy(dest, "hello", 5);
  strncpy(expected, "hello", 5);
  expected[5] = '\0';  // Гарантируем, что строка завершена нулевым символом
  ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_s21_strncpy_smaller_buffer) {
  char dest[3] = {0};
  char expected[3] = {0};
  s21_strncpy(dest, "hello", 2);
  strncpy(expected, "hello", 2);
  expected[2] = '\0';  // Гарантируем, что строка завершена нулевым символом
  ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_s21_strncpy_non_ascii) {
  char dest[13] = {0};
  char expected[13] = {0};
  s21_strncpy(dest, "Привет мир", 12);
  strncpy(expected, "Привет мир", 12);
  expected[12] = '\0';  // Гарантируем, что строка завершена нулевым символом
  ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_s21_strncpy_numeric) {
  char dest[11] = {0};
  char expected[11] = {0};
  s21_strncpy(dest, "1234567890", 10);
  strncpy(expected, "1234567890", 10);
  expected[10] = '\0';  // Гарантируем, что строка завершена нулевым символом
  ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_s21_strncpy_special_symbols) {
  char dest[10] = {0};
  char expected[10] = {0};
  s21_strncpy(dest, "@#$%^&*()", 9);
  strncpy(expected, "@#$%^&*()", 9);
  expected[9] = '\0';  // Гарантируем, что строка завершена нулевым символом
  ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_s21_strncpy_with_spaces) {
  char dest[12] = {0};
  char expected[12] = {0};
  s21_strncpy(dest, "hello world", 11);
  strncpy(expected, "hello world", 11);
  expected[11] = '\0';  // Гарантируем, что строка завершена нулевым символом
  ck_assert_str_eq(dest, expected);
}
END_TEST

// strcspn tests

START_TEST(s21_strcspn_match) {
  char array_str_1[5][10] = {"123456781", "fhs74iud", "hhhhh", "siu34 x",
                             "t3q45h"};
  char array_str_2[5][5] = {"34", "ud", "hh", " x", "t3"};
  for (int i = 0; i < 5; i++)
    ck_assert_int_eq(s21_strcspn(array_str_1[i], array_str_2[i]),
                     strcspn(array_str_1[i], array_str_2[i]));
}
END_TEST

START_TEST(s21_strcspn_no_match) {
  char str_1[12] = "sf2q345dusf";
  char str_2[3] = "31";
  ck_assert_int_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(s21_strcspn_str_2_empty) {
  char str_1[9] = "k3245asd";
  char *str_2 = "\0";
  ck_assert_int_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(s21_strcspn_str_1_empty) {
  char str_1[9] = "";
  char str_2[4] = ";5s";
  ck_assert_int_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(s21_strcspn_str_1_str_2_empty) {
  char str_1[4] = "";
  char str_2[4] = "\0";
  ck_assert_int_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_basic) {
  ck_assert_int_eq(s21_strcspn("hello", "aeiou"), strcspn("hello", "aeiou"));
}
END_TEST

START_TEST(test_s21_strcspn_no_match) {
  const char *str = "hello";
  const char *reject = "xyz";
  int expected = strcspn(str, reject);
  int result = s21_strcspn(str, reject);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strcspn_empty_string) {
  const char *str = "";
  const char *reject = "aeiou";
  int expected = strcspn(str, reject);
  int result = s21_strcspn(str, reject);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strcspn_empty_reject_chars) {
  const char *str = "hello";
  const char *reject = "";
  int expected = strcspn(str, reject);
  int result = s21_strcspn(str, reject);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strcspn_special_chars) {
  const char *str = "hello$%#world";
  const char *reject = "$#";
  int expected = strcspn(str, reject);
  int result = s21_strcspn(str, reject);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strcspn_with_null_char) {
  const char str_with_null[] = {'a', 'b', 'c', '\0', 'd', 'e'};
  const char *reject = "de";
  int expected = strcspn(str_with_null, reject);
  int result = s21_strcspn(str_with_null, reject);
  ck_assert_int_eq(result, expected);
}
END_TEST

// strerror tests

START_TEST(s21_strerror_long_int_pos) {
  int num_3 = 2147483647;
  ck_assert_str_eq(strerror(num_3), s21_strerror(num_3));
}
END_TEST

START_TEST(s21_strerror_long_int_neg) {
  int num_4 = -2147483647;
  ck_assert_str_eq(strerror(num_4), s21_strerror(num_4));
}
END_TEST

START_TEST(test_s21_strerror_0) {
  int errnum = 0;
  char *expected = strerror(errnum);
  char *actual = s21_strerror(errnum);
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strerror_1) {
  int errnum = 1;
  char *expected = strerror(errnum);
  char *actual = s21_strerror(errnum);
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strerror_2) {
  int errnum = 2;
  char *expected = strerror(errnum);
  char *actual = s21_strerror(errnum);
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strerror_12) {
  int errnum = 12;
  char *expected = strerror(errnum);
  char *actual = s21_strerror(errnum);
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strerror_negative) {
  int errnum = -1;
  char *expected = strerror(errnum);
  char *actual = s21_strerror(errnum);
  ck_assert_str_eq(actual, expected);
}
END_TEST

START_TEST(test_s21_strerror_large) {
  int errnum = 1000;
  char *expected = strerror(errnum);
  char *actual = s21_strerror(errnum);
  ck_assert_str_eq(actual, expected);
}
END_TEST

// strlen tests

START_TEST(s21_strlen_default) {
  char array_str[5][10] = {"qwertxews", "rtukuytf", "cbhnhhy", "ahgubvx",
                           "tuhgdh"};
  for (int i = 0; i < 5; i++)
    ck_assert_int_eq(s21_strlen(array_str[i]), strlen(array_str[i]));
}
END_TEST

START_TEST(s21_strlen_null) {
  char *str = "\0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_empty) {
  ck_assert_int_eq(s21_strlen(""), strlen(""));
}
END_TEST

START_TEST(test_s21_strlen_basic) {
  ck_assert_int_eq(s21_strlen("hello"), strlen("hello"));
}
END_TEST

START_TEST(test_s21_strlen_with_spaces) {
  ck_assert_int_eq(s21_strlen("hello world"), strlen("hello world"));
}
END_TEST

START_TEST(test_s21_strlen_special_chars) {
  ck_assert_int_eq(s21_strlen("hello\nworld"), strlen("hello\nworld"));
}
END_TEST

START_TEST(test_s21_strlen_non_ascii) {
  ck_assert_int_eq(s21_strlen("Привет"), strlen("Привет"));
}
END_TEST

START_TEST(test_s21_strlen_long_string) {
  const char *long_str =
      "This is a very long string used for testing the length function.";
  ck_assert_int_eq(s21_strlen(long_str), strlen(long_str));
}
END_TEST

START_TEST(test_s21_strlen_with_null_inside) {
  const char str_with_null[] = {'a', 'b', 'c', '\0', 'd', 'e', 'f'};
  ck_assert_int_eq(s21_strlen(str_with_null), strlen(str_with_null));
}
END_TEST

START_TEST(test_s21_strlen_single_char) {
  ck_assert_int_eq(s21_strlen("a"), strlen("a"));
}
END_TEST

START_TEST(test_s21_strlen_numeric) {
  ck_assert_int_eq(s21_strlen("1234567890"), strlen("1234567890"));
}
END_TEST

START_TEST(test_s21_strlen_special_symbols) {
  ck_assert_int_eq(s21_strlen("@#$%^&*()"), strlen("@#$%^&*()"));
}
END_TEST

// strpbrk tests

START_TEST(s21_strpbrk_match) {
  char array_str1[5][10] = {"123456781", "fhs74iud", "hhhhh", "siu34 x",
                            "t3q45h"};
  char array_str2[5][5] = {"34", "ud", "hh", " x", "t3"};
  for (int i = 0; i < 5; i++)
    ck_assert_str_eq(s21_strpbrk(array_str1[i], array_str2[i]),
                     strpbrk(array_str1[i], array_str2[i]));
}
END_TEST

START_TEST(s21_strpbrk_no_match) {
  char str1[12] = "sf2q345dusf";
  char str2[3] = "31";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_str2_empty) {
  char str1[9] = "k3245asd";
  char *str2 = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_str1_empty) {
  char str1[9] = "";
  char str2[4] = ";5s";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_str1_str2_empty) {
  char str1[4] = "";
  char str2[4] = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_basic) {
  const char *str = "hello";
  const char *accept = "el";
  char *expected = strpbrk(str, accept);
  char *result = s21_strpbrk(str, accept);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_no_match) {
  const char *str = "hello";
  const char *accept = "xyz";
  char *expected = strpbrk(str, accept);
  char *result = s21_strpbrk(str, accept);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_empty_string) {
  const char *str = "";
  const char *accept = "abc";
  char *expected = strpbrk(str, accept);
  char *result = s21_strpbrk(str, accept);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_empty_search_chars) {
  const char *str = "hello";
  const char *accept = "";
  char *expected = strpbrk(str, accept);
  char *result = s21_strpbrk(str, accept);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_special_chars) {
  const char *str = "hello$%#world";
  const char *accept = "$#";
  char *expected = strpbrk(str, accept);
  char *result = s21_strpbrk(str, accept);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_with_null_char) {
  const char str_with_null[] = {'a', 'b', 'c', '\0', 'd', 'e'};
  const char *accept = "de";
  char *expected = strpbrk(str_with_null, accept);
  char *result = s21_strpbrk(str_with_null, accept);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// strrchr tests

START_TEST(s21_strrchr_cmp) {
  char array_str[5][10] = {"qwertxews", "rtukuytf", "cbhnhhy", "ahgubvx",
                           "tuhgdh"};
  int array_symb[5] = {'w', 'r', 'h', 'x', 'u'};
  for (int i = 0; i < 5; i++)
    ck_assert_str_eq(s21_strrchr(array_str[i], array_symb[i]),
                     strrchr(array_str[i], array_symb[i]));
}
END_TEST

START_TEST(s21_strrchr_no_cmp) {
  char *str = "z86hs-vbcx";
  int symb = 'o';
  ck_assert_pstr_eq(s21_strrchr(str, symb), strrchr(str, symb));
}
END_TEST

START_TEST(s21_strrchr_less_zero) {
  char *str = "kuyuteasd";
  int symb = -100;
  ck_assert_pstr_eq(s21_strrchr(str, symb), strrchr(str, symb));
}
END_TEST

START_TEST(s21_strrchr_empty_str) {
  char *str = "";
  int symb = 'a';
  ck_assert_pstr_eq(s21_strrchr(str, symb), strrchr(str, symb));
}
END_TEST

START_TEST(s21_strrchr_empty_str_symb) {
  char *str = "";
  int symb = '\0';
  ck_assert_pstr_eq(s21_strrchr(str, symb), strrchr(str, symb));
}
END_TEST

START_TEST(s21_strrchr_empty) {
  int c = 'e';
  char str[40] = "test";

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_one_find) {
  int c = 'e';
  char str[40] = "test";

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_several_find) {
  int c = 't';
  char str[40] = "test";

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_first_find) {
  int c = 'l';
  char str[40] = "lover";

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_last_find) {
  int c = 'r';
  char str[40] = "lover";

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_no_find) {
  int c = '5';
  char str[40] = "test";

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_non_print) {
  int c = '\t';
  char str[40] = "te\tst";

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

// strstr tests
START_TEST(s21_strstr_match) {
  char array_haystack[5][10] = {"123456781", "fhs74iud", "hhhhh", "siu34 x",
                                "t3q45h"};
  char array_needle[5][5] = {"34", "ud", "hh", " x", "t3"};
  for (int i = 0; i < 5; i++)
    ck_assert_str_eq(s21_strstr(array_haystack[i], array_needle[i]),
                     strstr(array_haystack[i], array_needle[i]));
}
END_TEST

START_TEST(s21_strstr_no_match) {
  char haystack[12] = "sf2q345dusf";
  char needle[3] = "31";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_needle_empty) {
  char haystack[9] = "k3245asd";
  char *needle = "\0";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_haystack_empty) {
  char haystack[9] = "";
  char needle[4] = ";5s";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_haystack_needle_empty) {
  char haystack[4] = "";
  char needle[4] = "\0";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_s21_strstr_basic) {
  ck_assert_ptr_eq(s21_strstr("hello world", "world"),
                   strstr("hello world", "world"));
}
END_TEST

START_TEST(test_s21_strstr_basic_end) {
  ck_assert_ptr_eq(s21_strstr("hello world", "\0"),
                   strstr("hello world", "\0"));
}
END_TEST

START_TEST(test_s21_strstr_basic_empty) {
  ck_assert_ptr_eq(s21_strstr("hello world", ""), strstr("hello world", ""));
}
END_TEST

START_TEST(test_s21_strstr_basic_empty2) {
  ck_assert_ptr_eq(s21_strstr("", "hello world"), strstr("", "hello world"));
}
END_TEST

START_TEST(test_s21_strstr_basic_none) {
  ck_assert_ptr_eq(s21_strstr("hello world", "CHIWAYWA"),
                   strstr("hello world", "CHIWAYWA"));
}
END_TEST

START_TEST(test_s21_strstr_no_match) {
  ck_assert_ptr_eq(s21_strstr("hello world", "earth"), NULL);
}
END_TEST

START_TEST(test_s21_strstr_substring_at_start) {
  ck_assert_ptr_eq(s21_strstr("hello world", "hello"),
                   strstr("hello world", "hello"));
}
END_TEST

START_TEST(test_s21_strstr_substring_middle) {
  ck_assert_ptr_eq(s21_strstr("hello world", "lo wo"),
                   strstr("hello world", "lo wo"));
}
END_TEST

START_TEST(test_s21_strstr_repeated_substring) {
  ck_assert_ptr_eq(s21_strstr("hello hello world", "hello"),
                   strstr("hello hello world", "hello"));
}
END_TEST

START_TEST(test_s21_strstr_long_substring) {
  ck_assert_ptr_eq(s21_strstr("hello world", "hello world"),
                   strstr("hello world", "hello world"));
}
END_TEST

START_TEST(test_s21_strstr_non_ascii) {
  ck_assert_ptr_eq(s21_strstr("Привет мир", "мир"),
                   strstr("Привет мир", "мир"));
}
END_TEST

// strtok tests

START_TEST(s21_strtok_match) {
  char str_1[32] = "test1/test2/test3/test4";
  char str_2[32] = "test1/test2/test3/test4";
  char delim[4] = "/,";
  ck_assert_str_eq(s21_strtok(str_1, delim), strtok(str_2, delim));
  ck_assert_str_eq(s21_strtok(s21_NULL, delim), strtok(s21_NULL, delim));
  ck_assert_str_eq(s21_strtok(s21_NULL, delim), strtok(s21_NULL, delim));
  ck_assert_str_eq(s21_strtok(s21_NULL, delim), strtok(s21_NULL, delim));
}
END_TEST

START_TEST(s21_strtok_one_token) {
  char str[32] = "test1/test2/test3/test4";
  char delim[4] = " ,";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
  ck_assert_pstr_eq(s21_strtok(s21_NULL, delim), strtok(s21_NULL, delim));
}
END_TEST

START_TEST(s21_strtok_empty_str_delim) {
  char str[4] = "";
  char *delim = "\0";
  ck_assert_pstr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_empty_delim) {
  char s21_str[100] = "Be";
  char str[100] = "Be";
  char delim[10] = "";

  ck_assert_str_eq(s21_strtok(s21_str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_empty_str) {
  char s21_str[100] = "";
  char str[100] = "";
  char delim[10] = " ";

  ck_assert_ptr_eq(s21_strtok(s21_str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_symbol_str) {
  char s21_str[100] = "R";
  char str[100] = "R";
  char delim[10] = " ";

  ck_assert_str_eq(s21_strtok(s21_str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_one_delim) {
  char s21_str[200] = "Features of national fishing - feature, comedy film.";
  char str[200] = "Features of national fishing - feature, comedy film.";
  char delim[10] = ",";

  ck_assert_str_eq(s21_strtok(s21_str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_several_delim) {
  char s21_str[200] = "Features of national fishing - feature, comedy film.";
  char str[200] = "Features of national fishing - feature, comedy film.";
  char delim[10] = ",.";
  char *s21_res, *res;

  s21_res = s21_strtok(s21_str, delim);
  res = strtok(str, delim);
  ck_assert_str_eq(s21_res, res);

  s21_res = s21_strtok(s21_NULL, delim);
  res = strtok(NULL, delim);
  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(s21_strtok_repeat_delim) {
  char s21_str[200] = "Features  of national fishing - feature, comedy film.";
  char str[200] = "Features  of national fishing - feature, comedy film.";
  char delim[10] = " ";
  char *s21_res, *res;

  s21_res = s21_strtok(s21_str, delim);
  res = strtok(str, delim);
  ck_assert_str_eq(s21_res, res);

  s21_res = s21_strtok(s21_NULL, delim);
  res = strtok(NULL, delim);
  ck_assert_str_eq(s21_res, res);

  s21_res = s21_strtok(s21_NULL, delim);
  res = strtok(NULL, delim);
  ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(s21_strtok_no_found_delim) {
  char s21_str[100] = "Be";
  char str[100] = "Be";
  char delim[10] = "+";

  ck_assert_str_eq(s21_strtok(s21_str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_first_delim) {
  char s21_str[100] = "(Be)";
  char str[100] = "(Be)";
  char delim[10] = "(";

  ck_assert_str_eq(s21_strtok(s21_str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_last_delim) {
  char s21_str[100] = "(Be)";
  char str[100] = "(Be)";
  char delim[10] = ")";

  ck_assert_str_eq(s21_strtok(s21_str, delim), strtok(str, delim));
}
END_TEST

// Suits

Suite *s21_memchr_suite(void) {
  Suite *s1;
  TCase *tc_core;
  s1 = suite_create("s21_memchr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memchr_cmp);
  tcase_add_test(tc_core, s21_memchr_no_cmp);
  tcase_add_test(tc_core, s21_memchr_str_empty);
  tcase_add_test(tc_core, s21_memchr_str_less_n);
  tcase_add_test(tc_core, s21_memchr_str_null);
  tcase_add_test(tc_core, s21_memchr_c_null);
  tcase_add_test(tc_core, s21_memchr_c_less_Zero);
  tcase_add_test(tc_core, s21_memchr_n_eq_Zero);
  suite_add_tcase(s1, tc_core);
  return s1;
}

Suite *s21_memcmp_suite(void) {
  Suite *s2;
  TCase *tc_core;
  s2 = suite_create("s21_memcmp");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memcmp_part_cmp);
  tcase_add_test(tc_core, s21_memcmp_len_less_n);
  tcase_add_test(tc_core, s21_memcmp_n_eq_zero);
  tcase_add_test(tc_core, s21_memcmp_str1_null);
  tcase_add_test(tc_core, s21_memcmp_str2_null);
  tcase_add_test(tc_core, s21_memcmp_no_cmp);
  tcase_add_test(tc_core, s21_memcmp_full_cmp);
  suite_add_tcase(s2, tc_core);
  return s2;
}

Suite *s21_memcpy_suite(void) {
  Suite *s3;
  TCase *tc_core;
  s3 = suite_create("s21_memcpy");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memcpy_default);
  tcase_add_test(tc_core, s21_memcpy_dest_not_empty);
  tcase_add_test(tc_core, s21_memcpy_src_empty);
  tcase_add_test(tc_core, s21_memcpy_n_eq_zero);
  suite_add_tcase(s3, tc_core);
  return s3;
}

Suite *s21_memset_suite(void) {
  Suite *s4;
  TCase *tc_core;
  s4 = suite_create("s21_memset");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memset_default);
  tcase_add_test(tc_core, s21_memset_NULL);
  tcase_add_test(tc_core, s21_memset_n_zero);
  tcase_add_test(tc_core, s21_memset_c_less_zero);
  tcase_add_test(tc_core, s21_memset_str_empty);
  suite_add_tcase(s4, tc_core);
  return s4;
}

Suite *s21_strncat_suite(void) {
  Suite *s1;
  TCase *tc_core;
  s1 = suite_create("s21_strncat");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncat_empty);
  tcase_add_test(tc_core, s21_strncat_len0);
  tcase_add_test(tc_core, s21_strncat_limit);
  tcase_add_test(tc_core, s21_strncat_outside);
  tcase_add_test(tc_core, s21_strncat_non_print);
  suite_add_tcase(s1, tc_core);
  return s1;
}

Suite *s21_strchr_suite(void) {
  Suite *s6;
  TCase *tc_core;
  s6 = suite_create("s21_strchr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strchr_cmp);
  tcase_add_test(tc_core, s21_strchr_no_cmp);
  tcase_add_test(tc_core, s21_strchr_less_zero);
  tcase_add_test(tc_core, s21_strchr_null_symb);
  tcase_add_test(tc_core, s21_strchr_empty_str);
  tcase_add_test(tc_core, s21_strchr_empty_str_symb);
  tcase_add_test(tc_core, test_s21_strchr_basic);
  tcase_add_test(tc_core, test_s21_strchr_no_match);
  tcase_add_test(tc_core, test_s21_strchr_empty_string);
  tcase_add_test(tc_core, test_s21_strchr_first_char);
  tcase_add_test(tc_core, test_s21_strchr_last_char);
  tcase_add_test(tc_core, test_s21_strchr_null_char);
  tcase_add_test(tc_core, test_s21_strchr_multiple_occurrences);

  suite_add_tcase(s6, tc_core);
  return s6;
}

Suite *s21_strncmp_suite(void) {
  Suite *s7;
  TCase *tc_core;
  s7 = suite_create("s21_strncmp");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncmp_part_cmp);
  tcase_add_test(tc_core, s21_strncmp_len_less_n);
  tcase_add_test(tc_core, s21_strncmp_n_eq_zero);
  tcase_add_test(tc_core, s21_strncmp_str1_null);
  tcase_add_test(tc_core, s21_strncmp_str2_null);
  tcase_add_test(tc_core, s21_strncmp_no_cmp);
  tcase_add_test(tc_core, s21_strncmp_full_cmp);
  tcase_add_test(tc_core, s21_strncmp_first_empty);
  tcase_add_test(tc_core, s21_strncmp_len0);
  tcase_add_test(tc_core, s21_strncmp_first_limit_match);
  tcase_add_test(tc_core, s21_strncmp_first_limit_no_match);
  tcase_add_test(tc_core, s21_strncmp_second_bigger);
  tcase_add_test(tc_core, s21_strncmp_non_print);

  suite_add_tcase(s7, tc_core);
  return s7;
}

Suite *s21_strncpy_suite(void) {
  Suite *s8;
  TCase *tc_core;
  s8 = suite_create("s21_strncpy");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncpy_default);
  tcase_add_test(tc_core, s21_strncpy_dest_not_empty);
  tcase_add_test(tc_core, s21_strncpy_src_empty);
  tcase_add_test(tc_core, s21_strncpy_n_eq_zero);
  tcase_add_test(tc_core, s21_strncpy_src_shorter);
  tcase_add_test(tc_core, test_s21_strncpy_basic);
  tcase_add_test(tc_core, test_s21_strncpy_empty);
  tcase_add_test(tc_core, test_s21_strncpy_with_null_inside);
  tcase_add_test(tc_core, test_s21_strncpy_n_less_than_len);
  tcase_add_test(tc_core, test_s21_strncpy_n_greater_than_len);
  tcase_add_test(tc_core, test_s21_strncpy_larger_buffer);
  tcase_add_test(tc_core, test_s21_strncpy_smaller_buffer);
  tcase_add_test(tc_core, test_s21_strncpy_non_ascii);
  tcase_add_test(tc_core, test_s21_strncpy_numeric);
  tcase_add_test(tc_core, test_s21_strncpy_special_symbols);
  tcase_add_test(tc_core, test_s21_strncpy_with_spaces);

  suite_add_tcase(s8, tc_core);
  return s8;
}

Suite *s21_strcspn_suite(void) {
  Suite *s9;
  TCase *tc_core;
  s9 = suite_create("s21_strcspn");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strcspn_match);
  tcase_add_test(tc_core, s21_strcspn_no_match);
  tcase_add_test(tc_core, s21_strcspn_str_2_empty);
  tcase_add_test(tc_core, s21_strcspn_str_1_empty);
  tcase_add_test(tc_core, s21_strcspn_str_1_str_2_empty);
  tcase_add_test(tc_core, test_s21_strcspn_basic);
  tcase_add_test(tc_core, test_s21_strcspn_no_match);
  tcase_add_test(tc_core, test_s21_strcspn_empty_string);
  tcase_add_test(tc_core, test_s21_strcspn_empty_reject_chars);
  tcase_add_test(tc_core, test_s21_strcspn_special_chars);
  tcase_add_test(tc_core, test_s21_strcspn_with_null_char);

  suite_add_tcase(s9, tc_core);
  return s9;
}

Suite *s21_strerror_suite(void) {
  Suite *s10;
  TCase *tc_core;
  s10 = suite_create("s21_strerror");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strerror_long_int_neg);
  tcase_add_test(tc_core, s21_strerror_long_int_pos);
  tcase_add_test(tc_core, test_s21_strerror_0);
  tcase_add_test(tc_core, test_s21_strerror_1);
  tcase_add_test(tc_core, test_s21_strerror_2);
  tcase_add_test(tc_core, test_s21_strerror_12);
  tcase_add_test(tc_core, test_s21_strerror_negative);
  tcase_add_test(tc_core, test_s21_strerror_large);

  suite_add_tcase(s10, tc_core);
  return s10;
}

Suite *s21_strlen_suite(void) {
  Suite *s11;
  TCase *tc_core;
  s11 = suite_create("s21_strlen");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strlen_default);
  tcase_add_test(tc_core, s21_strlen_null);
  tcase_add_test(tc_core, test_s21_strlen_empty);
  tcase_add_test(tc_core, test_s21_strlen_basic);
  tcase_add_test(tc_core, test_s21_strlen_with_spaces);
  tcase_add_test(tc_core, test_s21_strlen_special_chars);
  tcase_add_test(tc_core, test_s21_strlen_non_ascii);
  tcase_add_test(tc_core, test_s21_strlen_long_string);
  tcase_add_test(tc_core, test_s21_strlen_with_null_inside);
  tcase_add_test(tc_core, test_s21_strlen_single_char);
  tcase_add_test(tc_core, test_s21_strlen_numeric);
  tcase_add_test(tc_core, test_s21_strlen_special_symbols);

  suite_add_tcase(s11, tc_core);
  return s11;
}

Suite *s21_strpbrk_suite(void) {
  Suite *s12;
  TCase *tc_core;
  s12 = suite_create("s21_strpbrk");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strpbrk_match);
  tcase_add_test(tc_core, s21_strpbrk_no_match);
  tcase_add_test(tc_core, s21_strpbrk_str2_empty);
  tcase_add_test(tc_core, s21_strpbrk_str1_empty);
  tcase_add_test(tc_core, s21_strpbrk_str1_str2_empty);
  tcase_add_test(tc_core, test_s21_strpbrk_basic);
  tcase_add_test(tc_core, test_s21_strpbrk_no_match);
  tcase_add_test(tc_core, test_s21_strpbrk_empty_string);
  tcase_add_test(tc_core, test_s21_strpbrk_empty_search_chars);
  tcase_add_test(tc_core, test_s21_strpbrk_special_chars);
  tcase_add_test(tc_core, test_s21_strpbrk_with_null_char);

  suite_add_tcase(s12, tc_core);
  return s12;
}

Suite *s21_strrchr_suite(void) {
  Suite *s13;
  TCase *tc_core;
  s13 = suite_create("s21_strrchr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strrchr_cmp);
  tcase_add_test(tc_core, s21_strrchr_no_cmp);
  tcase_add_test(tc_core, s21_strrchr_less_zero);
  tcase_add_test(tc_core, s21_strrchr_empty_str);
  tcase_add_test(tc_core, s21_strrchr_empty_str_symb);
  tcase_add_test(tc_core, s21_strrchr_empty);
  tcase_add_test(tc_core, s21_strrchr_one_find);
  tcase_add_test(tc_core, s21_strrchr_several_find);
  tcase_add_test(tc_core, s21_strrchr_first_find);
  tcase_add_test(tc_core, s21_strrchr_last_find);
  tcase_add_test(tc_core, s21_strrchr_no_find);
  tcase_add_test(tc_core, s21_strrchr_non_print);

  suite_add_tcase(s13, tc_core);
  return s13;
}

Suite *s21_strstr_suite(void) {
  Suite *s14;
  TCase *tc_core;
  s14 = suite_create("s21_strstr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strstr_match);
  tcase_add_test(tc_core, s21_strstr_no_match);
  tcase_add_test(tc_core, s21_strstr_needle_empty);
  tcase_add_test(tc_core, s21_strstr_haystack_empty);
  tcase_add_test(tc_core, s21_strstr_haystack_needle_empty);
  tcase_add_test(tc_core, test_s21_strstr_basic);
  tcase_add_test(tc_core, test_s21_strstr_no_match);
  tcase_add_test(tc_core, test_s21_strstr_basic_end);
  tcase_add_test(tc_core, test_s21_strstr_basic_none);
  tcase_add_test(tc_core, test_s21_strstr_basic_empty);
  tcase_add_test(tc_core, test_s21_strstr_basic_empty2);
  tcase_add_test(tc_core, test_s21_strstr_substring_at_start);
  tcase_add_test(tc_core, test_s21_strstr_substring_middle);
  tcase_add_test(tc_core, test_s21_strstr_repeated_substring);
  tcase_add_test(tc_core, test_s21_strstr_long_substring);
  tcase_add_test(tc_core, test_s21_strstr_non_ascii);

  suite_add_tcase(s14, tc_core);
  return s14;
}

Suite *s21_strtok_suite(void) {
  Suite *s15;
  TCase *tc_core;
  s15 = suite_create("s21_strtok");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strtok_match);
  tcase_add_test(tc_core, s21_strtok_one_token);
  tcase_add_test(tc_core, s21_strtok_empty_delim);
  tcase_add_test(tc_core, s21_strtok_empty_str);
  tcase_add_test(tc_core, s21_strtok_empty_str_delim);
  tcase_add_test(tc_core, s21_strtok_symbol_str);
  tcase_add_test(tc_core, s21_strtok_one_delim);
  tcase_add_test(tc_core, s21_strtok_several_delim);
  tcase_add_test(tc_core, s21_strtok_repeat_delim);
  tcase_add_test(tc_core, s21_strtok_no_found_delim);
  tcase_add_test(tc_core, s21_strtok_first_delim);
  tcase_add_test(tc_core, s21_strtok_last_delim);

  suite_add_tcase(s15, tc_core);
  return s15;
}