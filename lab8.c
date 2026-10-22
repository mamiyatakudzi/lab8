#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

int task0(int count, char sym);
int task1(int n, int m);
int task1A(int n);
int task2(double h);
double task3(int n, double x);

int main(void) {
    setlocale(LC_ALL, ".UTF-8");

    int choice, count, n, m;
    char sym;
    double h, x, result;

    printf("Выберите номер задания (0, 1, 11 [для 1А], 2, 3): ");
    if (scanf("%d", &choice) != 1) return 1;

    switch (choice) {
    case 0:
        printf("Введите количество символов и вид символа: ");
        scanf("%d %c", &count, &sym);
        task0(count, sym);
        break;

    case 1:
        printf("Введите n и m (где m >= n): ");
        scanf("%d %d", &n, &m);
        printf("результат %d\n", task1(n, m));
        break;

    case 11:
        printf("Введите степень n: ");
        scanf("%d", &n);
        task1A(n);
        break;

    case 2:
        printf("Вычисляемая функция: y = x^3 + 3x^2 - 3 на отрезке [2; 4]\n");
        printf("Введите шаг табуляции h: ");
        scanf("%lf", &h);
        task2(h);
        break;

    case 3:
        printf("Введите натуральное число n и действительное число x (в радианах): ");
        scanf("%d %lf", &n, &x);
        result = task3(n, x);
        printf("Результат выражения: %.6f\n", result);
        break;

    default:
        printf("Неверный выбор задания.\n");
    }

    return 0;
}

int task0(int count, char sym) {
    for (int start = 1; start <= count; start++)
        putchar(sym);
    putchar('\n');
    return 0;
}

int task1(int n, int m) {
    int s = 0, k = 1;
    for (int i = m; i >= n; i--) {
        s += i;
        printf("выполнено %d раз\n", k++);
    }
    return s;
}

int task1A(int n) {
    long long res = 1;
    for (int i = 0; i <= n; i++) {
        printf("2^%2d = %10lld\n", i, res);
        if (i < n) res *= 2;
    }

    if (res >= 1024) printf("Результат: %.1fK\n", (double)res / 1024.0);
    else printf("Результат: %lld\n", res);
    return 0;
}

int task2(double h) {
    printf("-------------------------\n");
    printf("|   x    |     f(x)     |\n");
    printf("-------------------------\n");

    for (double x = 2.0; x <= 4.0 + h / 2.0; x += h)
        printf("| %6.2f | %12.4f |\n", x, x * x * x + 3.0 * x * x - 3.0);

    printf("-------------------------\n");
    return 0;
}

double task3(int n, double x) {
    double sum = 0.0;
    double current_sin = x;

    for (int i = 1; i <= n; i++) {
        current_sin = sin(current_sin);
        sum += current_sin;
    }

    return sum;
}