/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &A) {
    priority_queue<int> pq;
    unordered_map<int,int> mp; //ele->idx
    for(int i = 0; i < A.size(); i++){
        pq.push(A[i]);
        mp[A[i]] = i;
    }
    TreeNode *root = NULL, *prev = NULL;
    int prevIdx = -1;
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        int idx = mp[x];
        TreeNode *t = new TreeNode(x);
        
        if(prevIdx == -1){
            root = t;
            prevIdx = idx;
        }
        else if(idx > prevIdx){
            prev->right = t;
        }
        else
            prev->left = t;
            
        prev = t;
    }
    
    return root;
}
