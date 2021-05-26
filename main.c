#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include <string.h>
#include "Btree.h"
#include <time.h>
#include "linkedList.h"

int main(void){


	int num = 0;
	l_node* head = makeListFromFile("Database", &num);


	while (1){


		printList(head);
		printf("\n");

		char input[30] = "";
		printf(">>");
		fgets(input, 30, stdin);
		char* p = strtok(input, " ");
		char *array[3];
		int i = 0;

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, " ");
    }


		if (strcmp(array[0],"set") == 0){
			insert(array[1], array[2]);
			head = insertIntoList(array[1], array[2], head);
		}

		if (strcmp(array[0],"get") == 0){
			getValue(array[1], head);
		}

}

	return 0;
}
