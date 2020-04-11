/*
Symmetric Binary Tree

https://www.interviewbit.com/problems/symmetric-binary-tree/

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3

The above binary tree is symmetric.
But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int symmetric(TreeNode * A, TreeNode * B){
    if(A == NULL && B == NULL)
        return 1;
    if(A && B){
        if(A->val == B->val)
            return symmetric(A->left, B->right) && symmetric(A->right, B->left);
    }
    return 0;
}
int Solution::isSymmetric(TreeNode* A) {
    return symmetric(A->left, A->right);
}
