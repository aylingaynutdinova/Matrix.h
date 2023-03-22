#include "common.h"

START_TEST(test_s21_create_matrix_1) {
  fflush(stdout);
  matrix_t *matrix = NULL;
  int rows = 10, columns = 3;
  ck_assert_int_eq(s21_create_matrix(rows, columns, matrix), INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix_2) {
  fflush(stdout);
  matrix_t matrix = {0};
  int rows = 5, columns = 5;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &matrix), OK);
  for (int i = 0; i < rows; i++) {
    free(matrix.matrix[i]);
  }
  free(matrix.matrix);
}
END_TEST

START_TEST(test_s21_create_matrix_3) {
  matrix_t matrix = {0};
  ck_assert_int_eq(s21_create_matrix(-1, -20, &matrix), INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix_4) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  ck_assert_int_eq(s21_create_matrix(4, 4, &matrix), OK);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_create_matrix_5) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  ck_assert_int_eq(s21_create_matrix(0, 5, &matrix), INCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_create_matrix_6) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  ck_assert_int_eq(s21_create_matrix(-1, 5, &matrix), INCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_create_matrix_7) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  ck_assert_int_eq(s21_create_matrix(-5, -5, &matrix), INCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

TCase *tcase_matrix_s21_create_matrix() {
  TCase *tcase = tcase_create("matrix_s21_create_matrix");
  tcase_add_test(tcase, test_s21_create_matrix_1);
  tcase_add_test(tcase, test_s21_create_matrix_2);
  tcase_add_test(tcase, test_s21_create_matrix_3);
  tcase_add_test(tcase, test_s21_create_matrix_4);
  tcase_add_test(tcase, test_s21_create_matrix_5);
  tcase_add_test(tcase, test_s21_create_matrix_6);
  tcase_add_test(tcase, test_s21_create_matrix_7);
  return tcase;
}
