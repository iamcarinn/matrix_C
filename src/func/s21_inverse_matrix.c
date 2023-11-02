#include "../s21_matrix.h"

// Обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  double determ = 0;
  if (!(A && result && A->matrix)) {
    status = INCORRECT_MATRIX;
  } else if (A->columns != A->rows)
    status = CALCULATION_ERROR;
  else if (s21_determinant(A, &determ) != OK || fabs(determ) < 1e-7)
    status = CALCULATION_ERROR;
  else {
    if (!(status = s21_create_matrix(A->columns, A->rows, result))) {
      if (A->rows == 1) {
        result->matrix[0][0] = 1 / A->matrix[0][0];
      } else {
        matrix_t first = {0}, second = {0};
        s21_calc_complements(A, &first);
        s21_transpose(&first, &second);
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->rows; j++) {
            result->matrix[i][j] = second.matrix[i][j] / determ;
          }
        }
        s21_remove_matrix(&first);
        s21_remove_matrix(&second);
      }
    }
  }
  return status;
}
