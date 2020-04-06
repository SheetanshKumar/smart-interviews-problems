/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode * first = NULL;
TreeNode * mid = NULL;
TreeNode * endnode = NULL;

void inorder(TreeNode * root, TreeNode * &prev){
    if(root == NULL)
        return;
    inorder(root->left, prev);

    if(prev && prev->val > root->val){
        if(first == NULL)
            {
                first = prev;
                mid = root;
            }
        else
            endnode = root;
    }
    prev = root;
    inorder(root->right, prev);

}

vector<int> Solution::recoverTree(TreeNode* root) {
    first = NULL;
    mid = NULL;
    endnode = NULL;
    vector<int> res;
    TreeNode * prev = NULL;
    inorder(root, prev);
    if(first && mid && endnode == NULL){
        res.push_back(first->val);
        res.push_back(mid->val);
    }
    else if(first && endnode){
        res.push_back(first->val);
        res.push_back(endnode->val);
    }
    sort(res.begin(), res.end());
    return res;
}
