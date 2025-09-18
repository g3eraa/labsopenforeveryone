#include <cstdio>
#include <locale.h>
using namespace std;
#define size 100

int input(int *n, double x[], char *fname);
double summ(double x[], int n, double start, double finish);

int main(int argc, char *argv[]){
    double a[size], b[size], c[size];
    double summa_a, summa_b, summa_c, start, finish, max_sum;
    int la, lb, lc;
    int max_count = 0;
    setlocale(LC_ALL, "rus");
    
    printf("Введите начало диапазона\n");
    if(scanf("%lf", &start) != 1){
        printf("Вы ввели не число");
        return 0;
    }
    
    printf("Введите конец диапазона\n");
    if(scanf("%lf", &finish) != 1){
        printf("Вы ввели не число");
        return 0;
    }
    
    if (start > finish){
        double temp = start;
        start = finish;
        finish = temp;
    }
    
    if (argc < 4) { 
        printf("Недостаточно параметров!\n"); 
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
    
    printf("\nСумма массива A: %.2lf\n", summa_a);
    printf("Сумма массива B: %.2lf\n", summa_b);
    printf("Сумма массива C: %.2lf\n", summa_c);
    
    
    max_sum = summa_a;
    if (summa_b > max_sum) max_sum = summa_b;
    if (summa_c > max_sum) max_sum = summa_c;
    
    
    if (summa_a == max_sum) max_count++;
    if (summa_b == max_sum) max_count++;
    if (summa_c == max_sum) max_count++;
    
    
    switch(max_count) {
        case 0:
            printf("Ни один массив не имеет элементов в диапазоне\n");
            break;
        case 1:
            printf("Максимальная сумма: %.2lf (", max_sum);
            if (summa_a == max_sum) printf("массив A");
            else if (summa_b == max_sum) printf("массив B");
            else printf("массив C");
            printf(")\n");
            break;
        case 2:
            printf("Два массива имеют максимальную сумму %.2lf: ", max_sum);
            if (summa_a == max_sum) printf("A ");
            if (summa_b == max_sum) printf("B ");
            if (summa_c == max_sum) printf("C ");
            printf("\n");
            break;
        case 3:
            printf("Все три массива имеют одинаковую максимальную сумму: %.2lf\n", max_sum);
            break;
    }
    
    return 0;
}

int input(int *n, double x[], char *fname){
    FILE *file;
    if ((file = fopen(fname, "r")) == NULL){
        printf("Невозможно открыть файл '%s'\n", fname);
        return 0;
    }
    if (fscanf(file, "%d", n) < 1) { 
        printf ("Ошибка чтения из файла '%s'\n", fname);
        fclose(file); 
        return 0; 
    } 
    if (*n < 0 || *n > size) { 
        printf("Кол-во эл-тов массива должно быть от 1 до %d! (файл '%s')\n", size, fname); 
        return 0;  
    } 
    for (int i = 0; i < *n; i++) { 
        if (fscanf(file, "%lf", &x[i]) < 1) { 
            printf ("Ошибка чтения из файла '%s'\n", fname);
            fclose(file); 
            return 0; 
        } 
    } 
    fclose(file);
    return 1; 
}

double summ(double x[], int n, double start, double finish){
    double sum = 0;
    for (int i = 0; i < n; i++) {
        if (start <= x[i] && x[i] <= finish) {
            sum += x[i];
        }
    }
    return sum;
}