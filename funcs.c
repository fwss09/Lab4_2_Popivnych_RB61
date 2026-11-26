#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

/**
 * @file funcs.c
 * @brief реалізація функцій
*/

int **create_matrix(int rows, int cols) {
    //виділяємо масив вказівників на рядки
    int **mat = (int **) malloc(rows * sizeof(int *));
    if (!mat) return 0;

    // виділяємо пам'ять під кожен рядок
    for (int i = 0; i < rows; i++) {
        mat[i] = (int *)malloc(cols * sizeof(int));
        if (!mat[i]) {
            // якщо пам'ять не виділилась, звільняємо вже створені рядки
            for (int j = 0; j < i; j++) free(mat[j]);
            free(mat);
            return NULL;
        }
    }
    return mat;
}

void free_matrix(int **mat, int rows) {
    if (!mat) return;

    // спочатку звільняємо кожен рядок, потім сам масив вказівників
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);
}

void fill_matrix(int **mat, int rows, int cols, int mode) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mode == 1) {
                // введення елемента з клавіатури
                printf("[%d][%d]: ", i, j);
                scanf("%d", &mat[i][j]);
            } else if (mode == 2) {
                // заповнення випадковими числами від -5 до 5
                mat[i][j] = rand() % 11 - 5;
            } else {
                // заповнення за формулою суми індексів
                mat[i][j] = i + j;
            }
        }
    }
}

void print_matrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d ", mat[i][j]);
        }
        printf("\n");
    }
}

void max_min(int **A, int n_a, int *max_a, int *min_a) {
    // початкове значення беремо з першого елемента нижче головної діагоналі
    *max_a = A[1][0];
    *min_a = A[1][0];

    // проходимо тільки по елементах нижче головної діагоналі (j < i)
    for (int i = 1; i < n_a; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i][j] > *max_a) {
                *max_a = A[i][j];
            }
            if (A[i][j] < *min_a) {
                *min_a = A[i][j];
            }
        }
    }
}

int **transpose_b(int **B, int n_b, int m_b) {
    // створюємо нову матрицю зі зворотними розмірами m_b x n_b
    int **BT = create_matrix(m_b, n_b);
    if (!BT) return NULL;

    // міняємо рядки та стовпці місцями
    for (int i = 0; i < n_b; i++) {
        for (int j = 0; j < m_b; j++) {
            BT[j][i] = B[i][j];
        }
    }

    return BT;
}

int **mult_a_b(int **B, int n_b, int m_b, int **A, int n_a) {
    // перевірка сумісності розмірів матриць для множення
    if (n_a != n_b) return NULL;

    // створюємо матрицю результату розміром n_a x m_b
    int **C = create_matrix(n_a, m_b);
    if (!C) return NULL;

    // обчислення матричного добутку C = A * B
    for (int i = 0; i < n_a; i++) {
        for (int j = 0; j < m_b; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n_a; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

void sort_matrix_a(int **A, int n_a, int mode, int target_row) {
    if (mode == 2) {
        // сортування бульбашкою лише одного обраного рядка
        for (int i = 0; i < n_a - 1; i++) {
            for (int j = 0; j < n_a - i - 1; j++) {
                if (A[target_row][j] > A[target_row][j + 1]) {
                    int temp = A[target_row][j];
                    A[target_row][j] = A[target_row][j + 1];
                    A[target_row][j + 1] = temp;
                }
            }
        }
    } else {
        // сортування бульбашкою всієї матриці за зростанням
        int total = n_a * n_a;
        for (int i = 0; i < total - 1; i++) {
            for (int j = 0; j < total - i - 1; j++) {
                // переведення наскрізного індексу у координати [рядок][стовпець]
                int r1 = j / n_a, c1 = j % n_a;
                int r2 = (j + 1) / n_a, c2 = (j + 1) % n_a;

                if (A[r1][c1] > A[r2][c2]) {
                    int temp = A[r1][c1];
                    A[r1][c1] = A[r2][c2];
                    A[r2][c2] = temp;
                }
            }
        }
    }
}

void print_sums(int **A, int n_a, int **B, int n_b, int m_b) {
    // підрахунок та виведення суми кожного рядка матриці A
    printf("sum of rows in matrix A: \n");
    for (int i = 0; i < n_a; i++) {
        int row_sum = 0;
        for (int j = 0; j < n_a; j++) {
            row_sum += A[i][j];
        }
        printf("row %d: %d\n", i, row_sum);
    }

    // підрахунок та виведення суми кожного стовпця матриці B
    printf("sum of cols in matrix B: \n");
    for (int j = 0; j < m_b; j++) {
        int col_sum = 0;
        for (int i = 0; i < n_b; i++) {
            col_sum += B[i][j];
        }
        printf("col %d: %d\n", j, col_sum);
    }
}