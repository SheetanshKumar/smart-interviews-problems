/**
 * https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

long getDigits(int n){
    int res = 10;
    while(n/10 != 0){
        res*=10;
        n = n/10;
    }
    return res;
}
long getSum(TreeNode * root, long sum){
    if(root == NULL)
        return 0;
    long digits = getDigits(root->val);
    sum = (sum*digits + root->val)%1003;
    if(root->left == NULL && root->right == NULL)
        return sum;
    return (getSum(root->left, sum)+getSum(root->right, sum))%1003;
}
int Solution::sumNumbers(TreeNode* A) {
    return getSum(A,0);
}
