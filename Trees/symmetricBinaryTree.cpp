/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool check(TreeNode *A, TreeNode *B){
    if(!A && !B)
        return 1;

    if(!A || !B)
        return 0;

    return (A->val == B->val) && check(A->left,B->right) && check(A->right,B->left);
}
int Solution::isSymmetric(TreeNode* A) {
    return check(A,A);
}
