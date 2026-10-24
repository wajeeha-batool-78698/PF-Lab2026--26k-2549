#include <stdio.h>

void bubbleSort(int *arr, int n);
void printArray(const int *arr, int n);

int main() {
    int arr[20];
    int n;

    do {
        printf("Enter the number of scores (1-20): ");
        scanf("%d", &n);

        if (n < 1 || n > 20) {
            printf("Invalid size\n");
        }

    } while (n < 1 || n > 20);

    printf("Enter the scores:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("After sorting: ");
    printArray(arr, n);

    return 0;
}

void bubbleSort(int *arr, int n) {
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void printArray(const int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }

    printf("\n");
}
