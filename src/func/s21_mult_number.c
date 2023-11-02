#include "../s21_matrix.h"

// Умножение матрицы на число
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;

  if (!(A && result)) {
    status = INCORRECT_MATRIX;
  } else if (!(status = s21_create_matrix(A->rows, A->columns, result))) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return status;
}
