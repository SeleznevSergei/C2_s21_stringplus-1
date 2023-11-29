#include <check.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

//  s21_memcpy

START_TEST(s21_memcpy_normal) {
  char test_dest[100] = "hello world again!";
  char test_dest2[100] = "hello world again!";
  const char *test_src = "tak";
  s21_size_t test_count = 3;
  char *s21_res = s21_memcpy(test_dest, test_src, test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
}
END_TEST

START_TEST(s21_memcpy_out) {
  char test_dest[100] = "hello world again!";
  char test_dest2[100] = "hello world again!";
  const char *test_src = "tak";
  s21_size_t test_count = 2;
  char *s21_res = s21_memcpy(test_dest, test_src, test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
}
END_TEST

START_TEST(s21_memcpy_empty_dest) {
  char test_dest[100] = "";
  char test_dest2[100] = "";
  const char *test_src = "tak";
  s21_size_t test_count = 3;
  char *s21_res = s21_memcpy(test_dest, test_src, test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
}
END_TEST

START_TEST(s21_memcpy_empty_src) {
  char test_dest[100] = "hello world";
  char test_dest2[100] = "hello world";
  const char *test_src = "";
  s21_size_t test_count = 0;
  char *s21_res = s21_memcpy(test_dest, test_src, test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
}
END_TEST

//  s21_memmove

START_TEST(s21_memmove_normal) {
  char test_dest[100] = "hello world again! and again";
  char test_dest2[100] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  s21_size_t test_count = 3;
  char *s21_res = s21_memmove(test_dest, test_src, test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
}
END_TEST

START_TEST(s21_memmove_no_normal) {
  char sc1[50] = "School21ForEveryBodyHere";
  s21_memmove(sc1, sc1 + 8, 8);

  char sc2[50] = "School21ForEveryBodyHere";
  s21_memmove(sc2 + 8, sc2, 16);

  char sc3[50] = "School21ForEveryBodyHere";
  memmove(sc3, sc3 + 8, 8);

  char sc4[50] = "School21ForEveryBodyHere";
  memmove(sc4 + 8, sc4, 16);

  ck_assert_str_eq(sc1, sc3);
  ck_assert_str_eq(sc2, sc4);
}
END_TEST

START_TEST(s21_memmove_with_index) {
  char test_dest[100] = "hello world again! and again";
  char test_dest2[100] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  s21_size_t test_count = 3;
  char *s21_res = s21_memmove(test_dest, &test_src[3], test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, &test_src[3], test_count));
}
END_TEST

START_TEST(s21_memmove_with_index_both) {
  char test_dest[100] = "hello world again! and again";
  char test_dest2[100] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  s21_size_t test_count = 3;
  char *s21_res = s21_memmove(&test_dest[1], &test_src[3], test_count);
  ck_assert_str_eq(s21_res, memcpy(&test_dest2[1], &test_src[3], test_count));
}
END_TEST

START_TEST(s21_memmove_out) {
  char test_dest[100] = "hello world again! and again";
  char test_dest2[100] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  s21_size_t test_count = 4;
  char *s21_res = s21_memmove(test_dest, test_src, test_count);
  ck_assert_str_eq(s21_res, memcpy(test_dest2, test_src, test_count));
}
END_TEST

START_TEST(s21_memmove_dest_short) {
  char test_dest[50] = "hello world again! and again";
  char test_dest2[50] = "hello world again! and again";
  s21_size_t test_count = 3;
  char *s21_res = s21_memmove(&test_dest[5], &test_dest[2], test_count);
  ck_assert_str_eq(s21_res, memcpy(&test_dest2[5], &test_dest2[2], test_count));
}
END_TEST

//  s21_strcpy

START_TEST(s21_strcpy_normal) {
  char test_dest[100] = "hello world again! and again";
  char test_dest2[100] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  char *s21_res = s21_strcpy(test_dest, test_src);
  ck_assert_str_eq(s21_res, strcpy(test_dest2, test_src));
}
END_TEST

START_TEST(s21_strcpy_out) {
  char test_dest[50] = "hello world again! and again";
  char test_dest2[50] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  char *s21_res = s21_strcpy(test_dest, test_src);
  ck_assert_str_eq(s21_res, strcpy(test_dest2, test_src));
}
END_TEST

//  s21_strncpy

START_TEST(s21_strncpy_normal) {
  char test_dest[100] = "Hello world gello world gellortwls";
  char test_dest2[100] = "Hello world gello world gellortwls";
  const char test_src[100] = "taktaktak";
  s21_size_t n = 5;
  char *s21_res = s21_strncpy(test_dest, test_src, n);
  ck_assert_str_eq(s21_res, strncpy(test_dest2, test_src, n));
}
END_TEST

START_TEST(s21_strncpy_out) {
  char test_dest[50] = "hello world again! and again";
  char test_dest2[50] = "hello world again! and again";
  const char test_src[100] = "taktaktak";
  s21_size_t n = 10;
  char *s21_res = s21_strncpy(test_dest, test_src, n);
  ck_assert_str_eq(s21_res, strncpy(test_dest2, test_src, n));
}
END_TEST

//  s21_insert

START_TEST(s21_insert_normal) {
  char *src = "lol cho";
  char *str = "nie rozumiem ";
  s21_size_t start_index = 4;

  char *func_result0 = s21_insert(src, str, start_index);
  ck_assert_str_eq(func_result0, "lol nie rozumiem cho");
  free(func_result0);
}
END_TEST

START_TEST(s21_insert_invalid_index) {
  char *src = "lol cho";
  char *str = "nie rozumiem";
  s21_size_t start_index1 = 1000;
  s21_size_t start_index2 = -2;

  char *func_result1 = s21_insert(src, str, start_index1);
  char *func_result2 = s21_insert(src, str, start_index2);

  ck_assert_ptr_eq(func_result1, s21_NULL);
  ck_assert_ptr_eq(func_result2, s21_NULL);
  free(func_result1);
  free(func_result2);
}
END_TEST

//  HARMONIC ****************************************

START_TEST(s21_to_upper_normal) {
  char *test_str0 = "hello world";
  char *test_str1 = "h1e2l3l4o5";

  char *func_result0 = s21_to_upper(test_str0);
  char *func_result1 = s21_to_upper(test_str1);

  ck_assert_str_eq(func_result0, "HELLO WORLD");
  ck_assert_str_eq(func_result1, "H1E2L3L4O5");
  free(func_result0);
  free(func_result1);
}
END_TEST

//  s21_to_upper
START_TEST(s21_to_upper_whith_sign) {
  char *test_str = "h!e1l/l&o.";

  char *func_result = s21_to_upper(test_str);
  ck_assert_str_eq(func_result, "H!E1L/L&O.");
  free(func_result);
}
END_TEST

START_TEST(s21_to_upper_whith_upper) {
  char *test_str = "HELLO";

  char *func_result = s21_to_upper(test_str);
  ck_assert_str_eq(func_result, test_str);
  free(func_result);
}
END_TEST

// s21_to_lower
START_TEST(s21_to_lower_normal) {
  char *test_str = "My Name Is";

  char *func_res = s21_to_lower(test_str);
  ck_assert_str_eq(func_res, "my name is");
  free(func_res);
}
END_TEST

START_TEST(s21_to_lower_sign) {
  char *test_str = "My Name 1s";

  char *func_res = s21_to_lower(test_str);
  ck_assert_str_eq(func_res, "my name 1s");
  free(func_res);
}
END_TEST

START_TEST(s21_to_lower_with_lower) {
  char *test_str = "my name is";

  char *func_res = s21_to_lower(test_str);
  ck_assert_str_eq(func_res, "my name is");
  free(func_res);
}
END_TEST

//  s21_trim
START_TEST(s21_trim_normal) {
  char *test_str = "my name is";
  char *trim_chars = "my";

  char *func_res = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(func_res, " name is");
  free(func_res);
}
END_TEST

START_TEST(s21_trim_sides) {
  char *test_str = "my name is rey";
  char *trim_chars = "my";

  char *func_res = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(func_res, " name is re");
  free(func_res);
}
END_TEST

START_TEST(s21_trim_empty) {
  char *test_str = " my name is rey ";
  char *trim_chars = " ";

  char *func_res = s21_trim(test_str, trim_chars);
  ck_assert_str_eq(func_res, "my name is rey");
  free(func_res);
}
END_TEST

//  s21_strtok
START_TEST(s21_strtok_normal) {
  char s21_test_str[30] = "one/two.three?four";
  char lib_test_str[30] = "one/two.three?four";
  char *step = "./?";
  char *s21_result = s21_strtok(s21_test_str, step);
  char *lib_result = strtok(lib_test_str, step);

  while (s21_result != s21_NULL && lib_result != s21_NULL) {
    ck_assert_str_eq(s21_result, lib_result);
    s21_result = s21_strtok(s21_NULL, step);
    lib_result = strtok(s21_NULL, step);
  }
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strtok_no_delimetr) {
  char s21_test_str[30] = "one/two.three?four";
  char lib_test_str[30] = "one/two.three?four";
  char *step = "$()-";
  char *s21_result = s21_strtok(s21_test_str, step);
  char *lib_result = strtok(lib_test_str, step);

  while (s21_result != s21_NULL && lib_result != s21_NULL) {
    ck_assert_str_eq(s21_result, lib_result);
    s21_result = s21_strtok(s21_NULL, step);
    lib_result = strtok(s21_NULL, step);
  }
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strtok_empty) {
  char s21_test_str[30] = "";
  char lib_test_str[30] = "";
  char *step = "$()-";
  char *s21_result = s21_strtok(s21_test_str, step);
  char *lib_result = strtok(lib_test_str, step);

  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

//  s21_strpbrk
START_TEST(s21_strpbrk_normal) {
  char test_str[11] = "0123456789";
  char symb[4] = "345";

  char *s21_result = s21_strpbrk(test_str, symb);
  char *lib_result = strpbrk(test_str, symb);

  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strpbrk_no_symb) {
  char test_str[11] = "0123456789";
  char symb[2] = "a";

  char *s21_result = s21_strpbrk(test_str, symb);
  char *lib_result = strpbrk(test_str, symb);

  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strpbrk_empty_symb) {
  char test_str[11] = "0123456789";
  char *symb = "";

  char *s21_result = s21_strpbrk(test_str, symb);
  char *lib_result = strpbrk(test_str, symb);

  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strpbrk_empty_str) {
  char *test_str = "";
  char symb[4] = "123";

  char *s21_result = s21_strpbrk(test_str, symb);
  char *lib_result = strpbrk(test_str, symb);

  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

//  memset
START_TEST(s21_memset_normal) {
  char s21_test_str[10] = "Hello";
  s21_memset(s21_test_str, 'c', 3);
  char lib_test_str[10] = "Hello";
  memset(lib_test_str, 'c', 3);

  ck_assert_str_eq(s21_test_str, lib_test_str);
}
END_TEST

START_TEST(s21_memset_null) {
  char *s21_test_str = (char *)calloc(12, sizeof(char));
  char *lib_test_str = (char *)calloc(12, sizeof(char));

  s21_memset(s21_test_str, '\0', 11);
  memset(lib_test_str, '\0', 11);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  free(s21_test_str);
  free(lib_test_str);
}
END_TEST

START_TEST(s21_memset_sign) {
  char s21_test_str[10] = "Hello";
  char lib_test_str[10] = "Hello";
  s21_memset(s21_test_str, 0, 5);
  memset(lib_test_str, 0, 5);
  ck_assert_str_eq(s21_test_str, lib_test_str);
}
END_TEST

//  strerror
START_TEST(s21_strerror_normal) {
  char *s21_test_str = s21_strerror(1);
  char *lib_test_str = strerror(1);

  ck_assert_str_eq(s21_test_str, lib_test_str);
}
END_TEST

START_TEST(s21_strerror_unknown) {
  char *s21_test_str = s21_strerror(109);
  char *lib_test_str = strerror(109);

  ck_assert_str_eq(s21_test_str, lib_test_str);
}
END_TEST

//  sprintf
START_TEST(s21_sprintf_d) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%d>|<%-3.d>|<%5.7d>|<%10d>|<%#d>|<%-d>|<%+d>|<%ld>|<% .d>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_nan_inf) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "%f %f %F %F %g %g %G %G %e %e %E %E";
  float f1 = INFINITY;
  float f2 = NAN;
  int res1 =
      sprintf(str1, str3, f1, f2, f1, f2, f1, f2, f1, f2, f1, f2, f1, f2);
  int res2 =
      s21_sprintf(str2, str3, f1, f2, f1, f2, f1, f2, f1, f2, f1, f2, f1, f2);
  ck_assert_int_eq(res1, res2);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_e) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%#e>|<%#.e>|<%#5.e>|<%#.0e>|<%#0.0e> %%";
  double num = -665695342471359.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_c) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%6.4c>|<%-6.4c>|<%4.10lc>|<%-4.10lc>|<%-0lc>";
  int a = 10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_E) {
  char str1[300] = "";
  char str2[300] = "";
  double num1 = .3529373967;
  double num2 = .0003529373967;
  double num3 = 0.00000003529373967;
  char *str3 = "<% 30.1E>|<% 30.E>|<%030.0E>";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_i) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%i><%3.i><%5.7i><%10i><%#i><%-i><%+i><%.i><% .i>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_on) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "text %o %n  %o%n";
  int val = 012;
  int val2 = 017;
  int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, &valn1, val2, &valn3),
                   s21_sprintf(str2, str3, val, &valn2, val2, &valn4));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
  ck_assert_int_eq(valn3, valn4);
}
END_TEST

START_TEST(s21_sprintf_o) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%o><%3.o><%5.7o><%10o %#o %-o %+o %.o % .o>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_p) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0p><%06p><%05.7p><%0.7p Oof %0.p>";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_s) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<% s><% 3.s><% 5.7s><% 10s GOD %.s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_u) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%u><%3.u><%5.7u><%10u><%#u><%-u><%+u><%.u><% .u>";
  unsigned int val = 0;
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_f) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%Lf>|<%.Lf>|<%+-#Lf>|<%+#.Lf>|<%-#.Lf>";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_g) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%g>|<%.0g>|<%4.2g>|<%4.g>|<%5.10g>";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_x) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%x><%3.x><%5.7x><%10x><%#x><%-x><%+x><%.x><% .x>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_h) {
  char *s21_test_str = (char *)calloc(256, sizeof(char));
  char *lib_test_str = (char *)calloc(256, sizeof(char));

  short e = 0;
  short f = 32767;
  unsigned short b = 65535;
  int lib_res = sprintf(lib_test_str, "|%hi| |%hd| |%hu|", e, f, b);
  int s21_res = s21_sprintf(s21_test_str, "|%hi| |%hd| |%hu|", e, f, b);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
}
END_TEST

START_TEST(s21_sprintf_l) {
  char *s21_test_str = (char *)calloc(256, sizeof(char));
  char *lib_test_str = (char *)calloc(256, sizeof(char));
  long i = INT_MAX;
  long a = INT_MIN;
  unsigned long b = 4294967295;
  int lib_res = sprintf(lib_test_str, "|%li| |%ld| |%lu|", i, a, b);
  int s21_res = s21_sprintf(s21_test_str, "|%li| |%ld| |%lu|", i, a, b);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
}
END_TEST

START_TEST(s21_sprintf_empty) {
  char *s21_test_str = (char *)calloc(512, sizeof(char));
  char *lib_test_str = (char *)calloc(512, sizeof(char));

  int lib_res = sprintf(lib_test_str, "%c", '\0');
  int s21_res = s21_sprintf(s21_test_str, "%c", '\0');

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
}
END_TEST

START_TEST(s21_strlen_normal) {
  // Arrange
  char *test_str = "12345678";
  // Act
  int s21_result = s21_strlen(test_str);
  int lib_result = strlen(test_str);
  // Assert
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strlen_empty) {
  char *test_str = "";

  int s21_result = s21_strlen(test_str);
  int lib_result = strlen(test_str);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

// s21_strstr
START_TEST(s21_strstr_normal) {
  char *test_haystack = "12345678";
  char *test_needle = "3";

  char *s21_result = s21_strstr(test_haystack, test_needle);
  char *lib_result = strstr(test_haystack, test_needle);

  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strstr_SF) {
  char *test_haystack = "67878";
  char *test_needle = "345";

  char *s21_result = s21_strstr(test_haystack, test_needle);
  char *lib_result = strstr(test_haystack, test_needle);

  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strstr_empty) {
  char *test_haystack = "123456";
  char *test_needle = "";

  char *s21_result = s21_strstr(test_haystack, test_needle);
  char *lib_result = strstr(test_haystack, test_needle);

  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strstr_all_empty) {
  char *test_haystack = "";
  char *test_needle = "";

  char *s21_result = s21_strstr(test_haystack, test_needle);
  char *lib_result = strstr(test_haystack, test_needle);

  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcmp_normal_plus) {
  char *test_str = "12346";
  char *test_substr = "12345";

  int s21_result = s21_strcmp(test_str, test_substr);
  int lib_result = strcmp(test_str, test_substr);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcmp_normal_minus) {
  char *test_str = "12345";
  char *test_substr = "12346";

  int s21_result = s21_strcmp(test_str, test_substr);
  int lib_result = strcmp(test_str, test_substr);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcmp_empty) {
  char *test_str = "12345";
  char *test_substr = "1";

  int s21_result = s21_strcmp(test_str, test_substr);
  int lib_result = strcmp(test_str, test_substr);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcmp_all_empty) {
  char *test_str = "";
  char *test_substr = "";

  int s21_result = s21_strcmp(test_str, test_substr);
  int lib_result = strcmp(test_str, test_substr);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcmp_midle_dif_plus) {
  char *test_str = "12845";
  char *test_substr = "12345";

  int s21_result = s21_strcmp(test_str, test_substr);
  int lib_result = strcmp(test_str, test_substr);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcmp_midle_dif_minus) {
  char *test_str = "12345";
  char *test_substr = "12845";

  int s21_result = s21_strcmp(test_str, test_substr);
  int lib_result = strcmp(test_str, test_substr);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcmp_equal) {
  char *test_str = "12345";
  char *test_substr = "12345";

  int s21_result = s21_strcmp(test_str, test_substr);
  int lib_result = strcmp(test_str, test_substr);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_equal_mid) {
  char *test_str = "12345";
  char *test_substr = "12345";
  s21_size_t n = 3;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_equal) {
  char *test_str = "12345";
  char *test_substr = "12345";
  s21_size_t n = 5;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_start_dif_plus) {
  char *test_str = "22345";
  char *test_substr = "12345";
  s21_size_t n = 7;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_start_dif_minus) {
  char *test_str = "12345";
  char *test_substr = "22345";
  s21_size_t n = 4;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_start_empty) {
  char *test_str = "22345";
  char *test_substr = "";
  s21_size_t n = 3;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_zero_n) {
  char *test_str = "22345";
  char *test_substr = "12345";
  s21_size_t n = 0;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_mid_dif) {
  char *test_str = "12345";
  char *test_substr = "13545";
  s21_size_t n = 4;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncmp_all_empty) {
  char *test_str = "";
  char *test_substr = "";
  s21_size_t n = 4;

  int s21_result = s21_strncmp(test_str, test_substr, n);
  int lib_result = strncmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_normal_equal) {
  char *test_str = "12345";
  char *test_substr = "12345";
  s21_size_t n = 5;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_zero_n) {
  char *test_str = "02345";
  char *test_substr = "12345";
  s21_size_t n = 0;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_normal_plus) {
  char *test_str = "12346";
  char *test_substr = "12345";
  s21_size_t n = 2;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_normal_minus) {
  char *test_str = "02346";
  char *test_substr = "04345";
  s21_size_t n = 2;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_all_empty) {
  char *test_str = "";
  char *test_substr = "";
  s21_size_t n = 0;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_empty_str) {
  char *test_str = "0";
  char *test_substr = "46545";
  s21_size_t n = 2;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memcmp_empty_substr) {
  char *test_str = "46426";
  char *test_substr = "1";
  s21_size_t n = 2;

  int s21_result = s21_memcmp(test_str, test_substr, n);
  int lib_result = memcmp(test_str, test_substr, n);

  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

// s_21_memchr
START_TEST(s21_memchr_normal) {
  // Arrange
  char *str = "ABCDEFG";
  char sym = 'D';
  s21_size_t n = strlen(str);
  // Act
  char *s21_result = s21_memchr(str, sym, n);
  char *lib_result = memchr(str, sym, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memchr_empty_str) {
  // Arrange
  char *str = "";
  char sym = 'D';
  s21_size_t n = strlen(str);
  // Act
  char *s21_result = s21_memchr(str, sym, n);
  char *lib_result = memchr(str, sym, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memchr_empty_sym) {
  // Arrange
  char *str = "ABCDEFG";
  char sym = '\0';
  s21_size_t n = strlen(str);
  // Act
  char *s21_result = s21_memchr(str, sym, n);
  char *lib_result = memchr(str, sym, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memchr_n_zero) {
  // Arrange
  char *str = "ABCDEFG";
  char sym = 'D';
  s21_size_t n = 0;
  // Act
  char *s21_result = s21_memchr(str, sym, n);
  char *lib_result = memchr(str, sym, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_memchr_empty_str_sym) {
  // Arrange
  char *str = "";
  char sym = '\0';
  s21_size_t n = strlen(str);
  // Act
  char *s21_result = s21_memchr(str, sym, n);
  char *lib_result = memchr(str, sym, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

// s21_strcat
START_TEST(s21_strcat_normal) {
  // Arrange
  char str_1[20] = "hello";
  char *str_2 = "world";
  // Act
  char *s21_result = s21_strcat(str_1, str_2);
  char *lib_result = strcat(str_1, str_2);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcat_first_str_empty) {
  // Arrange
  char str_1[20];
  str_1[0] = '\0';
  char str_2[20];
  str_2[0] = '\0';
  char *str_3 = "world";
  // Act
  char *s21_result = s21_strcat(str_1, str_3);
  char *lib_result = strcat(str_2, str_3);
  // Assert
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcat_second_str_empty) {
  // Arrange
  char str_1[20] = "hello";
  char *str_2 = "";
  // Act
  char *s21_result = s21_strcat(str_1, str_2);
  char *lib_result = strcat(str_1, str_2);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcat_both_str_empty) {
  // Arrange
  char str_1[20] = "";
  char *str_2 = "";
  // Act
  char *s21_result = s21_strcat(str_1, str_2);
  char *lib_result = strcat(str_1, str_2);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

// s21_strncat
START_TEST(s21_strncat_normal) {
  // Arrange
  char str_1[20] = "hello";
  char str_2[20] = "hello";
  char *str_3 = "world";
  s21_size_t n = 3;
  // Act
  char *s21_result = s21_strncat(str_1, str_3, n);
  char *lib_result = strncat(str_2, str_3, n);
  // Assert
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncat_first_str_empty) {
  // Arrange
  char str_1[20] = "";
  char *str_2 = "world";
  s21_size_t n = 3;
  // Act
  char *s21_result = s21_strncat(str_1, str_2, n);
  char *lib_result = strncat(str_1, str_2, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncat_second_str_empty) {
  // Arrange
  char str_1[20] = "hello";
  char *str_2 = "";
  s21_size_t n = 3;
  // Act
  char *s21_result = s21_strncat(str_1, str_2, n);
  char *lib_result = strncat(str_1, str_2, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncat_both_str_empty) {
  // Arrange
  char str_1[20] = "";
  char *str_2 = "";
  s21_size_t n = 3;
  // Act
  char *s21_result = s21_strncat(str_1, str_2, n);
  char *lib_result = strncat(str_1, str_2, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncat_size_empty) {
  // Arrange
  char str_1[20] = "hello";
  char *str_2 = "world";
  s21_size_t n = 0;
  // Act
  char *s21_result = s21_strncat(str_1, str_2, n);
  char *lib_result = strncat(str_1, str_2, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncat_size_zero) {
  // Arrange
  char str_1[20] = "hello";
  char *str_2 = "world";
  s21_size_t n = 0;
  // Act
  char *s21_result = s21_strncat(str_1, str_2, n);
  char *lib_result = strncat(str_1, str_2, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strncat_all_empty) {
  // Arrange
  char str_1[20] = "";
  char *str_2 = "";
  s21_size_t n = 0;
  // Act
  char *s21_result = s21_strncat(str_1, str_2, n);
  char *lib_result = strncat(str_1, str_2, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

// s21_strchr
START_TEST(s21_strchr_normal) {
  // Arrange
  char *str_1 = "hello";
  char n = 'h';
  // Act
  char *s21_result = s21_strchr(str_1, n);
  char *lib_result = strchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strchr_empty_str) {
  // Arrange
  char *str_1 = "";
  char n = 'h';
  // Act
  char *s21_result = s21_strchr(str_1, n);
  char *lib_result = strchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strchr_empty_sym) {
  // Arrange
  char *str_1 = "hello";
  char n = '\0';
  // Act
  char *s21_result = s21_strchr(str_1, n);
  char *lib_result = strchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strchr_both_empty) {
  // Arrange
  char *str_1 = "";
  char n = '\0';
  // Act
  char *s21_result = s21_strchr(str_1, n);
  char *lib_result = strchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

// s21_strcspn
START_TEST(s21_strcspn_normal) {
  char *str = "hello, world";
  char *keys = "wl";
  // Act
  s21_size_t s21_result = s21_strcspn(str, keys);
  s21_size_t lib_result = strcspn(str, keys);
  // Assert
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcspn_empty_str) {
  char *str = "";
  char *keys = "wl";
  // Act
  s21_size_t s21_result = s21_strcspn(str, keys);
  s21_size_t lib_result = strcspn(str, keys);
  // Assert
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcspn_empty_key) {
  char *str = "hello, world";
  char *keys = "";
  // Act
  s21_size_t s21_result = s21_strcspn(str, keys);
  s21_size_t lib_result = strcspn(str, keys);
  // Assert
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strcspn_both_key) {
  char *str = "";
  char *keys = "";
  // Act
  s21_size_t s21_result = s21_strcspn(str, keys);
  s21_size_t lib_result = strcspn(str, keys);
  // Assert
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

// s21_strrchr
START_TEST(s21_strrchr_normal) {
  // Arrange
  char *str_1 = "hehllo";
  char n = 'h';
  // Act
  char *s21_result = s21_strrchr(str_1, n);
  char *lib_result = strrchr(str_1, n);
  // Assert
  ck_assert_str_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strrchr_empty_str) {
  // Arrange
  char *str_1 = "";
  char n = 'h';
  // Act
  char *s21_result = s21_strrchr(str_1, n);
  char *lib_result = strrchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strrchr_empty_sym) {
  // Arrange
  char *str_1 = "hello";
  char n = '\0';
  // Act
  char *s21_result = s21_strrchr(str_1, n);
  char *lib_result = strrchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strrchr_both_empty) {
  // Arrange
  char *str_1 = "";
  char n = '\0';
  // Act
  char *s21_result = s21_strrchr(str_1, n);
  char *lib_result = strrchr(str_1, n);
  // Assert
  ck_assert_ptr_eq(s21_result, lib_result);
}
END_TEST

// s21_strspn
START_TEST(s21_strspn_normal) {
  // Arrange
  char str_1[12] = "hello world";
  char *str_2 = "world";
  // Act
  int s21_result = s21_strspn(str_1, str_2);
  int lib_result = strspn(str_1, str_2);
  // Assert
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strspn_normal_2) {
  // Arrange
  char str_1[12] = "hello";
  char *str_2 = "hello";
  // Act
  int s21_result = s21_strspn(str_1, str_2);
  int lib_result = strspn(str_1, str_2);
  // Assert
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strspn_first_str_empty) {
  // Arrange
  char *str_1 = "";
  char *str_2 = "world";
  // Act
  int s21_result = s21_strspn(str_1, str_2);
  int lib_result = strspn(str_1, str_2);
  // Assert
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strspn_second_str_empty) {
  // Arrange
  char str_1[12] = "hello world";
  char *str_2 = "";
  // Act
  int s21_result = s21_strspn(str_1, str_2);
  int lib_result = strspn(str_1, str_2);
  // Assert
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strspn_str2_not_in_str1) {
  // Arrange
  char str_1[12] = "hello world";
  char *str_2 = "mac";
  // Act
  int s21_result = s21_strspn(str_1, str_2);
  int lib_result = strspn(str_1, str_2);
  // Assert
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_strspn_both_empty) {
  // Arrange
  char *str_1 = "";
  char *str_2 = "";
  // Act
  int s21_result = s21_strspn(str_1, str_2);
  int lib_result = strspn(str_1, str_2);
  // Assert
  ck_assert_int_eq(s21_result, lib_result);
}
END_TEST

START_TEST(s21_sscanf_c) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(s21_sscanf_d) {
  char format[] = "%d";
  char str[] = "";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_d_width) {
  char format[] = "%2d %4d";
  char str[] = "87654 1234";
  int p1, p2;
  int q1, q2;

  int16_t res1 = s21_sscanf(str, format, &p1, &q1);
  int16_t res2 = sscanf(str, format, &p2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(p1, p2);
  ck_assert_int_eq(q1, q2);
}
END_TEST

START_TEST(s21_sscanf_x_X) {
  char format[] = "%x %x";
  char str[] = "8abc 8ABC";
  int p1, p2;
  int q1, q2;

  int16_t res1 = s21_sscanf(str, format, &p1, &q1);
  int16_t res2 = sscanf(str, format, &p2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(p1, p2);
  ck_assert_int_eq(q1, q2);
}
END_TEST

START_TEST(s21_sscanf_p) {
  char format[] = "%p";
  char str[] = "     ";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_f) {
  char format[] = "%f";
  char str[] = "\n";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_fexp) {
  char format[] = "%f %f";
  char str[] = "123e+04 123E-04";
  float p1, p2;
  float q1, q2;

  int res1 = s21_sscanf(str, format, &p1, &q1);
  int res2 = sscanf(str, format, &p2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(p1, p2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(s21_sscanf_fexp_l) {
  char format[] = "%lf %Lf";
  char str[] = "123e+04 123e-04";
  double p1, p2;
  long double q1, q2;

  int res1 = s21_sscanf(str, format, &p1, &q1);
  int res2 = sscanf(str, format, &p2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq((float)p1, (float)p2);
  ck_assert_float_eq((float)q1, (float)q2);
}
END_TEST

START_TEST(s21_sscanf_f_n) {
  char format[] = "%f %f %n";
  char str[] = "123e+04 123e-04";

  char format2[] = "%f %f %n";
  char str2[] = "123e+04 123e-04";
  float p1, p2;
  float q1, q2;
  int n1, n2;

  int res1 = s21_sscanf(str, format, &p1, &q1, &n1);
  int res2 = sscanf(str2, format2, &p2, &q2, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(p1, p2);
  ck_assert_float_eq(q1, q2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_sscanf_inf) {
  char format[] = "%f";
  char str[] = "inf";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_nan) {
  char format[] = "%f";
  char str[] = "nan";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_o) {
  char format[] = "%o";
  char str[] = "\t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_x) {
  char format[] = "%x";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_empty) {
  char format[] = "";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_t) {
  char format[] = "\t";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_h) {
  char format[] = "%hi%hd%hi";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(s21_sscanf_l) {
  char format[] = "%li %li %ld";
  char str[] = "123 +198 -87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(s21_sscanf_dot) {
  char format[] = "%*x %*x %*x";
  char str[] = "0x123 +04 -372f3";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(s21_sscanf_fg) {
  char format[] = "%fg %f w%fx";
  char str[] = "75g +19.8w -87.x";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST
// самописные
START_TEST(s21_sscanf_fg2) {
  char format[] = "%fg%% %f w%fx";
  char str[] = "75g% +19.8w -87.x";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(s21_sscanf_s) {
  char format[] = "%s";
  char str[] = "some str";
  char buf1[100] = {0};
  char buf2[100] = {0};

  int16_t res1 = s21_sscanf(str, format, buf1);
  int16_t res2 = sscanf(str, format, buf2);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_cw3) {
  char format[] = "%c%c";
  char str[] = "qwerty";
  char str2[] = "qwerty";
  char c1 = 0, c2 = 0;
  char q1 = 0, q2 = 0;

  int16_t res2 = sscanf(str2, format, &c2, &q2);
  int16_t res1 = s21_sscanf(str, format, &c1, &q1);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(q2, q1);
}
END_TEST

START_TEST(s21_sscanf_0x) {
  char format[] = "%x %2x w%X";
  char str[] = "0x1234 156 w789A";

  char format2[] = "%x %2x w%X";
  char str2[] = "0x1234 156 w789A";
  int d1 = 1, d2 = 1;
  int q1 = 2, q2 = 2;
  int z1 = 3, z2 = 3;
  int res2 = sscanf(str2, format2, &d2, &q2, &z2);
  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(q1, q2);
  ck_assert_int_eq(z1, z2);
}
END_TEST

START_TEST(s21_sscanf_0xL) {
  char format[] = "%Lx %2Lx w%LX";
  char str[] = "0x12 15236 w789A";

  char format2[] = "%Lx %2Lx w%LX";
  char str2[] = "0x12 15236 w789A";

  long long int d1 = 1, d2 = 1;
  long long int q1 = 2, q2 = 2;
  long long int z1 = 3, z2 = 3;
  int res2 = sscanf(str2, format2, &d2, &q2, &z2);
  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq((int)d1, (int)d2);
  ck_assert_int_eq(q1, q2);
  ck_assert_int_eq(z1, z2);
}
END_TEST

START_TEST(s21_sscanf_0) {
  char format[] = "%o %2o w%o";
  char str[] = "01234 156 w789A";

  char format2[] = "%o %2o w%o";
  char str2[] = "01234 156 w789A";
  int d1 = 1, d2 = 1;
  int q1 = 2, q2 = 2;
  int z1 = 3, z2 = 3;
  int res2 = sscanf(str2, format2, &d2, &q2, &z2);
  int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(q1, q2);
  ck_assert_int_eq(z1, z2);
}
END_TEST

START_TEST(s21_sscanf_u) {
  char format[] = "%u%hu%lu";
  char str[] = "123 198 87";
  unsigned int d1, d2;
  unsigned short q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

Suite *s21_string_suite() {
  Suite *s;
  TCase *tc_insert, *tc_trim, *tc_strerror, *tc_sprintf, *tc_strncpy,
      *tc_strcpy, *tc_memmove, *tc_memcpy, *tc_to_upper, *tc_strtok,
      *tc_strpbrk, *tc_memset, *tc_strlen, *tc_strstr, *tc_strcmp, *tc_strncmp,
      *tc_memcmp, *tc_memchr, *tc_strcat, *tc_strncat, *tc_strchr, *tc_strcspn,
      *tc_strrchr, *tc_strspn, *tc_to_lower, *tc_sscanf;

  s = suite_create("s21_string");

  tc_memmove = tcase_create("s21_memmove");
  tcase_add_test(tc_memmove, s21_memmove_normal);
  tcase_add_test(tc_memmove, s21_memmove_with_index);
  tcase_add_test(tc_memmove, s21_memmove_with_index_both);
  tcase_add_test(tc_memmove, s21_memmove_out);
  tcase_add_test(tc_memmove, s21_memmove_dest_short);
  tcase_add_test(tc_memmove, s21_memmove_no_normal);
  suite_add_tcase(s, tc_memmove);

  tc_memcpy = tcase_create("s21_memcpy");
  tcase_add_test(tc_memcpy, s21_memcpy_normal);
  tcase_add_test(tc_memcpy, s21_memcpy_out);
  tcase_add_test(tc_memcpy, s21_memcpy_empty_dest);
  tcase_add_test(tc_memcpy, s21_memcpy_empty_src);
  suite_add_tcase(s, tc_memcpy);

  tc_strcpy = tcase_create("s21_strcpy");
  tcase_add_test(tc_strcpy, s21_strcpy_normal);
  tcase_add_test(tc_strcpy, s21_strcpy_out);
  suite_add_tcase(s, tc_strcpy);

  tc_strncpy = tcase_create("s21_strncpy");
  tcase_add_test(tc_strncpy, s21_strncpy_normal);
  tcase_add_test(tc_strncpy, s21_strncpy_out);
  suite_add_tcase(s, tc_strncpy);

  tc_strtok = tcase_create("s21_strtok");
  tcase_add_test(tc_strtok, s21_strtok_normal);
  tcase_add_test(tc_strtok, s21_strtok_no_delimetr);
  tcase_add_test(tc_strtok, s21_strtok_empty);
  suite_add_tcase(s, tc_strtok);

  tc_strpbrk = tcase_create("s21_strpbrk");
  tcase_add_test(tc_strpbrk, s21_strpbrk_normal);
  tcase_add_test(tc_strpbrk, s21_strpbrk_no_symb);
  tcase_add_test(tc_strpbrk, s21_strpbrk_empty_symb);
  tcase_add_test(tc_strpbrk, s21_strpbrk_empty_str);
  suite_add_tcase(s, tc_strpbrk);

  tc_memset = tcase_create("s21_memset");
  tcase_add_test(tc_memset, s21_memset_normal);
  tcase_add_test(tc_memset, s21_memset_null);
  tcase_add_test(tc_memset, s21_memset_sign);
  suite_add_tcase(s, tc_memset);

  tc_strerror = tcase_create("s21_strerror");
  tcase_add_test(tc_strerror, s21_strerror_normal);
  tcase_add_test(tc_strerror, s21_strerror_unknown);
  suite_add_tcase(s, tc_strerror);

  tc_strlen = tcase_create("s21_strlen");
  tcase_add_test(tc_strlen, s21_strlen_normal);
  tcase_add_test(tc_strlen, s21_strlen_empty);
  suite_add_tcase(s, tc_strlen);

  tc_strstr = tcase_create("s21_strstr");
  tcase_add_test(tc_strstr, s21_strstr_normal);
  tcase_add_test(tc_strstr, s21_strstr_SF);
  tcase_add_test(tc_strstr, s21_strstr_empty);
  tcase_add_test(tc_strstr, s21_strstr_all_empty);
  suite_add_tcase(s, tc_strstr);

  tc_strcmp = tcase_create("s21_strcmp");
  tcase_add_test(tc_strcmp, s21_strcmp_all_empty);
  tcase_add_test(tc_strcmp, s21_strcmp_empty);
  tcase_add_test(tc_strcmp, s21_strcmp_equal);
  tcase_add_test(tc_strcmp, s21_strcmp_midle_dif_minus);
  tcase_add_test(tc_strcmp, s21_strcmp_midle_dif_plus);
  tcase_add_test(tc_strcmp, s21_strcmp_normal_minus);
  tcase_add_test(tc_strcmp, s21_strcmp_normal_plus);
  suite_add_tcase(s, tc_strcmp);

  tc_strncmp = tcase_create("s21_strncmp");
  tcase_add_test(tc_strncmp, s21_strncmp_all_empty);
  tcase_add_test(tc_strncmp, s21_strncmp_start_empty);
  tcase_add_test(tc_strncmp, s21_strncmp_start_dif_minus);
  tcase_add_test(tc_strncmp, s21_strncmp_start_dif_plus);
  tcase_add_test(tc_strncmp, s21_strncmp_mid_dif);
  tcase_add_test(tc_strncmp, s21_strncmp_equal);
  tcase_add_test(tc_strncmp, s21_strncmp_equal_mid);
  tcase_add_test(tc_strncmp, s21_strncmp_zero_n);
  suite_add_tcase(s, tc_strncmp);

  tc_memcmp = tcase_create("s21_memcmp");
  tcase_add_test(tc_memcmp, s21_memcmp_normal_equal);
  tcase_add_test(tc_memcmp, s21_memcmp_normal_minus);
  tcase_add_test(tc_memcmp, s21_memcmp_normal_plus);
  tcase_add_test(tc_memcmp, s21_memcmp_zero_n);
  tcase_add_test(tc_memcmp, s21_memcmp_all_empty);
  tcase_add_test(tc_memcmp, s21_memcmp_empty_str);
  tcase_add_test(tc_memcmp, s21_memcmp_empty_substr);
  suite_add_tcase(s, tc_memcmp);

  tc_memchr = tcase_create("s21_memchr");
  tcase_add_test(tc_memchr, s21_memchr_normal);
  tcase_add_test(tc_memchr, s21_memchr_empty_str);
  tcase_add_test(tc_memchr, s21_memchr_empty_sym);
  tcase_add_test(tc_memchr, s21_memchr_n_zero);
  tcase_add_test(tc_memchr, s21_memchr_empty_str_sym);
  suite_add_tcase(s, tc_memchr);

  tc_strcat = tcase_create("s21_strcat");
  tcase_add_test(tc_strcat, s21_strcat_normal);
  tcase_add_test(tc_strcat, s21_strcat_first_str_empty);
  tcase_add_test(tc_strcat, s21_strcat_second_str_empty);
  tcase_add_test(tc_strcat, s21_strcat_both_str_empty);
  suite_add_tcase(s, tc_strcat);

  tc_strncat = tcase_create("s21_strncat");
  tcase_add_test(tc_strncat, s21_strncat_normal);
  tcase_add_test(tc_strncat, s21_strncat_first_str_empty);
  tcase_add_test(tc_strncat, s21_strncat_second_str_empty);
  tcase_add_test(tc_strncat, s21_strncat_both_str_empty);
  tcase_add_test(tc_strncat, s21_strncat_size_empty);
  tcase_add_test(tc_strncat, s21_strncat_size_zero);
  tcase_add_test(tc_strncat, s21_strncat_all_empty);
  suite_add_tcase(s, tc_strncat);

  tc_strchr = tcase_create("s21_strchr");
  tcase_add_test(tc_strchr, s21_strchr_normal);
  tcase_add_test(tc_strchr, s21_strchr_empty_str);
  tcase_add_test(tc_strchr, s21_strchr_empty_sym);
  tcase_add_test(tc_strchr, s21_strchr_both_empty);
  suite_add_tcase(s, tc_strchr);

  tc_strcspn = tcase_create("s21_strcspn");
  tcase_add_test(tc_strcspn, s21_strcspn_normal);
  tcase_add_test(tc_strcspn, s21_strcspn_empty_str);
  tcase_add_test(tc_strcspn, s21_strcspn_empty_key);
  tcase_add_test(tc_strcspn, s21_strcspn_both_key);
  suite_add_tcase(s, tc_strcspn);

  tc_strrchr = tcase_create("s21_strrchr");
  tcase_add_test(tc_strrchr, s21_strrchr_normal);
  tcase_add_test(tc_strrchr, s21_strrchr_empty_str);
  tcase_add_test(tc_strrchr, s21_strrchr_empty_sym);
  tcase_add_test(tc_strrchr, s21_strrchr_both_empty);
  suite_add_tcase(s, tc_strrchr);

  tc_strspn = tcase_create("s21_strspn");
  tcase_add_test(tc_strspn, s21_strspn_normal);
  tcase_add_test(tc_strspn, s21_strspn_normal_2);
  tcase_add_test(tc_strspn, s21_strspn_first_str_empty);
  tcase_add_test(tc_strspn, s21_strspn_second_str_empty);
  tcase_add_test(tc_strspn, s21_strspn_str2_not_in_str1);
  tcase_add_test(tc_strspn, s21_strspn_both_empty);
  suite_add_tcase(s, tc_strspn);

  tc_to_lower = tcase_create("s21_to_lower");
  tcase_add_test(tc_to_lower, s21_to_lower_normal);
  tcase_add_test(tc_to_lower, s21_to_lower_sign);
  tcase_add_test(tc_to_lower, s21_to_lower_with_lower);
  suite_add_tcase(s, tc_to_lower);

  tc_trim = tcase_create("s21_trim");
  tcase_add_test(tc_trim, s21_trim_normal);
  tcase_add_test(tc_trim, s21_trim_sides);
  tcase_add_test(tc_trim, s21_trim_empty);
  suite_add_tcase(s, tc_trim);

  tc_to_upper = tcase_create("s21_to_upper");
  tcase_add_test(tc_to_upper, s21_to_upper_normal);
  tcase_add_test(tc_to_upper, s21_to_upper_whith_sign);
  tcase_add_test(tc_to_upper, s21_to_upper_whith_upper);
  suite_add_tcase(s, tc_to_upper);

  tc_insert = tcase_create("s21_insert");
  tcase_add_test(tc_insert, s21_insert_normal);
  tcase_add_test(tc_insert, s21_insert_invalid_index);
  suite_add_tcase(s, tc_insert);

  tc_sprintf = tcase_create("s21_sprintf");
  tcase_add_test(tc_sprintf, s21_sprintf_d);
  tcase_add_test(tc_sprintf, s21_sprintf_u);
  tcase_add_test(tc_sprintf, s21_sprintf_x);
  tcase_add_test(tc_sprintf, s21_sprintf_g);
  tcase_add_test(tc_sprintf, s21_sprintf_p);
  tcase_add_test(tc_sprintf, s21_sprintf_o);
  tcase_add_test(tc_sprintf, s21_sprintf_on);
  tcase_add_test(tc_sprintf, s21_sprintf_x);
  tcase_add_test(tc_sprintf, s21_sprintf_e);
  tcase_add_test(tc_sprintf, s21_sprintf_E);
  tcase_add_test(tc_sprintf, s21_sprintf_c);
  tcase_add_test(tc_sprintf, s21_sprintf_f);
  tcase_add_test(tc_sprintf, s21_sprintf_i);
  tcase_add_test(tc_sprintf, s21_sprintf_s);
  tcase_add_test(tc_sprintf, s21_sprintf_h);
  tcase_add_test(tc_sprintf, s21_sprintf_l);
  tcase_add_test(tc_sprintf, s21_sprintf_empty);
  tcase_add_test(tc_sprintf, s21_sprintf_nan_inf);

  suite_add_tcase(s, tc_sprintf);

  tc_sscanf = tcase_create("s21_sscanf");
  tcase_add_test(tc_sscanf, s21_sscanf_c);
  tcase_add_test(tc_sscanf, s21_sscanf_cw3);
  tcase_add_test(tc_sscanf, s21_sscanf_d);
  tcase_add_test(tc_sscanf, s21_sscanf_p);
  tcase_add_test(tc_sscanf, s21_sscanf_o);
  tcase_add_test(tc_sscanf, s21_sscanf_f);
  tcase_add_test(tc_sscanf, s21_sscanf_x);
  tcase_add_test(tc_sscanf, s21_sscanf_h);
  tcase_add_test(tc_sscanf, s21_sscanf_fg);
  tcase_add_test(tc_sscanf, s21_sscanf_fg2);
  tcase_add_test(tc_sscanf, s21_sscanf_empty);
  tcase_add_test(tc_sscanf, s21_sscanf_t);
  tcase_add_test(tc_sscanf, s21_sscanf_l);
  tcase_add_test(tc_sscanf, s21_sscanf_dot);
  tcase_add_test(tc_sscanf, s21_sscanf_s);
  tcase_add_test(tc_sscanf, s21_sscanf_0x);
  tcase_add_test(tc_sscanf, s21_sscanf_0xL);
  tcase_add_test(tc_sscanf, s21_sscanf_0);
  tcase_add_test(tc_sscanf, s21_sscanf_inf);
  tcase_add_test(tc_sscanf, s21_sscanf_nan);
  tcase_add_test(tc_sscanf, s21_sscanf_u);
  tcase_add_test(tc_sscanf, s21_sscanf_fexp);
  tcase_add_test(tc_sscanf, s21_sscanf_f_n);
  tcase_add_test(tc_sscanf, s21_sscanf_fexp_l);
  tcase_add_test(tc_sscanf, s21_sscanf_d_width);
  tcase_add_test(tc_sscanf, s21_sscanf_x_X);

  suite_add_tcase(s, tc_sscanf);

  return s;
}

int main() {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = s21_string_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
