/*
https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]

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
void sumPath(TreeNode * root, int B, vector<int> &res, vector<vector<int>> &mres, int &s)
{
    if(root == NULL)
        return;
    res.push_back(root->val);
    s+=(root->val);
    if(root->left == NULL && root->right == NULL){
        if(s == B)
            mres.push_back(res);
    }
    sumPath(root->left, B, res, mres, s);
    sumPath(root->right, B, res, mres, s);
    free(root->left);
    free(root->right);
    s-=res[res.size()-1];
    res.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int B) {
    vector<vector<int>> mres;
    vector<int> res;
    int s=0;
    sumPath(root, B, res, mres, s);
    return mres;
}