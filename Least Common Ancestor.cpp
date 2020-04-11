/*
https://www.hackerrank.com/contests/smart-interviews/challenges/si-least-common-ancestor/copy-from/1322622883
Given an array of unique elements, construct a Binary Search Tree. Now, given two nodes u and v of the BST, find their Lowest Common Ancestor (LCA). LCA is defined as the furthest node from the root that is an ancestor for both u and v.

Input Format

First line of input contains T - number of test cases. First line of each test case contains N, Q - number of nodes in the BST and the number of queries. The next line contains N unique integers - value of the nodes. Its followed by Q lines, each contains 2 nodes of the tree, u and v.

Constraints

1 <= T <= 1000
1 <= N,Q <= 1000
0 <= ar[i] <= 10000

Output Format

For each test case, for each query print the LCA of the given nodes u and v, separated by space. Separate the output of different test cases with a newline.

Sample Input 0

2
5 2
3 2 4 1 5
2 5
1 2
7 3
4 5 15 0 1 7 17
0 15
7 17
17 4

Sample Output 0

3 2
4 15 4

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

struct Node * lca(struct Node * root, int u, int v){
    if(root == NULL || root->val ==  u || root->val == v)
        return root;

    struct Node * left = lca(root->left, u, v);
    struct Node * right = lca(root->right, u, v);

    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    return root;
}

int main() {
    int t;
    scanf("%d", &t);

    int i = 0;
    for(i = 0; i < t; i++){
        int n, q;
        scanf("%d", &n);
        scanf("%d", &q);
        int * arr = (int *)malloc(sizeof(int)*n);
        int j = 0;
        struct Node * node = NULL;
        for(j = 0; j < n; j++){
            scanf("%d", &arr[j]);
            node = insert(node, arr[j]);
        }
        for(j = 0; j < q; j++){
            int u, v;
            scanf("%d", &u);
            scanf("%d", &v);
            printf("%d ", lca(node, u, v)->val);
        }
        printf("\n");
    }
    return 0;
}
