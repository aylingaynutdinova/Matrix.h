#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (!is_normal_matrix(A) && !is_normal_matrix(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      for (int i = 0; i < A->rows && res; i++) {
        for (int j = 0; j < A->columns && res; j++) {
          if ((float)A->matrix[i][j] != (float)B->matrix[i][j]) res = FAILURE;
        }
      }
    } else
      res = FAILURE;
  } else
    res = FAILURE;
  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  if (is_normal_matrix(A) || is_normal_matrix(B))
    res = INCORRECT_MATRIX;
  else if (!is_equal_size(A, B))
    res = INCORRECT_INPUT;
  else {
    if (!s21_create_matrix(A->rows, A->columns, result)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          double sum = A->matrix[i][j] + B->matrix[i][j];
          result->matrix[i][j] = sum;
        }
      }
    } else
      res = INCORRECT_MATRIX;
  }
  return res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  if (is_normal_matrix(A) || is_normal_matrix(B))
    res = INCORRECT_MATRIX;
  else if (!is_equal_size(A, B))
    res = INCORRECT_INPUT;
  else {
    if (!s21_create_matrix(A->rows, A->columns, result)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          double sum = A->matrix[i][j] - B->matrix[i][j];
          result->matrix[i][j] = sum;
        }
      }
    } else
      res = INCORRECT_MATRIX;
  }
  return res;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = 0;
  if (!s21_create_matrix(A->rows, A->columns, result) && !is_normal_matrix(A)) {
    double sum = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        sum = A->matrix[i][j] * number;
        result->matrix[i][j] = sum;
      }
    }
  } else
    res = INCORRECT_MATRIX;
  return res;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  if (is_normal_matrix(A) || is_normal_matrix(B))
    res = INCORRECT_MATRIX;
  else if ((A->columns == B->rows)) {
    if (!s21_create_matrix(A->rows, B->columns, result)) {
      int count = 0;
      double sum = 0;
      for (int i = 0; i < result->rows && !res; i++) {
        for (int j = 0; j < result->columns && !res; j++) {
          while (count < B->rows) {
            sum += (A->matrix[i][count] * B->matrix[count][j]);
            count++;
          }
          count = 0;
          result->matrix[i][j] = sum;
          sum = 0;
        }
      }
    } else
      res = INCORRECT_MATRIX;
  } else
    res = INCORRECT_INPUT;
  return res;
}
