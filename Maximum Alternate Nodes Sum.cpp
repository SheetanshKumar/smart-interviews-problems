/*
https://www.hackerrank.com/contests/smart-interviews/challenges/si-maximum-alternate-nodes-sum/copy-from/1322470300
Given an array of unique elements, construct a Binary Search Tree and find the maximum sum of nodes, with the constraint that if you select a node, you cannot select any of its immediate child nodes.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Constraints

1 <= T <= 1000
1 <= N <= 1000
-10000 <= ar[i] <= 10000

Output Format

For each test case, print the maximum sum, separated by newline.

Sample Input 0

5
5
1 2 3 4 5
7
4 5 15 0 1 7 17
5
4 1 3 5 2
9
6472 -3661 -2660 5275 3009 1733 5234 4191 6812
12
8827 93 1794 -6354 -2386 -2985 1460 7095 8778 4958 52 5284

Sample Output 0

9
30
8
19054
24735

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

pair<int, int> getMax(struct Node * root){
    if(root == NULL ){
        pair<int, int> sum(0,0);
        return sum;
    }
    pair<int, int> suml = getMax(root->left);
    pair<int, int> sumr = getMax(root->right);
    pair<int, int> sum;

    sum.first = suml.second + sumr.second + root->val;

    sum.second = max(suml.first, suml.second) + max(sumr.first, sumr.second);
    return sum;
}

int getMaxSum(struct Node * root){
    if (root == NULL)
        return 0;

    pair<int, int> sum = getMax(root);
    return max(sum.first, sum.second);
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
        printf("%d\n", getMaxSum(node));
    }
    return 0;
}
