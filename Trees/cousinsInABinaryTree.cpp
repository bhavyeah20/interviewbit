/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    queue<TreeNode *> q;
    TreeNode *root = A;
    vector<int> ans;
    bool nodeFound = 0, flag = 0;

    if(!root)
        return ans;

    if(B == root->val)
        return ans;

    q.push(root);

    while(!q.empty()){
        int sz = q.size();
        ans.clear();
        for(int i = 0; i < sz; i++){
            nodeFound = 0;
            root = q.front();
            q.pop();
            
            if((root->left && root->left->val == B) ||( 
                            root->right && root->right->val == B))
                nodeFound = 1, flag = 1;
                
                

            if(root->left){
                if(!nodeFound){
                    ans.push_back(root->left->val);
                }
                q.push(root->left);
            }

            if(root->right){
                if(!nodeFound){
                    ans.push_back(root->right->val);
                }
                q.push(root->right);
            }

        }

        if(flag){
            return ans;   
        }
    }


}
