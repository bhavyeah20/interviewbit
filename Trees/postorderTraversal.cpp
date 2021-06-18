/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode *> s;

    TreeNode *root = A;
    while(root || !s.empty()){
        if(root){
            s.push(root);
            ans.push_back(root->val);
            root = root->right;
        }

        else{
            root = s.top();
            s.pop();
            root = root->left;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
