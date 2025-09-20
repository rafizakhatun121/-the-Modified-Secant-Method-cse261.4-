# Modified Secant Method in C

This section implements the **Modified Secant Method** for root finding.  
It requires:
- One initial guess `x0`
- A small perturbation `delta`
- An error tolerance `error_limit`
- A maximum number of iterations `max_iter`

The method iteratively updates the root approximation until either:
- The error is less than the specified tolerance, or  
- The maximum number of iterations is reached.

---

Function Implementation


// Modified Secant Method Implementation
double modifiedSecant(double x0, double delta, double error_limit, int max_iter) {
    int iter = 0;
    double x1;

    printf("\nModified Secant Method:\n");
    printf("Iter\t   x\t\t f(x)\t\t Error\n");
    printf("--------------------------------------------------\n");

    while(iter < max_iter) {
        double fx = f(x0);
        double fx_delta = f(x0 + delta * x0);

        if(fx_delta - fx == 0) {
            printf("Division by zero detected!\n");
            return NAN;
        }

        x1 = x0 - (fx * delta * x0) / (fx_delta - fx);
        double error = fabs(x1 - x0);

        printf("%d\t %.6f\t %.6f\t %.6f\n", iter+1, x1, f(x1), error);

        if(error < error_limit) {
            printf("Root found near x = %.6f after %d iterations\n", x1, iter+1);
            return x1;
        }

        x0 = x1;
        iter++;
    }

    printf("Modified Secant did not converge within max iterations.\n");
    return NAN;
}

