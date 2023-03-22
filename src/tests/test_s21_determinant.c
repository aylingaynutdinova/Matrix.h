#include "common.h"

START_TEST(test_s21_determinant_1) {
  matrix_t result1;
  double result2;
  s21_create_matrix(3, 3, &result1);
  result1.matrix[0][0] = 1;
  result1.matrix[0][1] = 2;
  result1.matrix[0][2] = 3;

  result1.matrix[1][0] = 4;
  result1.matrix[1][1] = 5;
  result1.matrix[1][2] = 6;

  result1.matrix[2][0] = 7;
  result1.matrix[2][1] = 8;
  result1.matrix[2][2] = 9;
  double expected_result = 0;
  s21_determinant(&result1, &result2);
  ck_assert_ldouble_eq(expected_result, result2);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  matrix_t result1;
  double result3 = 0;
  s21_create_matrix(3, 4, &result1);
  int actual_result = INCORRECT_INPUT;
  int expected_result = s21_determinant(&result1, &result3);
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  matrix_t temp;
  double result = 0;
  int result_defolt = 0;
  s21_create_matrix(3, 2, &temp);
  s21_gen_matrix(&temp);
  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 2);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_determinant_4) {
  matrix_t temp;
  double result;
  int result_defolt;
  s21_create_matrix(3, 3, &temp);
  temp.matrix[0][0] = 0;
  temp.matrix[0][1] = 9;
  temp.matrix[0][2] = 5;

  temp.matrix[1][0] = 4;
  temp.matrix[1][1] = 3;
  temp.matrix[1][2] = -5;

  temp.matrix[2][0] = -1;
  temp.matrix[2][1] = 6;
  temp.matrix[2][2] = -4;
  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 0);
  ck_assert_uint_eq(result, 324);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  matrix_t temp;
  double result = 0;
  int result_defolt = 0;
  s21_create_matrix(3, 3, &temp);
  temp.matrix[0][0] = 1;
  temp.matrix[1][1] = 1;
  temp.matrix[2][2] = 1;

  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 0);
  ck_assert_uint_eq(result, 1);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_determinant_6) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  double result = 0;
  s21_create_matrix(5, 5, &matrix);
  s21_fill(&matrix, -1);
  ck_assert_int_eq(s21_determinant(&matrix, &result), 0);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_determinant_7) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  double result = 0;
  s21_create_matrix(6, 4, &matrix);
  s21_fill(&matrix, -1.676675645);
  ck_assert_int_eq(s21_determinant(&matrix, &result), INCORRECT_INPUT);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_determinant_8) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  double result = 0;
  s21_create_matrix(0, 4, &matrix);
  ck_assert_int_eq(s21_determinant(&matrix, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_determinant_9) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  double result = 0;
  s21_create_matrix(2, 2, &matrix);
  s21_fill(&matrix, 5);
  ck_assert_int_eq(s21_determinant(&matrix, &result), OK);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_determinant_10) {
  double result = 0;
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 9;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[0][3] = 4;

  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 4;
  matrix.matrix[1][3] = 4;

  matrix.matrix[2][0] = 4;
  matrix.matrix[2][1] = 4;
  matrix.matrix[2][2] = 9;
  matrix.matrix[2][3] = 9;

  matrix.matrix[3][0] = 1;
  matrix.matrix[3][1] = 1;
  matrix.matrix[3][2] = 5;
  matrix.matrix[3][3] = 1;
  s21_determinant(&matrix, &result);
  ck_assert_int_eq(result, -578);
  s21_remove_matrix(&matrix);
}
END_TEST

TCase *tcase_matrix_s21_determinant() {
  TCase *tcase = tcase_create("matrix_s21_determinant");
  tcase_add_test(tcase, test_s21_determinant_1);
  tcase_add_test(tcase, test_s21_determinant_2);
  tcase_add_test(tcase, test_s21_determinant_3);
  tcase_add_test(tcase, test_s21_determinant_4);
  tcase_add_test(tcase, test_s21_determinant_5);
  tcase_add_test(tcase, test_s21_determinant_6);
  tcase_add_test(tcase, test_s21_determinant_7);
  tcase_add_test(tcase, test_s21_determinant_8);
  tcase_add_test(tcase, test_s21_determinant_9);
  tcase_add_test(tcase, test_s21_determinant_10);
  return tcase;
}
