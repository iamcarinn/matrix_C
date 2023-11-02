#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

// Создание матриц
int s21_create_matrix(int rows, int columns, matrix_t* result);
// Очистка матриц
void s21_remove_matrix(matrix_t* A);
// Сравнение матриц
int s21_eq_matrix(matrix_t* A, matrix_t* B);
// Сложение матриц
int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
// Вычитание матриц
int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
// Умножение матрицы на число
int s21_mult_number(matrix_t* A, double number, matrix_t* result);
// Умножение двух матриц
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
// Транспонирование матрицы
int s21_transpose(matrix_t* A, matrix_t* result);
// Минор матрицы и матрица алгебраических дополнений
int s21_calc_complements(matrix_t* A, matrix_t* result);
// Определитель матрицы (determinant)
int s21_determinant(matrix_t* A, double* result);
// Обратная матрица
int s21_inverse_matrix(matrix_t* A, matrix_t* result);

// ДРУГОЕ
// Минор элемента
void s21_my_minor(matrix_t* A, int skipX, int skipY, matrix_t* result);
double s21_my_determinant(matrix_t* A);
#endif  // S21_MATRIX_H