#include <stdio.h>
#include <stdlib.h>
#include "stringLib.h"

struct keys {struct keys* left; struct keys* right; int keyValue;};

int main(void){

	char lolo[] = "patito:quack";

	printf("keyword is: %s\n", getKeyword(lolo));

	printf("value is: %s\n", getValue(lolo));

	return 0;
}
