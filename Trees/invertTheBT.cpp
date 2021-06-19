/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if(!A)
        return A;

    A->left = invertTree(A->left);
    A->right = invertTree(A->right);

    TreeNode *Aright = A->right;
    A->right = A->left;
    A->left = Aright;

    return A;

}
