/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {

    if(!A->right && !A->left)
        return 1;
    if(!A->right)
        return 1 + minDepth(A->left);
    if(!A->left)
        return 1 + minDepth(A->right);
    return 1 + min(minDepth(A->left),minDepth(A->right));
}
