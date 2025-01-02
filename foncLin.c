#include <stdio.h>

void linear_regression(double x[], double y[], int n, double *m, double *b) {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0;

    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x_squared += x[i] * x[i];
    }

    *m = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);
    *b = (sum_y * sum_x_squared - sum_x * sum_xy) / (n * sum_x_squared - sum_x * sum_x);
}

int main() {
    
     int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the values for x and y:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i + 1);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i + 1);
        scanf("%lf", &y[i]);
    }

    double m, b;
    linear_regression(x, y, n, &m, &b);

    printf("\nLinear Regression Equation: y = %.2fx + %.2f\n", m, b);


    return 0;
}