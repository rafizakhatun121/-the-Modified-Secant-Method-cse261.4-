// shimanto
//  SHIMANTO

// Section 1: Header Files and Function Definition
// This section includes necessary libraries and defines the function f(x)
// whose root we want to find.
#include <stdio.h>
#include <math.h>

// Test function: f(x) = e^x - 3x
double f(double x)
{
    return exp(x) - 3 * x;
}

// Rafiza
//  Section 2: Modified Secant Method Function
//  This section implements the Modified Secant method using one initial guess,
//  a small delta, and stops when the error < error_limit or max iterations are reached.
double modifiedSecant(double x0, double delta, double error_limit, int max_iter)
{
    int iter = 0;
    double x1;

    printf("\nModified Secant Method:\n");
    printf("Iter\t   x\t\t f(x)\t\t Error\n");
    printf("--------------------------------------------------\n");

    while (iter < max_iter)
    {
        double fx = f(x0);
        double fx_delta = f(x0 + delta * x0);

        if (fx_delta - fx == 0)
        {
            printf("Division by zero detected!\n");
            return NAN;
        }

        x1 = x0 - (fx * delta * x0) / (fx_delta - fx);
        double error = fabs(x1 - x0);

        printf("%d\t %.6f\t %.6f\t %.6f\n", iter + 1, x1, f(x1), error);

        if (error < error_limit)
        {
            printf("Root found near x = %.6f after %d iterations\n", x1, iter + 1);
            return x1;
        }

        x0 = x1;
        iter++;
    }

    printf("Modified Secant did not converge within max iterations.\n");
    return NAN;
}
// RAtul
//Ratul
// Section 3: Standard Secant Method Function
// This section implements the Standard Secant method using two initial guesses.
// It stops when error < error_limit or max iterations are reached.
double secant(double x0, double x1, double error_limit, int max_iter) {
    int iter = 0;
    double x2;

    printf("\nStandard Secant Method:\n");
    printf("Iter\t   x0\t\t x1\t\t f(x1)\t\t Error\n");
    printf("-----------------------------------------------------------\n");

    while(iter < max_iter) {
        double fx0 = f(x0);
        double fx1 = f(x1);

        if(fx1 - fx0 == 0) {
            printf("Division by zero detected!\n");
            return NAN;
        }

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        double error = fabs(x2 - x1);

        printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\n", iter+1, x0, x1, fx1, error);

        if(error < error_limit) {
            printf("Root found near x = %.6f after %d iterations\n", x2, iter+1);
            return x2;
        }

        x0 = x1;
        x1 = x2;
        iter++;
    }

    printf("Secant did not converge within max iterations.\n");
    return NAN;
}


// rifaft
// safin
// Section 5: User Input for Modified Secant Method
// This section takes user input for Modified Secant method parameters.
    printf("\nModified Secant Method Input:\n");
    printf("Enter initial guess x0: "); scanf("%lf", &x0_mod);
    printf("Enter delta (small value, e.g., 0.01): "); scanf("%lf", &delta);
    printf("Enter error limit: "); scanf("%lf", &error_limit);
    printf("Enter maximum iterations: "); scanf("%d", &max_iter);
// susmita