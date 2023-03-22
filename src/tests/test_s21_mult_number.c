#include "common.h"

START_TEST(test_s21_mult_number_1) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  double num = 777.777;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_create_matrix(3, 3, &result_defolt);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  for (int i = 0; (i < temp.rows); i++) {
    for (int j = 0; j < temp.columns; j++) {
      result_defolt.matrix[i][j] = temp.matrix[i][j] * 777.777;
    }
  }
  ck_assert_int_eq(s21_mult_number(&temp, num, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_mult_number_2) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  double num = 777.777;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_create_matrix(3, 3, &result_defolt);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  for (int i = 0; i < temp.rows; i++) {
    for (int j = 0; j < temp.columns; j++) {
      result_defolt.matrix[i][j] = temp.matrix[i][j] * 777.777;
    }
  }
  ck_assert_int_eq(s21_mult_number(&temp, num, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_mult_number_3) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(3, 3, &matrix);
  s21_fill(&matrix, -1);
  ck_assert_int_eq(s21_mult_number(&matrix, 2, &result), OK);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_4) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(0, 3, &matrix);
  ck_assert_int_eq(s21_mult_number(&matrix, 2, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_5) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(1, 3, &matrix);
  s21_fill(&matrix, 1);
  ck_assert_int_eq(s21_mult_number(&matrix, 2.2222222, &result), OK);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

TCase *tcase_matrix_s21_mult_number() {
  TCase *tcase = tcase_create("matrix_s21_mult_number");
  tcase_add_test(tcase, test_s21_mult_number_1);
  tcase_add_test(tcase, test_s21_mult_number_2);
  tcase_add_test(tcase, test_s21_mult_number_3);
  tcase_add_test(tcase, test_s21_mult_number_4);
  tcase_add_test(tcase, test_s21_mult_number_5);
  return tcase;
}
