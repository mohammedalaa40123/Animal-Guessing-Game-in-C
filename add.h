#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
void add(node *ptr, char c)
{
	node *newq = (node *)malloc(sizeof(node));
	node *newa = (node *)malloc(sizeof(node));

	printf("What was the animal you were thinking of?: ");

	gets(newa->data);
	fflush(stdin);
	strcat(newa->data, "\n");

	// gets(newa->data);
	printf("What question should I have asked?: ");
	gets(newq->data);
	fflush(stdin);
	strcat(newq->data, "\n");

	// strcpy_s(newq->data,100, a);
	newq->yes = newa;
	newa->yes = NULL;
	newa->no = NULL;
	ptr->no->yes = NULL;
	ptr->no->no = NULL;

	if (c == 'y' || c == 'Y')
	{
		newq->no = ptr->yes;
		ptr->yes->yes = NULL;
		ptr->yes->no = NULL;
		ptr->yes = newq;
	}

	else
	{
		newq->no = ptr->no;
		ptr->no->yes = NULL;
		ptr->no->no = NULL;
		ptr->no = newq;
	}
}
