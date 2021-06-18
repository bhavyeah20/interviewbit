/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode *> q;
    vector<int> ans;

    if(!A)
        return ans;
    q.push(A);
    ans.push_back(A->val);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode *root = q.front();
            q.pop();
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        if(!q.empty())
            ans.push_back(q.back()->val);
    }

    return ans;
}
