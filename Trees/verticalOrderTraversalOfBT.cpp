/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
   map<int,vector<int>> mp;
   vector<vector<int> > ans;
   
   queue<pair<int, TreeNode *> > q;
   if(!root)
    return ans;

    q.push({0,root});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        mp[it.first].push_back((it.second)->val);
        if((it.second)->left)
            q.push({(it.first)-1,(it.second)->left});
        if((it.second)->right)
            q.push({(it.first)+1,(it.second)->right});
    } 

    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
}
