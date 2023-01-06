#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"
node *readFile()
{
	errno_t error_code;
	FILE *Ptr;
	char item[100];
	node *head;
	node *arr1[100];
	node *arr2[100];
	error_code = fopen_s(&Ptr, "animal.txt", "r+");
	if (error_code != 0)
	{
		printf("Error! Failed to open file in r mode!");
		return -1;
	}
	else
	{
		fgets(item, 100, Ptr);
		arr1[0] = (node *)malloc(sizeof(node *));
		strcpy_s(arr1[0]->data, 100, item);
		head = arr1[0];
		int n = 1;
		int a = 0;
		int nullcount = 1;
		while (nullcount >= 1)
		{
			int c = 0;
			for (int i = c; i < n * 2; i++)
			{
				fgets(item, 100, Ptr);
				a++;
				fflush(stdin);
				if (strcmp(item, "NULL\n") == 0)
				{
					arr2[i] = NULL;

					nullcount++;
				}
				else
				{
					arr2[i] = (node *)malloc(sizeof(node *));
					strcpy_s(arr2[i]->data, 100, item);
				}
			}
			for (int i = c; i < n; i++)
			{
				arr1[i]->yes = arr2[2 * i];
				arr1[i]->no = arr2[(2 * i) + 1];
				c++;
			}
			int k = n;
			n = 0;

			for (int i = 0; i < k * 2; i++)
			{
				if (arr2[i] != NULL)
				{
					arr1[n] = arr2[i];
					n++;
				}
			}
			if (nullcount > n + 1)
				break;
			//
		}
		fclose(Ptr);
		// remove("animal.txt");
		return head;
	}
}
