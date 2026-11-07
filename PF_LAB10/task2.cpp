#include <stdio.h>
#include <string.h>
int main(){
	
	char f_name[50];
	char l_name[50];
	
	printf("Enter your first name: ");
	fgets(f_name, sizeof(f_name), stdin);
	f_name[strcspn(f_name, "\n")] = '\0';

	printf("Enter your last name: ");
	fgets(l_name, sizeof(l_name), stdin);
	l_name[strcspn(l_name, "\n")] = '\0';

	char fullname[100];
	strcpy(fullname, f_name);
	strcat(fullname, " ");
	strcat(fullname, l_name);
	
	printf("\nFull Name: %s", fullname);
}

