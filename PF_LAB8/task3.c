#include <stdio.h>

int isValidMark(int m);
void findMinMax(int arr[], int size, int *min, int *max);

int main() {
    int marks[5];
    int min, max;

    for (int i = 0; i < 5; i++) {
        do {
            printf("Enter mark for student %d: ", i + 1);
            scanf("%d", &marks[i]);

            if (isValidMark(marks[i]) == 0) {
                printf("Invalid mark, enter again\n");
            }

        } while (isValidMark(marks[i]) == 0);
    }

    findMinMax(marks, 5, &min, &max);

    printf("Lowest mark = %d\n", min);
    printf("Highest mark = %d\n", max);

    return 0;
}

int isValidMark(int m) {
    if (m >= 0 && m <= 100) {
        return 1;
    } else {
        return 0;
    }
}

void findMinMax(int arr[], int size, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }

        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}
