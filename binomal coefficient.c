#include <stdio.h>

int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    else
        return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

void printPascalsTriangle(int n) {
    int c[n + 1][n + 1];
    for (int line = 0; line <= n; line++) {
        for (int i = 0; i <= line; i++) {
            c[line][i] = binomialCoefficient(line, i);
            printf("%d ", c[line][i]);
        }
        printf("\n");
    }
}

int main() {
    int n, k;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (n >= k && k >= 0) {
        printf("Binomial coefficient C(%d, %d) = %d\n", n, k, binomialCoefficient(n, k));
        printf("\nPascal's Triangle:\n");
        printPascalsTriangle(n);
    } else {
        printf("Invalid input. Enter value n >= k >= 0.\n");
    }

    return 0;
}
