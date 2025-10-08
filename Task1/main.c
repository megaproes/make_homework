#include <stdio.h>
#include <math.h>
#include "calc.h"

int main() {
    int choice;
    double a, b;
    unsigned int n;
    unsigned long long fact_res;

    printf("=== Simple Calculator ===\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Factorial\n");
    printf("6. Square root\n");
    printf("0. Exit\n"); //

    while (1) {
        printf("\nChoose option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Wrong input!\n");
            return 1;
        }

        if (choice == 0) break;

        if (choice >= 1 && choice <= 4) {
            printf("Enter first number: ");
            scanf("%lf", &a);
            printf("Enter second number: ");
            scanf("%lf", &b);
        }

        switch (choice) {
            case 1:
                printf("Result = %.2lf\n", add(a, b));
                break;
            case 2:
                printf("Result = %.2lf\n", sub(a, b));
                break;
            case 3:
                printf("Result = %.2lf\n", mul(a, b));
                break;
            case 4:
                if (b == 0) printf("Error: division by zero!\n");
                else {
                    double out;
                    divide(a, b, &out);
                    printf("Result = %.2lf\n", out);
                }
                break;
            case 5:
                printf("Enter integer: ");
                scanf("%u", &n);
                if (factorial(n, &fact_res))
                    printf("Error: too big number!\n");
                else
                    printf("Result = %llu\n", fact_res);
                break;
            case 6:
                printf("Enter number: ");
                scanf("%lf", &a);
                if (a < 0)
                    printf("Error: negative number!\n");
                else {
                    double out;
                    square_root(a, &out);
                    printf("Result = %.2lf\n", out);
                }
                break;
            default:
                printf("Unknown option!\n");
        }
    }

    printf("Bye!\n");
    return 0;
}
