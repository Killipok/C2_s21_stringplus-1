#include "s21_tests.h"

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  /*--------------- string.h ---------------*/
  case_test(s21_memchr_suite(), &fail);
  case_test(s21_memcmp_suite(), &fail);
  case_test(s21_memcpy_suite(), &fail);
  case_test(s21_memset_suite(), &fail);
  case_test(s21_strncat_suite(), &fail);
  case_test(s21_strchr_suite(), &fail);
  case_test(s21_strncmp_suite(), &fail);
  case_test(s21_strncpy_suite(), &fail);
  case_test(s21_strcspn_suite(), &fail);
  case_test(s21_strerror_suite(), &fail);
  case_test(s21_strlen_suite(), &fail);
  case_test(s21_strpbrk_suite(), &fail);
  case_test(s21_strrchr_suite(), &fail);
  case_test(s21_strstr_suite(), &fail);
  case_test(s21_strtok_suite(), &fail);

  /*--------------- sprintf ---------------*/
  case_test(s21_sprintf_d_suite(), &fail);
  case_test(s21_sprintf_c_suite(), &fail);
  // case_test(s21_sprintf_s_suite(), &fail);
  case_test(s21_sprintf_u_suite(), &fail);
  case_test(s21_sprintf_o_suite(), &fail);
  case_test(s21_sprintf_x_suite(), &fail);
  case_test(s21_sprintf_percent_suite(), &fail);

  /*--------------- string C# ---------------*/
  case_test(s21_lower_suite(), &fail);
  case_test(s21_upper_suite(), &fail);
  case_test(s21_insert_suite(), &fail);
  case_test(s21_trim_suite(), &fail);

  /*--------------- sscanf ---------------*/
  case_test(test_sscanf_empty(), &fail);
  case_test(test_sscanf_c(), &fail);
  case_test(test_sscanf_s(), &fail);
  case_test(test_sscanf_i(), &fail);
  case_test(test_sscanf_o(), &fail);
  case_test(test_sscanf_x(), &fail);
  case_test(test_sscanf_p(), &fail);
  case_test(test_sscanf_real(), &fail);
  case_test(test_sscanf_d(), &fail);
  case_test(test_sscanf_n(), &fail);

  return fail;
}
