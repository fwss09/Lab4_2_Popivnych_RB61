#ifndef LAB4_2_POPIVNYCH_RB61_FUNCS_H
#define LAB4_2_POPIVNYCH_RB61_FUNCS_H

/**
 * @brief виділяє динамічну пам'ять під двовимірну матрицю
 * @param rows кількість рядків
 * @param cols кількість стовпців
 * @return вказівник на створену матрицю або null у разі помилки
*/
int **create_matrix(int rows, int cols);

/**
 * @brief звільняє динамічну пам'ять яка буда виділена під матрицю
 * @param mat вказівник на матрицю
 * @param rows кількість рядків
*/
void free_matrix(int **mat, int rows);

/**
 * @brief заповнює матрицю обраним способом
 * @param mat вказівник на матрицю
 * @param rows кількість рядків
 * @param cols кількість стовпців
 * @param mode спосіб заповнення
*/
void fill_matrix(int **mat, int rows, int cols, int mode);

/**
 * @brief виводить двовимірну матрицю на екран
 * @param mat вказівник на матрицю
 * @param rows кількість рядків
 * @param cols кількість стовпців
*/
void print_matrix(int **mat, int rows, int cols);

/**
 * @brief знаходить максимальний та мінімальний елементи матриці A нижче головної діагоналі
 * @param A квадратна матриця A
 * @param n_a розмірність матриці A
 * @param max_a вказівник для збереження максимального елемента
 * @param min_a вказівник для збереження мінімального елемента
*/
void max_min(int **A, int n_a, int *max_a, int *min_a);

/**
 * @brief транспонує прямокутну матрицю B
 * @param B вихідна матриця B
 * @param n_b кількість рядків B
 * @param m_b кількість стовпців B
 * @return вказівник на нову транспоновану матрицю розміром m_b x n_b
*/
int **transpose_b(int **B, int n_b, int m_b);

/**
 * @brief обчислює матричний добуток C = A * B
 * @param B матриця B
 * @param n_b кількість рядків B
 * @param m_b кількість стовпців B
 * @param A квадратна матриця A
 * @param n_a розмірність матриці A
 * @return вказівник на матрицю результату C розміром n_a x m_b
*/
int **mult_a_b(int **B, int n_b, int m_b, int **A, int n_a);

/**
 * @brief сортує за зростанням усю матрицю A або лише один обраний рядок
 * @param A квадратна матриця A
 * @param n_a розмірність матриці A
 * @param mode режим сортування (1 - вся матриця, 2 - один рядок)
 * @param target_row індекс рядка для сортування
*/
void sort_matrix_a(int **A, int n_a, int mode, int target_row);

/**
 * @brief обчислює та виводить суми елементів рядків матриці A та стовпців матриці B
 * @param A матриця A
 * @param n_a розмірність матриці A
 * @param B матриця B
 * @param n_b кількість рядків B
 * @param m_b кількість стовпців B
*/
void print_sums(int **A, int n_a, int **B, int n_b, int m_b);

#endif //LAB4_2_POPIVNYCH_RB61_FUNCS_H
