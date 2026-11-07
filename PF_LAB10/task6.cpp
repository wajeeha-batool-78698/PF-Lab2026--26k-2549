#include <stdio.h>
#include <string.h>
int main() {
	
    char names[5][50];
    char temp[50]; 
    
    printf("Enter 5 student names:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d: ", i + 1);
        scanf("%s", names[i]); 
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
    
    printf("\nSorted Names:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }
    
    return 0;
}
