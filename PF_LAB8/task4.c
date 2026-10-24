#include <stdio.h>

float averageSteps(int *steps, int n);
int countGoalDays(int *steps, int n, int goal);

int main() {
    int steps[7];
    float avg;
    int days;

    for (int i = 0; i < 7; i++) {
        printf("Enter steps for day %d: ", i + 1);
        scanf("%d", &steps[i]);
    }

    avg = averageSteps(steps, 7);
    days = countGoalDays(steps, 7, 8000);

    printf("Average steps: %.2f\n", avg);
    printf("Days goal reached (8000 or more): %d\n", days);

    return 0;
}

float averageSteps(int *steps, int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total = total + *(steps + i);
    }

    return (float) total / n;
}

int countGoalDays(int *steps, int n, int goal) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (*(steps + i) >= goal) {
            count++;
        }
    }

    return count;
}