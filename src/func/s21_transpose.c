#include "../s21_matrix.h"

// Транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (!(A && result)) {
    status = INCORRECT_MATRIX;
  } else if (!(status = s21_create_matrix(A->columns, A->rows, result))) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] += A->matrix[i][j];
      }
    }
  }
  return status;
}
