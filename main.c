#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
#include "node.h"
#include "init.h"
#include "read.h"
#include "add.h"
#include "writefile.h"

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
        printf("\x1b[2J\x1b[1;1H");
        fflush(stdin);
        printf("-------------------------------\n");
        printf("Welcome To Animal Guessing Game\n");
        printf("-------------------------------\n");
        printf("         .--.             .---.\n        /:.  '.         .' ..  '._.---.\n       /:::-.  \\.-\"\"\"-;` .-:::.     .::\\\n      /::'|  `\\/  _ _  \'   `\\:'   ::::|\n  __.'    |   /  (o|o)  \\     `'.   ':/\n /    .:. /   |   ___   |        '---'\n|    ::::'   /:  (._.) .:\\\n\\    .='    |:'        :::|\n `\"\"`       \\     .-.   ':/\n             '---`|I|`---'\n                  '-'\n\n");

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