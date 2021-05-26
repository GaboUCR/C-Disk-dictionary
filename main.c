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
	// l_node* head = NULL;

	// insert("petrofsafef","perrgro");
	// insert("petrofsfef","perrgrdgo");
	// insert("petrothfth","perrdfgo");
	// insert("petrojydj","perrogg");
	// insert("petrogrgsrg","pegdrgrrro");

	// static char z [] = "podomeos";
	// static char p [] = "forcfafefes";
	// static char s [] = "forcoggddf";
	// static char g [] = "forcgnhtht";
	// static char h [] = "forcvewdgr";
	// //
	// head = insertIntoList(p,"finca", head);
	// head = insertIntoList(s,"finca", head);
	// head = insertIntoList(z,"finca", head);
	// head = insertIntoList(g,"finca", head);
	// head = insertIntoList(h,"finca", head);

	// printList(l);
	// printf("\n");
	node* t = listToTree(head, num);
	printTree(t);

	return 0;
}
