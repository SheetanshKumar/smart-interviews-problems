

Node * LLtoBST(Node * head, int n){
    if(n <= 0)
        return NULL;

    Node * left = LLtoBST(head, n/2);

    Node * root = newNode(head->data);
    root->left = left;

    Node * right = LLtoBST(head, n - n/2 -1);
    root->right = right;
    return root;
}

T.C : O(n)