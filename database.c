#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

void insert(char keyToValue[]){
	FILE *file = fopen("Database","w");
	char * first = &keyToValue[0];

	fwrite(first,1,strlen(keyToValue),file);
	fclose(file);

}

void readEverything(void){
	FILE *file = fopen("Database","r");
	char content[200] = "";
	char * first = &content[0];
	
	fread(first,1,100,file);
	fclose(file);
	printf("%s\n", content);
}

char* getValue(char keyToValue[]) {

	int length = strlen(keyToValue);
	static char value[51] = "";
	int start = 0;
	//printf("%d\n", length);
	// printf("%s\n", value);

	for (int i=0; i<length; i++){

		//58 is : in ascii
		if (keyToValue[i] == 58){
			i++;
			start = i;
			break;
		}
	}
	int keyToValueIndex = start;

	if(length-start >= 50){
		return "";
	}

	for (int j = 0; j < length - start; j++){
		*(&value[j]) = keyToValue[keyToValueIndex];
		keyToValueIndex++;
	}

	return value;
}

char* getKeyword(char keyToValue[]) {

	int length = strlen(keyToValue);
	static char keyword[51] = "";

	for (int i=0; i<length; i++){

		//58 is : in ascii
		if (keyToValue[i] == 58){
			break;
		}
		//the keyword can only be 50 characters long
		if (i == 50){

			return "";
		}

		*(&keyword[i]) = keyToValue[i];
	}

	return keyword;
}
