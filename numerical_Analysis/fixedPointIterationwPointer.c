#include <stdio.h>
#include <math.h>

// Target equation: f(x) = x^3 - x - 2 = 0
// Real root: r ? 1.521380

// Form 1 (Divergent): g1(x) = x^3 - 2
// Near the root (x ? 1.52), |g1'(x)| = 3*x^2 ? 6.94 > 1 -> Diverges
double g1(double x) { 
    return pow(x, 3) - 2.0; 
}
double dg1(double x) { 
    return 3.0 * pow(x, 2); 
}

// Form 2 (Divergent): g2(x) = 2 / (x^2 - 1)
// Near the root (x ? 1.52), |g2'(x)| ? 3.55 > 1 -> Diverges
double g2(double x) { 
    return 2.0 / (pow(x, 2) - 1.0); 
}
double dg2(double x) { 
    return (-4.0 * x) / pow(pow(x, 2) - 1.0, 2); 
}

// Form 3 (Convergent): g3(x) = (x + 2)^(1/3)
// Near the root (x ? 1.52), |g3'(x)| ? 0.144 < 1 -> Converges
double g3(double x) { 
    return cbrt(x + 2.0); 
}
double dg3(double x) {
    double diff = x + 2.0;
    if (fabs(diff) < 1e-7) return 999.0; // Division-by-zero guard
    return 1.0 / (3.0 * cbrt(pow(diff, 2)));
}

void testForm(const char* name, const char* definition, double (*g)(double), double (*dg)(double), double x0, int steps) {
    printf("%s [%s]:\n", name, definition);
    double derivative = fabs(dg(x0));
    printf(" |g'(%.2f)| = %.4f\n", x0, derivative);
    
    if (derivative < 1.0) {
        printf(" -> Status: CONVERGES (|g'| < 1). Calculating iterations:\n");
        double x = x0;
        for (int i = 1; i <= steps; i++) {
            x = g(x);
            printf("    x%d = %.6f\n", i, x);
        }
    } else {
        printf(" -> Status: DIVERGES (|g'| >= 1). Cannot converge to the root with this form!\n");
    }
    printf("--------------------------------------------------\n");
}

int main() {
    double x0;
    int steps;
    
    printf("=== FIXED-POINT ITERATION (f(x) = x^3 - x - 2 = 0) ===\n\n");
    printf("Enter initial guess (x0) (Suggested: 1.5): ");
    if (scanf("%lf", &x0) != 1) return 1;
    
    printf("Enter number of iterations (N) (Suggested: 5 or 6): ");
    if (scanf("%d", &steps) != 1) return 1;
    
    printf("\n--------------------------------------------------\n");
    
    testForm("Form 1", "g(x) = x^3 - 2", g1, dg1, x0, steps);
    testForm("Form 2", "g(x) = 2 / (x^2 - 1)", g2, dg2, x0, steps);
    testForm("Form 3", "g(x) = (x + 2)^(1/3)", g3, dg3, x0, steps);
    
    return 0;
}
