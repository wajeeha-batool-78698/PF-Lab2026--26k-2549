#include <stdio.h>
int main() {

    int mat[3][3] = {{2, 4, 5}, {5, 8, 3}, {7, 2, 0}};

    int cofactor[3][3];
    int adjoint[3][3];
    float inverse[3][3];
    int determinant = 0;

    printf("Original Matrix:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    printf("\nTranspose of Matrix:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", mat[j][i]);
        }
        printf("\n");
    }

// cofactor

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            int minor[2][2];
            int r = 0;

            for (int row = 0; row < 3; row++) {

                if (row == i)
                    continue;

                int c = 0;

                for (int col = 0; col < 3; col++) {

                    if (col == j)
                        continue;

                    minor[r][c] = mat[row][col];
                    c++;
                }

                r++;
            }

            int minor_det = minor[0][0] * minor[1][1] - minor[0][1] * minor[1][0];

            if ((i + j) % 2 == 0)
                cofactor[i][j] = minor_det;
            else
                cofactor[i][j] = -minor_det;
        }
    }

// determinant

    for (int j = 0; j < 3; j++) {
        determinant = determinant + mat[0][j] * cofactor[0][j];
    }

    printf("\nDeterminant = %d\n", determinant);

    printf("\nCofactor Matrix:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", cofactor[i][j]);
        }
        printf("\n");
    }

// adjoint

    printf("\nAdjoint Matrix:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            adjoint[i][j] = cofactor[j][i];
            printf("%d\t", adjoint[i][j]);
        }
        printf("\n");
    }

    // Find inverse

    if (determinant != 0) {

        printf("\nInverse Matrix:\n");

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                inverse[i][j] = (float)adjoint[i][j] / determinant;
                printf("%.3f\t", inverse[i][j]);
            }
            printf("\n");
        }

    } 
	else {
        printf("\nInverse does not exist.\n");
    }

    return 0;
}

