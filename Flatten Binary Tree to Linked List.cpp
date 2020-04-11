/*
https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/



Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Note that the left child of all nodes should be NULL.

*/

// My solution with space O(n)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode * newNode(int val){
    TreeNode * obj = (TreeNode *)malloc(sizeof(TreeNode));
    obj->val = val;
    obj->left = NULL;
    obj->right = NULL;
    return obj;
}
void convert(TreeNode * root, TreeNode * &head){
    if(!root)
        return ;
    TreeNode * temp = newNode(root->val);
    head->right = temp;
    head = head->right;
    convert(root->left, head);
    convert(root->right, head);
    free(root->left);
    free(root->right);
}



TreeNode* Solution::flatten(TreeNode* root) {
    TreeNode * head = newNode(-100000);
    TreeNode * res = head;
    convert(root, head);
    return res->right;
}



/*


         1                      1
        / \                       \
       2   5        =>              2           => and so on.
      / \   \                      /  \
     3   4   6                    3    4
                                        \
                                         5
                                          \
                                           6
*/




// editorial solution by changing directions
TreeNode* Solution::flatten(TreeNode* root) {
    if(!root)
        return root;
    TreeNode * node = root;
    while(node){
        if(node->left){
            TreeNode * rightnode = node->left;
            while(rightnode->right)
                rightnode = rightnode->right;
            rightnode->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        node = node->right;
    }
    return root;
}
