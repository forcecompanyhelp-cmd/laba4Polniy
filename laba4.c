#include <stdio.h>
#include <math.h>

void task38(void) {
    int n, i;
    double sum = 0.0;

    printf("n: ");
    if (scanf("%d", &n) != 1 || n < 1) return;
    for (i = 1; i <= n; i++) {
        double d = 2.0 * i + 1.0;
        sum += 1.0 / (d * d);
    }
    printf("S = %.10f\n", sum);
}

void task45(void) {
    int n, i;
    double sum = 0.0;

    printf("n: ");
    if (scanf("%d", &n) != 1 || n < 1) return;
    for (i = 1; i <= n; i++) {
        sum += (double)(i + 1) / i;
    }
    printf("S = %.10f\n", sum);
}

void task64(void) {
    double a, power = 1.0;
    int n, i;

    printf("a and n: ");
    if (scanf("%lf%d", &a, &n) != 2 || n < 1) return;
    for (i = 1; i <= n; i++) {
        power *= a;
        printf("a^%d = %.10g\n", i, power);
    }
}

void task101(void) {
    int n, i, grade;
    int excellent1 = 0, good1 = 0, satisfactory1 = 0, unsatisfactory1 = 0;
    int excellent2 = 0, good2 = 0, satisfactory2 = 0, unsatisfactory2 = 0;

    printf("Number of students in each class: ");
    if (scanf("%d", &n) != 1 || n < 1) return;

    printf("Enter grades for class 1 (5=excellent, 4=good, 3=satisfactory, 2=unsatisfactory):\n");
    for (i = 1; i <= n; i++) {
        printf("Student %d: ", i);
        if (scanf("%d", &grade) != 1 || grade < 2 || grade > 5) {
            printf("Grade must be 2, 3, 4 or 5.\n");
            return;
        }
        if (grade == 5) excellent1++;
        else if (grade == 4) good1++;
        else if (grade == 3) satisfactory1++;
        else unsatisfactory1++;
    }

    printf("Enter grades for class 2:\n");
    for (i = 1; i <= n; i++) {
        printf("Student %d: ", i);
        if (scanf("%d", &grade) != 1 || grade < 2 || grade > 5) {
            printf("Grade must be 2, 3, 4 or 5.\n");
            return;
        }
        if (grade == 5) excellent2++;
        else if (grade == 4) good2++;
        else if (grade == 3) satisfactory2++;
        else unsatisfactory2++;
    }

    printf("\nClass 1: excellent=%d, good=%d, satisfactory=%d, unsatisfactory=%d\n",
           excellent1, good1, satisfactory1, unsatisfactory1);
    printf("Class 2: excellent=%d, good=%d, satisfactory=%d, unsatisfactory=%d\n",
           excellent2, good2, satisfactory2, unsatisfactory2);
}

void task162(void) {
    long long n, remaining, t, divisor = 1;
    long long sumRight = 0, sumLeft = 0;
    int digit, sign;

    printf("Natural number: ");
    scanf("%lld", &n);

    /* First sum: start with the rightmost digit and alternate signs. */
    t = n;
    sign = 1;
    while (t > 0) {
        digit = (int)(t % 10);
        sumRight += sign * digit;
        sign = -sign;
        t /= 10;
    }

    /* Find the highest decimal place, then read digits left to right. */
    t = n;
    while (t >= 10) {
        divisor *= 10;
        t /= 10;
    }

    remaining = n;
    sign = 1;
    while (divisor > 0) {
        digit = (int)(remaining / divisor);
        sumLeft += sign * digit;
        sign = -sign;
        remaining %= divisor;
        divisor /= 10;
    }

    printf("Alternating sum from rightmost digit: %lld\n", sumRight);
    printf("Alternating sum from leftmost digit: %lld\n", sumLeft);
}

void task253(void) {
    const double a = 2.0, b = 1.0;
    const int xValues[] = {-5, -4, -3, -1, 0, 2, 4};
    int i;

    printf("y = 2.6*a*b - (0.5*a*sqrt(2*b-x))/(a+2*x), a=2, b=1\n");
    for (i = 0; i < 7; i++) {
        double x = xValues[i];
        double radicand = 2.0 * b - x;
        double denominator = a + 2.0 * x;

        if (radicand < 0.0 || fabs(denominator) < 1e-12) {
            printf("x = %g: expression is undefined for real numbers\n", x);
        } else {
            double y = 2.6 * a * b - (0.5 * a * sqrt(radicand)) / denominator;
            printf("x = %g, y = %.6f\n", x, y);
        }
    }
}

void task100(void) {
    int i;
    double area, yield, totalArea = 0.0, totalHarvest = 0.0;

    for (i = 1; i <= 10; i++) {
        printf("District %d: area (ha), average yield (centners/ha): ", i);
        if (scanf("%lf%lf", &area, &yield) != 2 || area < 0.0 || yield < 0.0) {
            printf("Incorrect data.\n");
            return;
        }
        totalArea += area;
        totalHarvest += area * yield;
    }

    printf("Total wheat harvest = %.2f centners\n", totalHarvest);
    if (totalArea > 0.0)
        printf("Average yield for the region = %.2f centners/ha\n", totalHarvest / totalArea);
    else
        printf("Average yield cannot be calculated because total area is zero.\n");
}

void task269(void) {
    long long n, t;
    int digit, max1 = -1, max2 = -1, min1 = 10, min2 = 10, count = 0;

    printf("Natural number: ");
    if (scanf("%lld", &n) != 1 || n < 1) return;
    t = n;

    while (t > 0) {
        digit = (int)(t % 10);
        count++;
        if (digit >= max1) { max2 = max1; max1 = digit; }
        else if (digit > max2) max2 = digit;

        if (digit <= min1) { min2 = min1; min1 = digit; }
        else if (digit < min2) min2 = digit;
        t /= 10;
    }

    printf("Largest digit: %d", max1);
    if (count >= 2) printf(", second largest digit: %d", max2);
    printf("\nSmallest digit: %d", min1);
    if (count >= 2) printf(", second smallest digit: %d", min2);
    printf("\n");
}

void task206(void) {
    double eps, term = 1.5, sum = 0.0;
    int n = 1;

    printf("epsilon (> 0): ");
    if (scanf("%lf", &eps) != 1 || eps <= 0.0) return;

    /* a_n = 3^n * n! / (2n)!, a_1 = 3/2.
       a_(n+1) / a_n = 3 / (2 * (2n + 1)). */
    while (fabs(term) >= eps && n < 100000) {
        sum += term;
        term *= 3.0 / (2.0 * (2.0 * n + 1.0));
        n++;
    }
    printf("Sum = %.12g\n", sum);
}

void task197(void) {
    int n = 1;
    double difference;

    do {
        difference = 1.0 / n - 1.0 / (n + 1.0);
        if (difference >= 1e-6) n++;
    } while (difference >= 1e-6);

    printf("First term: 1/%d = %.10f\n", n, 1.0 / n);
    printf("Next term:  1/%d = %.10f\n", n + 1, 1.0 / (n + 1.0));
    printf("Difference = %.12g\n", difference);
}

int main(void) {
    int choice;

    do {
        printf("\n=== Variant K = 6 ===\n");
        printf("1 - Task 38\n2 - Task 45\n3 - Task 64\n4 - Task 101\n");
        printf("5 - Task 162\n6 - Task 253\n7 - Task 100\n8 - Task 269\n");
        printf("9 - Task 206\n10 - Task 197\n0 - Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: task38(); break;
            case 2: task45(); break;
            case 3: task64(); break;
            case 4: task101(); break;
            case 5: task162(); break;
            case 6: task253(); break;
            case 7: task100(); break;
            case 8: task269(); break;
            case 9: task206(); break;
            case 10: task197(); break;
            case 0: puts("Exit."); break;
            default: puts("No such option.");
        }
    } while (choice != 0);

    return 0;
}
