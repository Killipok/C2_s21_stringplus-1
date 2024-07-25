#include "s21_string.h"
#include "s21_tests.h"

// to_upper

START_TEST(test_s21_upper_basic) {
  char str[] = "hello";
  char *result = s21_to_upper(str);
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    ck_assert_int_eq(result[i], toupper(str[i]));
  }
  free(result);
}
END_TEST

START_TEST(test_s21_upper_with_spaces) {
  char str[] = "hello world";
  char *result = s21_to_upper(str);
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    ck_assert_int_eq(result[i], toupper(str[i]));
  }
  free(result);
}
END_TEST

START_TEST(test_s21_upper_empty) {
  char str[] = "";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, str);
  free(result);
}
END_TEST

START_TEST(test_s21_upper_special_chars) {
  char str[] = "hello\nworld";
  char *result = s21_to_upper(str);
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    ck_assert_int_eq(result[i], toupper(str[i]));
  }
  free(result);
}
END_TEST

START_TEST(test_s21_upper_upper) {
  char str[] = "HELLO\nworld";
  char *result = s21_to_upper(str);
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    ck_assert_int_eq(result[i], toupper(str[i]));
  }
  free(result);
}
END_TEST

// to lower

START_TEST(test_s21_lower_basic) {
  char str[] = "HELLO";
  char *result = s21_to_lower(str);
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    ck_assert_int_eq(result[i], tolower(str[i]));
  }
  free(result);
}
END_TEST

START_TEST(test_s21_lower_with_spaces) {
  char str[] = "HELLO WORLD";
  char *result = s21_to_lower(str);
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    ck_assert_int_eq(result[i], tolower(str[i]));
  }
  free(result);
}
END_TEST

START_TEST(test_s21_lower_empty) {
  char str[] = "";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, str);
  free(result);
}
END_TEST

START_TEST(test_s21_lower_special_chars) {
  char str[] = "HELLO\nWORLD";
  char *result = s21_to_lower(str);
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    ck_assert_int_eq(result[i], tolower(str[i]));
  }
  free(result);
}
END_TEST

START_TEST(test_s21_lower_lower) {
  char str[] = "hello\nWORLD";
  char *result = s21_to_lower(str);
  for (s21_size_t i = 0; i < s21_strlen(str); i++) {
    ck_assert_int_eq(result[i], tolower(str[i]));
  }
  free(result);
}
END_TEST

// insert

START_TEST(s21_insert_empty) {
  char src[] = "Hello, World!";
  char str[] = "";
  s21_size_t start_index = 5;
  char expected_result[] = "Hello, World!";
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected_result);
  free(result);
}
END_TEST

START_TEST(s21_insert_null) {
  char *src = s21_NULL;
  char str[] = "";
  s21_size_t start_index = 1;
  char *expected_result = s21_NULL;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_eq(s21_insert(src, str, start_index), expected_result);
  free(result);
}
END_TEST

START_TEST(s21_insert_start) {
  char src[] = "Hello, World!";
  char str[] = "Start!";
  s21_size_t start_index = 0;
  char expected_result[] = "Start!Hello, World!";
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected_result);
  free(result);
}
END_TEST

START_TEST(s21_insert_end) {
  char src[] = "Hello, World!";
  char str[] = "End!";
  s21_size_t start_index = s21_strlen(src);
  char expected_result[] = "Hello, World!End!";
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected_result);
  free(result);
}
END_TEST

START_TEST(s21_insert_middle) {
  char src[] = "Hello, World!";
  char str[] = "beautiful ";
  s21_size_t start_index = 7;
  char expected_result[] = "Hello, beautiful World!";
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected_result);
  free(result);
}
END_TEST

START_TEST(s21_insert_larger) {
  char src[] = "Hello";
  char str[] = " Beautiful, wonderful, amazing World!";
  s21_size_t start_index = 5;
  char expected_result[] = "Hello Beautiful, wonderful, amazing World!";
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected_result);
  free(result);
}
END_TEST

START_TEST(s21_insert_incorrect_index) {
  char src[] = "Hello, World!";
  char str[] = "beautiful ";
  s21_size_t start_index = 20;
  char *expected_result = NULL;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, expected_result);
  free(result);
}
END_TEST

// trim

START_TEST(s21_trim_default) {
  char src[5][64] = {"   zkjdhfg    ", "kasgdfkja", "zxcshdfshxzc", "\tzsdhf",
                     "\nasdf\tadfgaf\t\t\t"};
  char trim_chars[5][64] = {" ", "zsdf", "zxc", "\t", "\n\t"};
  char expected_res[5][64] = {"zkjdhfg", "kasgdfkja", "shdfsh", "zsdhf",
                              "asdf\tadfgaf"};
  for (int i = 0; i < 5; i++) {
    char *result = s21_trim(src[i], trim_chars[i]);
    ck_assert_str_eq(result, expected_res[i]);
    free(result);
  }
}
END_TEST

START_TEST(s21_trim_all_comp) {
  char src[64] = "ababbababababa";
  char trim_chars[64] = "ba";
  char expected_res[64] = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected_res);
  free(result);
}
END_TEST

START_TEST(s21_trim_chars_null) {
  char src[64] = "\t\n zsjdff\r\t";
  char *trim_chars = s21_NULL;
  char expected_res[64] = "zsjdff";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected_res);
  free(result);
}
END_TEST

START_TEST(s21_trim_src_null) {
  char *src = s21_NULL;
  char trim_chars[64] = "aff";
  char *expected_res = s21_NULL;
  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_eq(result, expected_res);
  free(result);
}
END_TEST

START_TEST(s21_trim_empty_src) {
  char src[64] = "";
  char trim_chars[64] = "zcvv";
  char expected_res[64] = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected_res);
  free(result);
}
END_TEST

START_TEST(s21_trim_empty_char) {
  char src[64] = "\ts21_NULL\t";
  char trim_chars[64] = "";
  char expected_res[64] = "s21_NULL";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected_res);
  free(result);
}
END_TEST

Suite *s21_upper_suite(void) {
  Suite *s1 = suite_create("s21_upper");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_upper_basic);
  tcase_add_test(tc_core, test_s21_upper_with_spaces);
  tcase_add_test(tc_core, test_s21_upper_empty);
  tcase_add_test(tc_core, test_s21_upper_special_chars);
  tcase_add_test(tc_core, test_s21_upper_upper);

  suite_add_tcase(s1, tc_core);
  return s1;
}

Suite *s21_lower_suite(void) {
  Suite *s2 = suite_create("s21_lower");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_lower_basic);
  tcase_add_test(tc_core, test_s21_lower_with_spaces);
  tcase_add_test(tc_core, test_s21_lower_empty);
  tcase_add_test(tc_core, test_s21_lower_special_chars);
  tcase_add_test(tc_core, test_s21_lower_lower);

  suite_add_tcase(s2, tc_core);
  return s2;
}

Suite *s21_insert_suite(void) {
  Suite *s3;
  TCase *tc_core;
  s3 = suite_create("s21_insert");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_insert_empty);
  tcase_add_test(tc_core, s21_insert_null);
  tcase_add_test(tc_core, s21_insert_start);
  tcase_add_test(tc_core, s21_insert_end);
  tcase_add_test(tc_core, s21_insert_middle);
  tcase_add_test(tc_core, s21_insert_incorrect_index);
  tcase_add_test(tc_core, s21_insert_larger);

  suite_add_tcase(s3, tc_core);
  return s3;
}

Suite *s21_trim_suite(void) {
  Suite *s4;
  TCase *tc_core;
  s4 = suite_create("s21_trim");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_trim_default);
  tcase_add_test(tc_core, s21_trim_all_comp);
  tcase_add_test(tc_core, s21_trim_chars_null);
  tcase_add_test(tc_core, s21_trim_empty_char);
  tcase_add_test(tc_core, s21_trim_empty_src);
  tcase_add_test(tc_core, s21_trim_src_null);
  suite_add_tcase(s4, tc_core);
  return s4;
}