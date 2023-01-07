#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
typedef struct node map;
struct qnode
{
	struct node *address;
	struct qnode *next;
};
struct qnode *qfront;
struct qnode *qrear;
void eneque(map *addresses)
{
	struct qnode* q1;
	q1 = (struct qnode*)malloc(sizeof(struct qnode));
	q1->address = addresses;
	q1->next = NULL;
	if ((qfront == NULL) && (qrear == NULL))
	{
		qfront = qrear = q1;
	}
	else
	{
		struct qnode* temp = qrear;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = q1;
	}
}
void pop(struct qnode** q)
{
	*q = (*q)->next;
}
void  Insert_Null_Node()
{
	map* Null;
	Null = (map*)malloc(sizeof(map));
	strcpy_s(Null->data,100,"NULL\n");
	Null->yes = NULL;
	Null->no = NULL;
	eneque(Null);
}
void write_File()
{
	FILE* Ptr;
	fopen_s(&Ptr, "animal.txt", "w");
	while (qfront != NULL && qfront->address != NULL)
	{
		fprintf(Ptr, "%s\n",qfront->address->data);
		if(strcmp(qfront->address->data,"NULL\n") != 0)
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
}void writeFile(map *A)
{
	eneque(A);
	write_File();
}

// Call Initiate Function to start writing ( Initiate (head of the map))
// Exp :- Initiate(head
