#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"

/**
 * @file main.c
 * @brief точка входу в програму
 * @return 0 при успішному виконанні
 */

int main() {
    // ініціалізація генератора випадкових чисел
    srand(time(NULL));

    // розмірності матриць A (варіант 12) та B
    int n_a = 12;
    int n_b = 12;
    int m_b, mode;

    // введення кількості стовпців для матриці B
    printf("enter cols for matrix B: ");
    scanf("%d", &m_b);

    // виділення динамічної пам'яті під матриці A та B
    int **A = create_matrix(n_a, n_a);
    int **B = create_matrix(n_b, m_b);

    // вибір способу заповнення та ініціалізація матриць
    printf("fill method (1 - keyboard, 2 - random -5..5, 3 - i+j): ");
    scanf("%d", &mode);

    fill_matrix(A, n_a, n_a, mode);
    fill_matrix(B, n_b, m_b, mode);

    // виведення початкових матриць на екран
    printf("\n--- matrix A (12x12) ---\n");
    print_matrix(A, n_a, n_a);

    printf("\n--- matrix B (12x%d) ---\n", m_b);
    print_matrix(B, n_b, m_b);

    // пошук максимуму та мінімуму нижче головної діагоналі матриці A
    int max_val, min_val;
    max_min(A, n_a, &max_val, &min_val);
    printf("\n[1] below main diagonal -> max = %d, min = %d\n", max_val, min_val);

    // транспонування матриці B та виведення результату
    int **BT = transpose_b(B, n_b, m_b);
    printf("\n[2] transposed matrix B (%dx12):\n", m_b);
    print_matrix(BT, m_b, n_b);

    // обчислення та виведення матричного добутку C = A * B
    int **C = mult_a_b(B, n_b, m_b, A, n_a);
    printf("\n[3] matrix product C = A * B (12x%d):\n", m_b);
    print_matrix(C, n_a, m_b);

    // обчислення сум рядків матриці A та стовпців матриці B
    printf("\n[4] sums:\n");
    print_sums(A, n_a, B, n_b, m_b);

    // вибір режиму та сортування матриці A
    int sort_mode, row = 0;
    printf("\n[5] sort matrix A (1 - all matrix, 2 - one row): ");
    scanf("%d", &sort_mode);
    if (sort_mode == 2) {
        printf("enter row index (0..11): ");
        scanf("%d", &row);
    }
    sort_matrix_a(A, n_a, sort_mode, row);
    printf("sorted matrix A:\n");
    print_matrix(A, n_a, n_a);

    // звільнення всієї виділеної динамічної пам'яті
    free_matrix(A, n_a);
    free_matrix(B, n_b);
    free_matrix(BT, m_b);
    free_matrix(C, n_a);

    return 0;
}
