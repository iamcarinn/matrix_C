#include "../s21_matrix.h"

// // Минор матрицы и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (!(A && result && A->matrix)) {
    status = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    status = CALCULATION_ERROR;
  } else if (!(status = s21_create_matrix(A->columns, A->rows, result))) {
    if (A->rows == 1) {
      result->matrix[0][0] = 1;
    } else {
      matrix_t now = {0};
      if (!(status = s21_create_matrix(A->columns - 1, A->rows - 1, &now))) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            int sign = 1;
            s21_my_minor(A, i, j, &now);
            if ((i + j) % 2) {
              sign = -1;
            }
            result->matrix[i][j] = sign * s21_my_determinant(&now);
          }
        }
        s21_remove_matrix(&now);
      }
    }
  }
  return status;
}
