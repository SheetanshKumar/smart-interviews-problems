//https://www.hackerrank.com/contests/smart-interviews/challenges/si-vertical-order-of-tree/copy-from/1320336304

/*Given an array of unique elements, construct a Binary Search Tree and print the tree in a Vertical Order, starting from the left-most node. Print the nodes in each vertical in sorted order.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= ar[i] <= 10000

Output Format

For each test case, print the Vertical Levels of the Binary Search Tree, separate each level by newline. Separate the output of different test cases with an extra newline.

Sample Input 0

3
5
1 2 3 4 5
5
3 1 2 5 4
7
4 5 15 0 1 7 17

Sample Output 0

1
2
3
4
5

1
2 3 4
5

0
1 4
5 7
15
17

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

void getVertical(Node * root, map<int, vector<int>> &mp, int level){
    if (root == NULL)
        return;

    mp[level].push_back(root->val);
    getVertical(root->left, mp, level-1);
    getVertical(root->right, mp, level+1);
}

void printVertical(Node * root){
    map<int, vector<int>> mp;
    getVertical(root, mp, 0);
    map<int, vector<int>> :: iterator i;
    for (i = mp.begin(); i != mp.end(); i++){
        vector<int> arr;
        for (int j = 0; j < i->second.size(); j++){
           arr.push_back(i->second[j]);
        }
        sort(arr.begin(), arr.end());
        for (int j = 0; j < i->second.size(); j++){
           printf("%d ", arr[j]);
        }
        printf("\n");
    }
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
        printVertical(node);
        printf("\n");
    }
    return 0;
}
