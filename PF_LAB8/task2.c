#include <stdio.h>
void swapValues(int *a, int *b);

int main() {
    int price1, price2;

    printf("Enter the first price: ");
    scanf("%d", &price1);

    printf("Enter the second price: ");
    scanf("%d", &price2);

    printf("Before swapping:\n");
    printf("Price 1 = %d\n", price1);
    printf("Price 2 = %d\n", price2);

    swapValues(&price1, &price2);

    printf("After swapping:\n");
    printf("Price 1 = %d\n", price1);
    printf("Price 2 = %d\n", price2);

    return 0;
}
void swapValues(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
