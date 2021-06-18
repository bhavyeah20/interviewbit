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
    vector<int> ans;
    if(not A) return ans;
    queue<TreeNode *> q;
    q.push(A);
    while(q.size())
    {
        TreeNode *ptr=q.front();
        q.pop();
        ans.push_back(ptr->val);
        if(ptr->right) q.push(ptr->right);
        if(ptr->left) q.push(ptr->left);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}