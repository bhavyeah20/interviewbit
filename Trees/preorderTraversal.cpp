/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode *> s;
    
    TreeNode *root = A;
    while(root || !s.empty()){
        if(root){
            ans.push_back(root->val);
            s.push(root);
            root = root->left;
        }
        
        else{
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
    
    return ans;
}
