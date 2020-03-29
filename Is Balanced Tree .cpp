/*
https://www.hackerrank.com/contests/smart-interviews/challenges/si-is-balanced-tree/copy-from/1322085295
Given an array of unique elements, construct a Binary Search Tree and check if its balanced. A tree is said to be balanced if for every node, the difference between the height of its child nodes is not greater than 1.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= ar[i] <= 10000

Output Format

For each test case, print "Yes" if the Binary Search Tree is balanced, "No" otherwise, separated by newline.

Sample Input 0

3
5
1 2 3 4 5
5
3 2 4 1 5
7
4 5 15 0 1 7 17

Sample Output 0

No
Yes
No

Explanation 0

Self Explanatory*/


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

int getHeight(struct Node * root){

    if (root == NULL)
        return 0;

    int left = 1 + getHeight(root->left);
    int right = 1 + getHeight(root->right);
    return (left > right ? left:right);
}

bool isBalancedTree(struct Node * root){

    if(root == NULL)
        return true;
    int lh;
    int rh;

    lh = getHeight(root->left);
    rh = getHeight(root->right);

    if(abs(lh-rh)<=1 && isBalancedTree(root->left) && isBalancedTree(root->right))
       return true;
    return false;
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
        if(isBalancedTree(node))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
