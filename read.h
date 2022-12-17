#include <stdio.h>
#include <stdlib.h>

#include "node.h"

node* read(node* ptr) {
	
	node* re = ptr;
	char c;
	while (ptr->yes != NULL) {
		printf("%s",ptr->data);
		scanf_s(" %c", &c);
		re = ptr;
		if (c == 'y' || c == 'Y')
			ptr = ptr->yes;
		else ptr = ptr->no;


	}
	printf("%s\n", ptr->data);
	return re;
}
