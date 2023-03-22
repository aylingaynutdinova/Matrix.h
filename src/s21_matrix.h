#ifndef SRC_S21_MATRIX
#define SRC_S21_MATRIX

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define INCORRECT_MATRIX 1
#define INCORRECT_INPUT 2

#define CORRECT 1
#define INCORRECT 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// functions from the task

/**
 * @brief Creates a new matrix with defined number of rows and columns.
 * @param result a newly created matrix.
 * @return 0 - OK;
 * 1 - Error, incorrect matrix;
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

/**
 * @brief Checks whether two inputed matrices are equal.
 * @return 1 - SUCCESS, if matrices are equal;
 * 0 - FAILURE, if matrices are not equal;
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);
/**
 * @brief Calculates the sum of two matrices
 * @return 0 - OK; 1 - Error, incorrect matrix; 2 - Calculation error
 * (mismatched matrix sizes; matrix for which calculations cannot be performed,
 * etc.)
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
/**
 * @brief Substracts one matrix from another
 * @return 0 - OK; 1 - Error, incorrect matrix; 2 - Calculation error
 * (mismatched matrix sizes; matrix for which calculations cannot be performed,
 * etc.)
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
/**
 * @brief Matrix multiplication by scalar
 * @return 0 - OK; 1 - Calculation error (mismatched matrix sizes; matrix for
 * which calculations cannot be performed, etc.)
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
/**
 * @brief Multiplication of two matrices
 * @return 0 - OK; 1 - Error, incorrect matrix; 2 - Calculation error
 * (mismatched matrix sizes; matrix for which calculations cannot be performed,
 * etc.)
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
/**
 * @brief Switches matrix's rows with its columns with its numbers retained
 * @return 0 - OK; 1 - Error, incorrect matrix; 2 - Calculation error
 * (mismatched matrix sizes; matrix for which calculations cannot be performed,
 * etc.)
 */
int s21_transpose(matrix_t *A, matrix_t *result);
/**
 * @brief Calculates the algebraic complement of a matrix element, the value of
 * the minor multiplied by -1^(i+j).
 * @return 0 - OK; 1 - Error, incorrect matrix;
 */
int s21_calc_complements(matrix_t *A, matrix_t *result);
/**
 * @brief Finds determinant
 * @return 0 - OK; 1 - Error, incorrect matrix; 2 - Calculation error
 * (mismatched matrix sizes; matrix for which calculations cannot be performed,
 * etc.)
 */
int s21_determinant(matrix_t *A, double *result);
/**
 * @return determinant of matrix
 */
double my_determinant(matrix_t *A, int rows);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

/**
 * @brief Checks if two matrices are equal
 * @return 1 - if matrices are equal; 0 - if matrices are not equal
 */
int is_equal_size(matrix_t *A, matrix_t *B);

/**
 * @brief Checks if the number is finite
 * @return 1 - number is too big; 2 - number is too small; 0 - is ok
 */
int is_normal_value(double value);

/**
 * @brief Checks matrix
 * @return 1 - incorrect matrix; 0 - matrix is ok
 */
int is_normal_matrix(matrix_t *A);

/**
 * @brief Minor of matrix. Submatrix is obtaibed by deleteing i'th row and j'th
 * column from the original matrix
 */
int submatrix(matrix_t *A, int a, int b, matrix_t *result);
#endif  // SRC_S21_MATRIX

double my_determinant(matrix_t *A, int rows);