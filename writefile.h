#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"node.h"

struct node1 {
	struct node* content;
	struct node1* next;
};
typedef struct node1 node1;
node1* front = NULL;
node1* rear = NULL;
void enque(node*data)
{
	node1* newnode = (node1*)malloc(sizeof(node1*));
	newnode->content = data;
	newnode->next = NULL;
	if (front == NULL && rear == NULL)
	{
		front = rear = newnode;
		return;
	}
	rear->next = newnode;
	rear = newnode;
}
node* deque()
{
	node1* temp = front;
	node* data = temp->content;
	if (front == NULL) return NULL;
	if (front == rear) front = rear = NULL;
	else
	{
		front = front->next;
	}
    
	free(temp);
	return data;
}

int isempty() {
	if (front == NULL)
		return 1;
	else return 0;
}

void writeFile(node* head) {
	FILE* Ptr;
	fopen_s(&Ptr, "animal.txt", "w");
	
	enque(head);

	while ( front != NULL) {	
		if (front->content->data!=NULL) {
            fprintf(Ptr,"%s\n",front->content->data);
			enque( front->content->yes);
			enque( front->content->no);
			}
        else{
            fprintf(Ptr,"%s\n","NULL");
        }    
		deque();	
	}
    fclose(Ptr);
}