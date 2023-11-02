#include "../s21_matrix.h"

// Умножение двух матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;

  if (!(A && B && result)) {
    status = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    status = CALCULATION_ERROR;
  } else if (!(status = s21_create_matrix(A->rows, B->columns, result))) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int z = 0; z < B->rows; z++) {
          result->matrix[i][j] += A->matrix[i][z] * B->matrix[z][j];
        }
      }
    }
  }
  return status;
}
