#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "init.h"
#include "read.h"

int main()
{
    node *head = NULL;
    initialize(&head);
    node* re = read(head);


    return 0;
}