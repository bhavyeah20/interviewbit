/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



TreeNode *halve(TreeNode *A){
    if(!A)
        return A;

    A->left = halve(A->left);
    A->right = halve(A->right);

    if(A->left && !A->right || !A->left && A->right){
        if(A->left){
            A = A->left;
        }

        else
            A = A->right;
    }

    return A;


}
TreeNode* Solution::solve(TreeNode* A) {
    return halve(A);
}
