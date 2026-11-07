#include <stdio.h>
#include <string.h>
int main(){
	
	char sentence[150];
	printf("Enter a sentence: ");
	fgets(sentence, sizeof(sentence), stdin);
	sentence[strcspn(sentence, "\n")] = '\0';
	
	char ch = 'a';
	char *ptr = strchr(sentence, ch);
	if(ptr != NULL){
		int index = ptr- sentence;
		printf("Character %c found at index %d\n", ch, index);
	}
	else{
		printf("Character not found");
	}
	
	char word[] = "good";
	if(strstr(sentence, word) != NULL){
		printf("the word \"good\" found\n");
    }
	else{
		printf("Word not found");
	}
}
