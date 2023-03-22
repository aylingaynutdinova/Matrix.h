#include "s21_matrix.h"

int count = 0;
int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (!s21_create_matrix(A->columns, A->rows, result) && !is_normal_matrix(A)) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  } else
    res = INCORRECT_MATRIX;
  return res;
}

int submatrix(matrix_t *A, int a, int b, matrix_t *result) {
  int i_res = 0;
  int j_res = 0;
  double temp = 0;
  for (int i = 0; i < A->rows && i_res < result->rows; i++) {
    if (i != a) {
      for (int j = 0; j < A->columns && j_res < result->columns; j++) {
        if (j != b) {
          temp = A->matrix[i][j];
          result->matrix[i_res][j_res] = temp;
          j_res++;
        }
      }
      j_res = 0;
      i_res++;
    }
  }
  return 0;
}

// int s21_determinant(matrix_t *A, double *result) {
//   int res = OK;
//   int rows = A->rows; // ?
//   if (is_normal_matrix(A))
//     res = INCORRECT_MATRIX;
//   else if (A->columns != A->rows)
//     res = INCORRECT_INPUT;
//   if (!res) {
//     matrix_t new_submatrix = {0}; // done
//     double det = 0;
//     if (!s21_create_matrix(A->rows - 1, A->columns - 1, &new_submatrix) &&
//         A->rows == A->columns) {
//       if (A->rows == 1) {
//         det = A->matrix[0][0];
//         printf("been here 1*1\n");
//       } else if (A->rows == 2) {
//         printf("been here1\n");
//         det = A->matrix[0][0] * A->matrix[1][1] -
//               A->matrix[0][1] * A->matrix[1][0];
//       } else {
//         printf("been here2\n");
//         double temp = 0;
//         for (int i = 0; i < rows; i++) {
//           if (!submatrix(A, 0, i, &new_submatrix)) {
//             if (!s21_determinant(&new_submatrix, &temp)) {
//               det += A->matrix[0][i] * ((i & 1) ? -1 : 1) * temp;
//             }
//           }
//         }
//       }
//       s21_remove_matrix(&new_submatrix);
//     } else {
//       printf("been here3\n");
//       res = INCORRECT_MATRIX;
//       new_submatrix.matrix = NULL; // ?
//     }
//     *result = det;
//   }
//   return res;
// }

double my_determinant(matrix_t *A, int rows) {
  matrix_t new_submatrix = {0};  // done
  double det = 0;
  if (!s21_create_matrix(A->rows - 1, A->columns - 1, &new_submatrix) &&
      A->rows == A->columns) {
    if (A->rows == 2) {
      det =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
      double temp = 0;
      for (int i = 0; i < rows; i++) {
        if (!submatrix(A, 0, i, &new_submatrix)) {
          if (!s21_determinant(&new_submatrix, &temp)) {
            det += A->matrix[0][i] * ((i & 1) ? -1 : 1) * temp;
          }
        }
      }
    }
    s21_remove_matrix(&new_submatrix);
  }
  return det;
}

int s21_determinant(matrix_t *A, double *result) {
  *result = 0;
  int res = OK;
  if (is_normal_matrix(A))
    res = INCORRECT_MATRIX;
  else if (A->columns != A->rows)
    res = INCORRECT_INPUT;

  else if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    *result = my_determinant(A, A->rows);
  }
  return res;
}

//    total heap usage: 273 allocs, 265 frees, 4,016 bytes allocated
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (is_normal_matrix(A)) {
    res = INCORRECT_MATRIX;
  } else if ((A->rows != A->columns) || (A->rows < 2)) {
    res = INCORRECT_INPUT;
  } else if (!s21_create_matrix(A->rows, A->columns, result)) {
    for (int i = 0; i < A->rows; i++) {
      int sign = (i & 1) ? -1 : 1;
      for (int j = 0; j < A->columns; j++) {
        matrix_t new_submatrix = {0};
        if (!s21_create_matrix(A->rows - 1, A->columns - 1, &new_submatrix)) {
          if (!submatrix(A, i, j, &new_submatrix)) {
            double det = 0;
            if (!s21_determinant(&new_submatrix, &det)) {
              result->matrix[i][j] = sign * det;
              s21_remove_matrix(&new_submatrix);
              sign = -sign;
            } else {
              res = INCORRECT_MATRIX;
            }
          } else {
            res = INCORRECT_MATRIX;
          }
        } else {
          res = INCORRECT_MATRIX;
        }
      }
    }
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = 0;
  matrix_t temp = {0};
  matrix_t temp1 = {0};
  double det = 0;
  count++;
  if (is_normal_matrix(A)) {
    res = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    res = INCORRECT_INPUT;
  } else {
    if (s21_determinant(A, &det)) res = INCORRECT_INPUT;

    if ((float)det) {
      if (s21_calc_complements(A, &temp)) {
        res = INCORRECT_MATRIX;
      }
      if (!res) {
        if (s21_transpose(&temp, &temp1)) {
          res = INCORRECT_MATRIX;
        }
        s21_remove_matrix(&temp);
      }
      if (!res) {
        if (s21_mult_number(&temp1, (1 / det), result)) res = INCORRECT_MATRIX;
        s21_remove_matrix(&temp1);
      }
    } else {
      res = INCORRECT_INPUT;
    }
  }
  return res;
}

// // gcc *.c -c && gcc *.o && ./a.out
// int main() {
//   matrix_t matrix;
//   matrix_t result;

//   s21_create_matrix(-1, -1, &matrix);
//   // int res = s21_inverse_matrix(&matrix, &result);

//   int res = s21_inverse_matrix(&matrix, &result);
//   printf("RES IS %d\n", res);

//   // printf("DET IS %d\n", det);
//   // ck_assert_int_eq(res, OK);
//   // ck_assert_double_eq_tol(det, 1.232, PRECISION);
//   // s21_remove_matrix(&matrix);
// }