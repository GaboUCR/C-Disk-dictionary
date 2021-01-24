#include <stdio.h>
#include <stdlib.h>
#include "stringLib.h"

struct keys {struct keys* left; struct keys* right; int keyValue;};

int main(void){
	char lolo[] = "patito:quackmistepp";

	printf("%s\n", getKeyword(lolo));

	return 0;
}
