/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int findMax(int start, int end, vector<int> &A){
    return max_element(A.begin()+start,A.begin()+end+1) - A.begin();
}
TreeNode *build(int start, int end, vector<int> &A){

    if(start > end)
        return NULL;

    int idx = findMax(start,end,A);
    TreeNode *root = new TreeNode(A[idx]);

    root->left = build(start,idx-1,A);
    root->right = build(idx+1,end,A);
    
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    return build(0,A.size()-1,A);
}
