#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(x) - 2.0;
}

double f_prime(double x) {
    return exp(x);
}

// Function to draw an ASCII stem plot for an array of values
void draw_stem_plot(const char *label, double vals[], int count, double min_val, double max_val) {
    int plot_width = 35; // Character width of the plot
    
    printf("\n=== Stem Plot: %s ===\n", label);
    printf("Iter | Value      | Distribution\n");
    printf("-----+------------+--------------------------------------\n");

    for (int i = 0; i < count; i++) {
        double val = vals[i];
        
        // Calculate horizontal position on a scale from min_val to max_val
        int pos = 0;
        if (max_val > min_val) {
            pos = (int)(((val - min_val) / (max_val - min_val)) * plot_width);
        }
        if (pos < 0) pos = 0;
        if (pos > plot_width) pos = plot_width;

        printf("%4d | %10.7f | ", i, val);
        
        // Draw the stem line (---) leading to the marker (o)
        for (int j = 0; j < pos; j++) {
            putchar('-');
        }
        printf("o\n");
    }
    printf("-----+------------+--------------------------------------\n");
}

int main() {
    double x = 1.0;            // Initial guess: x0 = 1
    double tolerance = 1e-7;
    int max_steps = 10;
    
    double x_history[20];
    double f_history[20];
    int count = 0;

    printf("Newton-Raphson Step-by-Step for: e^x - 2 = 0\n");
    printf("Formula: x_{n+1} = x_n - f(x_n) / f'(x_n)\n\n");

    x_history[count] = x;
    f_history[count] = f(x);
    count++;

    while (count < max_steps) {
        double fx = f(x);
        double fpx = f_prime(x);

        // Next iteration value
        double next_x = x - (fx / fpx);

        printf("[Step %d -> %d]\n", count - 1, count);
        printf("  x_%d       = %.7f\n", count - 1, x);
        printf("  f(x_%d)    = %.7f\n", count - 1, fx);
        printf("  f'(x_%d)   = %.7f\n", count - 1, fpx);
        printf("  x_%d (next)= %.7f - (%.7f / %.7f) = %.7f\n\n", 
               count, x, fx, fpx, next_x);

        x = next_x;
        x_history[count] = x;
        f_history[count] = f(x);
        count++;

        if (fabs(f(x)) < tolerance) {
            printf("Converged to root: x = %.7f\n", x);
            break;
        }
    }

    // Generate Stem Plot for x_n convergence
    draw_stem_plot("x_n Convergence", x_history, count, 0.65, 1.05);

    // Generate Stem Plot for error / f(x_n) approaching 0
    draw_stem_plot("f(x_n) Error", f_history, count, 0.0, 0.8);

    return 0;
}

