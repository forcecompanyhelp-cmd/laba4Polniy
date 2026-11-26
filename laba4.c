#include <stdio.h>
#include <math.h>

void task1(void)
{
    int n, i;
    double sum = 0.0;

    printf("Введите n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        double d = 2.0 * i + 1.0;
        sum += 1.0 / (d * d);
    }

    printf("Сумма: %.6f\n", sum);
}

void task2(void)
{
    int n, i;
    double sum = 0.0;

    printf("Введите n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        sum += (double)(i + 1) / i;
    }

    printf("Сумма: %.4f\n", sum);
}

void task3(void)
{
    double a, p = 1.0;
    int n, i;

    printf("Введите a и n: ");
    scanf("%lf %d", &a, &n);

    for (i = 1; i <= n; i++)
    {
        p *= a;
        printf("a^%d = %.4f\n", i, p);
    }
}

void task4(void)
{
    int n, i, mark;
    int c1[4] = {0}, c2[4] = {0};

    printf("Количество учеников в классе: ");
    scanf("%d", &n);

    printf("Оценки 1-го класса (от 2 до 5):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &mark);
        if (mark >= 2 && mark <= 5)
            c1[mark - 2]++;
    }

    printf("Оценки 2-го класса (от 2 до 5):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &mark);
        if (mark >= 2 && mark <= 5)
            c2[mark - 2]++;
    }

    printf("1 класс: 5 - %d, 4 - %d, 3 - %d, 2 - %d\n", c1[3], c1[2], c1[1], c1[0]);
    printf("2 класс: 5 - %d, 4 - %d, 3 - %d, 2 - %d\n", c2[3], c2[2], c2[1], c2[0]);
}

void task5(void)
{
    unsigned long long num, tmp, div = 1;
    long long s1 = 0, s2 = 0;
    int sign = 1;

    printf("Введите натуральное число: ");
    scanf("%llu", &num);

    tmp = num;
    while (tmp > 0)
    {
        s1 += sign * (long long)(tmp % 10);
        sign = -sign;
        if (tmp >= 10)
            div *= 10;
        tmp /= 10;
    }

    sign = 1;
    tmp = num;
    while (div > 0)
    {
        s2 += sign * (long long)(tmp / div);
        sign = -sign;
        tmp %= div;
        div /= 10;
    }

    printf("а) %lld\n", s1);
    printf("б) %lld\n", s2);
}

void task6(void)
{
    double a = 2.0, b = 1.0;
    double xs[] = {-5.0, -4.0, -3.0, -1.0, 0.0, 2.0, 4.0};
    int i;

    for (i = 0; i < 7; i++)
    {
        double x = xs[i];
        double root = 2.0 * b - x;
        double den = a + 2.0 * x;

        if (root < 0.0 || fabs(den) < 1e-9)
        {
            printf("x = %5.1f | не определено\n", x);
        }
        else
        {
            double y = 2.6 * a * b - (0.5 * a * sqrt(root)) / den;
            printf("x = %5.1f | y = %8.4f\n", x, y);
        }
    }
}

void task7(void)
{
    int i;
    double area, yield;
    double total_area = 0.0, total_harvest = 0.0;

    for (i = 1; i <= 10; i++)
    {
        printf("Район %d (площадь, урожайность): ", i);
        scanf("%lf %lf", &area, &yield);
        total_area += area;
        total_harvest += area * yield;
    }

    printf("Общий сбор: %.2f ц\n", total_harvest);
    if (total_area > 0.0)
        printf("Средняя урожайность: %.2f ц/га\n", total_harvest / total_area);
}

void task8(void)
{
    unsigned long long num;
    int max1 = -1, max2 = -1;
    int min1 = 10, min2 = 10;

    printf("Введите натуральное число: ");
    scanf("%llu", &num);

    while (num > 0)
    {
        int d = (int)(num % 10);

        if (d >= max1)
        {
            max2 = max1;
            max1 = d;
        }
        else if (d > max2)
        {
            max2 = d;
        }

        if (d <= min1)
        {
            min2 = min1;
            min1 = d;
        }
        else if (d < min2)
        {
            min2 = d;
        }

        num /= 10;
    }

    if (max2 == -1)
    {
        printf("В числе только одна цифра: %d\n", max1);
    }
    else
    {
        printf("Максимальные цифры: %d, %d\n", max1, max2);
        printf("Минимальные цифры: %d, %d\n", min1, min2);
    }
}

void task9(void)
{
    double eps, sum = 0.0, term = 1.5;
    int n = 1;

    printf("Введите eps: ");
    scanf("%lf", &eps);

    while (fabs(term) >= eps)
    {
        sum += term;
        n++;
        term = term * (3.0 * n) / ((2.0 * n - 1.0) * (2.0 * n));
    }

    printf("Сумма: %.6f\n", sum);
}

void task10(void)
{
    int n = 1;
    double prev = 1.0, cur;

    while (1)
    {
        n++;
        cur = 1.0 / n;
        if (fabs(prev - cur) < 1e-6)
        {
            printf("Элементы: %.8f и %.8f (номера %d и %d)\n", prev, cur, n - 1, n);
            break;
        }
        prev = cur;
    }
}

int main(void)
{
    int choice;

    while (1)
    {
        printf("\nВыберите задачу (1-10, 0 - выход): ");
        if (scanf("%d", &choice) != 1 || choice == 0)
            break;

        switch (choice)
        {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 9: task9(); break;
            case 10: task10(); break;
            default: printf("Неверный пункт меню\n");
        }
    }

    return 0;
}
