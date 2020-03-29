/*
https://www.hackerrank.com/contests/smart-interviews/challenges/si-left-view-of-tree/copy-from/1322086057

Given an array of unique elements, construct a Binary Search Tree and print the left-view of the tree. Left view of a Tree is the set of nodes visible when tree is viewed from left side.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= ar[i] <= 10000

Output Format

For each test case, print the left-view of the Binary Search Tree, separated by newline.

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
3 2 1
4 0 1 7

Explanation 0

Self Explanatory
*/


#include <bits/stdc++.h>
using namespace std;

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

void printLeftView(struct Node * root){

    queue<struct Node *> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for (int i = 0; i < n; i++){
            struct Node * temp = q.front();
            q.pop();
            if(i == 0)
                printf("%d ", temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
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
        printLeftView(node);
        printf("\n");
    }
    return 0;
}
