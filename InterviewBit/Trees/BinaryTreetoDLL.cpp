

void btoDLL(Node * root, Node* head){
    if(root == NULL)
        return;
    btoDLL(root->right, head);
    if(head)
        head->left = root;
    head = root;
    btoDLL(root->left, head);
}

T.C = O(n)