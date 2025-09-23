

# Explanation :
# Root Finding in C: Modified Secant vs Standard Secant Method

This project demonstrates the implementation of **Modified Secant Method** and **Standard Secant Method** in C, applied to the nonlinear test function:

\[
f(x) = e^x - 3x
\]

The goal is to approximate the root of the function using iterative numerical methods and compare their performance.

---

## Explanation:


# Header Files and Function Definition:

This section includes the necessary libraries and defines the test function  
\( f(x) = e^x - 3x \) whose root we want to find.

```c
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
# Modified Secant Method Function:
// This section implements the Modified Secant method using one initial guess,
// a small delta, and stops when the error < error_limit or max iterations are reached.
## Modified Secant Method in C:

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

## Function Implementation:


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
## 🔄 Modified Secant Method – Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Input x0, δ, error_limit, max_iter]
    B --> C[Compute f(x0) and f(x0 + δ·x0)]
    C --> D{Is f(x0+δ·x0) - f(x0) = 0?}
    D -->|Yes| E[Stop: Division by Zero]
    D -->|No| F[Compute x1 = x0 - (f(x0)·δ·x0)/(f(x0+δ·x0)-f(x0))]
    F --> G[Error = |x1 - x0|]
    G --> H{Error < error_limit?}
    H -->|Yes| I[Root Found -> Print x1]
    H -->|No| J{Iterations < max_iter?}
    J -->|No| K[Stop: Did not converge]
    J -->|Yes| L[Set x0 = x1, Repeat Loop]

##Standard Secant Method Function  :
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
## 🔄 Standard Secant Method – Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Input x0, x1, error_limit, max_iter]
    B --> C[Compute f(x0), f(x1)]
    C --> D{Is f(x1) - f(x0) = 0?}
    D -->|Yes| E[Stop: Division by Zero]
    D -->|No| F[Compute x2 = x1 - f(x1)·(x1-x0)/(f(x1)-f(x0))]
    F --> G[Error = |x2 - x1|]
    G --> H{Error < error_limit?}
    H -->|Yes| I[Root Found -> Print x2]
    H -->|No| J{Iterations < max_iter?}
    J -->|No| K[Stop: Did not converge]
    J -->|Yes| L[Set x0 = x1, x1 = x2, Repeat Loop]

## collects input from the user and executes both methods for comparison:
int main() {
    double x0_mod, delta, error_limit;
    double x0_sec, x1_sec;
    int max_iter;

    printf("Comparing Modified Secant and Standard Secant Methods for f(x) = e^x - 3x\n");

    // Modified Secant Method Input
    printf("\nModified Secant Method Input:\n");
    printf("Enter initial guess x0: "); scanf("%lf", &x0_mod);
    printf("Enter delta (small value, e.g., 0.01): "); scanf("%lf", &delta);
    printf("Enter error limit: "); scanf("%lf", &error_limit);
    printf("Enter maximum iterations: "); scanf("%d", &max_iter);

    modifiedSecant(x0_mod, delta, error_limit, max_iter);

    // Standard Secant Method Input
    printf("\nStandard Secant Method Input:\n");
    printf("Enter first guess x0: "); scanf("%lf", &x0_sec);
    printf("Enter second guess x1: "); scanf("%lf", &x1_sec);

    secant(x0_sec, x1_sec, error_limit, max_iter);

    return 0;
}
# Comparing Modified Secant and Standard Secant Methods for f(x) = e^x - 3x:

Modified Secant Method Input:
Enter initial guess x0: 1
Enter delta (small value, e.g., 0.01): 0.01
Enter error limit: 0.0001
Enter maximum iterations: 10

Modified Secant Method:
Iter       x            f(x)          Error
--------------------------------------------------
1     0.652315     -0.021379     0.032315
2     0.619061     -0.000056     0.033254
Root found near x = 0.619061 after 2 iterations


 
 



	​

 





