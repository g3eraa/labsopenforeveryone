#include <cstdio>

// ВАРИАНТ 5 
// g++ main.cpp -o main 
// cd /Users/mac/Desktop/lab3_cem
// условие, таблица данных для одной функции, тесты, код 

void read(FILE* f, int mas[], int nmax) {
    int i;   
    for (i = 0; i < nmax; i++)
        fscanf(f,"%d", &mas[i]);
}

int poisk(int mas[], int nmax, int pivot) {
    int foundidx = -1; 

    for(int i = 0; i < nmax; i++) {
        if(mas[i] > pivot) { 
            if (foundidx == -1) { 
                foundidx = i;
            } else if(mas[i] < mas[foundidx]) {
                foundidx = i; 
            }
        }
    }
    return foundidx; 
}

int main(int argc, char* argv[]) {
    if (argc < 2) { 
        printf("недостаточно парам-в\n");
        return 1; 
    }
    
    FILE* f = fopen(argv[1], "r");
    if (!f) { 
        printf("не уд откр файл\n");
        return 1;
    }

    int n1; 
    fscanf(f, "%d", &n1);
    int a1[100];
    read(f, a1, n1); 

    int n2; 
    fscanf(f, "%d", &n2);
    int a2[100];
    read(f, a2, n2); 

    int n3; 
    fscanf(f, "%d", &n3);
    int a3[100];
    read(f, a3, n3); 

    fclose(f);

    int pivot;
    printf("введите опорное число: ");
    if(scanf("%d", &pivot)!=1){
        printf("Введите опорное, ошибка");
        return 0;
    }
    
    int min1 = poisk(a1, n1, pivot);
    int min2 = poisk(a2, n2, pivot);
    int min3 = poisk(a3, n3, pivot);

    printf("массив 1: ");
    for (int i = 0; i < n1; i++) printf("%d ", a1[i]);
    printf("\n");

    printf("массив 2: ");
    for (int i = 0; i < n2; i++) printf("%d ", a2[i]);
    printf("\n");

    printf("массив 3: ");
    for (int i = 0; i < n3; i++) printf("%d ", a3[i]);
    printf("\n");

    if (min1 != -1)
        printf("Мин > %d в массиве 1: %d\n", pivot, a1[min1]);
    else
        printf("В массиве 1 нет эл больше опорного\n");

    if (min2 != -1)
        printf("Мин > %d в массиве 2: %d\n", pivot, a2[min2]);
    else
        printf("В массиве 2 нет эл больше опорного\n");

    if (min3 != -1)
        printf("Мин > %d в массиве 3: %d\n", pivot, a3[min3]);
    else
        printf("В массиве 3 нет эл больше опорного\n");

    int overall = -1;

    if (min1 != -1) {
        overall = (overall == -1 || a1[min1] < overall) ? a1[min1] : overall;
    }
    if (min2 != -1) {
        overall = (overall == -1 || a2[min2] < overall) ? a2[min2] : overall;
    }
    if (min3 != -1) {
        overall = (overall == -1 || a3[min3] < overall) ? a3[min3] : overall;
    }

    if (overall == -1) {
        printf("Во всех массивах нет элементов больше %d\n", pivot);
    } else {
        printf("Общий минимум больше опорного = %d\n", overall);
    }

    return 0;
}