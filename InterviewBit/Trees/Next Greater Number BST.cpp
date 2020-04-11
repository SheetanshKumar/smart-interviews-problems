/*
https://www.interviewbit.com/problems/next-greater-number-bst/

Given a BST node, return the node which has value just greater than the given node.

Example:

Given the tree

               100
              /   \
            98    102
           /  \
         96    99
          \
           97

Given 97, you should return the node corresponding to 98 as thats the value just greater than 97 in the tree.
If there are no successor in the tree ( the value is the largest in the tree, return NULL).

Using recursion is not allowed.

Assume that the value is always present in the tree.
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

TreeNode* Solution::getSuccessor(TreeNode* root, int B) {
    TreeNode * res = NULL;

    while(root){
        if(root->val <= B){
            root = root->right;
        }
        else{
            res = root;
            root = root->left;
        }
    }
    return res;
}
