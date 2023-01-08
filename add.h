#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "node.h"
void add(node *ptr, char c)
{
	node *newq = (node *)malloc(sizeof(node*));
	node *newa = (node *)malloc(sizeof(node*));
	printf("What was the animal you were thinking of?: ");
	gets(newa->data);
	fflush(stdin);
	strcat(newa->data, "\n");

	printf("What question should I have asked?: ");
	gets(newq->data);
	fflush(stdin);
	strcat(newq->data, "\n");

	newq->yes = newa;
	newa->yes = NULL;
	newa->no = NULL;

	if (c == 'y' || c == 'Y')
	{
		newq->no = ptr->yes;
		ptr->yes = newq;
	}

	else
	{
		newq->no = ptr->no;
		ptr->no = newq;
	}
	while (ptr->no != NULL)
	{
		if (strcmp(ptr->no->data, "Cat\n") == 0||strcmp(ptr->no->data, "horse\n") == 0)
		{
			ptr->no->yes = NULL;
			ptr->no->no = NULL;
		}
		ptr = ptr->no;
	}
}
