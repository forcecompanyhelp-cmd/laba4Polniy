#include <stdio.h>

// Завдання 38
void task38() {
    int n = 0, i, temp;
    int a[100];

    printf("Введіть кількість елементів (1..100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Некоректний розмір масиву\n");
        return;
    }

    printf("Введіть %d цілих чисел:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i + 1 < n; i += 2) {
        temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }

    printf("Результат:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Завдання 45
void task45() {
    int n = 0, i;
    double a[100], k = 0;
    int less = 0, equal = 0, greater = 0;

    printf("Введіть N (1..100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Некоректний розмір масиву\n");
        return;
    }

    printf("Введіть %d дійсних чисел:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    printf("Введіть число K: ");
    scanf("%lf", &k);

    for (i = 0; i < n; i++) {
        if (a[i] < k) {
            less++;
        } else if (a[i] > k) {
            greater++;
        } else {
            equal++;
        }
    }

    printf("Менших за K: %d\n", less);
    printf("Рівних K: %d\n", equal);
    printf("Більших за K: %d\n", greater);
}

// Завдання 64
void task64() {
    int n = 0, i;
    double a[100], sum = 0;

    printf("Введіть кількість елементів (1..100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Некоректний розмір масиву\n");
        return;
    }

    printf("Введіть %d дійсних чисел:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    for (i = 0; i < n; i += 2) {
        sum += a[i];
    }

    printf("Сума елементів з непарними номерами: %.2f\n", sum);
}

// Завдання 101
void task101() {
    int n = 0, i, idx = -1;
    double a[100], sum = 0, avg;

    printf("Введіть кількість елементів (1..100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Некоректний розмір масиву\n");
        return;
    }

    printf("Введіть %d дійсних чисел:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
        sum += a[i];
    }

    avg = sum / n;
    printf("Середнє арифметичне: %.2f\n", avg);

    for (i = 0; i < n; i++) {
        if (a[i] < avg) {
            idx = i;
        }
    }

    if (idx == -1) {
        printf("Елементи для видалення не знайдені\n");
        return;
    }

    for (i = idx; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    a[n - 1] = 0;

    printf("Масив після видалення:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
}

// Завдання 162
void task162() {
    int n = 0, i, j;
    int imax = 0, imin = 0, idef = 0;
    double p[100], w[100], temp;

    printf("Введіть кількість школярів (1..100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Некоректна кількість\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Школяр %d (зріст і вага): ", i + 1);
        scanf("%lf %lf", &p[i], &w[i]);
        if (p[i] <= 0 || w[i] <= 0) {
            printf("Зріст і вага мають бути більшими за 0\n");
            return;
        }
    }

    for (i = 1; i < n; i++) {
        if (p[i] > p[imax]) {
            imax = i;
        }
        if (p[i] < p[imin]) {
            imin = i;
        }
        if ((w[i] / p[i]) < (w[idef] / p[idef])) {
            idef = i;
        }
    }

    printf("Максимальний зріст: %.2f (школяр №%d)\n", p[imax], imax + 1);
    printf("Мінімальний зріст: %.2f (школяр №%d)\n", p[imin], imin + 1);
    printf("Найбільший дефіцит ваги: школяр №%d (вага/зріст = %.4f)\n", idef + 1, w[idef] / p[idef]);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
    }

    printf("Масив ваг за зростанням:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", w[i]);
    }
    printf("\n");
}

// Завдання 43
void task43() {
    int n = 0, i, best = 0;
    double buy[100], sell[100];

    printf("Введіть кількість банків N (1..100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Некоректна кількість банків\n");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Банк %d (купівля та продаж): ", i + 1);
        scanf("%lf %lf", &buy[i], &sell[i]);
    }

    for (i = 1; i < n; i++) {
        if (buy[i] > buy[best]) {
            best = i;
        }
    }

    printf("Найвигідніший обмін у банку №%d (курс купівлі: %.2f)\n", best + 1, buy[best]);
}

int main() {
    int choice = 0;

    do {
        printf("\nЛабораторна робота №5 (Варіант K = 6)\n");
        printf("1 - Завдання 38\n");
        printf("2 - Завдання 45\n");
        printf("3 - Завдання 64\n");
        printf("4 - Завдання 101\n");
        printf("5 - Завдання 162\n");
        printf("6 - Завдання 43\n");
        printf("0 - Вихід\n");
        printf("Виберіть завдання: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1: task38(); break;
            case 2: task45(); break;
            case 3: task64(); break;
            case 4: task101(); break;
            case 5: task162(); break;
            case 6: task43(); break;
            case 0: printf("Вихід\n"); break;
            default: printf("Невірний пункт меню\n");
        }
    } while (choice != 0);

    return 0;
}
