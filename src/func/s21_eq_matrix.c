#include "../s21_matrix.h"

// Сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;
  if ((A && B) &&
      (A->rows > 0 && A->columns > 0 && B->rows > 0 && B->columns > 0)) {
    if (A->rows == B->rows && A->columns == B->columns) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) {
            status = FAILURE;
          }
        }
      }
    } else {
      status = FAILURE;
    }
  } else {
    status = FAILURE;
  }
  return status;
}
