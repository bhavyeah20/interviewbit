/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<TreeNode*> s;
    TreeNode *root = A;
    
    if(!root)
        return root;
        
    bool flag = 0;
    while(root || !s.empty()){
        while(root){
            s.push(root);
            root = root->left;
        }
        
        root = s.top();
        if(flag)
            return root;
        if(root->val == B)
            flag = 1;
        s.pop();
        root = root->right;
    }
    
    return NULL;
    
    
}
