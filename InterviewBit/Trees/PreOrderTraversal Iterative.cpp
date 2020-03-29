/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack <TreeNode*> s;
    if(root == NULL)
        return res;

    s.push(root);
    while(!s.empty()){
        TreeNode * node = s.top();
        res.push_back(node->val);
        s.pop();

        if(node->right!=NULL)
            s.push(node->right);
        if(node->left!=NULL)
            s.push(node->left);
    }
    return res;
}