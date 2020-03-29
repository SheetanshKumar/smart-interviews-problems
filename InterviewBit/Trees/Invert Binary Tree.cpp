/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void invert(TreeNode * root){
    if(root == NULL)
        return;
    swap(root->left, root->right);
    invert(root->left);
    invert(root->right);
}

void swap(TreeNode * a, TreeNode * b){
    TreeNode * temp = a;
    a = b;
    b = temp;
}
TreeNode* Solution::invertTree(TreeNode* root) {
    invert(root);
    return root;
}
