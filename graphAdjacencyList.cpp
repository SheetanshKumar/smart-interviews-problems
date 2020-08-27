/*
author: sheetansh
subject: graph adjancency list using linked list
*/

#include<iostream>
#include<conio.h>
#define N 8


struct Node{
	int data;
	struct Node * next;
};

void addEdge(struct Node ** arr, int a, int b)
{
	struct Node * ptr = new Node;
	ptr->data = b;
	ptr->next = NULL;

	if (arr[a] == NULL)
	{
		arr[a] = ptr;
	}
	else
	{
		struct Node * temp = arr[a];
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = ptr;
	}
}

void printGraph(struct Node ** arr)
{
	for (int i = 0; i < N; i++)
	{
		struct Node * temp = arr[i];
		printf("\nVertex %d ", i);
		while (temp)
		{
			printf("-> %d", temp->data);
			temp = temp->next;
		}
	}
}
int main()
{
	struct Node * adj[N] = { NULL };
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 4, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 7);
	addEdge(adj, 3, 8);
	addEdge(adj, 5, 4);
	addEdge(adj, 6, 7);
	addEdge(adj, 7, 8);

	printGraph(adj);
	_getch();
	return 0;
}