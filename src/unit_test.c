#include <check.h>

#include "smart_calc.h"

START_TEST(plus_binar_test) {
  double x = 0;
  // test_string = (char*) malloc(40);
  double s21_res = 0, res = 0;
  int err = 0;
  char* test_string = "1+2=";
  s21_res = calculate(test_string, &err, x);
  res = 1 + 2;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "1.234567+2=";
  s21_res = calculate(test_string, &err, x);
  res = 1.234567 + 2;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "1.234567+2.987654=";
  s21_res = calculate(test_string, &err, x);
  res = 1.234567 + 2.987654;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-3+7=";
  s21_res = calculate(test_string, &err, x);
  res = -3 + 7;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-3.141592+7=";
  s21_res = calculate(test_string, &err, x);
  res = -3.141592 + 7;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-3.141592+7.182818284=";
  s21_res = calculate(test_string, &err, x);
  res = -3.141592 + 7.182818284;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "40000+10=";
  s21_res = calculate(test_string, &err, x);
  res = 40000 + 10;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-40000+10=";
  s21_res = calculate(test_string, &err, x);
  res = -40000 + 10;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-3.141592+7182818284=";
  s21_res = calculate(test_string, &err, x);
  res = -3.141592 + 7182818284;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "3141592+0.07182818284=";
  s21_res = calculate(test_string, &err, x);
  res = 3141592 + 0.07182818284;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "(3141592+1.82818284)=";
  s21_res = calculate(test_string, &err, x);
  res = (3141592 + 1.82818284);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "(3141592+(-1.82818284))=";
  s21_res = calculate(test_string, &err, x);
  res = (3141592 + (-1.82818284));
  // printf("%.3f %.3f\n", res, s21_res);
  ck_assert_double_eq_tol(res, s21_res, 1);
  ck_assert_int_eq(err, 0);

  test_string = "(314.1592+(-271.8))=";
  // printf("String %s\n", test_string);
  s21_res = calculate(test_string, &err, x);
  res = (+314.1592) + (-271.8);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(minus_binar_test) {
  double s21_res = 0, res = 0;
  int err = 0;
  char* test_string = "1-2=";
  double x = 0;
  s21_res = calculate(test_string, &err, x);
  res = 1 - 2;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "1.234567-2=";
  s21_res = calculate(test_string, &err, x);
  res = 1.234567 - 2;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "1.234567-2.987654=";
  s21_res = calculate(test_string, &err, x);
  res = 1.234567 - 2.987654;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-3-7=";
  s21_res = calculate(test_string, &err, x);
  res = -3 - 7;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-3.141592-7=";
  s21_res = calculate(test_string, &err, x);
  res = -3.141592 - 7;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-3.141592-7.182818284=";
  s21_res = calculate(test_string, &err, x);
  res = -3.141592 - 7.182818284;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "40000-10=";
  s21_res = calculate(test_string, &err, x);
  res = 40000 - 10;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-40000-10=";
  s21_res = calculate(test_string, &err, x);
  res = -40000 - 10;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-3.141592-7182818284=";
  s21_res = calculate(test_string, &err, x);
  res = -3.141592 - 7182818284;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "3141592-0.07182818284=";
  s21_res = calculate(test_string, &err, x);
  res = 3141592 - 0.07182818284;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "(3141592-1.82818284)=";
  s21_res = calculate(test_string, &err, x);
  res = (3141592 - 1.82818284);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "(3141592-(-1.82818284))=";
  s21_res = calculate(test_string, &err, x);
  res = (3141592 - (-1.82818284));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "((+314.1592)-(-2718))=";
  s21_res = calculate(test_string, &err, x);
  res = ((+314.1592) - (-2718));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(plus_minus_multiple_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "1+2+3+4+5+6=";
  s21_res = calculate(test_string, &err, x);
  res = 1 + 2 + 3 + 4 + 5 + 6;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "1-2+3-4+5-6=";
  s21_res = calculate(test_string, &err, x);
  res = 1 - 2 + 3 - 4 + 5 - 6;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-1+2-3+4-5+6=";
  s21_res = calculate(test_string, &err, x);
  res = -1 + 2 - 3 + 4 - 5 + 6;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+1+(-2)+3+(-4)+5+(+6)=";
  s21_res = calculate(test_string, &err, x);
  res = +1 + (-2) + 3 + (-4) + 5 + (+6);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(multiplication_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "3*2=";
  s21_res = calculate(test_string, &err, x);
  res = 3 * 2;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "3.1415*2.76=";
  s21_res = calculate(test_string, &err, x);
  res = 3.1415 * 2.76;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "3.1415*2716.12=";
  s21_res = calculate(test_string, &err, x);
  res = 3.1415 * 2716.12;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-3.1415*2716.12=";
  s21_res = calculate(test_string, &err, x);
  res = -3.1415 * 2716.12;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "3.1415*(-2.71612)=";
  s21_res = calculate(test_string, &err, x);
  res = 3.1415 * (-2.71612);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-3.1415*(-2.71612)=";
  s21_res = calculate(test_string, &err, x);
  res = -3.1415 * (-2.71612);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+3.1415*(-2.71612)=";
  s21_res = calculate(test_string, &err, x);
  res = +3.1415 * (-2.71612);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+31415*(+2.71612)=";
  s21_res = calculate(test_string, &err, x);
  res = +31415 * (+2.71612);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(division_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "300/4=";
  s21_res = calculate(test_string, &err, x);
  res = 300. / 4;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "1/8=";
  s21_res = calculate(test_string, &err, x);
  res = 1. / 8;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "0.063/21=";
  s21_res = calculate(test_string, &err, x);
  res = 0.063 / 21;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "0.04/1=";
  s21_res = calculate(test_string, &err, x);
  res = 0.04 / 1;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-15/2=";
  s21_res = calculate(test_string, &err, x);
  res = -15. / 2;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-28/(-4)=";
  s21_res = calculate(test_string, &err, x);
  res = -28. / (-4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "92.123/(+5)=";
  s21_res = calculate(test_string, &err, x);
  res = 92.123 / (+5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
  test_string = "+92.123/(+5)=";
  s21_res = calculate(test_string, &err, x);
  res = +92.123 / (+5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(mod_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "300%4=";
  s21_res = calculate(test_string, &err, x);
  res = fmodl(300., 4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "100%8=";
  s21_res = calculate(test_string, &err, x);
  res = fmodl(100., 8);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "0.063%21=";
  s21_res = calculate(test_string, &err, x);
  res = fmodl(0.063, 21);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "0.04%1=";
  s21_res = calculate(test_string, &err, x);
  res = fmodl(0.04, 1);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-15%2=";
  s21_res = calculate(test_string, &err, x);
  res = fmodl(-15., 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-28%(-4)=";
  s21_res = calculate(test_string, &err, x);
  res = fmodl(-28., (-4));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "92.123%(+5)=";
  s21_res = calculate(test_string, &err, x);
  res = fmodl(92.123, (+5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+92.123%(+5)=";
  s21_res = calculate(test_string, &err, x);
  res = fmodl(+92.123, (+5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(mul_div_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "12/34*18/0.021=";
  s21_res = calculate(test_string, &err, x);
  res = 12. / 34 * 18. / 0.021;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "2*(2/2)=";
  s21_res = calculate(test_string, &err, x);
  res = 2. * (2. / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "14.23/2.11/(11.3129*(-12))=";
  s21_res = calculate(test_string, &err, x);
  res = 14.23 / 2.11 / (11.3129 * (-12));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-14.23/2.11/(11.3129*(-12))=";
  s21_res = calculate(test_string, &err, x);
  res = -14.23 / 2.11 / (11.3129 * (-12));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "2.2/(2.2/(2.2/(-2.2/1)))=";
  s21_res = calculate(test_string, &err, x);
  res = 2.2 / (2.2 / (2.2 / (-2.2 / 1)));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-12*(+1)/(-4)=";
  s21_res = calculate(test_string, &err, x);
  res = -12 * (+1) / (-4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(mul_div_add_sub_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "1.12+2.25*8-14=";
  s21_res = calculate(test_string, &err, x);
  res = 1.12 + 2.25 * 8 - 14;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "2+2*2=";
  s21_res = calculate(test_string, &err, x);
  res = 2 + 2 * 2;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+2+(-4)*(120-94.23/18*(11+4))=";
  s21_res = calculate(test_string, &err, x);
  res = +2 + (-4) * (120 - 94.23 / 18 * (11 + 4));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "2000-4*(1000+(-3000))=";
  s21_res = calculate(test_string, &err, x);
  res = 2000 - 4 * (1000 + (-3000));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+3.122346-2.1134/6.231=";
  s21_res = calculate(test_string, &err, x);
  res = +3.122346 - 2.1134 / 6.231;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-28-23*(-4)=";
  s21_res = calculate(test_string, &err, x);
  res = -28 - 23 * (-4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "88/2+1=";
  s21_res = calculate(test_string, &err, x);
  res = 88 / 2 + 1;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(sin_simple_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "sin(2)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(0)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(0);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-sin(pi/2)=";
  s21_res = calculate(test_string, &err, x);
  res = -sin(M_PI / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+sin(pi/2)=";
  s21_res = calculate(test_string, &err, x);
  res = +sin(M_PI / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-sin(-pi/2)=";
  s21_res = calculate(test_string, &err, x);
  res = -sin(-M_PI / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(-1/3*pi)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(-1. / 3 * M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/4)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / 4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(sin_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "sin((3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = sin((3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/8+pi/3-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / 8 + M_PI / 3 - M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/8)+sin(pi/3)-sin(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / 8) + sin(M_PI / 3) - sin(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/8)*sin(pi/3)*sin(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / 8) * sin(M_PI / 3) * sin(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/8)+sin(pi/3)*(-sin(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / 8) + sin(M_PI / 3) * (-sin(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/8)+sin(pi/3)*(-sin(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / 8) + sin(M_PI / 3) * (-sin(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(-(3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(-(3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+sin(-pi/8+pi/3-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = +sin(-M_PI / 8 + M_PI / 3 - M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(-pi/8)+sin(+pi/3)-sin(pi/(-5))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(-M_PI / 8) + sin(+M_PI / 3) - sin(M_PI / (-5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(+pi/8)*sin(pi/(-3))*sin(-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(+M_PI / 8) * sin(M_PI / (-3)) * sin(-M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/(-8))+sin(+pi/3)*(-sin(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / (-8)) + sin(+M_PI / 3) * (-sin(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(-pi/(+8))+sin(+pi/(-3))*(-sin(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(-M_PI / (+8)) + sin(+M_PI / (-3)) * (-sin(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(cos_simple_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "cos(2)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(0)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(0);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/2)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-cos(pi/2)=";
  s21_res = calculate(test_string, &err, x);
  res = -cos(M_PI / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+cos(pi/2)=";
  s21_res = calculate(test_string, &err, x);
  res = +cos(M_PI / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-cos(-pi/2)=";
  s21_res = calculate(test_string, &err, x);
  res = -cos(-M_PI / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(-1/3*pi)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(-1. / 3 * M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/4)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(cos_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "cos((3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = cos((3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/8+pi/3-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 8 + M_PI / 3 - M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/8)+cos(pi/3)-cos(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 8) + cos(M_PI / 3) - cos(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/8)*cos(pi/3)*cos(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 8) * cos(M_PI / 3) * cos(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/8)+cos(pi/3)*(-cos(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 8) + cos(M_PI / 3) * (-cos(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/8)+cos(pi/3)*(-cos(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 8) + cos(M_PI / 3) * (-cos(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(-(3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(-(3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+cos(-pi/8+pi/3-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = +cos(-M_PI / 8 + M_PI / 3 - M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(-pi/8)+cos(+pi/3)-cos(pi/(-5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(-M_PI / 8) + cos(+M_PI / 3) - cos(M_PI / (-5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(+pi/8)*cos(pi/(-3))*cos(-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(+M_PI / 8) * cos(M_PI / (-3)) * cos(-M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/(-8))+cos(+pi/3)*(-cos(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / (-8)) + cos(+M_PI / 3) * (-cos(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(-pi/(+8))+cos(+pi/(-3))*(-cos(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(-M_PI / (+8)) + cos(+M_PI / (-3)) * (-cos(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(tan_simple_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "tan(2)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(0)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(0);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-tan(pi/2)=";
  s21_res = calculate(test_string, &err, x);
  res = -tan(M_PI / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+tan(pi/2)=";
  s21_res = calculate(test_string, &err, x);
  res = +tan(M_PI / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-tan(-pi/2)=";
  s21_res = calculate(test_string, &err, x);
  res = -tan(-M_PI / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(-1/3*pi)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(-1. / 3 * M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/4)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / 4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(tan_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "tan((3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = tan((3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/8+pi/3-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / 8 + M_PI / 3 - M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/8)+tan(pi/3)-tan(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / 8) + tan(M_PI / 3) - tan(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/8)*tan(pi/3)*tan(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / 8) * tan(M_PI / 3) * tan(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/8)+tan(pi/3)*(-tan(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / 8) + tan(M_PI / 3) * (-tan(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/8)+tan(pi/3)*(-tan(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / 8) + tan(M_PI / 3) * (-tan(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(-(3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(-(3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+tan(-pi/8+pi/3-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = +tan(-M_PI / 8 + M_PI / 3 - M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(-pi/8)+tan(+pi/3)-tan(pi/(-5))=";
  s21_res = calculate(test_string, &err, x);
  res = tan(-M_PI / 8) + tan(+M_PI / 3) - tan(M_PI / (-5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(+pi/8)*tan(pi/(-3))*tan(-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(+M_PI / 8) * tan(M_PI / (-3)) * tan(-M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/(-8))+tan(+pi/3)*(-tan(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / (-8)) + tan(+M_PI / 3) * (-tan(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(-pi/(+8))+tan(+pi/(-3))*(-tan(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = tan(-M_PI / (+8)) + tan(+M_PI / (-3)) * (-tan(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(sin_cos_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "sin((3+4*8)/16)+2*cos((3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = sin((3. + 4 * 8) / 16) + 2 * cos((3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/8)+cos(pi/3)-sin(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / 8) + cos(M_PI / 3) - sin(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/8)*cos(pi/3)*sin(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 8) * cos(M_PI / 3) * sin(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/8)+sin(pi/3)*(-sin(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 8) + sin(M_PI / 3) * (-sin(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/8)+cos(pi/3)*(-sin(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / 8) + cos(M_PI / 3) * (-sin(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(-(3+4*8)/16)-2*sin(-(3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(-(3. + 4 * 8) / 16) - 2 * sin(-(3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "+sin(-pi/8+pi/3-pi/5)+cos(pi/8-pi/3-pi/5)-cos(-pi/8+pi/3-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = +sin(-M_PI / 8 + M_PI / 3 - M_PI / 5) +
        cos(M_PI / 8 - M_PI / 3 - M_PI / 5) -
        cos(-M_PI / 8 + M_PI / 3 - M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(-pi/8)+sin(+pi/3)-cos(pi/(-5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(-M_PI / 8) + sin(+M_PI / 3) - cos(M_PI / (-5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(+pi/8)*cos(pi/(-3))*sin(-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(+M_PI / 8) * cos(M_PI / (-3)) * sin(-M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/(-8))+sin(+pi/3)*(-cos(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / (-8)) + sin(+M_PI / 3) * (-cos(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(-pi/(+8))+sin(+pi/(-3))*(-sin(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(-M_PI / (+8)) + sin(+M_PI / (-3)) * (-sin(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(sin_tan_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "sin((3+4*8)/16)+2*tan((3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = sin((3. + 4 * 8) / 16) + 2 * tan((3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/8)+tan(pi/3)-sin(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / 8) + tan(M_PI / 3) - sin(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/8)*tan(pi/3)*sin(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / 8) * tan(M_PI / 3) * sin(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/8)+sin(pi/3)*(-sin(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / 8) + sin(M_PI / 3) * (-sin(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/8)+tan(pi/3)*(-sin(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / 8) + tan(M_PI / 3) * (-sin(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(-(3+4*8)/16)-2*sin(-(3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(-(3. + 4 * 8) / 16) - 2 * sin(-(3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "+sin(-pi/8+pi/3-pi/5)+tan(pi/8-pi/3-pi/5)-tan(-pi/8+pi/3-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = +sin(-M_PI / 8 + M_PI / 3 - M_PI / 5) +
        tan(M_PI / 8 - M_PI / 3 - M_PI / 5) -
        tan(-M_PI / 8 + M_PI / 3 - M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(-pi/8)+sin(+pi/3)-tan(pi/(-5))=";
  s21_res = calculate(test_string, &err, x);
  res = tan(-M_PI / 8) + sin(+M_PI / 3) - tan(M_PI / (-5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(+pi/8)*tan(pi/(-3))*sin(-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(+M_PI / 8) * tan(M_PI / (-3)) * sin(-M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/(-8))+sin(+pi/3)*(-tan(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / (-8)) + sin(+M_PI / 3) * (-tan(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(-pi/(+8))+sin(+pi/(-3))*(-sin(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = tan(-M_PI / (+8)) + sin(+M_PI / (-3)) * (-sin(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(cos_tan_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "tan((3+4*8)/16)+2*cos((3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = tan((3. + 4 * 8) / 16) + 2 * cos((3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/8)+cos(pi/3)-tan(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / 8) + cos(M_PI / 3) - tan(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/8)*cos(pi/3)*tan(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 8) * cos(M_PI / 3) * tan(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/8)+tan(pi/3)*(-tan(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 8) + tan(M_PI / 3) * (-tan(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/8)+cos(pi/3)*(-tan(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / 8) + cos(M_PI / 3) * (-tan(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(-(3+4*8)/16)-2*tan(-(3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(-(3. + 4 * 8) / 16) - 2 * tan(-(3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "+tan(-pi/8+pi/3-pi/5)+cos(pi/8-pi/3-pi/5)-cos(-pi/8+pi/3-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = +tan(-M_PI / 8 + M_PI / 3 - M_PI / 5) +
        cos(M_PI / 8 - M_PI / 3 - M_PI / 5) -
        cos(-M_PI / 8 + M_PI / 3 - M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(-pi/8)+tan(+pi/3)-cos(pi/(-5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(-M_PI / 8) + tan(+M_PI / 3) - cos(M_PI / (-5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(+pi/8)*cos(pi/(-3))*tan(-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(+M_PI / 8) * cos(M_PI / (-3)) * tan(-M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/(-8))+tan(+pi/3)*(-cos(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / (-8)) + tan(+M_PI / 3) * (-cos(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(-pi/(+8))+tan(+pi/(-3))*(-tan(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(-M_PI / (+8)) + tan(+M_PI / (-3)) * (-tan(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(sin_cos_tan_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "-4*sin((3+4*8)/16)+tan((3+4*8)/16)+2*cos((3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = -4 * sin((3. + 4 * 8) / 16) + tan((3. + 4 * 8) / 16) +
        2 * cos((3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/8)+cos(pi/3)-tan(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / 8) + cos(M_PI / 3) - tan(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/8)*sin(pi/3)*tan(pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 8) * sin(M_PI / 3) * tan(M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(pi/8)+tan(pi/3)*(-sin(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(M_PI / 8) + tan(M_PI / 3) * (-sin(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi/8)+cos(pi/3)*(-tan(pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI / 8) + cos(M_PI / 3) * (-tan(M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "3*sin(-(3+4*8)/16)-cos(-(3+4*8)/16)-2*tan(-(3+4*8)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = 3 * sin(-(3. + 4 * 8) / 16) - cos(-(3. + 4 * 8) / 16) -
        2 * tan(-(3. + 4 * 8) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "+tan(-pi/8+pi/3-pi/5)+cos(pi/8-pi/3-pi/5)-sin(-pi/8+pi/3-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = +tan(-M_PI / 8 + M_PI / 3 - M_PI / 5) +
        cos(M_PI / 8 - M_PI / 3 - M_PI / 5) -
        sin(-M_PI / 8 + M_PI / 3 - M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(-pi/8)+tan(+pi/3)-sin(pi/(-5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(-M_PI / 8) + tan(+M_PI / 3) - sin(M_PI / (-5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(+pi/8)*sin(pi/(-3))*tan(-pi/5)=";
  s21_res = calculate(test_string, &err, x);
  res = cos(+M_PI / 8) * sin(M_PI / (-3)) * tan(-M_PI / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "tan(pi/(-8))+sin(+pi/3)*(-cos(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = tan(M_PI / (-8)) + sin(+M_PI / 3) * (-cos(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(-pi/(+8))+tan(+pi/(-3))*(-sin(-pi/5))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(-M_PI / (+8)) + tan(+M_PI / (-3)) * (-sin(-M_PI / 5));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(trigonometry_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "sin((3+4*8)/16)^2+cos((3+4*8)/16)^2=";
  s21_res = calculate(test_string, &err, x);
  res = pow(sin((3. + 4 * 8) / 16), 2) + pow(cos((3. + 4 * 8) / 16), 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "(tan(pi/8)+tan(pi/3))/(1-tan(pi/8)*tan(pi/3))=";
  s21_res = calculate(test_string, &err, x);
  res = (tan(M_PI / 8) + tan(M_PI / 3)) / (1 - tan(M_PI / 8) * tan(M_PI / 3));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "4*cos(pi/8)^3-3*cos(pi/8)=";
  s21_res = calculate(test_string, &err, x);
  res = 4 * pow(cos(M_PI / 8), 3) - 3 * cos(M_PI / 8);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "3*sin(pi/7)^3-4*sin(pi/7)=";
  s21_res = calculate(test_string, &err, x);
  res = 3 * pow(sin(M_PI / 7), 3) - 4 * sin(M_PI / 7);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(asin_simple_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "asin(0)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(0);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "asin(-1)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(-1);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "asin(1)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(1);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "asin(1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "asin(-1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(-1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-asin(-1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = -asin(-1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-asin(+1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = -asin(+1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(asin_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "asin(1*(28-20)/56)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(1. * (28 - 20) / 56);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "asin(14*(12-10*(11+4)/20)/(-85))=";
  s21_res = calculate(test_string, &err, x);
  res = asin(14. * (12 - 10. * (11 + 4) / 20) / (-85));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "asin(1/3)-asin(0.5)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(1. / 3) - asin(0.5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "asin(1/3)+asin(-1/5)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(1. / 3) + asin(-1. / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "asin(-1/3)+asin(+1/4)-asin(1/5)-asin(-1/6)*asin(1/7)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(-1. / 3) + asin(+1. / 4) - asin(1. / 5) -
        asin(-1. / 6) * asin(1. / 7);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "-asin(-1/3)*asin(1/4)*asin(1/5)*asin(1/6)*asin(1/7)*asin(1/8)=";
  s21_res = calculate(test_string, &err, x);
  res = -asin(-1. / 3) * asin(1. / 4) * asin(1. / 5) * asin(1. / 6) *
        asin(1. / 7) * asin(1. / 8);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(acos_simple_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "acos(0)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(0);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(-1)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(-1);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(1)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(1);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(-1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(-1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-acos(-1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = -acos(-1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-acos(+1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = -acos(+1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(acos_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "acos(1*(28-20)/56)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(1. * (28 - 20) / 56);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(14*(12-10*(11+4)/20)/(-85))=";
  s21_res = calculate(test_string, &err, x);
  res = acos(14. * (12 - 10. * (11 + 4) / 20) / (-85));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(1/3)-acos(0.5)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(1. / 3) - acos(0.5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(1/3)+acos(-1/5)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(1. / 3) + acos(-1. / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(-1/3)+acos(+1/4)-acos(1/5)-acos(-1/6)*acos(1/7)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(-1. / 3) + acos(+1. / 4) - acos(1. / 5) -
        acos(-1. / 6) * acos(1. / 7);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "-acos(-1/3)*acos(1/4)*acos(1/5)*acos(1/6)*acos(1/7)*acos(1/8)=";
  s21_res = calculate(test_string, &err, x);
  res = -acos(-1. / 3) * acos(1. / 4) * acos(1. / 5) * acos(1. / 6) *
        acos(1. / 7) * acos(1. / 8);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(atan_simple_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "atan(0)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(0);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(-1)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(-1);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(1)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(1);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(-1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(-1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-atan(-1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = -atan(-1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-atan(+1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = -atan(+1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-atan(100)=";
  s21_res = calculate(test_string, &err, x);
  res = -atan(100);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-atan(+10/28-94*22)=";
  s21_res = calculate(test_string, &err, x);
  res = -atan(+10. / 28 - 94 * 22);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(atan_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "atan(1*(28-20)/56)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(1. * (28 - 20) / 56);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(14*(12-10*(11+4)/20)/(-30))=";
  s21_res = calculate(test_string, &err, x);
  res = atan(14. * (12 - 10. * (11 + 4) / 20) / (-30));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(1/3)-atan(0.5)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(1. / 3) - atan(0.5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(1/3)+atan(-1/5)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(1. / 3) + atan(-1. / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(-1/3)+atan(+1/4)-atan(1/5)-atan(-1/6)*atan(1/7)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(-1. / 3) + atan(+1. / 4) - atan(1. / 5) -
        atan(-1. / 6) * atan(1. / 7);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "-atan(-1/3)*atan(1/4)*atan(1/5)*atan(1/6)*atan(1/7)*atan(1/8)=";
  s21_res = calculate(test_string, &err, x);
  res = -atan(-1. / 3) * atan(1. / 4) * atan(1. / 5) * atan(1. / 6) *
        atan(1. / 7) * atan(1. / 8);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(asin_acos_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "asin(1*(28-20)/56)-acos(-1*(28-20)/56)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(1. * (28 - 20) / 56) - acos(-1. * (28 - 20) / 56);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "asin(14*(12-10*(11+4)/20)/(-85))*acos(14*(12-5.5*(9-4)/20)/(-180))=";
  s21_res = calculate(test_string, &err, x);
  res = asin(14. * (12 - 10. * (11 + 4) / 20) / (-85)) *
        acos(14. * (12 - 5.5 * (9 - 4) / 20) / (-180));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "asin(1/3)-acos(0.5)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(1. / 3) - acos(0.5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(1/3)+asin(-1/5)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(1. / 3) + asin(-1. / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(-1/3)+acos(+1/4)-asin(1/5)-acos(-1/6)*asin(1/7)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(-1. / 3) + acos(+1. / 4) - asin(1. / 5) -
        acos(-1. / 6) * asin(1. / 7);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "-acos(-1/3)*acos(1/4)*acos(1/5)*asin(1/6)*asin(1/7)*asin(1/8)=";
  s21_res = calculate(test_string, &err, x);
  res = -acos(-1. / 3) * acos(1. / 4) * acos(1. / 5) * asin(1. / 6) *
        asin(1. / 7) * asin(1. / 8);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(asin_atan_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "asin(1*(28-20)/56)-atan(-1*(28-20)/56)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(1. * (28 - 20) / 56) - atan(-1. * (28 - 20) / 56);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "asin(14*(12-10*(11+4)/20)/(-85))*atan(14*(12-5*(7-4)/20)/(-120))=";
  s21_res = calculate(test_string, &err, x);
  res = asin(14. * (12 - 10. * (11 + 4) / 20) / (-85)) *
        atan(14. * (12 - 5. * (7 - 4) / 20) / (-120));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "asin(1/3)-atan(0.5)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(1. / 3) - atan(0.5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(1/3)+asin(-1/5)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(1. / 3) + asin(-1. / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(-1/3)+atan(+1/4)-asin(1/5)-atan(-1/6)*asin(1/7)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(-1. / 3) + atan(+1. / 4) - asin(1. / 5) -
        atan(-1. / 6) * asin(1. / 7);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "-atan(-1/3)*atan(1/4)*atan(1/5)*asin(1/6)*asin(1/7)*asin(1/8)=";
  s21_res = calculate(test_string, &err, x);
  res = -atan(-1. / 3) * atan(1. / 4) * atan(1. / 5) * asin(1. / 6) *
        asin(1. / 7) * asin(1. / 8);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(acos_atan_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "atan(1*(28-20)/56)-acos(-1*(28-20)/56)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(1. * (28 - 20) / 56) - acos(-1. * (28 - 20) / 56);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "atan(14*(12-10*(11+4)/20)/(-85))*acos(14*(12-5*(7-4)/20)/(-180))=";
  s21_res = calculate(test_string, &err, x);
  res = atan(14. * (12 - 10. * (11 + 4) / 20) / (-85)) *
        acos(14. * (12 - 5. * (7 - 4) / 20) / (-180));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(1/3)-acos(0.5)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(1. / 3) - acos(0.5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(1/3)+atan(-1/5)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(1. / 3) + atan(-1. / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(-1/3)+acos(+1/4)-atan(1/5)-acos(-1/6)*atan(1/7)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(-1. / 3) + acos(+1. / 4) - atan(1. / 5) -
        acos(-1. / 6) * atan(1. / 7);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "-acos(-1/3)*acos(1/4)*acos(1/5)*atan(1/6)*atan(1/7)*atan(1/8)=";
  s21_res = calculate(test_string, &err, x);
  res = -acos(-1. / 3) * acos(1. / 4) * acos(1. / 5) * atan(1. / 6) *
        atan(1. / 7) * atan(1. / 8);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(reverse_trigonometry_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "sin(asin(-0.9))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(asin(-0.9));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(asin(0))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(asin(0));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(asin(1))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(asin(1));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(asin(-1))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(asin(-1));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "cos(asin(0.9))=";
  s21_res = calculate(test_string, &err, x);
  res = cos(asin(0.9));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-tan(asin(-0.4))=";
  s21_res = calculate(test_string, &err, x);
  res = -tan(asin(-0.4));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-tan(asin(-0))=";
  s21_res = calculate(test_string, &err, x);
  res = -tan(asin(-0));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-sin(acos(-0.4))=";
  s21_res = calculate(test_string, &err, x);
  res = -sin(acos(-0.4));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-sin(acos(0.001))=";
  s21_res = calculate(test_string, &err, x);
  res = -sin(acos(0.001));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(asin_acos_atan_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string =
      "(atan(1*(28-20)/56)-acos(-1*(28-20)/56))*asin(3.4*(28-20)/180.25)=";
  s21_res = calculate(test_string, &err, x);
  res = (atan(1. * (28 - 20) / 56) - acos(-1. * (28 - 20) / 56)) *
        asin(3.4 * (28 - 20) / 180.25);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "atan(14*(12-10*(11+4)/20)/(-85))*acos(14*(12-5*(7-4)/20)/"
      "(-220))*asin(1.4*(1.22-0.005*(7.1-4.007)/20)/(-220))=";
  s21_res = calculate(test_string, &err, x);
  res = atan(14. * (12 - 10. * (11 + 4) / 20) / (-85)) *
        acos(14. * (12 - 5. * (7 - 4) / 20) / (-220)) *
        asin(1.4 * (1.22 - 0.005 * (7.1 - 4.007) / 20) / (-220));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(1/3)-acos(0.5)+asin(3/4)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(1. / 3) - acos(0.5) + asin(3. / 4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(1/3)+atan(-1/5)-asin(7/8)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(1. / 3) + atan(-1. / 5) - asin(7. / 8);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "acos(-1/3)+asin(+1/4)-atan(1/5)-acos(-1/6)*asin(1/7)=";
  s21_res = calculate(test_string, &err, x);
  res = acos(-1. / 3) + asin(+1. / 4) - atan(1. / 5) -
        acos(-1. / 6) * asin(1. / 7);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string =
      "-asin(-1/3)*acos(1/4)*atan(1/5)*asin(1/6)*atan(1/7)*acos(1/8)=";
  s21_res = calculate(test_string, &err, x);
  res = -asin(-1. / 3) * acos(1. / 4) * atan(1. / 5) * asin(1. / 6) *
        atan(1. / 7) * acos(1. / 8);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(sqrt_simple_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "sqrt(0)=";
  s21_res = calculate(test_string, &err, x);
  res = sqrt(0);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sqrt(0.00001)=";
  s21_res = calculate(test_string, &err, x);
  res = sqrt(0.00001);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sqrt(100)=";
  s21_res = calculate(test_string, &err, x);
  res = sqrt(100);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sqrt(1000000.99)=";
  s21_res = calculate(test_string, &err, x);
  res = sqrt(1000000.99);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-sqrt(10000009.4)=";
  s21_res = calculate(test_string, &err, x);
  res = -sqrt(10000009.4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+sqrt(100000000.99)=";
  s21_res = calculate(test_string, &err, x);
  res = +sqrt(100000000.99);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+sqrt(pi)=";
  s21_res = calculate(test_string, &err, x);
  res = +sqrt(M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(sqrt_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "sqrt(4*pi+3*0.1)=";
  s21_res = calculate(test_string, &err, x);
  res = sqrt(4 * M_PI + 3 * 0.1);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-sqrt(-0.00001*pi+12.12)=";
  s21_res = calculate(test_string, &err, x);
  res = -sqrt(-0.00001 * M_PI + 12.12);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sqrt(pi*10/2-14/5)=";
  s21_res = calculate(test_string, &err, x);
  res = sqrt(M_PI * 10 / 2 - 14. / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-sqrt(pi*10/2-14/5)=";
  s21_res = calculate(test_string, &err, x);
  res = -sqrt(M_PI * 10 / 2 - 14. / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-sqrt(0*pi)=";
  s21_res = calculate(test_string, &err, x);
  res = -sqrt(0 * M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+sqrt(1.3+4.44*(12+0.001*(1.1-0.1)))=";
  s21_res = calculate(test_string, &err, x);
  res = +sqrt(1.3 + 4.44 * (12 + 0.001 * (1.1 - 0.1)));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(log_simple_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "log(pi)=";
  s21_res = calculate(test_string, &err, x);
  res = log(M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "log(0.00001)=";
  s21_res = calculate(test_string, &err, x);
  res = log(0.00001);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "log(100)=";
  s21_res = calculate(test_string, &err, x);
  res = log(100);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "log(1000000.99)=";
  s21_res = calculate(test_string, &err, x);
  res = log(1000000.99);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-log(10000009.4)=";
  s21_res = calculate(test_string, &err, x);
  res = -log(10000009.4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+log(100000000.99)=";
  s21_res = calculate(test_string, &err, x);
  res = +log(100000000.99);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "log(exp(1))=";
  s21_res = calculate(test_string, &err, x);
  res = +log(exp(1));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
  /**/
  test_string = "-log(10)=";
  s21_res = calculate(test_string, &err, x);
  res = -log(10);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(log_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "log(4*pi+3*0.1)=";
  s21_res = calculate(test_string, &err, x);
  res = log(4 * M_PI + 3 * 0.1);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-log(-0.00001*pi+12.12)=";
  s21_res = calculate(test_string, &err, x);
  res = -log(-0.00001 * M_PI + 12.12);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "log(pi*10/2-14/5)=";
  s21_res = calculate(test_string, &err, x);
  res = log(M_PI * 10 / 2 - 14. / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-log(pi*10/2-14/5)=";
  s21_res = calculate(test_string, &err, x);
  res = -log(M_PI * 10 / 2 - 14. / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-log(exp(1)*pi)=";
  s21_res = calculate(test_string, &err, x);
  res = -log(exp(1) * M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+log(1.3+4.44*(12+0.001*(1.1-0.1)))=";
  s21_res = calculate(test_string, &err, x);
  res = +log(1.3 + 4.44 * (12 + 0.001 * (1.1 - 0.1)));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(log10_simple_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "log10(pi)=";
  s21_res = calculate(test_string, &err, x);
  res = log10(M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "log10(0.00001)=";
  s21_res = calculate(test_string, &err, x);
  res = log10(0.00001);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "log10(100)=";
  s21_res = calculate(test_string, &err, x);
  res = log10(100);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "log10(1000000.99)=";
  s21_res = calculate(test_string, &err, x);
  res = log10(1000000.99);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-log10(10000009.4)=";
  s21_res = calculate(test_string, &err, x);
  res = -log10(10000009.4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+log10(100000000.99)=";
  s21_res = calculate(test_string, &err, x);
  res = +log10(100000000.99);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+log10(exp(1))=";
  s21_res = calculate(test_string, &err, x);
  res = +log10(exp(1));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-log10(10)=";
  s21_res = calculate(test_string, &err, x);
  res = -log10(10);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(log10_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "log10(4*pi+3*0.1)=";
  s21_res = calculate(test_string, &err, x);
  res = log10(4 * M_PI + 3 * 0.1);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-log10(-0.00001*pi+12.12)=";
  s21_res = calculate(test_string, &err, x);
  res = -log10(-0.00001 * M_PI + 12.12);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "log10(pi*10/2-14/5)=";
  s21_res = calculate(test_string, &err, x);
  res = log10(M_PI * 10 / 2 - 14. / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-log10(pi*10/2-14/5)=";
  s21_res = calculate(test_string, &err, x);
  res = -log10(M_PI * 10 / 2 - 14. / 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-log10(exp(1)*pi)=";
  s21_res = calculate(test_string, &err, x);
  res = -log10(exp(1) * M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-log10(10*exp(1)*pi)=";
  s21_res = calculate(test_string, &err, x);
  res = -log10(10 * exp(1) * M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+log10(1.3+4.44*(12+0.001*(1.1-0.1)))=";
  s21_res = calculate(test_string, &err, x);
  res = +log10(1.3 + 4.44 * (12 + 0.001 * (1.1 - 0.1)));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(pow_simple_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "2^2=";
  s21_res = calculate(test_string, &err, x);
  res = powl(2, 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "2.2^(1/2)=";
  s21_res = calculate(test_string, &err, x);
  res = powl(2.2, 1. / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "+100.28^(-5)=";
  s21_res = calculate(test_string, &err, x);
  res = +powl(100.28, -5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "22^0=";
  s21_res = calculate(test_string, &err, x);
  res = powl(22., 0);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "19.4443^1=";
  s21_res = calculate(test_string, &err, x);
  res = powl(19.4443, 1);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "exp(1)^pi=";
  s21_res = calculate(test_string, &err, x);
  res = powl(exp(1), M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "(-3)^2=";
  s21_res = calculate(test_string, &err, x);
  res = powl(-3., 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(pow_complex_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "(2*pi-3^4)^2=";
  s21_res = calculate(test_string, &err, x);
  res = powl(2 * M_PI - powl(3, 4), 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "2.2^(1/2+1/3-1/6)=";
  s21_res = calculate(test_string, &err, x);
  res = powl(2.2, 1. / 2 + 1. / 3 - 1. / 6);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "(+100.28-13.2341)^(-5+4-1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = powl(+100.28 - 13.2341, -5 + 4 - 1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-(22^(-0*pi))=";
  s21_res = calculate(test_string, &err, x);
  res = -powl(22., -0 * M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "(-19.4443/22+12.22^(0.5))^(1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = powl(-19.4443 / 22 + powl(12.22, 0.5), 1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
  /*
  test_string = "-exp(-1*0.4)^(pi-3)=";
  s21_res = calculate(test_string, &err, x);
  res = -powl(exp(-1*0.4), M_PI-3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
  */
  test_string = "(((-3)^2)^2)^2=";
  s21_res = calculate(test_string, &err, x);
  res = powl(powl(powl(-3., 2), 2), 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(pi_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "(2*pi+pi^4)^pi=";
  s21_res = calculate(test_string, &err, x);
  res = powl(2 * M_PI + powl(M_PI, 4), M_PI);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "(pi/2+pi/3+pi/6+pi/10)/pi=";
  s21_res = calculate(test_string, &err, x);
  res = (M_PI / 2 + M_PI / 3 + M_PI / 6 + M_PI / 10) / M_PI;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(pi)+cos(pi/2)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(M_PI) + cos(M_PI / 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "asin(pi/4)-acos(pi/8)*atan(pi/16)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(M_PI / 4) - acos(M_PI / 8) * atan(M_PI / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "pi/2*(-pi/3+0.1*(pi/12-1))=";
  s21_res = calculate(test_string, &err, x);
  res = M_PI / 2 * (-M_PI / 3 + 0.1 * (M_PI / 12 - 1));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
  /*
     test_string = "-exp(-pi*0.4)^(pi-3)=";
     s21_res = calculate(test_string, &err, x);
     res = -powl(exp(-M_PI*0.4), M_PI-3);
     ck_assert_double_eq_tol(res, s21_res, 1e-6);
     ck_assert_int_eq(err, 0);
    */
  test_string = "(((-pi)^2)^2)^2=";
  s21_res = calculate(test_string, &err, x);
  res = powl(powl(powl(-M_PI, 2), 2), 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(e_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "(2*exp(1)-exp(-3)^4)^exp(0.4)=";
  s21_res = calculate(test_string, &err, x);
  res = powl(2 * exp(1) - powl(exp(-3), 4), exp(0.4));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "(exp(1)/2+exp(-2)/3+exp(0.3)/6+exp(1/4)/10)/exp(-3/4)=";
  s21_res = calculate(test_string, &err, x);
  res = (exp(1) / 2 + exp(-2) / 3 + exp(0.3) / 6 + exp(1. / 4) / 10) /
        exp(-3. / 4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(exp(-4))+cos(exp(0.3)/8)=";
  s21_res = calculate(test_string, &err, x);
  res = sin(exp(-4)) + cos(exp(0.3) / 8);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "asin(exp(1/4)/4)-acos(exp(1/8)/8)*atan(exp(1/16)/16)=";
  s21_res = calculate(test_string, &err, x);
  res = asin(exp(1. / 4) / 4) - acos(exp(1. / 8) / 8) * atan(exp(1. / 16) / 16);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "exp(1)/2*(-exp(0.22)/3+0.1*(exp(-0.0021)/12-1))=";
  s21_res = calculate(test_string, &err, x);
  res = exp(1) / 2 * (-exp(0.22) / 3 + 0.1 * (exp(-0.0021) / 12 - 1));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
  /*
  test_string = "-exp(-exp(0.11)*0.4)^(exp(2)-3)=";
  s21_res = calculate(test_string, &err, x);
  res = -powl(exp(-exp(0.11)*0.4), exp(2)-3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
  */
  test_string = "(((-exp(2))^2)^2)^2=";
  s21_res = calculate(test_string, &err, x);
  res = powl(powl(powl(-exp(2), 2), 2), 2);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(all_simple_test) {
  double s21_res = 0, res = 0, x = 12.22;
  int err = 0;

  char* test_string = "(x^2+tan(x)+15)^(1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = powl(12.22 * 12.22 + tan(12.22) + 15, 1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  x = 0.4;
  test_string = "7^(asin(x)^2)=";
  s21_res = calculate(test_string, &err, x);
  res = powl(7, asin(0.4) * asin(0.4));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sqrt(9*2.2^3-12*2.2+5)=";
  s21_res = calculate(test_string, &err, x);
  res = sqrt(9 * 2.2 * 2.2 * 2.2 - 12 * 2.2 + 5);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "atan(2-11*4.4+4.4^2)=";
  s21_res = calculate(test_string, &err, x);
  res = atan(2 - 11 * 4.4 + powl(4.4, 2));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  x = 4;
  test_string = "log(4+32*x+x^2)=";
  s21_res = calculate(test_string, &err, x);
  res = log(4 + 32 * 4 + 4 * 4);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "exp(4*sin(3*pi/8)-11*1.1^7)=";
  s21_res = calculate(test_string, &err, x);
  res = exp(4 * sin(3 * M_PI / 8) - 11 * powl(1.1, 7));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "sin(sqrt(2*2*2+5*2))=";
  s21_res = calculate(test_string, &err, x);
  res = sin(sqrt(2 * 2 * 2 + 5 * 2));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(all_complex_test) {
  double s21_res = 0, res = 0, x = 12.22;
  int err = 0;

  char* test_string = "log(sin(sqrt(2*x^2+5*x+pi)))=";
  s21_res = calculate(test_string, &err, x);
  res = log(sin(sqrt(2 * 12.22 * 12.22 + 5 * 12.22 + M_PI)));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  x = 0.4;
  test_string = "(x^2+tan(x)+15)^(1/3)=";
  s21_res = calculate(test_string, &err, x);
  res = powl(0.4 * 0.4 + tan(0.4) + 15, 1. / 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "-2*1.1*exp(3*(-1.1))+(1.1^2-4*1.1+3)*sin(7*1.1)=";
  s21_res = calculate(test_string, &err, x);
  res = -2 * 1.1 * exp(3 * (-1.1)) + (1.1 * 1.1 - 4 * 1.1 + 3) * sin(7 * 1.1);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "log10((2.1^3+2)/(4.2-3.8))=";
  s21_res = calculate(test_string, &err, x);
  res = log10((powl(2.1, 3) + 2) / (4.2 - 3.8));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  x = 4;
  test_string = "log10(sin(x^3)+exp(cos(x)))=";
  s21_res = calculate(test_string, &err, x);
  res = log10(sin(powl(4, 3)) + exp(cos(4)));
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(all_edge_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "1000000.1^3=";
  s21_res = calculate(test_string, &err, x);
  res = powl(1000000.1, 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "0.01^3=";
  s21_res = calculate(test_string, &err, x);
  res = powl(0.01, 3);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "log(0.001)=";
  s21_res = calculate(test_string, &err, x);
  res = log(0.001);
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(x_simple_test) {
  double s21_res = 0, res = 0, x = 3;
  int err = 0;

  char* test_string = "2*x=";
  s21_res = calculate(test_string, &err, x);
  res = 2 * 3;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "x*3=";
  s21_res = calculate(test_string, &err, x);
  res = 3 * 3;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);

  test_string = "2*x*3=";
  s21_res = calculate(test_string, &err, x);
  res = 2 * x * 3;
  ck_assert_double_eq_tol(res, s21_res, 1e-6);
  ck_assert_int_eq(err, 0);
}
END_TEST
START_TEST(incorrect_input) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "1+*-2+3+4+5+6=";
  s21_res = calculate(test_string, &err, x);

  ck_assert_int_eq(err, 1);

  test_string = "1.-2=";
  s21_res = calculate(test_string, &err, x);

  ck_assert_int_eq(err, 1);

  test_string = "-1..23+23=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);

  test_string = "+1.23+=23=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);

  test_string = "1+2*(3+4*(5+6*7)=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);

  test_string = ")=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);

  test_string = "+=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);

  test_string = "23.32.1234.33=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);
}
END_TEST
START_TEST(incorrect_test) {
  double s21_res = 0, res = 0, x = 0;
  int err = 0;

  char* test_string = "sqrt(-4)=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);

  test_string = "log(0)=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);

  test_string = "log10(0)=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);

  test_string = "asin(-3)=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);

  test_string = "acos(-4)=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);

  test_string = "1/0=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);

  test_string = "log(-3)=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);

  test_string = "(-1)^(0.5)=";
  s21_res = calculate(test_string, &err, x);
  ck_assert_int_eq(err, 1);
}
END_TEST

int main(void) {
  Suite* s1 = suite_create("Suite");
  SRunner* sr = srunner_create(s1);

  TCase* tc_main = tcase_create("tests");
  suite_add_tcase(s1, tc_main);

  // 1
  tcase_add_test(tc_main, plus_binar_test);
  tcase_add_test(tc_main, minus_binar_test);
  tcase_add_test(tc_main, plus_minus_multiple_test);
  tcase_add_test(tc_main, multiplication_test);
  tcase_add_test(tc_main, division_test);
  // 2
  tcase_add_test(tc_main, mod_test);
  tcase_add_test(tc_main, mul_div_complex_test);
  tcase_add_test(tc_main, mul_div_add_sub_complex_test);
  tcase_add_test(tc_main, incorrect_input);
  tcase_add_test(tc_main, sin_simple_test);
  // 3
  tcase_add_test(tc_main, sin_complex_test);
  tcase_add_test(tc_main, cos_simple_test);
  tcase_add_test(tc_main, cos_complex_test);
  tcase_add_test(tc_main, tan_simple_test);
  tcase_add_test(tc_main, tan_complex_test);
  // 4
  tcase_add_test(tc_main, sin_cos_complex_test);
  tcase_add_test(tc_main, sin_tan_complex_test);
  tcase_add_test(tc_main, cos_tan_complex_test);
  tcase_add_test(tc_main, sin_cos_tan_complex_test);
  tcase_add_test(tc_main, trigonometry_test);
  // 5
  tcase_add_test(tc_main, asin_simple_test);
  tcase_add_test(tc_main, asin_complex_test);
  tcase_add_test(tc_main, acos_simple_test);
  tcase_add_test(tc_main, acos_complex_test);
  tcase_add_test(tc_main, atan_simple_test);
  // 6
  tcase_add_test(tc_main, atan_complex_test);
  tcase_add_test(tc_main, asin_acos_complex_test);
  tcase_add_test(tc_main, asin_atan_complex_test);
  tcase_add_test(tc_main, acos_atan_complex_test);
  tcase_add_test(tc_main, asin_acos_atan_complex_test);
  // 7

  tcase_add_test(tc_main, reverse_trigonometry_test);
  tcase_add_test(tc_main, sqrt_simple_test);
  tcase_add_test(tc_main, sqrt_complex_test);
  tcase_add_test(tc_main, log_simple_test);
  tcase_add_test(tc_main, log_complex_test);
  // 8
  tcase_add_test(tc_main, log10_simple_test);
  tcase_add_test(tc_main, log10_complex_test);
  tcase_add_test(tc_main, pow_simple_test);
  tcase_add_test(tc_main, pow_complex_test);
  tcase_add_test(tc_main, pi_test);
  // 9
  tcase_add_test(tc_main, e_test);
  tcase_add_test(tc_main, all_simple_test);
  tcase_add_test(tc_main, all_complex_test);
  tcase_add_test(tc_main, all_edge_test);
  tcase_add_test(tc_main, x_simple_test);
  /* Not Done
//10
 tcase_add_test(tc_main, x_complex_test);
 tcase_add_test(tc_main, x_edge_test);
*/
  tcase_add_test(tc_main, incorrect_test);

  srunner_run_all(sr, CK_ENV);
  srunner_free(sr);

  return 0;
}
