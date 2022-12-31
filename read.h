#include <stdio.h>
#include <stdlib.h>

#include "node.h"

node* read(node* ptr, char* c) {

	node* re = ptr;

	while (ptr->yes != NULL) {
		printf("%s", ptr->data);
		scanf_s(" %c", c);
		fflush(stdin);
		re = ptr;
		if (*c == 'y' || *c == 'Y')
			ptr = ptr->yes;
		else if (*c == 'n' || *c == 'N')
			ptr = ptr->no;
		else
			printf("You have entered an invalid input, please try again (y/n)\n");

	}
	printf("%s\n", ptr->data);
	return re;
}
