#include <stdio.h>
#define MAX_ELEMENTS 100

void findSubsets(int arr[], int n, int sum) {
    int subset[MAX_ELEMENTS];
    int subsetSize = 0;
    int total = 0;
    int i, j;

    for (i = 0; i < (1 << n); i++) {
        total = 0;
        subsetSize = 0;
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                total += arr[j];
                subset[subsetSize++] = arr[j];
            }
        }
        if (total == sum) {
            printf("Subset with sum %d: ", sum);
            for (j = 0; j < subsetSize; j++) {
                printf("%d ", subset[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n, i, arr[MAX_ELEMENTS], sum, totalSum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in ascending order:\n");
    scanf("%d", &arr[0]); // First element
    totalSum += arr[0];

    for (i = 1; i < n; i++) {
        do {
            printf("Enter element %d: ", i + 1);
            scanf("%d", &arr[i]);
            if (arr[i] < arr[i - 1]) {
                printf("Please enter elements in ascending order.\n");
            }
        } while (arr[i] < arr[i - 1]);
        totalSum += arr[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &sum);

    if (sum > totalSum) {
        printf("Subset with sum %d is not possible.\n", sum);
    } else {
        findSubsets(arr, n, sum);
    }

    return 0;
}
