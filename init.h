#include "node.h"
#include <stdio.h>
#include <stdlib.h>
void initialize(node **head)
{
	node *n1 = (node*)malloc(sizeof(node));
	node *yes1 = (node*)malloc(sizeof(node));
	node *no1 = (node*)malloc(sizeof(node));

	n1->yes = yes1;
	n1->no = no1;
	n1->data = "Does it bark?";
	yes1->data = "Dog";
	no1->data = "Cat";
	yes1->yes = NULL;
	yes1->no = NULL;
	no1->yes = NULL;
	no1->no = NULL;
	*head = n1;
}