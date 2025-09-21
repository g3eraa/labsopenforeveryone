/*Даны две матрицы разного размера. Для той из матриц, в которой есть элементы, равные 0, проверить наличие отрицательных элементов в каждой строке. */
#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

const int nmax = 100;

int readmatrix(int *rows, int *cols, double x[nmax][nmax], char *fname);
int Zeros(int rows, int cols, double x[nmax][nmax]);
void NegativeInRow(double row[], int cols, bool &hasNegative);

int main(int argc, char* argv[]){
    double a[nmax][nmax], b[nmax][nmax];
    int row_1, col_1, row_2, col_2;
    int result = 0;
    
    if (argc < 3) {
        cout << "Недостаточно параметров!" << endl;
        return 0;
    }
    
    if (!readmatrix(&row_1, &col_1, a, argv[1])) return 0;
    if (!readmatrix(&row_2, &col_2, b, argv[2])) return 0;

    if (Zeros(row_1, col_1, a)) result += 1;
    if (Zeros(row_2, col_2, b)) result += 2;
    
    switch (result) {
    case 0:
        cout << "Ни одна матрица не имеет элементов равных нулю" << endl;
        break;
        
    case 1:
        cout << "Только в первой матрице есть нулевые элементы"<< endl;
        cout << "Наличие отрицательных элементов по строкам матрицы 1:" << endl;
        for (int i = 0; i < row_1; i++) {
            bool hasNegative = false;
            NegativeInRow(a[i], col_1, hasNegative);
            cout << "Строка " << (i + 1) << ": " << (hasNegative ? "Есть" : "Нет") << endl;
        }
        break;
    
    case 2:
        cout << "Только во второй матрице есть нулевые элементы"<< endl;
        cout << "Наличие отрицательных элементов по строкам матрицы 2:" << endl;
        for (int i = 0; i < row_2; i++) {
            bool hasNegative = false;
            NegativeInRow(b[i], col_2, hasNegative);
            cout << "Строка " << (i + 1) << ": " << (hasNegative ? "Есть" : "Нет") << endl;
        }
        break;
        
    case 3:
        cout << "Нулевые элементы есть в обоих матрицах" << endl;
        cout << "Отрицательные элементы по строкам матриц:"<< endl;
        
        cout << "Первая матрица:" << endl;
        for (int i = 0; i < row_1; i++) {
            bool hasNegative = false;
            NegativeInRow(a[i], col_1, hasNegative);
            cout << "Строка " << (i + 1) << ": " << (hasNegative ? "Есть" : "Нет") << endl;
        }
        
        cout << "Вторая матрица:" << endl;
        for (int i = 0; i < row_2; i++) {
            bool hasNegative = false;
            NegativeInRow(b[i], col_2, hasNegative);
            cout << "Строка " << (i + 1) << ": " << (hasNegative ? "Есть" : "Нет") << endl;
        }
        break;
    }
    return 0;
}

int readmatrix(int *rows, int *cols, double x[nmax][nmax], char *fname) {
    ifstream file(fname); 
    if (!file.is_open()) {
        cout << "Невозможно открыть файл '" << fname << "'" << endl;
        return 0;
    }
    
    file >> *rows;
    if (file.fail()) {
        cout << "Ошибка чтения количества строк из файла '" << fname << "'";
        return 0;
    }
    
    file >> *cols;
    if (file.fail()) {
        cout << "Ошибка чтения количества столбцов из файла '" << fname << "'";
        return 0;
    }
    
    if (*rows <= 0 || *rows > nmax || *cols <= 0 || *cols > nmax) {
        cout << "Размеры матрицы должны быть от 1 до " << nmax << "! (файл '" << fname << "')" << endl;
        return 0;
    }
    
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            file >> x[i][j]; 
            if (file.fail()) {
                cout << "Ошибка чтения элемента [" << i << "][" << j << "] из файла '" << fname << "'" << endl;
                return 0;
            }
        }
    }
    
    file.close();
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

void NegativeInRow(double row[], int cols, bool &hasNegative) {
    hasNegative = false;
    for (int j = 0; j < cols; j++) {
        if (row[j] < 0) {
            hasNegative = true;
            break;
        }
    }
}