#include <stdio.h>
#include <string.h>
int main(){
	
	char name[50];
	printf("Enter your name: ");
	fgets(name, sizeof(name), stdin);
	
	// to remove the nulll charcter:
	name[strcspn(name, "\n")] = '\0';
	
	int len = strlen(name);
	printf("\nThe string length is: %d", len);
	
	int size = sizeof(name);
	printf("\nThe string size is: %d", size);

	char copy[50];
	strcpy(copy, name);
	
	printf("\nCopied Name: %s", copy);
	
}
