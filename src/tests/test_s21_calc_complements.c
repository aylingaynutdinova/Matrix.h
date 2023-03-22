#include "common.h"

START_TEST(test_s21_calc_complements_1) {
  matrix_t test, result;
  s21_create_matrix(3, 2, &test);
  int result_status;
  s21_gen_matrix(&test);
  result_status = s21_calc_complements(&test, &result);
  ck_assert_int_eq(result_status, 2);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(test_s21_calc_complements_2) {
  matrix_t test, result;
  s21_create_matrix(3, 3, &test);
  s21_gen_matrix(&test);
  int result_status = s21_calc_complements(&test, &result);
  ck_assert_int_eq(result_status, 0);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_3) {
  matrix_t test, test_2, result;
  s21_create_matrix(3, 3, &test);
  test.matrix[0][0] = 1;
  test.matrix[0][1] = 2;
  test.matrix[0][2] = 3;
  test.matrix[1][0] = 0;
  test.matrix[1][1] = 4;
  test.matrix[1][2] = 2;
  test.matrix[2][0] = 5;
  test.matrix[2][1] = 2;
  test.matrix[2][2] = 1;
  s21_calc_complements(&test, &result);
  s21_create_matrix(3, 3, &test_2);
  test_2.matrix[0][0] = 0;
  test_2.matrix[0][1] = 10;
  test_2.matrix[0][2] = -20;
  test_2.matrix[1][0] = 4;
  test_2.matrix[1][1] = -14;
  test_2.matrix[1][2] = 8;
  test_2.matrix[2][0] = -8;
  test_2.matrix[2][1] = -2;
  test_2.matrix[2][2] = 4;
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      double res = result.matrix[i][j];
      double must = result.matrix[i][j];
      ck_assert_uint_eq(res, must);
    }
  }
  s21_remove_matrix(&test);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_4) {  // минор матрицы и матрицы
                                           // алгебраических дополнений
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(5, 5, &matrix);
  s21_fill(&matrix, 13);
  ck_assert_int_eq(s21_calc_complements(&matrix, &result), OK);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_5) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(5, 7, &matrix);
  s21_fill(&matrix, 2);
  ck_assert_int_eq(s21_calc_complements(&matrix, &result), INCORRECT_INPUT);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_6) {
  matrix_t matrix = {.rows = 0, .columns = 0, .matrix = NULL};
  matrix_t result = {.rows = 0, .columns = 0, .matrix = NULL};
  s21_create_matrix(0, 0, &matrix);
  s21_fill(&matrix, 1);
  ck_assert_int_eq(s21_calc_complements(&matrix, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

TCase *tcase_matrix_s21_calc_complements() {
  TCase *tcase = tcase_create("matrix_s21_calc_complements");
  tcase_add_test(tcase, test_s21_calc_complements_1);
  tcase_add_test(tcase, test_s21_calc_complements_2);
  tcase_add_test(tcase, test_s21_calc_complements_3);
  tcase_add_test(tcase, test_s21_calc_complements_4);
  tcase_add_test(tcase, test_s21_calc_complements_5);
  tcase_add_test(tcase, test_s21_calc_complements_6);
  return tcase;
}
