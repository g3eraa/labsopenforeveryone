#include <iostream>
#include <fstream>
#include <cmath>
#include <locale>
#include <cstdlib>
using namespace std;

int input(int* n, double** x, const char* fname);
double summ(double* x, int n, double start, double finish, double (*f)(double));
void output(double* x, int n, const char* fname, double (*f)(double));

double user_func(double x);

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");

    if (argc < 5) {
        cout << "Недостаточно параметров" << endl;
        return 0;
    }

    double start, finish;
    cout << "Введите начало диапазона:" << endl;
    cin >> start;

    cout << "Введите конец диапазона:" << endl;
    cin >> finish;

    if (start > finish) {
        double t = start;
        start = finish;
        finish = t;
    }

    double* a = nullptr, * b = nullptr, * c = nullptr;
    int la, lb, lc;

    if (!input(&la, &a, argv[1])) return 0;
    if (!input(&lb, &b, argv[2])) return 0;
    if (!input(&lc, &c, argv[3])) return 0;

    double sa = summ(a, la, start, finish, fabs);
    double sb = summ(b, lb, start, finish, user_func);
    double sc = summ(c, lc, start, finish, [](double x) { return x * x; });

    cout << "Сумма A: " << sa << endl;
    cout << "Сумма B: " << sb << endl;
    cout << "Сумма C: " << sc << endl;

    output(a, la, argv[4], fabs);
    output(b, lb, argv[4], user_func);
    output(c, lc, argv[4], [](double x) { return x * x; });

    free(a);
    free(b);
    free(c);

    return 0;
}

int input(int* n, double** x, const char* fname) {
    ifstream f(fname);
    if (!f.is_open()) return 0;

    f >> *n;
    if (*n <= 0) return 0;

    *x = (double*)calloc(*n, sizeof(double));
    if (!*x) return 0;

    for (int i = 0; i < *n; i++) {
        f >> (*x)[i];
        if (f.fail()) return 0;
    }

    return 1;
}

double summ(double* x, int n, double start, double finish, double (*f)(double)) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        double v = f(x[i]);
        if (v >= start && v <= finish)
            s += v;
    }
    return s;
}

void output(double* x, int n, const char* fname, double (*f)(double)) {
    ofstream out(fname, ios::app);
    for (int i = 0; i < n; i++)
        out << f(x[i]) << " ";
    out << endl;
}

double user_func(double x) {
    return x + 10;
}
