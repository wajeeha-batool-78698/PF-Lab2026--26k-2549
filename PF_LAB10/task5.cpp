#include <stdio.h>
#include <string.h>
int main(){
	
	char cities[5][30];
	printf("Enter 5 city names:\n");

	for(int i = 0; i<5; i++){
		fgets(cities[i], sizeof(cities[i]), stdin);
		cities[i][strcspn(cities[i], "\n")] = '\0';
	}
	
	printf("All city names:\n");
	for(int i = 0; i<5; i++){
		printf("%d. %s\n", i+1, cities[i]);
	}
	
	int longest = 0;
	int max = strlen(cities[0]);
	
	for(int i =0; i<5; i++ ){
		int current = strlen(cities[i]);
		if(current > max){
			max = strlen(cities[i]);
			longest = i;
		}
	}
	
	printf("The longest city name is: %s\nLength : %d", cities[longest], max);
}
