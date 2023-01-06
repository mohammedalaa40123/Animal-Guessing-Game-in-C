#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"node.h"
struct node1 {
	struct node* content;
	struct node1* next;
};
typedef struct node node;
typedef struct node1 node1;
node1* front = NULL;
node1* rear = NULL;
void enque(node* data)
{
	struct node1* newnode = (struct node1*)malloc(sizeof(struct node1));
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
	struct node1* temp = front;
	node* data = temp->content;
	if (front == NULL) return;
	if (front == rear) front = rear = NULL;
	else
	{
		front = front->next;
	}
	free(temp);
	return data;
}
// void printQueue()
// {
// 	struct node1* temp = front;
// 	while (temp != NULL)
// 	{
// 		printf("%d\t", temp->content);
// 		temp = temp->next;
// 	}
// }
int isempty() {
	if (front == NULL)
		return 1;
	else return 0;
}

void writeFile(node* head) {
	FILE* Ptr;
	errno_t error_code;
	error_code = fopen_s(&Ptr, "animal.txt", "w");
	if (error_code != 0)
	{
		printf("Error! Failed to open file in w mode!");
		return -1;
	}
    else{
	enque(head);

	while (!isempty()) {

		if (front->content->data[0]) {
			fprintf(Ptr, "%s\n", front->content->data);
			enque(front->content->yes);
			enque(front->content->no);

		}
		else fprintf(Ptr, "%s\n", "NULL");
		
		deque();

	}

	fclose(Ptr);
    }

}