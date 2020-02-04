//https://www.hackerrank.com/contests/smart-interviews/challenges/si-tree-traversals/submissions/code/1320137621


/*
Given an array of unique elements, construct a Binary Search Tree and print the PreOrder, InOrder and PostOrder Traversals of the tree.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= ar[i] <= 10000

Output Format

For each test case, print the PreOrder, InOrder and PostOrder Traversals of the Binary Search Tree, separate each traversal by newline. Separate the output of different test cases with an extra newline.

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
1 2 3 4 5
5 4 3 2 1

3 2 1 4 5
1 2 3 4 5
1 2 5 4 3

4 0 1 5 15 7 17
0 1 4 5 7 15 17
1 0 7 17 15 5 4


*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node * left;
    struct Node * right;
};

struct Node * newNode(int val){
    struct Node * obj = (struct Node *)malloc(sizeof(struct Node));
    obj->val = val;
    obj->left = NULL;
    obj->right = NULL;
    return obj;
}

struct Node * insert(struct Node * node, int val){
    struct Node * obj = newNode(val);
    if(node == NULL)
        return obj;
    struct Node * temp = node;
    struct Node * prev = node;
    while(temp != NULL){
        prev = temp;
        if (val > temp->val){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    if(val > prev->val)
        prev-> right = obj;
    else
        prev->left = obj;

    return node;
}

void preOrder(struct Node * root){
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node * root){
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}

void postOrder(struct Node * root){
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}

int main() {
    int t;
    scanf("%d", &t);

    int i = 0;
    for(i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        int * arr = (int *)malloc(sizeof(int)*n);
        int j = 0;
        struct Node * node = NULL;
        for(j = 0; j < n; j++){
            scanf("%d", &arr[j]);
            node = insert(node, arr[j]);
        }
        preOrder(node);
        printf("\n");
        inOrder(node);
        printf("\n");
        postOrder(node);
        printf("\n\n");
    }
    return 0;
}
