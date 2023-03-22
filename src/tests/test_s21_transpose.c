#include "common.h"

START_TEST(test_s21_transpose_1) {
  matrix_t temp;
  matrix_t result;
  matrix_t result_defolt;
  s21_create_matrix(3, 2, &temp);
  s21_create_matrix(2, 3, &result_defolt);
  s21_gen_matrix(&temp);
  result_defolt.matrix[0][0] = 1;
  result_defolt.matrix[0][1] = 3;
  result_defolt.matrix[0][2] = 5;
  result_defolt.matrix[1][0] = 2;
  result_defolt.matrix[1][1] = 4;
  result_defolt.matrix[1][2] = 6;
  ck_assert_int_eq(s21_transpose(&temp, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_transpose_2) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(3, 5, &matrix);
  s21_fill(&matrix, -1.75756);
  ck_assert_int_eq(s21_transpose(&matrix, &result), OK);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_3) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(-5, 5, &matrix);
  s21_fill(&matrix, 14);
  ck_assert_int_eq(s21_transpose(&matrix, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_4) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(1, 1, &matrix);
  s21_fill(&matrix, 13);
  ck_assert_int_eq(s21_transpose(&matrix, &result), OK);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

TCase *tcase_matrix_s21_transpose() {
  TCase *tcase = tcase_create("matrix_s21_transpose");
  tcase_add_test(tcase, test_s21_transpose_1);
  tcase_add_test(tcase, test_s21_transpose_2);
  tcase_add_test(tcase, test_s21_transpose_3);
  tcase_add_test(tcase, test_s21_transpose_4);
  return tcase;
}
