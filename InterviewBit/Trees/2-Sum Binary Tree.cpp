/*
https://www.interviewbit.com/problems/2sum-binary-tree/


Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

    Your solution should run in linear time and not take memory more than O(height of T).
    Assume all values in BST are distinct.

Example :

Input 1:

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2:

T:        10
         / \
        9   20

K = 40

Return: 0


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
void inorder(TreeNode* root, vector<int> & res){
    if(root == NULL)
        return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

int checkSum(vector<int> arr, int k){
    int i = 0;
    int j = arr.size()-1;
    while(i != j){
        if(arr[i] + arr[j] == k)
            return 1;
        if(arr[i] + arr[j] > k)
            j--;
        else
            i++;
    }
    return 0;
}
int Solution::t2Sum(TreeNode* A, int B) {
    vector<int> arr;
    inorder(A, arr);
    return checkSum(arr, B);
}
