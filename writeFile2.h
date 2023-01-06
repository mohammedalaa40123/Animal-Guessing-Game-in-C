#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
struct node1
{
    struct node *content;
    struct node *next;
};
typedef struct node node;
typedef struct node1 fifo;
fifo *front = NULL;
fifo *rear = NULL;
void enque(node *data)
{
    struct node1 *newnode = (struct node1 *)malloc(sizeof(struct node1));
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
node *deque()
{
    struct node1 *temp = front;
    node *data = temp->content;
    if (front == NULL)
        return;
    if (front == rear)
        front = rear = NULL;
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
int isempty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void writeFile(node *head)
{
    FILE *Ptr;
    fopen_s(&Ptr, "animal.txt", "w");

    enque(head);
    // node *n = (node *)malloc(sizeof(node));

    while (!isempty())
    {
        if (front->content == NULL)
            fputs("NULL\n", Ptr);
        else
        {
            fputs(front->content->data, Ptr);
            fputc('\n', Ptr);
        }
        if ((front->content->yes != NULL))
        {
            enque(front->content->yes);
        }
        if ((front->content->no != NULL))
        {
            enque(front->content->no);
        }

        deque();
    }
}

// int main()
// {

// 	node* head = malloc(sizeof(node));

// 	strcpy_s(head->data, 100, "Does it bark?");

// 	node* dog = malloc(sizeof(node));
// 	strcpy_s(dog->data, 100, "Dog");

// 	node* cat = malloc(sizeof(node));
// 	strcpy_s(cat->data, 100, "cat");

// 	head->yes = dog;
// 	head->no = cat;
// 	cat->yes = NULL;
// 	cat->no = NULL;
// 	dog->yes = NULL;
// 	dog->no = NULL;
// 	writeFile(head);
// }