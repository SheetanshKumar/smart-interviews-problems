//https://www.hackerrank.com/contests/smart-interviews/challenges/si-level-order-of-tree/submissions/code/1320326929

/*First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Constraints

For each test case, print the Level Order of the Binary Search Tree, separate each level by newline. Separate the output of different test cases with an extra newline.

Output Format

1 <= T <= 1000
1 <= N <= 1000
0 <= ar[i] <= 10000

Sample Input 0

3
5
1 2 3 4 5
5
3 2 4 1 5
7
4 5 15 0 1 7 17

Sample Output 0

1
2
3
4
5

3
2 4
1 5

4
0 5
1 15
7 17

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

void printLevel(Node * root){
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(q.empty() == false){
        while(!q.empty() && q.front() != NULL){
            Node * node = q.front();
            printf("%d ", node->val);
            q.pop();
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }
        q.pop();
        printf("\n");
        if(q.empty() == false)
            q.push(NULL);
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
        printLevel(node);
        printf("\n");
    }
    return 0;
}
