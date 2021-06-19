/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void build(TreeNode *A, int B, vector<int> &curr, vector<vector<int> > &ans){
    if(!A)
        return ;

    if(!A->left && !A->right){
        if(B == A->val){
            curr.push_back(A->val);
            ans.push_back(curr);
            curr.pop_back();
        }
        
       
        return ;
    }

    curr.push_back(A->val);
    build(A->left, B - A->val, curr,ans);
    build(A->right,B - A->val, curr,ans);
    curr.pop_back();

}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<int> curr;
    vector<vector<int> > ans;
    build(A,B,curr,ans);
    return ans;
}
