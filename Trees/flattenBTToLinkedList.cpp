/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *getRightMost(TreeNode *root){
    if(!root)
        return root;
    while(root->right || root->left){
        if(root->right)
            root = root->right;
        else
            root = root->left;
    }
    return root;
}

TreeNode *flat(TreeNode *root){
    if(!root)
        return root;
    TreeNode *head = root;
    while(root && (root->left || root->right)){
        root->left = flat(root->left);
        TreeNode *rootsRight = root->right;
        root->right = root->left;
        root->left = NULL;
        if(root->right)
            getRightMost(root->right)->right = rootsRight;
        else
            root->right = rootsRight;
        root = rootsRight;
    }
    return head;
}


TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return flat(A);
}


//or

private TreeNode prev = null;

public void flatten(TreeNode root) {
    if (root == null)
        return;
    flatten(root.right);
    flatten(root.left);
    root.right = prev;
    root.left = null;
    prev = root;
}