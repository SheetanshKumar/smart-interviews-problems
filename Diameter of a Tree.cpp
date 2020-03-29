/*
https://www.hackerrank.com/contests/smart-interviews/challenges/si-diameter-of-a-tree/copy-from/1322262047
Given an array of unique elements, construct a Binary Search Tree and find the diameter of the tree. Diameter is defined as the number of nodes on the longest path between 2 nodes of the tree.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Constraints

1 <= T <= 1000
1 <= N <= 5000
0 <= ar[i] <= 10000

Output Format

For each test case, print the diameter of the Binary Search Tree, separated by newline.

Sample Input 0

3
5
1 2 3 4 5
5
2 4 3 1 5
7
4 5 15 0 1 7 17

Sample Output 0

5
4
6

*/

#include <bits/stdc++.h>
#include <algorithm>

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

struct Node * insert(struct Node * &node, int val){
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

int maxA(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int getHeight(struct Node * &root, int &ans){

    if (root == NULL)
        return 0;
    int left = getHeight(root->left, ans);
    int right = getHeight(root->right, ans);
    ans = maxA(ans, 1 + left+right);

    return (1 + maxA(left, right)) ;
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
        int ans = 0;
        getHeight(node, ans);
        printf("%d\n", ans);
    }
    return 0;
}
