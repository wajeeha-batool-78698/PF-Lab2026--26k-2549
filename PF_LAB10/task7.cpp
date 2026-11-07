#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	
    char name[50];
    
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    
    printf("Enter 3 student names:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%s", name);
        fprintf(file, "%s\n", name);
    }
    
    fclose(file);
    
    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    
    printf("\nNames read from students.txt:\n");
    int count = 0;
    
    while (fgets(name, sizeof(name), file) != NULL) {
        name[strcspn(name, "\n")] = '\0';
        count++;
        printf("%d. %s\n", count, name);
    }
    
    fclose(file);
    
    printf("Total students in file: %d\n", count);
    
    return 0;
}
