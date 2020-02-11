/*
https://www.hackerrank.com/contests/smart-interviews/challenges/si-sum-of-numbers-from-root-to-leaf-paths/copy-from/1320616668
Given an array of unique elements, construct a Binary Search Tree and print the sum of all the numbers formed along the path from the root node to the leaf nodes.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= ar[i] <= 10000

Output Format

For each test case, print the sum, separate each traversal by newline. Since the output can be very large, print output % 1000000007.

Sample Input 0

3
5
1 2 3 4 5
5
3 2 4 1 5
7
4 5 15 2 1 7 17

Sample Output 0

12345
666
497095

Explanation 0

Test Case 1
Total Sum = 12345

Test Case 2
Total Sum = 321 + 345 = 666

Test Case 3
Total Sum = 421 + 45157 + 451517 = 497095 */

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

long long int getNumberOfDigits(int num){
    long long int res = 10;
    while(num/10 != 0){
        res*=10;
        num=num/10;
    }
    return res;
}

unsigned long long int getSum(struct Node * root, unsigned long long int  temp){
    if (root == NULL)
        return 0;
    long long int digits = getNumberOfDigits(root->val);
   temp = (temp*digits + (root->val))%1000000007;
    if (root ->right == NULL && root->left == NULL)
        return temp;
    return ((getSum(root->left, temp) +
        getSum(root->right, temp))%1000000007);
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
       printf("%llu\n", getSum(node, 0));
    }
    return 0;
}
