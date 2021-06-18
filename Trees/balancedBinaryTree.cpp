/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int height(TreeNode *A){
    if(!A) return -1;

    return 1 + max(height(A->left),height(A->right));
}
int Solution::isBalanced(TreeNode* A) {
    if(!A) return 1;
    return isBalanced(A->left) && isBalanced(A->right) && abs(height(A->left) - height(A->right)) <= 1;
    
} 
