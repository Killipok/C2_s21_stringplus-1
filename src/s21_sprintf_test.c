#include "s21_string.h"
#include "s21_tests.h"

/* ---------- SPECIFIER d, i ---------- */

START_TEST(sprintf_spec_d_0) {
  char str1[400];
  char str2[400];
  const char *format = " %d %i %d";

  ck_assert_int_eq(s21_sprintf(str1, format, 0, 0, 0),
                   sprintf(str2, format, 0, 0, 0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_1) {
  char str1[400];
  char str2[400];
  const char *format = " %d %i %d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_2) {
  char str1[400];
  char str2[400];
  const char *format = "%+d %+i %+d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_3) {
  char str1[400];
  char str2[400];
  const char *format = "% d % i % d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_4) {
  char str1[400];
  char str2[400];
  const char *format = "%-d %-i %-d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_5) {
  char str1[400];
  char str2[400];
  const char *format = "%#d %#i %#d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_6) {
  char str1[400];
  char str2[400];
  const char *format = "%0d %0i %0d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_7) {
  char str1[400];
  char str2[400];
  const char *format = "%2d %2i %3d";

  int first = 2565465;
  int third = -35243543;
  int fifth = -454356;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_8) {
  char str1[400];
  char str2[400];
  const char *format = "%.2d %.13i %.98d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*d %i %d";

  int first = 2552;
  int second = -1352;
  int third = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, second, third),
                   sprintf(str2, format, 10, first, second, third));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_10) {
  char str1[400];
  char str2[400];
  const char *format = "%+-*d %0#d % -*d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, third, 0, fifth),
                   sprintf(str2, format, -10, first, third, 0, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_11) {
  char str1[400];
  char str2[400];
  const char *format = " %d %d %d";

  int first = 02552;
  int third = -01352;
  int fifth = 0032552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_12) {
  char str1[400];
  char str2[400];
  const char *format = " %d %d %d";

  char *first = "2552";
  char *third = "-1352";
  char *fifth = "-325";

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_13) {
  char str1[400];
  char str2[400];
  const char *format = "%.*d %d %.*d";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, 5, fifth),
                   sprintf(str2, format, 10, first, third, 5, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_15) {
  char str1[400];
  char str2[400];
  const char *format = " %ld %ld %ld";

  long int first = 12345067891352;
  long int third = -98654302165;
  long int fifth = -6574654353654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_16) {
  char str1[400];
  char str2[400];
  const char *format = " %6ld %0ld %-20ld";

  long int first = 123450891352;
  long int third = -987654302165;
  long int fifth = -6574654353654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_17) {
  char str1[400];
  char str2[400];
  const char *format = " %hd %hd %hd";

  short int first = 12354;
  short int third = -352;
  short int fifth = -3768;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_18) {
  char str1[400];
  char str2[400];
  const char *format = " %hd %hd %hd";

  short int first = 14435;
  short int third = -3352;
  short int fifth = -3585;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_19) {
  char str1[400];
  char str2[400];
  const char *format = "% #+d % #+d % #+d";

  int first = 2552;
  int third = -1352;
  int fifth = -3552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

/* ---------- SPECIFIER c ---------- */

START_TEST(sprintf_spec_c_1) {
  char str1[400];
  char str2[400];
  const char *format = "%c %c";
  char first = ',';
  char second = '?';
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_2) {
  char str1[400];
  char str2[400];
  const char *format = "%7c %0c";
  char first = 'x';
  char second = 'z';
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_3) {
  char str1[400];
  char str2[400];
  const char *format = "dcdcd%-20c ll%+010c";
  char first = 'x';
  char second = 'i';
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_4) {
  char str1[400];
  char str2[400];
  const char *format = "dvd%-3c home%13cdcdvdf";
  char first = 'x';
  char second = '?';
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_5) {
  char str1[400];
  char str2[400];
  const char *format = "2121%0cdvdvdvd %+0cf fdvf";
  char first = 'x';
  char second = '?';
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_6) {
  char str1[400];
  char str2[400];
  const char *format = "ssc%7c dvdv%15ccdvdvd";
  char first = 'x';
  char second = '?';
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_7) {
  char str1[400];
  char str2[400];
  const char *format = "%*c ___cdkmv_ %*c";
  char first = 'x';
  char second = '?';
  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, 15, second),
                   sprintf(str2, format, 10, first, 15, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_8) {
  char str1[400];
  char str2[400];
  const char *format = "%*c foror%*c";
  char first = 'x';
  char second = '?';
  ck_assert_int_eq(s21_sprintf(str1, format, -10, first, -15, second),
                   sprintf(str2, format, -10, first, -15, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_9) {
  char str1[400];
  char str2[400];
  const char *format = "HEllo %c %c";
  char first = '\n';
  char second = '\t';
  ck_assert_int_eq(s21_sprintf(str1, format, first, second),
                   sprintf(str2, format, first, second));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_10) {
  char str1[400];
  char str2[400];
  const char *format = "% c";
  char first = 'h';
  ck_assert_int_eq(s21_sprintf(str1, format, first),
                   sprintf(str2, format, first));
}
END_TEST

/* ---------- SPECIFIER s ---------- */

// START_TEST(sprintf_spec_s_1) {
//   char str1[400];
//   char str2[400];
//   const char *format = "%s";
//   char *text = "Hello";
//   ck_assert_int_eq(s21_sprintf(str1, format, text),
//                    sprintf(str2, format, text));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_spec_s_2) {
//   char str1[400];
//   char str2[400];
//   const char *format = "%10s";
//   char *text = "Hello";
//   ck_assert_int_eq(s21_sprintf(str1, format, text),
//                    sprintf(str2, format, text));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_spec_s_3) {
//   char str1[400];
//   char str2[400];
//   const char *format = "%.3s";
//   char *text = "Hello";
//   ck_assert_int_eq(s21_sprintf(str1, format, text),
//                    sprintf(str2, format, text));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_spec_s_4) {
//   char str1[400];
//   char str2[400];
//   const char *format = "%10.3s";
//   char *text = "Hello";
//   ck_assert_int_eq(s21_sprintf(str1, format, text),
//                    sprintf(str2, format, text));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_spec_s_5) {
//   char str1[400];
//   char str2[400];
//   const char *format = "%-10s";
//   char *text = "Hello";
//   ck_assert_int_eq(s21_sprintf(str1, format, text),
//                    sprintf(str2, format, text));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_spec_s_6) {
//   char str1[400];
//   char str2[400];
//   const char *format = "%s %s";
//   char *text1 = "Hello";
//   char *text2 = "World";
//   ck_assert_int_eq(s21_sprintf(str1, format, text1, text2),
//                    sprintf(str2, format, text1, text2));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_spec_s_7) {
//   char str1[400];
//   char str2[400];
//   const char *format = "%-10.3s %5s";
//   char *text1 = "Hello";
//   char *text2 = "World";
//   ck_assert_int_eq(s21_sprintf(str1, format, text1, text2),
//                    sprintf(str2, format, text1, text2));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_spec_s_8) {
//   char str1[400];
//   char str2[400];
//   const char *format = "%s";
//   char *text =
//       "This is a very long string to test the buffer handling in the sprintf
//       " "function";
//   ck_assert_int_eq(s21_sprintf(str1, format, text),
//                    sprintf(str2, format, text));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_spec_s_9) {
//   char str1[400];
//   char str2[400];
//   const char *format = "%ls";
//   wchar_t *text = L"Привет";
//   ck_assert_int_eq(s21_sprintf(str1, format, text),
//                    sprintf(str2, format, text));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_spec_s_10) {
//   char str1[400];
//   char str2[400];
//   const char *format = "%s";
//   ck_assert_int_eq(s21_sprintf(str1, format, 14), sprintf(str2, format, 14));
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

/* ---------- SPECIFIER u ---------- */

START_TEST(sprintf_spec_u_1) {
  char str1[400];
  char str2[400];
  const char *format = "%u %u %u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_2) {
  char str1[400];
  char str2[400];
  const char *format = "%+u %+u %+u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_3) {
  char str1[400];
  char str2[400];
  const char *format = "% u % u % u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_4) {
  char str1[400];
  char str2[400];
  const char *format = "%-u %-u %-u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_6) {
  char str1[400];
  char str2[400];
  const char *format = "%0u %0u %0u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_7) {
  char str1[400];
  char str2[400];
  const char *format = "%2u %2u %3u";

  int first = 2565465;
  int third = 35243543;
  int fifth = -454356;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_8) {
  char str1[400];
  char str2[400];
  const char *format = "%.2u %.13u %.98u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*u %u %u";

  int first = 2552;
  int third = 1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, fifth),
                   sprintf(str2, format, 10, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_11) {
  char str1[400];
  char str2[400];
  const char *format = "%u %u %u";

  int first = 02552;
  int third = 01352;
  int fifth = 0032552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_12) {
  char str1[400];
  char str2[400];
  const char *format = "% #.10u % 0u % -.3u";

  char *first = "2552";
  char *third = "1352";
  char *fifth = "-325";

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_13) {
  char str1[400];
  char str2[400];
  const char *format = "%.*u %u %.*u";

  int first = 2552;
  int third = 1352552;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, 5, fifth),
                   sprintf(str2, format, 10, first, third, 5, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_15) {
  char str1[400];
  char str2[400];
  const char *format = "%lu %lu %lu";

  long int first = 123450678952;
  long int third = 987654302165;
  long int fifth = -6574654353654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_16) {
  char str1[400];
  char str2[400];
  const char *format = "%6lu %0lu %-15lu";

  long int first = 123450678952;
  long int third = 987654302165;
  long int fifth = -6574654353654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_17) {
  char str1[400];
  char str2[400];
  const char *format = " %hu %hu %hu";

  short int first = 12354;
  short int third = 352;
  short int fifth = -32768;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_18) {
  char str1[400];
  char str2[400];
  const char *format = " %hu %hu %hu";

  short int first = 12435;
  unsigned short int third = 35452;
  short int fifth = -3585;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_19) {
  char str1[400];
  char str2[400];
  const char *format = "% #+u % #+u % #+u";

  int first = 2552;
  int third = -1352;
  int fifth = -32552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

/* ---------- SPECIFIER o ---------- */
START_TEST(sprintf_spec_o_1) {
  char str1[400];
  char str2[400];
  const char *format = "%o %o %o";

  int first = 02552;
  int third = 01352;
  int fifth = -032552;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_2) {
  char str1[400];
  char str2[400];
  const char *format = "%+o %+o %+o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325152;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_3) {
  char str1[400];
  char str2[400];
  const char *format = "% o % o % o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_4) {
  char str1[400];
  char str2[400];
  const char *format = "%-o %-o %-o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_6) {
  char str1[400];
  char str2[400];
  const char *format = "%0o %0o %0o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_7) {
  char str1[400];
  char str2[400];
  const char *format = "%2.o %2.0o %3.13o";

  int first = 02565465;
  int third = 035243543;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_8) {
  char str1[400];
  char str2[400];
  const char *format = "%.2o %.13o %.98o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*o %o %o";

  int first = 02552;
  int third = 01352;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, fifth),
                   sprintf(str2, format, 10, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_12) {
  char str1[400];
  char str2[400];
  const char *format = "%2o %010o %o";

  char *first = "02552";
  char *third = "01352";
  char *fifth = "-0325052";

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_13) {
  char str1[400];
  char str2[400];
  const char *format = "%.*o %o %.*o";

  int first = 02552;
  int third = 01352552;
  int fifth = -0325052;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, 5, fifth),
                   sprintf(str2, format, 10, first, third, 5, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_15) {
  char str1[400];
  char str2[400];
  const char *format = "%lo %lo %lo";

  long int first = 01234506752;
  long int third = 07654302165;
  long int fifth = -065746553654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_16) {
  char str1[400];
  char str2[400];
  const char *format = "%6lo %0lo %-15lo";

  long int first = 01234506752;
  long int third = 07654302165;
  long int fifth = -065746353654;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_17) {
  char str1[400];
  char str2[400];
  const char *format = "%ho %ho %ho";

  short int first = 012354;
  short int third = 0352;
  short int fifth = -035052;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_18) {
  char str1[400];
  char str2[400];
  const char *format = "%ho %ho %ho";

  short int first = 012435;
  short int third = 03452;
  short int fifth = -03505;

  ck_assert_int_eq(s21_sprintf(str1, format, first, third, fifth),
                   sprintf(str2, format, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

/* ---------- SPECIFIER o, x, X ---------- */

START_TEST(sprintf_spec_x_1) {
  char str1[400];
  char str2[400];
  const char *format = "%x %x %x\n%X %X %X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_2) {
  char str1[400];
  char str2[400];
  const char *format = "%+x %+x %+x\n%+X %+X %+X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_3) {
  char str1[400];
  char str2[400];
  const char *format = "% x % x % x\n% X % X % X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_4) {
  char str1[400];
  char str2[400];
  const char *format = "%-x %-x %-x\n%-X %-X %-X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_6) {
  char str1[400];
  char str2[400];
  const char *format = "%0x %0x %0x\n%0X %0X %0X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_7) {
  char str1[400];
  char str2[400];
  const char *format = "%4x %5x %3x\n%4X %5X %3X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_8) {
  char str1[400];
  char str2[400];
  const char *format = "%.2x %.13x %.98x\n%.2X %.13X %.98X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_9) {
  char str1[400];
  char str2[400];
  const char *format = "%*x %x %x\n%*X %X %X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 10, first, third, fifth, 10, first, third,
                  fifth),
      sprintf(str2, format, 10, first, third, fifth, 10, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_11) {
  char str1[400];
  char str2[400];
  const char *format = "%x %x %x\n%X %X %X";

  int first = 0x0005c4353b;
  int third = 0x0001111111;
  int fifth = 000325052;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_12) {
  char str1[400];
  char str2[400];
  const char *format = "%x %x %x\n%X %X %X";

  char *first = "0x5c4353b";
  char *third = "0x11111111";
  char *fifth = "-3435435";

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_13) {
  char str1[400];
  char str2[400];
  const char *format = "%.*x %x %.*x\n%.*X %X %.*X";

  int first = 0x5c4353b;
  int third = 0x11111111;
  int fifth = -3435435;

  ck_assert_int_eq(s21_sprintf(str1, format, 10, first, third, 5, fifth, 10,
                               first, third, 5, fifth),
                   sprintf(str2, format, 10, first, third, 5, fifth, 10, first,
                           third, 5, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_15) {
  char str1[400];
  char str2[400];
  const char *format = "%lx %lx %lx\n%lX %lX %lX";

  long int first = 0xc43532b1;
  long int third = 0xFba788ba;
  long int fifth = -657853654;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_16) {
  char str1[400];
  char str2[400];
  const char *format = "%6lx %0lx %-15lx\n%6lx %0lX %-15lX";

  long int first = 0xc43532b1;
  long int third = 0xFba788ba;
  long int fifth = -657853654;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_17) {
  char str1[400];
  char str2[400];
  const char *format = "%hx %hx %hx\n%hX %hX %hX";

  short int first = 0x53b;
  short int third = 0x519c;
  short int fifth = -6435;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_18) {
  char str1[400];
  char str2[400];
  const char *format = "%6hx %2xo %1hx\n%6hX %2hX %1hX";

  short int first = 0x5ab2;
  short int third = 0x1621;
  short int fifth = -3615;

  ck_assert_int_eq(
      s21_sprintf(str1, format, first, third, fifth, first, third, fifth),
      sprintf(str2, format, first, third, fifth, first, third, fifth));
  ck_assert_str_eq(str1, str2);
}
END_TEST

/* ---------- SPECIFIER % ---------- */

START_TEST(sprintf_spec_percent_1) {
  char str1[400];
  char str2[400];
  const char *format = "Hello %c%%";

  ck_assert_int_eq(s21_sprintf(str1, format, 'z'), sprintf(str2, format, 'z'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_percent_2) {
  char str1[400];
  char str2[400];
  const char *format = "Hello %%c%%%";

  ck_assert_int_eq(s21_sprintf(str1, format, 'z'), sprintf(str2, format, 'z'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_percent_3) {
  char str1[400];
  char str2[400];
  const char *format = "%%%%%c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'z'), sprintf(str2, format, 'z'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_percent_4) {
  char str1[400];
  char str2[400];
  const char *format = "%%%%c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'z'), sprintf(str2, format, 'z'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

/* ---------- TESTS ---------- */

Suite *s21_sprintf_d_suite(void) {
  Suite *s1;
  TCase *tc_core;
  s1 = suite_create("SPECIFIER D");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_d_0);
  tcase_add_test(tc_core, sprintf_spec_d_1);
  tcase_add_test(tc_core, sprintf_spec_d_2);
  tcase_add_test(tc_core, sprintf_spec_d_3);
  tcase_add_test(tc_core, sprintf_spec_d_4);
  tcase_add_test(tc_core, sprintf_spec_d_5);
  tcase_add_test(tc_core, sprintf_spec_d_6);
  tcase_add_test(tc_core, sprintf_spec_d_7);
  tcase_add_test(tc_core, sprintf_spec_d_8);
  tcase_add_test(tc_core, sprintf_spec_d_9);
  tcase_add_test(tc_core, sprintf_spec_d_10);
  tcase_add_test(tc_core, sprintf_spec_d_11);
  tcase_add_test(tc_core, sprintf_spec_d_12);
  tcase_add_test(tc_core, sprintf_spec_d_13);
  tcase_add_test(tc_core, sprintf_spec_d_15);
  tcase_add_test(tc_core, sprintf_spec_d_16);
  tcase_add_test(tc_core, sprintf_spec_d_17);
  tcase_add_test(tc_core, sprintf_spec_d_18);
  tcase_add_test(tc_core, sprintf_spec_d_19);
  suite_add_tcase(s1, tc_core);
  return s1;
}

Suite *s21_sprintf_c_suite(void) {
  Suite *s2;
  TCase *tc_core;
  s2 = suite_create("SPECIFIER C");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_c_1);
  tcase_add_test(tc_core, sprintf_spec_c_2);
  tcase_add_test(tc_core, sprintf_spec_c_3);
  tcase_add_test(tc_core, sprintf_spec_c_4);
  tcase_add_test(tc_core, sprintf_spec_c_5);
  tcase_add_test(tc_core, sprintf_spec_c_6);
  tcase_add_test(tc_core, sprintf_spec_c_7);
  tcase_add_test(tc_core, sprintf_spec_c_8);
  tcase_add_test(tc_core, sprintf_spec_c_9);
  tcase_add_test(tc_core, sprintf_spec_c_10);
  suite_add_tcase(s2, tc_core);
  return s2;
}

// Suite *s21_sprintf_s_suite(void) {
//   Suite *s3;
//   TCase *tc_core;
//   s3 = suite_create("SPECIFIER S");
//   tc_core = tcase_create("core");
//   tcase_add_test(tc_core, sprintf_spec_s_1);
//   tcase_add_test(tc_core, sprintf_spec_s_2);
//   tcase_add_test(tc_core, sprintf_spec_s_3);
//   tcase_add_test(tc_core, sprintf_spec_s_4);
//   tcase_add_test(tc_core, sprintf_spec_s_5);
//   tcase_add_test(tc_core, sprintf_spec_s_6);
//   tcase_add_test(tc_core, sprintf_spec_s_7);
//   tcase_add_test(tc_core, sprintf_spec_s_8);
//   tcase_add_test(tc_core, sprintf_spec_s_9);
//   tcase_add_test(tc_core, sprintf_spec_s_10);
//   suite_add_tcase(s3, tc_core);
//   return s3;
// }

Suite *s21_sprintf_u_suite(void) {
  Suite *s5;
  TCase *tc_core;
  s5 = suite_create("SPECIFIER U");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_u_1);
  tcase_add_test(tc_core, sprintf_spec_u_2);
  tcase_add_test(tc_core, sprintf_spec_u_3);
  tcase_add_test(tc_core, sprintf_spec_u_4);
  tcase_add_test(tc_core, sprintf_spec_u_6);
  tcase_add_test(tc_core, sprintf_spec_u_7);
  tcase_add_test(tc_core, sprintf_spec_u_8);
  tcase_add_test(tc_core, sprintf_spec_u_9);
  tcase_add_test(tc_core, sprintf_spec_u_11);
  tcase_add_test(tc_core, sprintf_spec_u_12);
  tcase_add_test(tc_core, sprintf_spec_u_13);
  tcase_add_test(tc_core, sprintf_spec_u_15);
  tcase_add_test(tc_core, sprintf_spec_u_16);
  tcase_add_test(tc_core, sprintf_spec_u_17);
  tcase_add_test(tc_core, sprintf_spec_u_18);
  tcase_add_test(tc_core, sprintf_spec_u_19);
  suite_add_tcase(s5, tc_core);
  return s5;
}

Suite *s21_sprintf_x_suite(void) {
  Suite *s9;
  TCase *tc_core;
  s9 = suite_create("SPECIFIER x,X");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_x_1);
  tcase_add_test(tc_core, sprintf_spec_x_2);
  tcase_add_test(tc_core, sprintf_spec_x_3);
  tcase_add_test(tc_core, sprintf_spec_x_4);
  tcase_add_test(tc_core, sprintf_spec_x_6);
  tcase_add_test(tc_core, sprintf_spec_x_7);
  tcase_add_test(tc_core, sprintf_spec_x_8);
  tcase_add_test(tc_core, sprintf_spec_x_9);
  tcase_add_test(tc_core, sprintf_spec_x_11);
  tcase_add_test(tc_core, sprintf_spec_x_12);
  tcase_add_test(tc_core, sprintf_spec_x_13);
  tcase_add_test(tc_core, sprintf_spec_x_15);
  tcase_add_test(tc_core, sprintf_spec_x_16);
  tcase_add_test(tc_core, sprintf_spec_x_17);
  tcase_add_test(tc_core, sprintf_spec_x_18);
  suite_add_tcase(s9, tc_core);
  return s9;
}

Suite *s21_sprintf_o_suite(void) {
  Suite *s9;
  TCase *tc_core;
  s9 = suite_create("SPECIFIER o");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_o_1);
  tcase_add_test(tc_core, sprintf_spec_o_2);
  tcase_add_test(tc_core, sprintf_spec_o_3);
  tcase_add_test(tc_core, sprintf_spec_o_4);
  tcase_add_test(tc_core, sprintf_spec_o_6);
  tcase_add_test(tc_core, sprintf_spec_o_7);
  tcase_add_test(tc_core, sprintf_spec_o_8);
  tcase_add_test(tc_core, sprintf_spec_o_9);
  tcase_add_test(tc_core, sprintf_spec_o_12);
  tcase_add_test(tc_core, sprintf_spec_o_13);
  tcase_add_test(tc_core, sprintf_spec_o_15);
  tcase_add_test(tc_core, sprintf_spec_o_16);
  tcase_add_test(tc_core, sprintf_spec_o_17);
  tcase_add_test(tc_core, sprintf_spec_o_18);
  suite_add_tcase(s9, tc_core);
  return s9;
}

Suite *s21_sprintf_percent_suite(void) {
  Suite *s11;
  TCase *tc_core;
  s11 = suite_create("SPECIFIER PERCENT %");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sprintf_spec_percent_1);
  tcase_add_test(tc_core, sprintf_spec_percent_2);
  tcase_add_test(tc_core, sprintf_spec_percent_3);
  tcase_add_test(tc_core, sprintf_spec_percent_4);
  suite_add_tcase(s11, tc_core);
  return s11;
}