#include <stdio.h>
int main() {
    int a[3][3][3];
    int same;

    // Input all elements
    for (int i = 0; i < 3; i++) {
        printf("\nEnter values for layer %d:\n", i + 1);

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                scanf("%d", &a[i][j][k]);
            }
        }
    }

    // Display all layers
    for (int i = 0; i < 3; i++) {
        printf("\nLayer %d:\n", i + 1);

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%d\t", a[i][j][k]);
            }
            printf("\n");
        }
    }

    // Compare every pair of layers
    for (int x = 0; x < 3; x++) {
        for (int y = x + 1; y < 3; y++) {
            same = 1;

            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (a[x][j][k] != a[y][j][k]) {
                        same = 0;
                    }
                }
            }

            if (same == 1) {
                printf("Layer %d and Layer %d are identical\n",
                       x + 1, y + 1);
            }
            else {
                printf("Layer %d and Layer %d are distinct\n",
                       x + 1, y + 1);
            }
        }
    }

    return 0;
}

