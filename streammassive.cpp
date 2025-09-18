#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

#define size 100

int input(int *n, double x[], char *fname) {
    ifstream file(fname); 
    if (!file.is_open()) {
        cout << "Невозможно открыть файл '" << fname << "'" << endl;
        return 0;
    }
    file >> *n; 
    if (file.fail()) {
        cout << "Ошибка чтения из файла '" << fname << "'" << endl;
        return 0;
    }
    if (*n < 0 || *n > size) {
        cout << "Кол-во эл-тов массива должно быть от 1 до " << size << "! (файл '" << fname << "')" << endl;
        return 0;
    }
    for (int i = 0; i < *n; i++) {
        file >> x[i]; 
        if (file.fail()) {
            cout << "Ошибка чтения из файла '" << fname << "'" << endl;
            return 0;
        }
    }
    file.close();
    return 1;
}

double summ(double x[], int n, double start, double finish) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        if (start <= x[i] && x[i] <= finish) {
            sum += x[i];
        }
    }
    return sum;
}


int main(int argc, char *argv[]) {
    double a[size], b[size], c[size];
    double summa_a, summa_b, summa_c, start, finish, max_sum;
    int la, lb, lc;
    int max_count = 0;
    setlocale(LC_ALL, "rus");

    
    cout << "Введите начало диапазона" << endl;
    cin >> start;
    if (cin.fail()) {
        cout << "Вы ввели не число" << endl;
        return 0;
    }

    cout << "Введите конец диапазона" << endl;
    cin >> finish; 
    if (cin.fail()) {
        cout << "Вы ввели не число" << endl;
        return 0;
    }

    if (start > finish) {
        double temp = start;
        start = finish;
        finish = temp;
    }

    if (argc < 4) {
        cout << "Недостаточно параметров!" << endl;
        return 0;
    }

    if (!input(&la, a, argv[1]))
        return 0;
    if (!input(&lb, b, argv[2]))
        return 0;
    if (!input(&lc, c, argv[3]))
        return 0;

    summa_a = summ(a, la, start, finish);
    summa_b = summ(b, lb, start, finish);
    summa_c = summ(c, lc, start, finish);

    
    cout << endl << "Сумма массива A: " << fixed << summa_a << endl;
    cout << "Сумма массива B: " << fixed << summa_b << endl;
    cout << "Сумма массива C: " << fixed << summa_c << endl;

    max_sum = summa_a;
    if (summa_b > max_sum) max_sum = summa_b;
    if (summa_c > max_sum) max_sum = summa_c;

    if (summa_a == max_sum) max_count++;
    if (summa_b == max_sum) max_count++;
    if (summa_c == max_sum) max_count++;

    
    switch (max_count) {
        case 0:
            cout << "Ни один массив не имеет элементов в диапазоне" << endl;
            break;
        case 1:
            cout << "Максимальная сумма: " << max_sum << " (";
            if (summa_a == max_sum) cout << "массив A";
            else if (summa_b == max_sum) cout << "массив B";
            else cout << "массив C";
            cout << ")" << endl;
            break;
        case 2:
            cout << "Два массива имеют максимальную сумму " <<  max_sum << ": ";
            if (summa_a == max_sum) cout << "A ";
            if (summa_b == max_sum) cout << "B ";
            if (summa_c == max_sum) cout << "C ";
            cout << endl;
            break;
        case 3:
            cout << "Все три массива имеют одинаковую максимальную сумму: " << max_sum << endl;
            break;
    }

    return 0;
}