#ifndef LAB4_2_POPIVNYCH_RB61_FUNCS_H
#define LAB4_2_POPIVNYCH_RB61_FUNCS_H

int **create_matrix(int rows, int cols);

void free_matrix(int **mat, int rows);

void fill_matrix(int **mat, int rows, int cols, int mode);

void print_matrix(int **mat, int rows, int cols);

void max_min(int **A, int n_a, int *max_a, int *min_a);

int **transpose_b(int **B, int n_b, int m_b);

int **mult_a_b(int **B, int n_b, int m_b, int **A, int n_a);

void sort_matrix_a(int **A, int n_a, int mode, int target_row);

void print_sums(int **A, int n_a, int **B, int n_b, int m_b);

#endif //LAB4_2_POPIVNYCH_RB61_FUNCS_H
