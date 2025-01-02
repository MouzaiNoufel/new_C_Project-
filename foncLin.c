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
    double x[] = {2011, 2012, 2013, 2014};
    double y[] = {567595.43, 407274.78, 425815.28, 510732.68};
    int n = sizeof(x) / sizeof(x[0]);

    double m, b;
    linear_regression(x, y, n, &m, &b);

    printf("Slope (m): %.2f\n", m);
    printf("Intercept (b): %.2f\n", b);

    return 0;
}