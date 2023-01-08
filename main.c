#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "node.h"
#include "init.h"
#include "read.h"
#include "add.h"
#include "writefile3.h"

int main()
{

    node *head = NULL;
    initialize(&head);
    char c = 'a';
    char comp = 'y';
    char guess = 'a';
    node *re;
    while (comp == 'Y' || comp == 'y')
    {

        fflush(stdin);
        re = read(head, &c);
        printf("Did I guess correctly? (y/n): ");
        scanf_s(" %c", &guess);
        fflush(stdin);
        while (guess != 'Y' && guess != 'y' && guess != 'n' && guess != 'N')
        {
            printf("Invalid Input\nDid I guess correctly? (y/n): ");
            scanf_s(" %c", &guess);
            fflush(stdin);
        }
        if (guess == 'n' || guess == 'N')
        {
            add(re, c);
            writeFile(head);
        }
        printf("Would you like to play again? (y/n): ");
        scanf_s(" %c", &comp);
        fflush(stdin);
        while (comp != 'Y' && comp != 'y' && comp != 'n' && comp != 'N')
        {
            printf("Invalid Input\nWould you like to play again? (y/n): ");
            scanf_s(" %c", &comp);
            fflush(stdin);
        }
    }

    return 0;
}