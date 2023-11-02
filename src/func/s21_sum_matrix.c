#include "../s21_matrix.h"

// Сложение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;

  if (!(A && B && result)) {
    status = INCORRECT_MATRIX;
  } else if (!(A->rows == B->rows && A->columns == B->columns)) {
    status = CALCULATION_ERROR;
  } else if (!(status = s21_create_matrix(A->rows, A->columns, result))) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return status;
}
