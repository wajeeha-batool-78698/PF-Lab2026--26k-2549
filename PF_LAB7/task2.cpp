#include <stdio.h>
int main(){

    int row, col;

    printf("Enter rows (1-5): ");
    scanf("%d", &row);

    printf("Enter columns (1-5): ");
    scanf("%d", &col);

    if(row < 1 || row > 5 || col < 1 || col > 5){
        printf("Invalid matrix size\n");
        return 0;
    }

    if(row == 1){
    	printf("Row Matrix\n");
	}
    if(col == 1){
    	printf("Column Matrix\n");
	}
    if(row == col){
    	printf("Square Matrix\n");
	}
    else{
    	printf("Rectangular Matrix\n");
	}

    int mat[5][5];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    printf("Transpose:\n");
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            printf("%d\t", mat[j][i]);
        }
        printf("\n");
    }

    // Zero matrix
    int zero = 1;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(mat[i][j] != 0){
                zero = 0;
            }
        }
    }

    if(zero == 1){
        printf("Zero Matrix / Null Matrix\n");
    }

    int identity = 1, diagonal = 1, scalar = 1;
    int skew = 1, symmetric = 1, upper = 1, lower = 1;
    int idempotent = 1, nilpotent = 1;

    if(row != col){
        identity = 0;
        diagonal = 0;
        scalar = 0;
        skew = 0;
        symmetric = 0;
        upper = 0;
        lower = 0;
        idempotent = 0;
        nilpotent = 0;
    }

    // Identity, diagonal, scalar, symmetric,
    // skew-symmetric, upper and lower triangular
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){

            if(i == j){
                if(mat[i][j] != 1){
                    identity = 0;
                }

                if(mat[i][j] != mat[0][0]){
                    scalar = 0;
                }
            }
            else{
                if(mat[i][j] != 0){
                    identity = 0;
                    diagonal = 0;
                    scalar = 0;
                }
            }

            if(row == col){
                if(mat[i][j] != mat[j][i]){
                    symmetric = 0;
                }

                if(mat[i][j] != -mat[j][i]){
                    skew = 0;
                }
            }

            if(i > j && mat[i][j] != 0){
                upper = 0;
            }

            if(i < j && mat[i][j] != 0){
                lower = 0;
            }
        }
    }

    // Idempotent
    if(row == col){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){

                int sum = 0;

                for(int k = 0; k < row; k++){
                    sum += mat[i][k] * mat[k][j];
                }

                if(sum != mat[i][j]){
                    idempotent = 0;
                }
            }
        }
    }

    if(idempotent == 1){
        printf("Idempotent Matrix\n");
    }

    // Nilpotent
    if(row == col){

        int power[5][5];
        int temp[5][5];

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                power[i][j] = mat[i][j];
            }
        }

        for(int p = 1; p < row; p++){

            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){

                    temp[i][j] = 0;

                    for(int k = 0; k < row; k++){
                        temp[i][j] += power[i][k] * mat[k][j];
                    }
                }
            }

            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    power[i][j] = temp[i][j];
                }
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(power[i][j] != 0){
                    nilpotent = 0;
                }
            }
        }
    }

    if(nilpotent == 1){
        printf("Nilpotent Matrix\n");
    }
    else{
        printf("Not Nilpotent Matrix\n");
    }

    // Determinant
    double det = 0;

    if(row == 1 && col == 1){
        det = mat[0][0];
    }

    if(row == 2 && col == 2){
        det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    if(row == 3 && col == 3){
        det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    }

    if((row == 4 && col == 4) || (row == 5 && col == 5)){

        double a[5][5];
        int swaps = 0;
        int singular = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                a[i][j] = mat[i][j];
            }
        }

        det = 1;

        for(int i = 0; i < row; i++){

            int k = i;

            while(k < row && a[k][i] == 0){
                k++;
            }

            if(k == row){
                singular = 1;
                det = 0;
                break;
            }

            if(k != i){
                for(int j = 0; j < col; j++){
                    double temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }

                swaps++;
            }

            det *= a[i][i];

            for(int j = i + 1; j < row; j++){

                double factor = a[j][i] / a[i][i];

                for(int k2 = i; k2 < col; k2++){
                    a[j][k2] -= factor * a[i][k2];
                }
            }
        }

        if(swaps % 2 != 0){
            det = -det;
        }

        if(singular == 1){
            det = 0;
        }
    }
    
    
    if(identity == 1){
		printf("Identity Matrix\n");
	}
	if(diagonal == 1){
		printf("Diagonal Matrix\n");
	}
	if(scalar == 1){
		printf("Scalar Matrix\n");
	}
	if(symmetric == 1){
		printf("Symmetric Matrix\n");
	}
	if(skew == 1){
		printf("Skew Symmetric Matrix\n");
	}
	if(upper == 1){
		printf("Upper Triangle Matrix\n");
	}
	if(lower == 1){
		printf("Lower Triangle Matrix\n");
	}	
    if(row == col){
    	printf("Determinant = %.0f\n", det);

    	if(det == 0){
        	printf("Singular Matrix\n");
    	}
    	else{
        	printf("Non-Singular Matrix\n");
    	}
	}
	


    // 2nd matrix to check equality
    int row2, col2;
    int equal = 1;

    printf("\nEnter rows of second matrix (1-5): ");
    scanf("%d", &row2);

    printf("Enter columns of second matrix (1-5): ");
    scanf("%d", &col2);

    if(row2 < 1 || row2 > 5 || col2 < 1 || col2 > 5){
        printf("Invalid second matrix size\n");
    }
    else{

        int mat2[5][5];

        for(int i = 0; i < row2; i++){
            for(int j = 0; j < col2; j++){
                printf("Enter second matrix element: ");
                scanf("%d", &mat2[i][j]);
            }
        }

        if(row != row2 || col != col2){
            equal = 0;
        }
        else{
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    if(mat[i][j] != mat2[i][j]){
                        equal = 0;
                    }
                }
            }
        }

        if(equal == 1){
            printf("Equal Matrices\n");
        }
        else{
            printf("Not Equal Matrices\n");
        }
    }

    return 0;
}

