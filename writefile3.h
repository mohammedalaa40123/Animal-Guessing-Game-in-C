#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include <string.h>
#include "node.h"
typedef struct node map;
struct qnode
{
	struct node *address;
	struct qnode *next;
};
struct qnode *qfront = NULL;
struct qnode *qrear = NULL;
void eneque(map *addresses)
{
	struct qnode *q1;
	q1 = (struct qnode *)malloc(sizeof(struct qnode));
	q1->address = addresses;
	q1->next = NULL;
	if ((qfront == NULL) || (qrear == NULL))
	{
		qfront = qrear = q1;
	}
	else
	{
		struct qnode *temp = qrear;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = q1;
	}
}
void pop(struct qnode **q)
{
	*q = (*q)->next;
}
void Insert_Null_Node()
{
	map *Null;
	Null = (map *)malloc(sizeof(map));
	strcpy_s(Null->data, 100, "NULL\n");
	Null->yes = NULL;
	Null->no = NULL;
	eneque(Null);
}
void write_File()
{
	FILE *Ptr = NULL;
	fopen_s(&Ptr, "animal.txt", "w");
	while (qfront != NULL && qfront->address != NULL )
	{
		// printf("%s\n",qfront->address->data);
		fputs(qfront->address->data, Ptr);
		if (strcmp(qfront->address->data, "NULL\n") != 0)
		{
			if (qfront->address->yes == NULL && qfront->address->no == NULL)
			{
				Insert_Null_Node();
				Insert_Null_Node();
			}
			else
			{
				eneque(qfront->address->yes);
				eneque(qfront->address->no);
			}
		}
		pop(&qfront);
	}
	fclose(Ptr);
}
void writeFile(map *A)
{
	eneque(A);
	write_File();
}
