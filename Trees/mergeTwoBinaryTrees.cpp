/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if(!A && !B)
        return A;

    if(!A)
        return B;

    if(!B)
        return A;

    A->left = solve(A->left, B->left);
    A->right = solve(A->right, B->right);

    A->val += B->val;

    return A;
}
