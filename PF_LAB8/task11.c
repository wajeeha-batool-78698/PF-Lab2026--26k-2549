#include <stdio.h>

int square(int x);
int negate(int x);
int isEven(int x);
int isPositive(int x);

void applyToArray(int *arr, int n, int (*fn)(int));
int countIf(const int *arr, int n, int (*pred)(int));
void printGeneric(void *data, char type, int n);

int main() {
    int arr[50] = {3, -2, 8, -5, 6};
    int n;

    do {
        printf("Enter n (1-50): ");
        scanf("%d", &n);

        if (n < 1 || n > 50) {
            printf("Invalid size\n");
        }
    } while (n < 1 || n > 50);

    printf("Original: ");
    printGeneric(arr, 'i', n);

    applyToArray(arr, n, negate);

    printf("After negate: ");
    printGeneric(arr, 'i', n);

    printf("Positive values after negate: %d\n",
           countIf(arr, n, isPositive));

    printf("Even values after negate: %d\n",
           countIf(arr, n, isEven));

    float values[] = {1.50, 2.25};

    printf("Float print (type f): ");
    printGeneric(values, 'f', 2);

    char letters[] = {'A', 'B', 'C'};

    printf("Character print (type c): ");
    printGeneric(letters, 'c', 3);

    printf("Testing invalid type:\n");
    printGeneric(arr, 'x', n);

    return 0;
}

int square(int x) {
    return x * x;
}

int negate(int x) {
    return -x;
}

int isEven(int x) {
    if (x % 2 == 0) {
        return 1;
    }
    return 0;
}

int isPositive(int x) {
    if (x > 0) {
        return 1;
    }
    return 0;
}

void applyToArray(int *arr, int n, int (*fn)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = fn(arr[i]);
    }
}

int countIf(const int *arr, int n, int (*pred)(int)) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (pred(arr[i])) {
            count++;
        }
    }

    return count;
}

void printGeneric(void *data, char type, int n) {
    if (type == 'i') {
        int *arr = (int *)data;

        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    } else if (type == 'f') {
        float *arr = (float *)data;

        for (int i = 0; i < n; i++) {
            printf("%.2f ", arr[i]);
        }
    } else if (type == 'c') {
        char *arr = (char *)data;

        for (int i = 0; i < n; i++) {
            printf("%c ", arr[i]);
        }
    } else {
        printf("Invalid type '%c' for printGeneric\n", type);
        return;
    }

    printf("\n");
}
