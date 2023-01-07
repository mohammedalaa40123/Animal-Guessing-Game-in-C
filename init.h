#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include "readFile2.h"
void initialize(node **head)
{
	if (readFile() != -1)
		*head = readFile();
	else
	{
		node *n1 = (node *)malloc(sizeof(node));
		node *yes1 = (node *)malloc(sizeof(node));
		node *no1 = (node *)malloc(sizeof(node));

		n1->yes = yes1;
		n1->no = no1;
		strcpy_s(n1->data, 100, "Does it bark?\n");
		strcpy_s(yes1->data, 100, "Dog\n");
		strcpy_s(no1->data, 100, "Cat\n");
		yes1->yes = NULL;
		yes1->no = NULL;
		no1->yes = NULL;
		no1->no = NULL;
		*head = n1;
	}
}
