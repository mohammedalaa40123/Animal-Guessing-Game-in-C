#include<stdio.h>
#include<stdlib.h>
#include "node.h"
void add(node* ptr, char c) {
	node* newq = (node*)malloc(sizeof(node));
	node* newa = (node*)malloc(sizeof(node));

	printf("What was the animal you were thinking of?: ");
	gets(newa->data);
	fflush(stdin);

	// gets(newa->data);
	printf("What question should I have asked?: ");
	gets(newq->data);
	fflush(stdin);
	//strcpy_s(newq->data,100, a);
	newq->yes = newa;
	newa->yes = NULL;
	newa->no = NULL;

	if (c == 'y' || c == 'Y') {
		newq->no = ptr->yes;
		ptr->yes = newq;
	}


	else {
		newq->no = ptr->no;
		ptr->no = newq;
	}

}
