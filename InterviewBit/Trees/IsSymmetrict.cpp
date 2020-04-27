bool check(struct Node * t1, struct Node * t2){
    if(t1 == NULL && t2 == NULL)
        return true;
    if(t1 == NULL || t2 == NULL)
        return false;
    return (t1->data == t2->data && check(t1->left, t2->right)
    && check(t1->right, t2->left));
}
bool isSymmetric(struct Node* root)
{
	return check(root->left, root->right);
}