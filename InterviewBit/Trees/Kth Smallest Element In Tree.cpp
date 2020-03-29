/**
 * https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int k = 1;
int ans = 0;

void inorder(TreeNode * root, int b){
    if(root == NULL)
        return;
    inorder(root->left, b);
    if(k==b)
        ans = root->val;
    k++;
    inorder(root->right, b);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    inorder(A, B);
    int mainans = ans;
    ans = 0;
    k = 1;
    return mainans;
}
