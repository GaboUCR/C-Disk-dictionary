#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringLib.h"


char* getKeyword(char keyToValue[]) {

	int length = strlen(keyToValue);
	static char keyword[51] = "";
	int start = 0;
	//printf("%d\n", length);
	// printf("%s\n", keyword);

	for (int i=0; i<length; i++){

		//58 is : in ascii
		if (keyToValue[i] == 58){
			i++;
			start = i;
			break;
		}
	}
	int keyToValueIndex = start;

	for (int j = 0; j < length - start; j++){
		*(&keyword[j]) = keyToValue[keyToValueIndex];
		keyToValueIndex++;
	}

	return keyword;
}
