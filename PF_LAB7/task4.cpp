#include <stdio.h>
int main() {
    int a[3][3][3];
    int total = 0, even = 0, odd = 0;
    int count = 0;

    // Input all elements
    for (int i = 0; i < 3; i++) {
        printf("\nEnter values for layer %d:\n", i + 1);

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                scanf("%d", &a[i][j][k]);
            }
        }
    }

    // Analyze each layer
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        int highest = a[i][0][0];
        int lowest = a[i][0][0];

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%d\t", a[i][j][k]);

                sum += a[i][j][k];
                total += a[i][j][k];
                count++;

                if (a[i][j][k] > highest) {
                    highest = a[i][j][k];
                }

                if (a[i][j][k] < lowest) {
                    lowest = a[i][j][k];
                }

                if (a[i][j][k] % 2 == 0) {
                    even++;
                }
                else {
                    odd++;
                }
            }
            printf("\n");
        }

        printf("Layer %d total = %d\n", i + 1, sum);
        printf("Layer %d highest = %d\n", i + 1, highest);
        printf("Layer %d lowest = %d\n\n", i + 1, lowest);
    }

    printf("Overall total = %d\n", total);
    printf("Overall average = %.2f\n", (float)total / count);
    printf("Even numbers = %d\n", even);
    printf("Odd numbers = %d\n", odd);

    return 0;
}

