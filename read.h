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
		else ptr = ptr->no;


	}
	printf("%s\n", ptr->data);
	return re;
}
