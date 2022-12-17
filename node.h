#ifndef NODE_H
#define NODE_H  
struct node {
	char *data;
	struct node* yes;
	struct node* no;
};
typedef struct node node;
#endif