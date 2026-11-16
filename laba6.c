#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Завдання 947
void task947() {
    int n = 0, i, j;
    int a[50][50];
    int imax = 0, imin = 0, smin = 0, smax = 0;

    printf("Введіть розмір квадратної матриці n (1..50): ");
    scanf("%d", &n);
    if (n < 1 || n > 50) {
        printf("Некоректний розмір матриці\n");
        return;
    }

    printf("Введіть елементи матриці %dx%d:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 1; i < n; i++) {
        if (a[i][i] > a[imax][imax]) {
            imax = i;
        }
        if (a[i][i] <= a[imin][imin]) {
            imin = i;
        }
        if (a[i][n - 1 - i] < a[smin][n - 1 - smin]) {
            smin = i;
        }
        if (a[i][n - 1 - i] >= a[smax][n - 1 - smax]) {
            smax = i;
        }
    }

    printf("а) Перший максимальний головної діагоналі: (%d, %d)\n", imax + 1, imax + 1);
    printf("б) Перший мінімальний побічної діагоналі: (%d, %d)\n", smin + 1, n - smin);
    printf("в) Останній мінімальний головної діагоналі: (%d, %d)\n", imin + 1, imin + 1);
    printf("г) Останній максимальний побічної діагоналі: (%d, %d)\n", smax + 1, n - smax);
}

// Завдання 961
void task961() {
    int a[18][36];
    int mode = 0, v = 0, i, j, free_seats = 0;

    printf("Спосіб заповнення (1 - випадково, 2 - вручну): ");
    scanf("%d", &mode);

    if (mode == 1) {
        for (i = 0; i < 18; i++) {
            printf("Вагон %2d: ", i + 1);
            for (j = 0; j < 36; j++) {
                a[i][j] = rand() % 2;
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    } else if (mode == 2) {
        printf("Введіть 18 рядків по 36 чисел (0 або 1):\n");
        for (i = 0; i < 18; i++) {
            for (j = 0; j < 36; j++) {
                scanf("%d", &a[i][j]);
            }
        }
    } else {
        printf("Невірний вибір\n");
        return;
    }

    printf("Введіть номер вагона (1..18): ");
    scanf("%d", &v);
    if (v < 1 || v > 18) {
        printf("Некоректний номер вагона\n");
        return;
    }

    for (j = 0; j < 36; j++) {
        if (a[v - 1][j] == 0) {
            free_seats++;
        }
    }

    printf("Кількість вільних місць у вагоні №%d: %d\n", v, free_seats);
}

void print_cols(int n, int m, int a[50][50]) {
    int i, j;
    for (j = 0; j < m; j++) {
        printf("Стовпець %d: ", j + 1);
        for (i = 0; i < n; i++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Завдання 987
void task987() {
    int n = 0, m = 0, i, j;
    int orig[50][50], a[50][50];

    printf("Введіть кількість рядків n і стовпців m (1..50): ");
    scanf("%d %d", &n, &m);
    if (n < 1 || n > 50 || m < 1 || m > 50) {
        printf("Некоректні розміри матриці\n");
        return;
    }

    printf("Введіть елементи матриці %dx%d:\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &orig[i][j]);
        }
    }

    printf("\nПункт а:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (orig[i][j] % 2 != 0) {
                a[i][j] = orig[i][j] - orig[n - 1][j];
            } else {
                a[i][j] = orig[i][j];
            }
        }
    }
    print_cols(n, m, a);

    printf("\nПункт б:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (orig[i][j] < 0) {
                a[i][j] = orig[i][j] * orig[i][0];
            } else {
                a[i][j] = orig[i][j];
            }
        }
    }
    print_cols(n, m, a);

    printf("\nПункт в:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (orig[i][j] % 2 == 0) {
                a[i][j] = orig[i][j] + orig[i][m - 1];
            } else {
                a[i][j] = orig[i][j] + orig[0][j];
            }
        }
    }
    print_cols(n, m, a);

    printf("\nПункт г:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                a[i][j] = -1;
            } else {
                a[i][j] = orig[i][j];
            }
        }
    }
    print_cols(n, m, a);
}

// Завдання 914
void task914() {
    int n = 0, m = 0, i, j, best = 0;
    int a[50][50];
    double max_avg = 0, avg;

    printf("Введіть кількість рядків n і стовпців m (1..50): ");
    scanf("%d %d", &n, &m);
    if (n < 1 || n > 50 || m < 1 || m > 50) {
        printf("Некоректні розміри матриці\n");
        return;
    }

    printf("Введіть елементи матриці %dx%d:\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (j = 0; j < m; j++) {
        int sum = 0;
        for (i = 0; i < n; i++) {
            sum += a[i][j];
        }
        avg = (double)sum / n;
        if (j == 0 || avg > max_avg) {
            max_avg = avg;
            best = j;
        }
    }

    printf("Стовпець з максимальним середнім арифметичним: №%d (середнє = %.2f)\n", best + 1, max_avg);
}

void magic_odd(int m, int start, int off_r, int off_c, int a[50][50]) {
    int r = 0, c = m / 2, num, nr, nc;

    for (num = 0; num < m * m; num++) {
        a[off_r + r][off_c + c] = start + num;
        nr = (r - 1 + m) % m;
        nc = (c + 1) % m;
        if (a[off_r + nr][off_c + nc] != 0) {
            r = (r + 1) % m;
        } else {
            r = nr;
            c = nc;
        }
    }
}

// Завдання 982
void task982() {
    int n = 0, i, j, temp, col;
    int a[50][50];

    printf("Введіть порядок магічного квадрата n (1..50): ");
    scanf("%d", &n);
    if (n < 1 || n > 50) {
        printf("Некоректний порядок\n");
        return;
    }
    if (n == 2) {
        printf("Магічного квадрата порядку 2 не існує\n");
        return;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    if (n % 2 == 1) {
        magic_odd(n, 1, 0, 0, a);
    } else if (n % 4 == 0) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                a[i][j] = i * n + j + 1;
                if ((i % 4 == j % 4) || (i % 4 + j % 4 == 3)) {
                    a[i][j] = n * n + 1 - a[i][j];
                }
            }
        }
    } else {
        int m = n / 2;
        int k = (n - 2) / 4;
        magic_odd(m, 1, 0, 0, a);
        magic_odd(m, m * m + 1, m, m, a);
        magic_odd(m, 2 * m * m + 1, 0, m, a);
        magic_odd(m, 3 * m * m + 1, m, 0, a);

        for (i = 0; i < m; i++) {
            for (j = 0; j < k; j++) {
                if (i == m / 2) {
                    col = j + 1;
                } else {
                    col = j;
                }
                temp = a[i][col];
                a[i][col] = a[i + m][col];
                a[i + m][col] = temp;
            }
            for (j = 0; j < k - 1; j++) {
                col = n - 1 - j;
                temp = a[i][col];
                a[i][col] = a[i + m][col];
                a[i + m][col] = temp;
            }
        }
    }

    printf("Магічний квадрат порядку %d (сума = %d):\n", n, n * (n * n + 1) / 2);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice = 0;
    srand((unsigned int)time(NULL));

    do {
        printf("\nЛабораторна робота №6 (Варіант K = 6)\n");
        printf("1 - Завдання 947\n");
        printf("2 - Завдання 961\n");
        printf("3 - Завдання 987\n");
        printf("4 - Завдання 914\n");
        printf("5 - Завдання 982\n");
        printf("0 - Вихід\n");
        printf("Виберіть завдання: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1: task947(); break;
            case 2: task961(); break;
            case 3: task987(); break;
            case 4: task914(); break;
            case 5: task982(); break;
            case 0: printf("Вихід\n"); break;
            default: printf("Невірний пункт меню\n");
        }
    } while (choice != 0);

    return 0;
}
