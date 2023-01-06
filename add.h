#include<stdio.h>
#include<stdlib.h>
#include "node.h"
void add(node* ptr, char c) {
	node* newq = (node*)malloc(sizeof(node));
	node* newa = (node*)malloc(sizeof(node));

	printf("What was the animal you were thinking of?: ");

	scanf(" %[^\n]%*c" , newa->data);

	// gets(newa->data);
	printf("What question should I have asked?: ");
	scanf(" %[^\n]%*c" , newq->data);

	
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
