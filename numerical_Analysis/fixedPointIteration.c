#include <stdio.h>
#include <math.h>

// f(x) = x^3 + x - 1 = 0
// Real root: r = 0.6823

// 1. Form: g1(x) = 1 - x^3
double g1(double x) {
    return 1.0 - pow(x, 3);
} 
double dg1(double x) {
    return -3.0 * pow(x, 2);
}

// 2. Form: g2(x) = 1 / (x^2 + 1)
double g2(double x) {
    return 1.0 / (pow(x, 2) + 1.0);
}
double dg2(double x) {
    return (-2.0 * x) / pow(pow(x, 2) + 1.0, 2);
}

// 3. Form: g3(x) = (1 - x)^(1/3)
double g3(double x) {
    return cbrt(1.0 - x);
}
double dg3(double x) {
    double difference = 1.0 - x;
    if (fabs(difference) < 1e-7) return 999.0; // Prevents division by zero
    return -1.0 / (3.0 * cbrt(pow(difference, 2)));
}

int main() {
    double x0;
    int count, i;
    double x;
    double derivative;
    
    printf("=== FIXED POINT ITERATION (f(x) = x^3 + x - 1 = 0) ===\n\n");
    
    printf("Enter beginning value (x0) (Suggestion: 0.75): ");
    if (scanf("%lf", &x0) != 1) return 1;
    
    printf("Enter the count (N) (Suggestion: 3 or 4): ");
    if (scanf("%d", &count) != 1) return 1;
    
    // --- 1. FORM ---
    printf("\n========================================\n");
    printf("1. Form: g(x) = 1 - x^3\n");
    derivative = fabs(dg1(x0));
    printf(" |g'(%.2f)| = %.4f\n", x0, derivative);
    
    if (derivative < 1.0) {
        printf(" -> Status: CONVERGES (|g'| < 1). Calculating iterations:\n");
        x = x0;
        for (i = 1; i <= count; i++) {
            x = g1(x);
            printf("    x%d = %.6f\n", i, x);
        }
    } else {
        printf(" -> Status: DIVERGES (|g'| >= 1). Cannot converge with this form!\n");
    }
    
    // --- 2. FORM ---
    printf("\n========================================\n");
    printf("2. Form: g(x) = 1 / (x^2 + 1)\n");
    derivative = fabs(dg2(x0));
    printf(" |g'(%.2f)| = %.4f\n", x0, derivative);
    
    if (derivative < 1.0) {
        printf(" -> Status: CONVERGES (|g'| < 1). Calculating iterations:\n");
        x = x0;
        for (i = 1; i <= count; i++) {
            x = g2(x);
            printf("    x%d = %.6f\n", i, x);
        }
    } else {
        printf(" -> Status: DIVERGES (|g'| >= 1). Cannot converge with this form!\n");
    }
    
    // --- 3. FORM ---
    printf("\n========================================\n");
    printf("3. Form: g(x) = (1 - x)^(1/3)\n");
    derivative = fabs(dg3(x0));
    printf(" |g'(%.2f)| = %.4f\n", x0, derivative);
    
    if (derivative < 1.0) {
        printf(" -> Status: CONVERGES (|g'| < 1). Calculating iterations:\n");
        x = x0;
        for (i = 1; i <= count; i++) {
            x = g3(x);
            printf("    x%d = %.6f\n", i, x);
        }
    } else {
        printf(" -> Status: DIVERGES (|g'| >= 1). Cannot converge with this form!\n");
    }
    
    printf("\n========================================\n");
    return 0;
}