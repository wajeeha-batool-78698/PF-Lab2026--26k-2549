#include <stdio.h>

int deposit(float *balance, float amount);
int withdraw(float *balance, float amount);

int main() {
    float balance = 2000;
    float amount;
    int choice, result;

    do {
        printf("\n1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                result = deposit(&balance, amount);

                if (result == 1) {
                    printf("Deposit successful\n");
                } else {
                    printf("Invalid amount\n");
                }
                break;

            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                result = withdraw(&balance, amount);

                if (result == 1) {
                    printf("Withdrawal successful\n");
                } else {
                    printf("Invalid amount or insufficient balance\n");
                }
                break;

            case 3:
                printf("Balance = %.2f\n", balance);
                break;

            case 4:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid option\n");
        }

    } while (choice != 4);

    return 0;
}

int deposit(float *balance, float amount) {
    if (amount <= 0) {
        return 0;
    }

    *balance = *balance + amount;
    return 1;
}

int withdraw(float *balance, float amount) {
    if (amount <= 0 || amount > *balance) {
        return 0;
    }

    *balance = *balance - amount;
    return 1;
}
