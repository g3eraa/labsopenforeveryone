#include <stdio.h>
#include <stdlib.h>

#define nmax 100

int readmatrix(int *rows, int *cols, double x[nmax][nmax], char *fname);
int Zeros(int rows, int cols, double x[nmax][nmax]);
void NegativeInRows(double x[][nmax], int rows, int cols, int neg[]);

int main(int argc, char* argv[]){
    double a[nmax][nmax], b[nmax][nmax];
    int row_1, col_1, row_2, col_2;
    int result = 0;
    int neg_a[nmax], neg_b[nmax];
    
    if (argc < 3) {
        printf("Недостаточно параметров!\n");
        return 0;
    }
    
    if (!readmatrix(&row_1, &col_1, a, argv[1])) return 0;
    if (!readmatrix(&row_2, &col_2, b, argv[2])) return 0;

    if (Zeros(row_1, col_1, a)) result += 1;
    if (Zeros(row_2, col_2, b)) result += 2;
    
    switch (result) {
        case 0:
            printf("Ни одна матрица не имеет элементов равных нулю\n");
            break;
        case 1:
            printf("Только в первой матрице есть нулевые элементы\n");
            NegativeInRows(a, row_1, col_1, neg_a);
            printf("Наличие отрицательных элементов по строкам матрицы 1:\n");
            for (int i = 0; i < row_1; i++) {
                printf("Строка %d: %s\n", i + 1, neg_a[i] ? "Есть" : "Нет");
            }
            break;
        case 2:
            printf("Только во второй матрице есть нулевые элементы\n");
            NegativeInRows(b, row_2, col_2, neg_b);
            printf("Наличие отрицательных элементов по строкам матрицы 2:\n");
            for (int i = 0; i < row_2; i++) {
                printf("Строка %d: %s\n", i + 1, neg_b[i] ? "Есть" : "Нет");
            }
            break;
        case 3:
            printf("Нулевые элементы есть в обоих матрицах\n");
            NegativeInRows(a, row_1, col_1, neg_a);
            NegativeInRows(b, row_2, col_2, neg_b);
            printf("Отрицательные элементы в первой матрице:\n");
            for (int i = 0; i < row_1; i++) {
                printf("Строка %d: %s\n", i + 1, neg_a[i] ? "Есть" : "Нет");
            }
            printf("Отрицательные элементы во второй матрице:\n");
            for (int i = 0; i < row_2; i++) {
                printf("Строка %d: %s\n", i + 1, neg_b[i] ? "Есть" : "Нет");
            }
            break;
    }
    return 0;
}

int readmatrix(int *rows, int *cols, double x[nmax][nmax], char *fname) {
    FILE *file = fopen(fname, "r");
    if (file == NULL) {
        printf("Невозможно открыть файл '%s'\n", fname);
        return 0;
    }
    
    if (fscanf(file, "%d", rows) != 1) {
        printf("Ошибка чтения количества строк из файла '%s'\n", fname);
        fclose(file);
        return 0;
    }
    
    if (fscanf(file, "%d", cols) != 1) {
        printf("Ошибка чтения количества столбцов из файла '%s'\n", fname);
        fclose(file);
        return 0;
    }
    
    if (*rows <= 0 || *rows > nmax || *cols <= 0 || *cols > nmax) {
        printf("Размеры матрицы должны быть от 1 до %d! (файл '%s')\n", nmax, fname);
        fclose(file);
        return 0;
    }
    
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            if (fscanf(file, "%lf", &x[i][j]) != 1) {
                printf("Ошибка чтения элемента [%d][%d] из файла '%s'\n", i, j, fname);
                fclose(file);
                return 0;
            }
        }
    }
    
    fclose(file);
    return 1;
}

int Zeros(int rows, int cols, double x[nmax][nmax]){
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (x[i][j] == 0) return 1;
        }
    }
    return 0;
}

void NegativeInRows(double x[][nmax], int rows, int cols, int neg[]){
    for (int i = 0; i < rows; i++) {
        neg[i] = 0;
        for (int j = 0; j < cols; j++) {
            if (x[i][j] < 0) {              
                neg[i] = 1;  
                break;        
            }
        }
    }
}