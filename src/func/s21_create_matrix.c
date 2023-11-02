#include "../s21_matrix.h"

// Создание матриц
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = INCORRECT_MATRIX;
  if (rows > 0 && columns > 0 && result != NULL) {
    // выделяем память под кол-во строк
    if ((result->matrix = (double **)calloc(rows, sizeof(double *)))) {
      result->rows = rows;
      result->columns = columns;
      // выделяем память под кол-во столбцов
      for (int i = 0; i < rows; i++) {
        if ((result->matrix[i] = (double *)calloc(columns, sizeof(double)))) {
          status = OK;
          for (int j = 0; j < columns; j++) {
            result->matrix[i][j] = 0;
          }
          // очищаем строки, если не удалось выделить столбцы
        } else {
          for (int q = 0; q < i; q++) {
            free(result->matrix[q]);
          }
          free(result->matrix);
        }
      }
    }
  }
  return status;
}
