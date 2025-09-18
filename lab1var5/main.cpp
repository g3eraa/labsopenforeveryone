#include <iostream>
#include <fstream>
using namespace std;


void read_mas(ifstream &fin, int mas[], int n);
int poisk_min(int mas[], int n, int pivot);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Использование: ./main input.txt output.txt\n";
        return 1;
    }

    ifstream fin(argv[1]);
    if (!fin) {
        cout << "Не удалось открыть входной файл\n";
        return 1;
    }

    ofstream fout(argv[2]);
    if (!fout) {
        cout << "Не удалось открыть выходной файл\n";
        return 1;
    }

    int n1, n2, n3;
    int a1[100], a2[100], a3[100];

    fin >> n1;
    read_mas(fin, a1, n1);
    fin >> n2;
    read_mas(fin, a2, n2);
    fin >> n3;
    read_mas(fin, a3, n3);

    fin.close();

    int pivot;
    cout << "Введите опорное число: ";
    cin >> pivot;

    int min1 = poisk_min(a1, n1, pivot);
    int min2 = poisk_min(a2, n2, pivot);
    int min3 = poisk_min(a3, n3, pivot);

    fout << "Массив 1: ";
    for (int i = 0; i < n1; ++i) fout << a1[i] << " ";
    fout << "\n";

    fout << "Массив 2: ";
    for (int i = 0; i < n2; ++i) fout << a2[i] << " ";
    fout << "\n";

    fout << "Массив 3: ";
    for (int i = 0; i < n3; ++i) fout << a3[i] << " ";
    fout << "\n";

    if (min1 != -1) fout << "Мин > " << pivot << " в массиве 1: " << a1[min1] << "\n";
    else fout << "В массиве 1 нет элементов > pivot\n";

    if (min2 != -1) fout << "Мин > " << pivot << " в массиве 2: " << a2[min2] << "\n";
    else fout << "В массиве 2 нет элементов > pivot\n";

    if (min3 != -1) fout << "Мин > " << pivot << " в массиве 3: " << a3[min3] << "\n";
    else fout << "В массиве 3 нет элементов > pivot\n";

    int overall = -1;

    if (min1 != -1) overall = a1[min1];
    if (min2 != -1) {
        if (overall == -1) overall = a2[min2];
        else if (a2[min2] < overall) overall = a2[min2];
    }
    if (min3 != -1) {
        if (overall == -1) overall = a3[min3];
        else if (a3[min3] < overall) overall = a3[min3];
    }

    if (overall == -1)
        fout << "Во всех массивах нет элементов больше " << pivot << "\n";
    else
        fout << "Общий минимум > " << pivot << " = " << overall << "\n";

    cout << "Результаты записаны в " << argv[2] << "\n";

    fout.close();
    return 0;
}

void read_mas(ifstream &fin, int mas[], int n) {
    for (int i = 0; i < n; ++i) {
        fin >> mas[i];
    }
}

int poisk_min(int mas[], int n, int pivot) {
    int foundIdx = -1;
    for (int i = 0; i < n; ++i) {
        if (mas[i] > pivot) {
            if (foundIdx == -1) {
                foundIdx = i;
            } else {
                if (mas[i] < mas[foundIdx]) {
                    foundIdx = i;
                }
            }
        }
    }
    return foundIdx;
}