#ifndef S21_STRING_TESTS_H
#define S21_STRING_TESTS_H

#include <check.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void case_test(Suite *s, int *fail);

/*--------------- string.h ---------------*/
Suite *s21_memchr_suite(void);
Suite *s21_memcmp_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_strchr_suite(void);
Suite *s21_strcspn_suite(void);
Suite *s21_strerror_suite(void);
Suite *s21_strlen_suite(void);
Suite *s21_strncat_suite(void);
Suite *s21_strncmp_suite(void);
Suite *s21_strncpy_suite(void);
Suite *s21_strpbrk_suite(void);
Suite *s21_strrchr_suite(void);
Suite *s21_strstr_suite(void);
Suite *s21_strtok_suite(void);

/*--------------- sprintf ---------------*/
Suite *s21_sprintf_d_suite(void);
Suite *s21_sprintf_c_suite(void);
// Suite *s21_sprintf_s_suite(void);
Suite *s21_sprintf_u_suite(void);
Suite *s21_sprintf_o_suite(void);
Suite *s21_sprintf_x_suite(void);
Suite *s21_sprintf_percent_suite(void);

/*--------------- string C# ---------------*/
Suite *s21_lower_suite(void);
Suite *s21_upper_suite(void);
Suite *s21_insert_suite(void);
Suite *s21_trim_suite(void);

/*--------------- sscanf ---------------*/
Suite *test_sscanf_d(void);
Suite *test_sscanf_x(void);
Suite *test_sscanf_real(void);
Suite *test_sscanf_p(void);
Suite *test_sscanf_o(void);
Suite *test_sscanf_n(void);
Suite *test_sscanf_i(void);
Suite *test_sscanf_empty(void);
Suite *test_sscanf_c(void);
Suite *test_sscanf_s(void);
#endif
