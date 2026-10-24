#include <stdio.h>

void printGrid(int (*grid)[5]);
int countNeighbours(int (*grid)[5], int row, int col);
void nextGeneration(int (*grid)[5]);

int main() {
    int grid[5][5] = {0};
    int generations;

    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;

    do {
        printf("Enter number of generations (0-50): ");
        scanf("%d", &generations);

        if (generations < 0 || generations > 50) {
            printf("Invalid number\n");
        }
    } while (generations < 0 || generations > 50);

    printf("Generation 0:\n");
    printGrid(grid);

    for (int i = 1; i <= generations; i++) {
        nextGeneration(grid);

        printf("Generation %d:\n", i);
        printGrid(grid);
    }

    return 0;
}

void printGrid(int (*grid)[5]) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }
}

int countNeighbours(int (*grid)[5], int row, int col) {
    int count = 0;

    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = col - 1; c <= col + 1; c++) {
            if (r >= 0 && r < 5 && c >= 0 && c < 5) {
                if (r != row || c != col) {
                    if (grid[r][c] & 1) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

void nextGeneration(int (*grid)[5]) {
    int neighbours;

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            neighbours = countNeighbours(grid, r, c);

            if (grid[r][c] & 1) {
                if (neighbours == 2 || neighbours == 3) {
                    grid[r][c] |= 2;
                }
            } else {
                if (neighbours == 3) {
                    grid[r][c] |= 2;
                }
            }
        }
    }

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            grid[r][c] >>= 1;
        }
    }
}
