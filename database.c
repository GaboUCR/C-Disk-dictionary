#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "linkedList.h"
#include "Btree.h"

void insert(char keyToValue[]){

	FILE *file = fopen("Database","a");

	int key = makeKey(getKeyword(keyToValue));
	char keyString[11];
	sprintf(keyString,"%d", key);

	char * first = &keyToValue[0];
	int num = fseek(file,0,SEEK_END);

	fwrite(&keyString[0], 1, 10, file);
	fwrite(first, 1, 101, file);
	fclose(file);

}

l_node* makeListFromFile (char fileName[], int* numberOfElements){

	l_node* head = NULL;

	FILE *file = fopen(fileName,"r");
	int num = fseek(file, 0, SEEK_END);
	fpos_t end;
	fgetpos(file, &end);

	num = fseek(file ,0, SEEK_SET);
	fpos_t current;
	fgetpos(file ,&current);

	while (current != end){

		(*numberOfElements)++;
		int intKey;
		// char key[11];
		// char keyToValue[102];
		char* key = malloc(11);
		char* keyToValue = malloc(102);

		fread(&key[0],1,10,file);
		fread(&keyToValue[0],1,101,file);

		sscanf(key,"%d",&intKey);
		head = insertIntoList(intKey,keyToValue,head);

		fgetpos(file ,&current);

	}

	fclose(file);
	return head;
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
