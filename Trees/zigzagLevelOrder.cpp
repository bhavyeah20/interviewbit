/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {

    int dir = 1;

    queue<TreeNode *> q;
    vector<vector<int> > ans;
    if(!A)
        return ans;
    q.push(A);
    while(!q.empty()){
        dir = (dir + 1) % 2;
        int sz = q.size();
        vector<int> res(sz);
        for(int i = 0; i < sz; i++){
            TreeNode *root = q.front();
            if(dir)
                res[sz-i-1] = root->val;
            else
                res[i] = root->val;
            q.pop();
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
     
        ans.push_back(res);
    }

    return ans;

}
