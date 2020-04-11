/*
https://www.interviewbit.com/problems/path-sum/


Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
int checkSum(TreeNode * root, int B){
    if(root == NULL)
        return 0;
    B-=(root->val);
    if(root->left == NULL && root->right ==NULL)
        {
            if(B==0)
                return 1;
            return 0;
        }
    int a = checkSum(root->left, B);
    free(root->left);
    a = a || checkSum(root->right, B);
    free(root->right);
    return a;
}

int Solution::hasPathSum(TreeNode* root, int B) {
    return checkSum(root, B);
}