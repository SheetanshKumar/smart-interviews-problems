/*
https://www.hackerrank.com/contests/smart-interviews/challenges/si-nodes-at-distance-k/submissions/code/1322452317
Given an array of unique elements, construct a Binary Search Tree and find the number of nodes at a distance K from the given source node S. Distance is defined as the number of edges between 2 nodes.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N, S, K - number of nodes in the BST, the source node and the distance K. The next line contains N unique integers - value of the nodes.

Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= ar[i] <= 10000

Output Format

For each test case, print the number of nodes in the Binary Search Tree which are K distance away from S, separated by newline.

Sample Input 0

3
5 3 2
1 2 3 4 5
5 4 1
2 4 3 1 5
7 5 2
4 5 15 0 1 7 17

Sample Output 0

2
3
3

*/


#include <bits/stdc++.h>

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

struct Node* insert(struct Node* &node, int val, int src, struct Node* &srcnode) {
    struct Node* obj = newNode(val);
    if (src == val)
        srcnode = obj;
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

int bfsCountNodeAtK(struct Node*& root, struct Node*& srcnode,
    unordered_map<struct Node*, struct Node*>& pmap, int k) {
    if(k==0)
        return 0;
    unordered_set<struct Node*> vis;
    vis.insert(srcnode);
    queue<struct Node*> q;
    q.push(srcnode);
    int c = 0;
    while (!q.empty()) {
        if (c == k)
            {
                return q.size();
            }
        int s = q.size();
        while(s--){
            struct Node* temp = q.front();
            q.pop();
            if (temp->left && vis.find(temp->left) == vis.end()) {
                q.push(temp->left);
                vis.insert(temp->left);
            }
            if (temp->right && vis.find(temp->right) == vis.end()) {
                q.push(temp->right);
                vis.insert(temp->right);
            }
            if (pmap.at(temp)->val != -1 && vis.find(pmap.at(temp)) == vis.end()) {
                q.push(pmap.at(temp));
                vis.insert(pmap.at(temp));
            }
        }
        c++;
    }
    return 0;
}

void preorder(unordered_map<struct Node*, struct Node*> &pmap, struct Node * root, struct Node * parent)
{
    if (root == NULL)
        return;
    pmap[root] = parent;
    preorder(pmap, root->left, root);
    preorder(pmap, root->right, root);
}

int main() {
    int t;
    cin>>t;

    int i = 0;
    for (i = 0; i < t; i++) {
        int n, s, k;
        cin >> n >> s >>k;
        int* arr = (int*)malloc(sizeof(int) * n);
        int j = 0;
        struct Node* node = NULL;
        struct Node* srcnode = NULL;

        for (j = 0; j < n; j++) {
            cin >> arr[j];
            node = insert(node, arr[j], s, srcnode);
        }
        unordered_map<struct Node*, struct Node*> pmap;
        struct Node* parenttemp = newNode(-1);
        preorder(pmap, node, parenttemp);
        for(auto x : pmap){
            //cout << x.first->val << " = " << x.second->val << endl;
        }
        //cout <<endl;
        int count = bfsCountNodeAtK(node, srcnode, pmap, k);
        printf("%d\n", count);
    }
    return 0;
}