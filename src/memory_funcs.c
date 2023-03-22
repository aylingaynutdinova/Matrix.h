#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK;
  if (rows > 0 && columns > 0 && result != NULL) {
    fflush(stdout);
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL)
      res = INCORRECT_MATRIX;
    else {
      for (int i = 0; i < rows && !res; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          res = INCORRECT_MATRIX;
          for (int j = 0; j < i; j++) {
            result->matrix[j] = 0;
            // free(result->matrix[j]);
          }
          // free(result->matrix);
        }
      }
      result->columns = columns;
      result->rows = rows;
    }
  } else {
    res = INCORRECT_MATRIX;
  }
  if (res) {
    if (result != NULL) result->matrix = NULL;
  }
  return res;
}

// void s21_remove_matrix(matrix_t *A) {
//   if (A->matrix) {
//     for (int i = 0; i < A->rows; i++) {
//       if (A->matrix[i]) {
//         free(A->matrix[i]);
//       }
//     }
//     free(A->matrix);
//   }
//   A->columns = 0;
//   A->rows = 0;
// }

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i]) {
        free(A->matrix[i]);
        A->matrix[i] = NULL;
      }
    }
    free(A->matrix);
    A->matrix = NULL;
  }
}