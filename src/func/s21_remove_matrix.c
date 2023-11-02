#include "../s21_matrix.h"

// Очистка матриц
void s21_remove_matrix(matrix_t *A) {
  if (A && A->matrix) {
    // Очищаем строки
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    // Очищаем столбцы
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}
