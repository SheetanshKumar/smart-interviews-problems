/*
https://www.hackerrank.com/contests/smart-interviews/challenges/si-zig-zag-level-order-of-tree/copy-from/1322472475
Given an array of unique elements, construct a Binary Search Tree and print the Level Order of the tree in a zig-zag fashion. Assume root is at level-1, zig-zag means that nodes at even levels will be printed left to right and the nodes at odd levels will be printed from right to left.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= ar[i] <= 10000

Output Format

For each test case, print the Level Order Traversal of the Binary Search Tree in zig-zag fashion, separated by newline.

Sample Input 0

3
5
1 2 3 4 5
5
3 2 4 1 5
7
4 5 15 0 1 7 17

Sample Output 0

1 2 3 4 5
3 2 4 5 1
4 0 5 15 1 7 17

*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
	int val;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int val) {
	struct Node* obj = (struct Node*)malloc(sizeof(struct Node));
	obj->val = val;
	obj->left = NULL;
	obj->right = NULL;
	return obj;
}

struct Node* insert(struct Node* node, int val) {
	struct Node* obj = newNode(val);
	if (node == NULL)
		return obj;
	struct Node* temp = node;
	struct Node* prev = node;
	while (temp != NULL) {
		prev = temp;
		if (val > temp->val) {
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	if (val > prev->val)
		prev->right = obj;
	else
		prev->left = obj;

	return node;
}

void reverseQueue(queue<struct Node*>& Queue)
{
	stack<struct Node*> Stack;
	while (!Queue.empty()) {
		Stack.push(Queue.front());
		Queue.pop();
	}
	while (!Stack.empty()) {
		Queue.push(Stack.top());
		Stack.pop();
	}
}

void printLevel(struct Node* root) {
	if (root == NULL)
		return;
	queue<struct Node*> q;
	q.push(root);
	bool isodd = true;
	while (!q.empty()) {
		int qsize = q.size(); // calculating earlier because if used in for loop directly the value
		if (isodd) {        // changes dynamically.
			reverseQueue(q);
			for (int i = 0; i < qsize; i++) {
				struct Node* temp = q.front();
				q.pop();
				cout << temp->val << " ";
				if (temp->right)
					q.push(temp->right);
				if (temp->left)
					q.push(temp->left);
			}
			isodd = false;
			reverseQueue(q);
		}
		else {
			for (int i = 0; i < qsize; i++) {
				struct Node* temp = q.front();
				q.pop();
				cout << temp->val << " ";
				if (temp->left)
					q.push(temp->left);
				if (temp->right)
					q.push(temp->right);
			}
			isodd = true;
		}
	}
}

int main() {
	int t;
	scanf_s("%d", &t);

	int i = 0;
	for (i = 0; i < t; i++) {
		int n;
		scanf_s("%d", &n);
		int* arr = (int*)malloc(sizeof(int) * n);
		int j = 0;
		struct Node* node = NULL;
		for (j = 0; j < n; j++) {
			scanf_s("%d", &arr[j]);
			node = insert(node, arr[j]);
		}
		printLevel(node);
		printf("\n");
	}
	return 0;
}
