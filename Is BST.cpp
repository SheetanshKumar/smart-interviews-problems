/*
https://www.hackerrank.com/challenges/is-binary-search-tree/copy-from/152586872
*/

bool check(Node * root, Node* &prev){
    if(root == NULL)
        return true;
    bool resl = check(root->left, prev);
    if(prev)
        if(prev->data >= root->data)
            return false;
    prev = root;
    bool resr = check(root->right, prev);
    return resr && resl;
}
bool checkBST(Node* root) {
    Node * prev = NULL;
    return check(root, prev);
}