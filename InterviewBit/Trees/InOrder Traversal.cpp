/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root == NULL)
        return res;
    stack <TreeNode*> s;
    s.push(root);
    unordered_set<TreeNode*> st;
    while(!s.empty()){
        TreeNode * temp = s.top();
        while(temp->left != NULL && st.count(temp->left)<1){
            s.push(temp->left);
            temp = temp->left;
        }
        //st.insert(s.top());
        s.pop();
        res.push_back(temp->val);
        if(temp->right)
            s.push(temp->right);
    }
    return res;
}

// my second solution without set

vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root == NULL)
        return res;
    stack <TreeNode*> s;
    s.push(root);
    unordered_set<TreeNode*> st;
    int flag = 1;
    while(!s.empty()){
        TreeNode * temp = s.top();
        while(temp->left != NULL && flag){
            s.push(temp->left);
            temp = temp->left;
        }
        //st.insert(s.top());
        s.pop();
        res.push_back(temp->val);
        if(temp->right){
            flag = 1;
            s.push(temp->right);
        }
        else
            flag = 0;
    }
    return res;
}



// Editorial :
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> res;
    stack<TreeNode* > st;
    TreeNode* root=A;
    while(true)
    {
        if(root==NULL)
        {
            if(st.empty())
            break;
            root=st.top();
            st.pop();
            res.push_back(root->val);
            root=root->right;


        }
        else
        {

            st.push(root);
            root=root->left;
        }
    }
    return res;
}

