/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A) {
    queue<TreeNode *> q;
    TreeNode *root = A;
    if(!root)
        return 0;

    q.push(root);
    int maxSum = 0;
    while(!q.empty()){
        int sum = 0;
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            root = q.front();
            q.pop();
            sum += root->val;

            if(root->left)
                q.push(root->left);

            if(root->right)
                q.push(root->right);
        }

        maxSum = max(sum,maxSum);
    }

    return maxSum;
}
