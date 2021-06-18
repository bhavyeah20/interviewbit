/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool path(TreeNode *A, int B, vector<int> &ans){
    
    if(!A)
        return 0;

    ans.push_back(A->val);

    if(A->val == B){
        return 1;
    }


    if(path(A->left,B,ans))
        return 1;

    if(path(A->right,B,ans))
        return 1;

    ans.pop_back();
    return 0;

}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    bool check = path(A,B,ans);
    return ans;
}
