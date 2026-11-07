#include <stdio.h>
#include <string.h>
int main(){
	
	char password[50];
	printf("Enter your password: ");
	fgets(password, sizeof(password), stdin);
	password[strcspn(password, "\n")] = '\0';
	
	char correct[50] = "lab10pass";
	
	if (strcmp(password, correct) == 0){
		printf("Secure Password");
	}
	else {
		printf("Password not secure");
	}
}
