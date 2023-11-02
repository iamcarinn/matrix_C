#include "../s21_matrix.h"

// Определитель матрицы (determinant)
int s21_determinant(matrix_t *A, double *result) {
  int status = OK;
  if (!(A && result && A->matrix))
    status = INCORRECT_MATRIX;
  else if (A->columns != A->rows)
    status = CALCULATION_ERROR;
  else {
    *result = s21_my_determinant(A);
  }
  return status;
}

double s21_my_determinant(matrix_t *A) {
  double result = 0;
  if (A->rows == 1) {
    result = A->matrix[0][0];
  } else {
    matrix_t now = {0};
    s21_create_matrix(A->columns - 1, A->rows - 1, &now);
    for (int i = 0, sign = 1; i < A->rows; i++, sign *= (-1)) {
      s21_my_minor(A, 0, i, &now);
      result += sign * A->matrix[0][i] * s21_my_determinant(&now);
    }
    s21_remove_matrix(&now);
  }
  return result;
}

// Минор элемента
void s21_my_minor(matrix_t *A, int skipX, int skipY, matrix_t *result) {
  for (int i = 0, x = 0; i < result->rows; i++, x++) {
    if (i == skipX) {
      x++;
    }
    for (int j = 0, y = 0; j < result->columns; j++, y++) {
      if (j == skipY) {
        y++;
      }
      result->matrix[i][j] = A->matrix[x][y];
    }
  }
}