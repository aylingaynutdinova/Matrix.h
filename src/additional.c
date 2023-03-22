#include "s21_matrix.h"

int is_equal_size(matrix_t *A, matrix_t *B) {
  int res = INCORRECT;
  if (A->columns == B->columns && A->rows == B->rows) res = CORRECT;
  return res;
}

int is_normal_matrix(matrix_t *A) {
  int res = 0;
  if ((A == NULL) || (A->matrix == NULL) || (A->columns < 1) || (A->rows < 1)) {
    res = INCORRECT_MATRIX;
  }
  return res;
}
